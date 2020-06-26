#include <gtest/gtest.h>

#include "../src/loader.cpp"

TEST(LoaderTest, LoadsPrefixesAndSuffixes)
{
    ASSERT_EQ(loader::load(loader::prefix).empty(), false);
    ASSERT_EQ(loader::load(loader::suffix).empty(), false);
}