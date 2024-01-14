#include "StartupConfig.h"

#include <gtest/gtest.h>
#include <string>
#include <array>

const std::string arg0 {"Program name"};
const std::string arg1 {"--create"};
const std::string arg2 {"--width"};
const std::string arg3 {"10"};

TEST(StartupConfigTests, validOptions_returnsStartupConfig)
{
    const unsigned int ARGC {5};
    std::array<const char*, ARGC> argv = { 
        arg0.c_str(), arg1.c_str(), arg2.c_str(), arg3.c_str(), nullptr };
    const auto config = optionsToStartupConfig(4, argv.data());
    ASSERT_TRUE(config);
    ASSERT_TRUE(config->m_Create);
    ASSERT_EQ(config->m_Width, 10);
}

TEST(StartupConfigTests, helpOption_returnsEmptyStartupConfig)
{
    const std::string help {"--help"};
    const unsigned int ARGC {3};
    std::array<const char*, ARGC> argv = { arg0.c_str(), help.c_str(), nullptr };
    const auto config = optionsToStartupConfig(2, argv.data());
    ASSERT_FALSE(config);
}

TEST(StartupConfigTests, notAllOptions_throws)
{
    //
    // Throw an exeption as no integer value is passed with --width option
    //
    const unsigned int ARGC {4};
    std::array<const char*, ARGC> argv = { 
        arg0.c_str(), arg1.c_str(), arg2.c_str(), nullptr };
    ASSERT_ANY_THROW(optionsToStartupConfig(3, argv.data()));
}
