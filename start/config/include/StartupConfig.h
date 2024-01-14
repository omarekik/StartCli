#pragma once
#include <optional>

struct StartupConfig {
    const bool m_Create;
    const int m_Width;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc, const char** argv);
