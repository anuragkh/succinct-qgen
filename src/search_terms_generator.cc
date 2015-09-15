#include "search_terms_generator.h"

#include <unistd.h>

void print_usage(char *exec) {
  fprintf(stderr, "Usage: %s [-n num-bins] [-m max-bin] [-i input] [-o output]\n", exec);
}

int main(int argc, char **argv) {
  if (argc > 9) {
    print_usage(argv[0]);
    return -1;
  }

  int c;
  std::string input = "data";
  std::string output = "queries";
  int64_t num_bins = 1000, bins_max = 10, term_length = 8;
  while ((c = getopt(argc, argv, "i:o:n:m:t:")) != -1) {
    switch (c) {
      case 'i':
        input = std::string(optarg);
        break;
      case 'o':
        output = std::string(optarg);
        break;
      case 'n':
        num_bins = atol(optarg);
        break;
      case 'm':
        bins_max = atol(optarg);
        break;
      case 't':
        term_length = atol(optarg);
        break;
      default:
        fprintf(stderr, "Could not parse argument %c\n", c);
        exit(-1);
    }
  }

  // Generate search terms
  SearchTermsGenerator gen(term_length, num_bins, bins_max, input, output);
  gen.generate();

  return 0;
}
