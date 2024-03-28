#include <gtest/gtest.h>

#include <array>
#include <string>

#include "StartupConfig.h"

class StartupConfigTests : public ::testing::Test {
 protected:
  const std::string karg0{"Program name"};
  const std::string karg1{"--create"};
  const std::string karg2{"--width"};
  const std::string karg3{"10"};
};

TEST_F(StartupConfigTests, validOptions_returnsStartupConfig) {
  const unsigned int kargc{5};
  std::array<const char*, kargc> argv = {karg0.c_str(), karg1.c_str(),
                                         karg2.c_str(), karg3.c_str(), nullptr};
  const auto kconfig = OptionsToStartupConfig(4, argv.data());
  ASSERT_TRUE(kconfig);
  ASSERT_TRUE(kconfig->create);
  ASSERT_EQ(kconfig->width, 10);
}

TEST_F(StartupConfigTests, helpOption_returnsEmptyStartupConfig) {
  const std::string khelp{"--help"};
  const unsigned int kargc{3};
  std::array<const char*, kargc> argv = {karg0.c_str(), khelp.c_str(), nullptr};
  const auto kconfig = OptionsToStartupConfig(2, argv.data());
  ASSERT_FALSE(kconfig);
}

TEST_F(StartupConfigTests, notAllOptions_throws) {
  //
  // Throw an exeption as no integer value is passed with --width option
  //
  const unsigned int kargc{4};
  std::array<const char*, kargc> argv = {karg0.c_str(), karg1.c_str(),
                                         karg2.c_str(), nullptr};
  ASSERT_ANY_THROW(OptionsToStartupConfig(3, argv.data()));
}
