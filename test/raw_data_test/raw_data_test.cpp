#include <tartarus/model/raw_data.hpp>

#include <gtest/gtest.h>

#include <vector>
#include <cstdint>

#include <algorithm>
#include <ctime>

#include <cassert>

#include <iostream>


TEST(test_raw_data, test_initialize)
{
    srand(static_cast<uint32_t>(time(0)));

    uint64_t file_id = 0;

    uint32_t data_size = 1024 * 128;
    std::vector<uint8_t> data(data_size);

    std::string file_name = "test.txt";
    std::string MIME_TYPE = "image";

    ASSERT_TRUE(data.size() == data_size);
    // Randomly fill data with data
    std::generate(data.begin(), data.end(), rand);
    ASSERT_FALSE(data.empty());

    tartarus::model::raw_data raw = {file_id, data_size, file_name, MIME_TYPE, data};

    EXPECT_EQ(raw.file_id, file_id);
    EXPECT_EQ(raw.data, data);
    EXPECT_EQ(raw.file_name, file_name);
    EXPECT_EQ(raw.file_size, data_size);
    EXPECT_EQ(raw.mime_type, MIME_TYPE);        
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
