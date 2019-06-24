# tartarus
Tartarus is a utility library containg common models and other components for the IoT demo


# NEWS

In `NEWS.md` you can see what have been changed from version to version

# JSON

For using the JSON part of tartarus you need to install nlohmanns' json library see:

https://github.com/nlohmann/json

# Configuration 

The configuration of Minerva is done in JSON and an example of such configuration can be seen below

```json
{
    "base_out_path":"/home/tools/.minervafs/.basis/",
    "base_register_path":"/home/tools/.minervafs/.registry/",
    "max_registry_size":8589934592,
    "out_path":"/home/tools/.minervafs/",
    "register_path":"/home/tools/.minervafs/.identifiers"
    "file_format": 0
}

```

| Configuration        | Description                                                                                             |
| =============        | ===========                                                                                             |
| `base_out_path`      | The path for where bases will be stored                                                                 |
| `base_register_path` | The directory to where we will write the register it self to disk                                       |
| `register_path`      | This is the path for the file in which the identifiers are stored                                       |
| `out_path`           | This is where the place holder files are written                                                        |
| `file_format`        | A Enum representation for the file format used to write the place holder files, see mapping table below |
| `max_registry_size`  | Number of bytes the register is allowed to take up in memory in bytes                                   |
|                      |                                                                                                         |


## File Format table 

In `minerva.hpp` you will find the enum `file_format` which represent the different formats with which the place holder files can be written to disk. 

```c++
enum file_format
{
    JSON,
    BSON,
    UBJSON,
    CBOR,
    MSGPACK
};
```

The mapping will then be like this: 


| Format     | Integer representation |
| =======    | ====================== |
| JSON       | 0                      |
| BSON/BJSON | 1                      |
| UBJSON     | 2                      |
| CBOR       | 3                      |
| MSGPACK    | 4                      |


