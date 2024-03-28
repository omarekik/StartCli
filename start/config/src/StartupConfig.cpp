#include "StartupConfig.h"

#include <boost/program_options.hpp>
#include <iostream>

namespace bpo = boost::program_options;

std::optional<const StartupConfig> OptionsToStartupConfig(int argc,
                                                          const char** argv) {
  bpo::options_description desc("Allowed options");
  const int kdefault_width = 10;
  desc.add_options()("help,h", "display help menu")(
      "create,c", bpo::bool_switch(), "Option of create as example of boolean")(
      "width,w", bpo::value<int>()->default_value(kdefault_width),
      "Option of width as example of Integer");

  bpo::variables_map vmap{};
  bpo::store(bpo::parse_command_line(argc, argv, desc), vmap);
  bpo::notify(vmap);

  if (vmap.count("help") != 0U) {
    std::cout << desc << "\n";
    return std::nullopt;
  }

  return StartupConfig{vmap["create"].as<bool>(), vmap["width"].as<int>()};
}
