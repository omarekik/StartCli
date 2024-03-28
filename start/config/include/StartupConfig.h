#pragma once
#include <optional>

struct StartupConfig {
  bool create;
  int width;
};

std::optional<const StartupConfig> OptionsToStartupConfig(int argc,
                                                          const char** argv);
