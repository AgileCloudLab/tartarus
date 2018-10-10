#include <tartarus/model/coded_data.hpp>

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


    tartarus::model::coded_data coded;

    coded.file_id = file_id;
    coded.pivot = pivot;
    coded.deviation = deviation;


    // ASSERT that the coded is initialised correct
    ASSERT_TRUE(coded.file_id == file_id);
    ASSERT_TRUE(coded.pivot == pivot);
    ASSERT_TRUE(coded.deviation == deviation);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
