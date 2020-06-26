#include <gtest/gtest.h>

#include "../src/generator.cpp"

TEST(GeneratorTest, GeneratesRandomName)
{
    Generator generator;
    const std::vector<std::string> prefixes = {"a", "b"};
    const std::vector<std::string> suffixes = {"a", "b"};

    ASSERT_EQ(generator.generateName(prefixes, suffixes).empty(), false);
}

