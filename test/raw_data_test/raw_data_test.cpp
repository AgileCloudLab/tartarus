#include <tartarus/model/raw_data.hpp>

#include <gtest/gtest.h>

#include <vector>
#include <cstdint>

#include <algorithm>
#include <ctime>

#include <cassert>

#include <iostream>

TEST(test_coded_data, test_initialize)
{
    srand(static_cast<uint32_t>(time(0)));

    uint64_t file_id = 0;

    uint32_t data_size = 1024 * 128;
    std::vector<uint8_t> data(data_size);
    ASSERT_FALSE(data.empty());
    // Randomly fill data with data
    std::generate(data.begin(), data.end(), rand);
    ASSERT_FALSE(data.empty());

    tartarus::model::raw_data raw = {file_id, data};

    ASSERT_TRUE(raw.file_id == file_id);
    ASSERT_TRUE(raw.data == data);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
