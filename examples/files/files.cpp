#include <tartarus/files.hpp>

#include <string>
#include <cassert>
int main(void)
{
    std::string file = "media/aulogo_uk_var2_blue.png";
    assert("png" == tartarus::files::extension(file));
    assert(18920 == tartarus::files::file_size(file));
}
