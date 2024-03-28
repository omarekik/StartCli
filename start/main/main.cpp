#include <gsl/gsl>
#include <iostream>

#include "StartupConfig.h"

int main(int argc, const char** argv) {
  Expects(argc > 0);  // define pre-conditions
  try {
    if (const auto kconfig = OptionsToStartupConfig(argc, argv)) {
      if (kconfig->create) {
        std::cout << "The width is " << kconfig->width << "\n";
      } else {
        std::cout << "Create option should be called\n";
      }
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }
}
