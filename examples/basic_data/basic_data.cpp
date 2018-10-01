#include <tartarus/model/data_container.hpp>

#include <cstdint>
#include <vector>

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

    auto container = tartarus::model::data_container(file_id, data);

    auto container_data = container.raw_data();

    if (std::equal(container_data.begin(), container_data.end(), data.begin()))
    {
        std::cout << "Data in the container is correct" << std::endl;
    } else
    {
        std::cout << "Something is wrong, please file a bug report" << std::endl;
    }

    if (container.is_raw_data_container())
    {
        std::cout << "Success the container is a raw data container" << std::endl;
    } else
    {
        std::cout << "Something is wrong, please file a bug report" << std::endl;
    }

    if (!container.is_pivot_container() && !container.is_deviation_container())
    {
        std::cout << "Success the container is neither a pivot nor a deviation container" << std::endl;
    } else
    {
        std::cout << "Something is wrong, please file a bug report" << std::endl;
    }

    return 0;
}
