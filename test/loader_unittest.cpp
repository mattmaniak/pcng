#include <gtest/gtest.h>

#include "../src/loader.cpp"

TEST(LoaderTest, LoadsPrefixesAndSufixes)
{
    ASSERT_NE(loader::load(loader::prefix).empty(), true);
    ASSERT_NE(loader::load(loader::sufix).empty(), true);
}