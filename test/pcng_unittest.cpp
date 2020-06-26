#include "generator_unittest.cpp"
#include "loader_unittest.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
