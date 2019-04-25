#include <tartarus/files.hpp>

#include <gtest/gtest.h>

#include <string>
/// Test that the encoders' and decoders' initialize() function can be used
/// to reset their state
TEST(test_file, test_extension)
{
    std::string file = "media/aulogo_uk_var2_blue.png";
    EXPECT_EQ("png", tartarus::files::extension(file));
}

TEST(test_file, test_file_size)
{
    std::string file = "media/aulogo_uk_var2_blue.png";
    assert(18920 == tartarus::files::file_size(file));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
