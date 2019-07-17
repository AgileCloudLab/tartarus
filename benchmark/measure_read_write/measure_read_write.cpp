#include "tartarus/writers.hpp"
#include "tartarus/readers.hpp"

#include <string>
#include <vector>
#include <chrono>
#include <iostream>


void measure_vector_writer_reader()
{
    std::string path = "vector_test.bin";
    int data_size = 1000000000; //1000 MB
    std::vector<uint8_t> data(data_size);

    srand(static_cast<uint32_t>(time(0)));

    // Write benchmark
    auto t1 = std::chrono::high_resolution_clock::now();
    tartarus::writers::vector_disk_writer(path, data);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    std::cout<<"Vector writer throughput for " << data_size <<
	" bytes: " << data_size / double(res.count()) << "MB/s" << std::endl;;

    //Read benchmark
    t1 = std::chrono::high_resolution_clock::now();
    std::vector<uint8_t> result = tartarus::readers::vector_disk_reader(path);
    t2 = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    std::cout<<"Vector reader throughput for " << data_size <<
	" bytes: " << data_size / double(res.count()) << "MB/s" << std::endl;

    //Delete file
    std::remove(path.c_str());
    
}

int main(void)
{
    measure_vector_writer_reader();
    return 0;
}
