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

    uint32_t pivot_size = 1024 * 4;
    std::vector<uint8_t> pivot(pivot_size);

    // Test that the vector is initialised as expected
    ASSERT_TRUE(pivot.size() == pivot_size);
    ASSERT_FALSE(pivot.empty());

    std::generate(pivot.begin(), pivot.end(), rand);

    ASSERT_FALSE(pivot.empty());

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
    
    std::vector<tartarus::model::coded_pair> empty;
    tartarus::model::coded_pair pair = {pivot, deviation};
    tartarus::model::coded_data coded = {file_id, coding_configuration, empty};
    coded.pairs.push_back(pair);
    
    // ASSERT that the coded is initialised correct
    ASSERT_TRUE(coded.file_id == file_id);
    ASSERT_TRUE(coded.pairs[0].pivot == pivot);
    ASSERT_TRUE(coded.pairs[0].deviation == deviation);
    

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
