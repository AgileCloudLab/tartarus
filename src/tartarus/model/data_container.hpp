#pragma once

#include <cstdint>
#include <vector>


namespace tartarus
{
///
/// data_containter:
/// This class servers as a wrapper for data representation in
/// the IoT demonstration
///
class data_container
{

public:
    data_container(uint64_t data_id, std::vector<uint8_t> raw_data) :
        m_data_id(data_id), m_raw_data(raw_data) {}

    // TODO: Take a pair
    data_container(uint64_t data_id, std::vector<uint8_t> pivot,
                   std::vector<uint8_t> deviation) :
        m_data_id(data_id), m_pivot(pivot), m_deviation(deviation) {}

    void set_raw_data(std::vector<uint8_t> raw_data)
    {
        m_raw_data = raw_data;
    }

    std::vector<uint8_t> raw_data()
    {
        return m_raw_data;
    }

    void set_pivot(std::vector<uint8_t> pivot)
    {
        m_pivot = pivot;
    }

    std::vector<uint8_t> pivot()
    {
        return m_pivot;
    }

    void set_deviation(std::vector<uint8_t> deviation)
    {
        m_deviation = deviation;
    }

    std::vector<uint8_t> deviation()
    {
        return m_deviation;
    }
private:
    uint64_t m_data_id;
    std::vector<uint8_t> m_raw_data;
    std::vector<uint8_t> m_pivot; //TODO: BETTER NAME
    std::vector<uint8_t> m_deviation;
};
}
