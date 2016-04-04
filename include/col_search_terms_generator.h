#ifndef COL_SEARCH_GENERATOR_H_
#define COL_SEARCH_GENERATOR_H_

#include <cstdint>
#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class ColumnSearchTermsGenerator {
 public:
  typedef std::pair<std::string, int> Cell;
  ColumnSearchTermsGenerator(char delim, uint64_t bin_size,
                       uint64_t num_bins, std::string input,
                       std::string output) {
    delim_ = delim;
    bin_size_ = bin_size;
    num_bins_ = num_bins;
    input_ = input;
    output_ = output;
  }

  void generate() {
    fprintf(stderr, "Creating %llu bins, each of size %llu queries.\n",
            num_bins_, bin_size_);
    std::map<Cell, uint64_t> term_count;

    // Compute term frequencies
    std::ifstream in(input_);
    std::string line;
    while (std::getline(in, line)) {
      std::stringstream ss(line);
      std::string term;
      int col_id = 0;
      while (std::getline(ss, term, delim_)) {
        Cell cur_cell(term, col_id);
        term_count[cur_cell]++;
        col_id++;
      }
    }
    in.close();

    // Create output streams
    std::ofstream *streams = new std::ofstream[num_bins_];
    for (uint64_t i = 0; i < num_bins_; i++)
      streams[i].open(output_ + "." + std::to_string(i));

    // Segregate terms into bins, output bins
    uint64_t occ_max_ = num_bins_ * bin_size_;
    for (auto term_entry : term_count)
      if (term_entry.second < occ_max_)
        streams[term_entry.second / bin_size_] << term_entry.second << "\t"
            << term_entry.first.second << "\t" << term_entry.first.first << "\n";

    // Close output streams
    for (uint64_t i = 0; i < num_bins_; i++)
      streams[i].close();

    delete[] streams;
  }

 private:
  char delim_;
  uint64_t bin_size_;
  uint64_t num_bins_;
  std::string input_;
  std::string output_;
};

#endif // COL_SEARCH_GENERATOR_H_
