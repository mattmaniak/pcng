#include <gtest/gtest.h>

#include "../src/generator.cpp"

TEST(GeneratorTest, GeneratesRandomName)
{
    Generator generator;
    const std::vector<std::string> _;

    ASSERT_EQ(generator.generateName(_, _), "");
}

