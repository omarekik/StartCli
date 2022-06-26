#pragma once

#include <cstdint>
#include <optional>

struct StartupConfig {
    const bool m_Create;
    const int m_Width;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[]);
