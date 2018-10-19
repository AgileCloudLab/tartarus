#include <tartarus/model/coded_data.hpp>

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

    // A 4KB pivot
    uint32_t pivot_size = 1024 * 4;
    std::vector<uint8_t> pivot(pivot_size);
    // Randomly generate the deviation
    std::generate(pivot.begin(), pivot.end(), rand);

    // A 4KB deviation
    uint32_t deviation_size = 1024 * 4;
    std::vector<uint8_t> deviation(deviation_size);
    std::generate(deviation.begin(), deviation.end(), rand);

    std::vector<tartarus::model::coded_pair> empty;
    tartarus::model::coded_pair pair = {pivot, deviation};
    tartarus::model::coded_data coded = {file_id, empty};
    coded.pairs.push_back(pair);

    assert(coded.file_id == file_id);
    assert(coded.pairs[0].pivot == pivot);
    assert(coded.pairs[0].deviation == deviation);

    std::cout << "SUCCESS WE REACH THE END OF THE PROGRAM" << std::endl;
}
