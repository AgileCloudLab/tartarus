#pragma once

#include <fstream>
#include <string>
#include <filesystem>

namespace tartarus
{
namespace files
{
    /// Creates and empty file at path. Remember to include name in path
    /// @param path is a string that create gives the path to where the file should be created 
    void create_file(const std::string& path)
    {
	std::ofstream outfile(path);
	outfile.close();         
    }

    /// Reads the size of a file in bytes
    /// @param path is a string that create gives the path to where the file should be created 
    size_t file_size(const std::string& path)
    {
        std::ifstream in(path, std::ifstream::ate | std::ifstream::binary);
        return (size_t)in.tellg(); 
    }

    std::string extension(const std::string& path)
    {
        return (((std::filesystem::path(path)).extension()).string()).substr(1);
    }
}
}
