#include <nlohmann/json.hpp>

#include <string>
#include <fstream>

namespace tartarus
{
namespace reader
{
  nlohmann::json json_reader(std::string file_path)
  {
    nlohmann::json json_data;

    std::ifstream input(file_path);
    input >> json_data;
    return json_data;
  }
}
}
