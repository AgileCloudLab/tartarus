#include "tartarus/writers.hpp"
#include "tartarus/readers.hpp"

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>

#include <algorithm>
#include <ctime>

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

void measure_vector_writer_reader(size_t data_size)
{
    std::string path = "vector_test.bin";
    // int data_size = 1000000000; //1000 MB
//    int data_size = 32000;
    std::vector<uint8_t> data(data_size);

    srand(static_cast<uint32_t>(time(0)));
    std::generate(data.begin(), data.end(), rand);

    uint32_t iterations = 10000;
    
    // Write benchmark
    auto t1 = std::chrono::high_resolution_clock::now();    
    for (uint32_t i = 0; i < iterations; ++i)
    {

        tartarus::writers::vector_disk_writer(path, data);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    std::cout<<"Vector writer throughput for " << data_size <<
	" bytes: " << (data_size * iterations) / double(res.count()) << "MB/s" << std::endl;;

    //Read benchmark
    t1 = std::chrono::high_resolution_clock::now();    
    for (uint32_t i = 0; i < iterations; ++i)
    {    

        std::vector<uint8_t> result = tartarus::readers::vector_disk_reader(path);
    }
    t2 = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    std::cout<<"Vector reader throughput for " << data_size <<
	" bytes: " << (data_size * iterations) / double(res.count()) << "MB/s" << std::endl;

    //Delete file
    std::remove(path.c_str());
}


void measure_json_writer_reader()
{
    int data_size = 0, data_size_bjson = 0, data_size_ubjson = 0, data_size_cbor = 0, data_size_msgpack = 0;	
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

    //JSON reader benchmark
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::json_reader(reader_paths[i % num_files]);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto res_read_json = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //JSON writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::json_writer(writer_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write_json = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //BJSON writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::bjson_writer(writer_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write_bjson = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //BJSON reader benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::bjson_reader(writer_paths[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_read_bjson = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //Measure file sizes and clean up
    for(int i=0; i < num_files; i++)
    {
	data_size_bjson += filesize(writer_paths[i].c_str());
	std::remove(writer_paths[i].c_str());
    }
    
    
    //UBJSON writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::ubjson_writer(writer_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write_ubjson = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //UBJSON reader benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::ubjson_reader(writer_paths[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_read_ubjson = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //Measure file sizes and clean up
    for(int i=0; i < num_files; i++)
    {
	data_size_ubjson += filesize(writer_paths[i].c_str());
	std::remove(writer_paths[i].c_str());
    }
    
    
    //CBOR writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::cbor_writer(writer_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write_cbor = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //CBOR reader benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::cbor_reader(writer_paths[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_read_cbor = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //Measure file sizes and clean up
    for(int i=0; i < num_files; i++)
    {
	data_size_cbor += filesize(writer_paths[i].c_str());
	std::remove(writer_paths[i].c_str());
    }
    

    //MSGPACK writer benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	tartarus::writers::msgpack_writer(writer_paths[i % num_files], objects[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_write_msgpack = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //MSGPACK reader benchmark
    t1 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations/num_files; i++){
	objects[i % num_files] = tartarus::readers::msgpack_reader(writer_paths[i % num_files]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto res_read_msgpack = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

    //Measure file sizes and clean up
    for(int i=0; i < num_files; i++)
    {
	data_size_msgpack += filesize(writer_paths[i].c_str());
	std::remove(writer_paths[i].c_str());
    }

    int fact = iterations/num_files; //The number of iterations each file is read/written
    
    std::cout<<"JSON results based on " << iterations/num_files << " iterations over "
	     << num_files << " files of average size for: " << data_size / double(num_files)
	     << " bytes, for a total of " << fact * data_size << " bytes." << std::endl;
    std::cout<<"Throughput calculated based on file sizes on disk, which varies for each format." << std::endl;
    
    std::cout<<"JSON writer throughput " << data_size * fact / double(res_write_json.count()) << "MB/s" << std::endl;
    std::cout<<"JSON reader throughput " << data_size * fact/ double(res_read_json.count()) << "MB/s" << std::endl;
    std::cout<<"BSON writer throughput " << data_size_bjson * fact / double(res_write_bjson.count()) << "MB/s" << std::endl;
    std::cout<<"BSON reader throughput " << data_size_bjson * fact / double(res_read_bjson.count()) << "MB/s" << std::endl;
    std::cout<<"UBJSON writer throughput " << data_size_ubjson * fact / double(res_write_ubjson.count()) << "MB/s" << std::endl;
    std::cout<<"UBJSON reader throughput " << data_size_ubjson * fact / double(res_read_ubjson.count()) << "MB/s" << std::endl;
    std::cout<<"CBOR writer throughput " << data_size_cbor * fact / double(res_write_cbor.count()) << "MB/s" << std::endl;
    std::cout<<"CBOR reader throughput " << data_size_cbor * fact / double(res_read_cbor.count()) << "MB/s" << std::endl;
    std::cout<<"MSGPACK writer throughput " << data_size_msgpack * fact / double(res_write_msgpack.count()) << "MB/s" << std::endl;
    std::cout<<"MSGPACK reader throughput " << data_size_msgpack * fact / double(res_read_msgpack.count()) << "MB/s" << std::endl;
}

int main(void)
{
    std::cout << "Note: benchmark must be run from project's root directory!" <<std::endl;
    measure_vector_writer_reader(4096);
    measure_vector_writer_reader(8192);
    measure_vector_writer_reader(16384);
    measure_vector_writer_reader(32768);
    measure_vector_writer_reader(65536);
    measure_vector_writer_reader(131072);        
    

    measure_json_writer_reader();
    return 0;
}
