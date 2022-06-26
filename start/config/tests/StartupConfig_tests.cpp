#include "StartupConfig.h"

#include <gtest/gtest.h>
#include <string>

char arg0[] = "Program name";
char arg1[] = "--create";
char arg2[] = "--width";
char arg3[] = "10";

TEST(StartupConfigTests, validOptions_returnsStartupConfig)
{
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], NULL };
    const auto config = optionsToStartupConfig(4, argv);
    ASSERT_TRUE(config);
    ASSERT_TRUE(config->m_Create);
    ASSERT_EQ(config->m_Width, 10);
}

TEST(StartupConfigTests, helpOption_returnsEmptyStartupConfig)
{
    char help[] = "--help";
    char* argv[] = { &arg0[0], &help[0], NULL };
    const auto config = optionsToStartupConfig(2, argv);
    ASSERT_FALSE(config);
}

TEST(StartupConfigTests, notAllOptions_throws)
{
    //
    // Throw an exeption as no integer value is passed with --width option
    //
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], NULL };
    ASSERT_ANY_THROW(optionsToStartupConfig(3, argv));
}
