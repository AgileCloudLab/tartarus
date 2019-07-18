#include "writers.hpp"

#include <fstream>

namespace tartarus
{
namespace writers
{

    bool vector_disk_writer(const std::string path, const std::vector<uint8_t>& data)
    {

        FILE* fp; // File pointer 
        if((fp=fopen(path.c_str(), "wb"))==NULL)
        {
            perror(path.c_str());
            return false;
        }

        bool result = true;
        if (fwrite(data.data(), sizeof(uint8_t), data.size(), fp) != data.size())
        {
            result = false;
        }
        fclose(fp);

        return result;
    }
    
    void json_writer(std::string path, nlohmann::json data)
    {
        std::ofstream json_out(path);
        json_out << data;
        json_out.close();
    }

    void bjson_writer(std::string path, nlohmann::json data)
    {
        std::vector<uint8_t> bdata = nlohmann::json::to_bson(data);
        vector_disk_writer(path, bdata);
    }    

    void ubjson_writer(std::string path, nlohmann::json data)
    {
        std::vector<uint8_t> ubjson_data = nlohmann::json::to_ubjson(data);
        vector_disk_writer(path, ubjson_data);
    }        

    void cbor_writer(std::string path, nlohmann::json data)
    {
        std::vector<uint8_t> cbor_data = nlohmann::json::to_cbor(data);
        vector_disk_writer(path, cbor_data);
    }

    void msgpack_writer(std::string path, nlohmann::json data)
    {
        std::vector<uint8_t> msgpack_data = nlohmann::json::to_msgpack(data);
        vector_disk_writer(path, msgpack_data);
    }

    

}
}
