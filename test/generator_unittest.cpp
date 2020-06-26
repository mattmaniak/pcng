#include <gtest/gtest.h>

#include "../src/generator.cpp"

TEST(generateMessageTest, Text) {
    ASSERT_EQ(generator::generateMessage(), "Hello!");
}

