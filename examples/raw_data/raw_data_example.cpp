#include <tartarus/model/raw_data.hpp>

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

    // Data size in bytes
    // 128 KB
    uint32_t data_size = 1024 * 128;

    // Initialise a vector with space for
    // #entries = 128KB
    std::vector<uint8_t> data(data_size);

    // Randomly fill data with data
    std::generate(data.begin(), data.end(), rand);

    tartarus::model::raw_data raw = {file_id, data};

    assert(raw.file_id == file_id);
    assert(raw.data == data);

    std::cout << "SUCCESS WE REACH THE END OF THE PROGRAM" << std::endl;
}
