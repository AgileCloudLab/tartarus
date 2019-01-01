#include <tartarus/reader/json_reader.hpp>

#include <nlohmann/json.hpp>


#include <gtest/gtest.h>

#include <string>

/// Test that the encoders' and decoders' initialize() function can be used
/// to reset their state
TEST(test_read_json, read_json)
{
  std::string file_path = "test/files/json/test.json";
  auto json_data = tartarus::reader::json_reader(file_path);

  std::string info_string = json_data.value("info", "failure");

  int version = json_data.value("version", 0);
  
  EXPECT_EQ(info_string, "Test of json reader");
  EXPECT_EQ(version, 1);
 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
