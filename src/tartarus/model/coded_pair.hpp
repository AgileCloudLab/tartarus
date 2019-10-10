#ifndef TARTARUS_MODEL_CODE_PAIR_H
#define TARTARUS_MODEL_CODE_PAIR_H

#include <cstdint>
#include <vector> 
namespace tartarus
{
namespace model
{

struct coded_pair {
    const std::vector<uint8_t> base;
    const std::vector<uint8_t> deviation;
};
}
}

#endif /* TARTARUS_MODEL_CODE_PAIR_H */
