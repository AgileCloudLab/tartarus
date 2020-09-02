#include "writers.hpp"

namespace tartarus
{
namespace writers
{

    FILE* vector_disk_writer(const std::string& path, const std::vector<uint8_t>& data)
    {

        FILE* fp; // File pointer 
        if((fp=fopen(path.c_str(), "wb"))==NULL)
        {
            perror(path.c_str());
            return fp;
        }

        if (fwrite(data.data(), sizeof(uint8_t), data.size(), fp) != data.size())
        {
            return fp;
        }
        fclose(fp);

        return fp;
    }
    
    void json_writer(const std::string& path, const nlohmann::json& data)
    {
        std::ofstream json_out(path);
        json_out << data;
        json_out.close();
    }

    void bjson_writer(const std::string& path, const nlohmann::json& data)
    {
        std::vector<uint8_t> bdata = nlohmann::json::to_bson(data);
        vector_disk_writer(path, bdata);
    }    

    void ubjson_writer(const std::string& path, const nlohmann::json& data)
    {
        std::vector<uint8_t> ubjson_data = nlohmann::json::to_ubjson(data);
        vector_disk_writer(path, ubjson_data);
    }        

    void cbor_writer(const std::string& path, const nlohmann::json& data)
    {
        std::vector<uint8_t> cbor_data = nlohmann::json::to_cbor(data);
        vector_disk_writer(path, cbor_data);
    }

    void msgpack_writer(const std::string& path, const nlohmann::json& data)
    {
        std::vector<uint8_t> msgpack_data = nlohmann::json::to_msgpack(data);
        vector_disk_writer(path, msgpack_data);
    }

    

}
}
