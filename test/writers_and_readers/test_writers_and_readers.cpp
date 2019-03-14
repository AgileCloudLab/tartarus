#include <tartarus/readers.hpp>
#include <tartarus/writers.hpp>

#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include <string>
#include <ctime>
#include <algorithm>
#include <cstdint>

TEST(test_read_json, read_json)
{
  std::string file_path = "test/files/json/test.json";
  auto json_data = tartarus::readers::json_reader(file_path);

  std::string info_string = json_data.value("info", "failure");

  int version = json_data.value("version", 0);
  
  EXPECT_EQ(info_string, "Test of json reader");
  EXPECT_EQ(version, 1);
 
}


TEST(test_disk_vector_reader_writer, reader_and_writer)
{
    srand(static_cast<uint32_t>(time(0)));
    std::vector<uint8_t> data_out(1024);
    std::generate(data_out.begin(), data_out.end(), rand);

    std::string path = "./TEST_DATA";
    auto result = tartarus::writers::vector_disk_writer(path, data_out);
    EXPECT_TRUE(result);

    auto data_in = tartarus::readers::vector_disk_reader(path);
    EXPECT_EQ(data_out, data_in);    
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

