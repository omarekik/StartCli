#pragma once
#include <optional>

struct StartupConfig {
    bool m_Create;
    int m_Width;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc, const char** argv);
