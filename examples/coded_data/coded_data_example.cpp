#include <tartarus/model/coded_data.hpp>

#include <nlohmann/json.hpp>

#include <vector>
#include <cstdint>

#include <algorithm>
#include <ctime>

#include <cassert>

#include <iostream>

int main(void)
{
    srand(static_cast<uint32_t>(time(0)));

    uint64_t file_id = 0;

    // A 4KB base
    uint32_t base_size = 1024 * 4;
    std::vector<uint8_t> base(base_size);
    // Randomly generate the deviation
    std::generate(base.begin(), base.end(), rand);

    // A 4KB deviation
    uint32_t deviation_size = 1024 * 4;
    std::vector<uint8_t> deviation(deviation_size);
    std::generate(deviation.begin(), deviation.end(), rand);

    nlohmann::json coding_configuration;
    coding_configuration["generation_size"] = 4;
    coding_configuration["symbol_size"] = 1024;
    
        
    std::vector<tartarus::model::coded_pair> empty;
    tartarus::model::coded_pair pair = {base, deviation};
    tartarus::model::coded_data coded = {file_id, 1337, "test.txt", "jpg", coding_configuration, empty};
    
    coded.pairs.push_back(pair);

    assert(coded.file_id == file_id);
    assert(coded.pairs[0].base == base);
    assert(coded.pairs[0].deviation == deviation);
    assert(coded.file_size == 1337);
    assert(coded.file_name == "test.txt");
    assert(coded.mime_type == "jpg");
        
    std::cout << "SUCCESS WE REACH THE END OF THE PROGRAM" << std::endl;
}
