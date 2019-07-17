#include "tartarus/writers.hpp"
#include "tartarus/readers.hpp"

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

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


void measure_json_writer_reader()
{
    int data_size = 0;
    int iterations = 100000; //iterations must be a multiple of num_files
    int num_files = 10;
    
    //Put together the paths and measure total bytes
    std::vector<std::string> reader_paths;
    std::vector<std::string> writer_paths;
    std::vector<nlohmann::json> objects(num_files);
    for(int i=0; i < num_files; i++)
    {
	std::string path = "benchmark/measure_read_write/json_test_data/"
	    + std::to_string(i) + ".json";
	reader_paths.push_back(path);
	data_size += filesize(path.c_str());
	
	path = "benchmark/measure_read_write/json_test_data/"
	    + std::to_string(i) + ".json.out";
	writer_paths.push_back(path);
    }

    data_size *= (iterations/num_files);
    
    //Reader benchmark
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::json_reader(reader_paths[i % num_files]);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto res_read = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    
    //Writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::json_writer(reader_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    std::cout<<"JSON results based on " << iterations/num_files << " iterations over "
	     << num_files << " files of average size: " << data_size / iterations
	     << " bytes, for a total of " << data_size << " bytes." << std::endl;
    
    std::cout<<"JSON writer throughput " << data_size / double(res_write.count()) << "MB/s" << std::endl;

    std::cout<<"JSON reader throughput " << data_size / double(res_read.count()) << "MB/s" << std::endl;

    //Delete files
    for(int i=0; i < num_files; i++)
    {
	std::remove(writer_paths[i].c_str());
    }
}

int main(void)
{
    std::cout << "Note: benchmark must be run from project's root directory!" <<std::endl;
    measure_vector_writer_reader();
    measure_json_writer_reader();
    return 0;
}
