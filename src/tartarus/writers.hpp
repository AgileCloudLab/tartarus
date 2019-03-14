#pragma once
#include <nlohmann/json.hpp>

#include <string>
#include <cstdint>
#include <vector>

#include <fstream>

namespace tartarus
{
namespace writers
{
    /// The function writes a piece of json to the file path provided
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object 
    inline void json_writer(std::string path, nlohmann::json data)
    {
        std::ofstream json_out(path);
        json_out << data;
        json_out.close();
    }

    /// The function writes a vector of uint8_t to the destination provided by path. Note that the
    /// path must contain the file name and if needed file extension.
    /// @param path is std::string representation of the path to the destination file where the data will be written
    /// @param data is a std::vector<uint8_t> which keeps the data which will be written to disk
    /// @return if the function succeed it returns true otherwise false    
    inline bool vector_disk_writer(const std::string path, const std::vector<uint8_t>& data)
    {

        const uint8_t* cdata = data.data();

        FILE* fp; // File pointer 
        if((fp=fopen(path.c_str(), "wb"))==NULL) {
            printf("Cannot open file.\n");
        }

        if (fwrite(cdata, sizeof(uint8_t), data.size(), fp) != data.size())
        {
            return false;
        }
        fclose(fp);

        return true;
    }
}
}
