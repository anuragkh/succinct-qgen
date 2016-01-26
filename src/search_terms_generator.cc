#include "search_terms_generator.h"

#include <unistd.h>

void PrintUsage(char *exec) {
  fprintf(stderr, "Usage: %s [-b bin-size] [-n num-bins] [-i input] [-o output]\n", exec);
}

int main(int argc, char **argv) {
  if (argc > 9) {
    PrintUsage(argv[0]);
    return -1;
  }

  int c;
  std::string input = "data";
  std::string output = "queries";
  int64_t bin_size = 1000, num_bins = 10, term_length = 8;
  while ((c = getopt(argc, argv, "i:o:b:n:t:")) != -1) {
    switch (c) {
      case 'i':
        input = std::string(optarg);
        break;
      case 'o':
        output = std::string(optarg);
        break;
      case 'b':
        bin_size = atol(optarg);
        break;
      case 'n':
        num_bins = atol(optarg);
        break;
      case 't':
        term_length = atol(optarg);
        break;
      default:
        fprintf(stderr, "Could not parse argument %c\n", c);
        PrintUsage(argv[0]);
        exit(-1);
    }
  }

  // Generate search terms
  SearchTermsGenerator gen(term_length, bin_size, num_bins, input, output);
  gen.generate();

  return 0;
}
