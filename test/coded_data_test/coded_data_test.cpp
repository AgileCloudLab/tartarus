#include <tartarus/model/coded_data.hpp>

#include <nlohmann/json.hpp>

#include <gtest/gtest.h>

#include <ctime>

#include <vector>
#include <cstdint>

#include <algorithm>

/// Test that the encoders' and decoders' initialize() function can be used
/// to reset their state
TEST(test_coded_data, test_initialize)
{
    srand(static_cast<uint32_t>(time(0)));

    uint64_t file_id = 0;

    uint32_t base_size = 1024 * 4;
    std::vector<uint8_t> base(base_size);

    // Test that the vector is initialised as expected
    ASSERT_TRUE(base.size() == base_size);
    ASSERT_FALSE(base.empty());

    std::generate(base.begin(), base.end(), rand);

    ASSERT_FALSE(base.empty());

    uint32_t deviation_size = 1024 * 4;
    std::vector<uint8_t> deviation(deviation_size);

    // Test that the vector is initialised as expected
    ASSERT_TRUE(deviation.size() == deviation_size);
    ASSERT_FALSE(deviation.empty());

    std::generate(deviation.begin(), deviation.end(), rand);

    ASSERT_FALSE(deviation.empty());

    nlohmann::json coding_configuration;
    coding_configuration["generation_size"] = 4;
    coding_configuration["symbol_size"] = 1024;

    std::string file_name = "test.txt";
    std::string MIME_TYPE = "png";
    uint32_t file_size = base.size() * deviation.size();
    
    std::vector<tartarus::model::coded_pair> empty;
    tartarus::model::coded_pair pair = {base, deviation};
    tartarus::model::coded_data coded = {file_id, file_size, file_name, MIME_TYPE, coding_configuration, empty};

    coded.pairs.push_back(pair);
    
    // ASSERT that the coded is initialised correct
    EXPECT_TRUE(coded.file_id == file_id);
    EXPECT_TRUE(coded.pairs[0].base == base);
    EXPECT_TRUE(coded.pairs[0].deviation == deviation);
    EXPECT_TRUE(coded.coding_configuration["generation_size"] == 4);
    EXPECT_TRUE(coded.coding_configuration["symbol_size"] == 1024);
    EXPECT_EQ(coded.file_size, file_size);
    EXPECT_EQ(coded.file_name, file_name);
    EXPECT_EQ(coded.mime_type, MIME_TYPE);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
