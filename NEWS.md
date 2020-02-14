# NEWS 

# 7.2.1

1. Updated the `wscript` file to the appropriate usage of `-isysroot` and removed the usage of `-lc++fs`on macOS. The later was done as it no longer works with clang on macOS due to clang fully supporting `<filesystem>` now on macOS.
2. Removed the usage of `LINK_FLAGS` and `CXX_FLAGS` lists and moved to using `ctx.env.append_value('LINKFLAGS', VALUES)` and `ctx.env.append_value('CXXFLAGS', VALUES)` as it is the waf way


## 4.0.0

We have moved all reader functions into the same file called `reader.hpp` and create a `writer.hpp` file as well. 

We have removed the `reader/json_reader.hpp` file as well

## 2.0.0

* We have added file meta data to the `raw_data` and `coded_data` structures. So file name, file size, and MIME type can be registered. 
* We have renamed `pivot` to `base` in `coded_pairs` 
