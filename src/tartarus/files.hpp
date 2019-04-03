#pragma once

#include <fstream>
#include <string>
namespace tartarus
{
namespace files
{
    /// Creates and empty file at path. Remember to include name in path
    /// @param path is a string that create gives the path to where the file should be created 
    void create_file(std::string path)
    {
	std::ofstream outfile(path);
	outfile.close();         
    }
}
}
