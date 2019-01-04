#include <tartarus/helpers/vector.hpp>

#include <gtest/gtest.h>

#include <vector>
#include <cstdint>
#include <string>

std::vector<uint32_t> get_test_uint32_t_vector()
{
    return std::vector<uint32_t> {31, 27, 34, 81, 31};
}

std::vector<std::string> get_test_string_vector()
{
    return std::vector<std::string> {"hello", "command", "cloud", "next", "command", "vacation"};
}

TEST(test_coded_data, test_contains)
{
    // First we test for unsigned integers
    auto ui_vec = get_test_uint32_t_vector();

    auto res = tartarus::helpers::vector::contains<std::vector<uint32_t>, uint32_t>(ui_vec, 31);
    EXPECT_TRUE(res);
    
    res = tartarus::helpers::vector::contains<std::vector<uint32_t>, uint32_t>(ui_vec, 32);
    EXPECT_FALSE(res);
    
    res = tartarus::helpers::vector::contains<std::vector<uint32_t>, uint32_t>(ui_vec, 34);
    EXPECT_TRUE(res);

    // we then check for strings
    auto str_vec = get_test_string_vector();
    res = tartarus::helpers::vector::contains<std::vector<std::string>, std::string>(str_vec, "hello");
    EXPECT_TRUE(res);

    res = tartarus::helpers::vector::contains<std::vector<std::string>, std::string>(str_vec, "demo");
    EXPECT_FALSE(res);

    res = tartarus::helpers::vector::contains<std::vector<std::string>, std::string>(str_vec, "command");
    EXPECT_TRUE(res);    
        
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
