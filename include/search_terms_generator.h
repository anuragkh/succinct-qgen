#ifndef SEARCH_GENERATOR_H_
#define SEARCH_GENERATOR_H_

#include <cstdint>
#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

class SearchTermsGenerator {

 public:
  SearchTermsGenerator(uint64_t term_length, uint64_t bin_size,
                       uint64_t num_bins, std::string input,
                       std::string output) {
    term_length_ = term_length;
    bin_size_ = bin_size;
    num_bins_ = num_bins;
    input_ = input;
    output_ = output;
  }

  void generate() {
    fprintf(stderr, "Creating %llu bins, each of size %llu queries.\n",
            num_bins_, bin_size_);
    std::map<std::string, uint64_t> term_count;

    // Compute term frequencies
    std::ifstream in(input_);
    std::string line;
    while (std::getline(in, line)) {
      if (line.length() < term_length_)
        continue;
      for (uint64_t i = 0; i <= line.length() - term_length_; i++) {
        std::string term = line.substr(i, term_length_);
        assert(term.length() == term_length_);
        term_count[term]++;
      }
    }
    in.close();

    // Create output streams
    std::ofstream *streams = new std::ofstream[num_bins_];
    for (uint64_t i = 0; i < num_bins_; i++) {
      streams[i].open(output_ + "." + std::to_string(i));
    }

    // Segregate terms into bins, output bins
    uint64_t occ_max_ = num_bins_ * bin_size_;
    for (auto term_entry : term_count) {
      if (term_entry.second < occ_max_) {
        streams[term_entry.second / bin_size_] << term_entry.second << "\t"
                                               << term_entry.first << "\n";
      }
    }

    // Close output streams
    for (uint64_t i = 0; i < num_bins_; i++) {
      streams[i].close();
    }

    delete[] streams;
  }

 private:
  uint64_t term_length_;
  uint64_t bin_size_;
  uint64_t num_bins_;
  std::string input_;
  std::string output_;
};

#endif // SEARCH_GENERATOR_H_
