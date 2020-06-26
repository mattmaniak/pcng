#include <gtest/gtest.h>

#include "../src/generator.cpp"

TEST(GeneratorTest, Text)
{
    Generator generator;
    std::vector<std::string> _;

    ASSERT_EQ(generator.generateName(_, _), "");
}

