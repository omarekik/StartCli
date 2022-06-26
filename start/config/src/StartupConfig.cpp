#include "StartupConfig.h"

#include <iostream>

#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[])
{
    bpo::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "display help menu")
        ("create,c", bpo::bool_switch(),"Option of create as example of boolean")
        ("width,w", bpo::value<int>() -> default_value(10), "Option of width as example of Integer");

    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return std::nullopt;
    }

    return StartupConfig{ vm["create"].as<bool>()
                        , vm["width"].as<int>() 
                        };
}
