#ifndef TARTARUS_FILES_H
#define TARTARUS_FILES_H

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

    /// Get the extension of the file at the given path
    /// @param File path for the file you want the extension of
    /// @return extension of a file
    std::string extension(const std::string& path)
    {
        return (((std::filesystem::path(path)).extension()).string()).substr(1);
    }
}
}

#endif /* TARTARUS_FILES_H */
