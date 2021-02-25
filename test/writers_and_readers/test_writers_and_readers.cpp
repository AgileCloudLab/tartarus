#include <tartarus/readers.hpp>
#include <tartarus/writers.hpp>

#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include <string>
#include <ctime>
#include <algorithm>
#include <cstdint>


TEST(test_vector_write_reader, writer_and_reader)
{

    std::vector<uint8_t> data(4096);
    std::generate(std::begin(data), std::end(data), rand);

    std::string path = "test_out/out.bin";

    EXPECT_TRUE(tartarus::writers::vector_disk_writer(path, data));

    auto read_data = tartarus::readers::vector_disk_reader(path);
    EXPECT_EQ(data, read_data);     
}

TEST(test_bjson_reader_writer, reader_and_writer)
{
    nlohmann::json obj;
    obj["test"] = "test";
    std::string path = "test_out/out.bjson";
    tartarus::writers::bjson_writer(path, obj);
    auto inobj = tartarus::readers::bjson_reader(path);
    EXPECT_EQ(obj["test"].get<std::string>(), inobj["test"].get<std::string>());
}

TEST(test_ubjson_reader_writer, reader_and_writer)
{
    nlohmann::json obj;
    obj["test"] = "test";
    std::string path = "test_out/out.ubjson";
    tartarus::writers::ubjson_writer(path, obj);
    auto inobj = tartarus::readers::ubjson_reader(path);
    EXPECT_EQ(obj["test"].get<std::string>(), inobj["test"].get<std::string>());
}

TEST(test_cbor_reader_writer, reader_and_writer)
{
    nlohmann::json obj;
    obj["test"] = "test";
    std::string path = "test_out/out.cbor";
    tartarus::writers::cbor_writer(path, obj);
    auto inobj = tartarus::readers::cbor_reader(path);
    EXPECT_EQ(obj["test"].get<std::string>(), inobj["test"].get<std::string>());
}

TEST(test_msgpack_reader_writer, reader_and_writer)
{
    nlohmann::json obj;
    obj["test"] = "test";
    std::string path = "test_out/out.ubjson";
    tartarus::writers::msgpack_writer(path, obj);
    auto inobj = tartarus::readers::msgpack_reader(path);
    EXPECT_EQ(obj["test"].get<std::string>(), inobj["test"].get<std::string>());
}

int main(int argc, char **argv) {
    srand(static_cast<uint32_t>(time(0)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

