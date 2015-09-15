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
                       uint64_t bin_max, std::string input,
                       std::string output) {
    term_length_ = term_length;
    bin_size_ = bin_size;
    bin_max_ = bin_max;
    input_ = input;
    output_ = output;
  }

  void generate() {
    std::map<std::string, uint64_t> term_count;

    // Compute term frequencies
    std::ifstream in(input_);
    std::string line;
    while (std::getline(in, line)) {
      for (uint64_t i = 0; i <= line.length() - term_length_; i++) {
        std::string term = line.substr(i, term_length_);
        assert(term.length() == term_length_);
        term_count[term]++;
      }
    }
    in.close();

    // Create output streams
    std::ofstream *streams = new std::ofstream[bin_max_];
    for (uint64_t i = 0; i < bin_max_; i++) {
      streams[i].open(output_ + "." + std::to_string(i));
    }

    // Segregate terms into bins, output bins
    uint64_t occ_max_ = bin_max_ * bin_size_;
    for (auto term_entry : term_count) {
      if (term_entry.second < occ_max_) {
        streams[term_entry.second / bin_size_] << term_entry.second << "\t"
                                               << term_entry.first << "\n";
      }
    }

    // Close output streams
    for (uint64_t i = 0; i < bin_max_; i++) {
      streams[i].close();
    }
  }

 private:
  uint64_t term_length_;
  uint64_t bin_size_;
  uint64_t bin_max_;
  std::string input_;
  std::string output_;
};

#endif // SEARCH_GENERATOR_H_
