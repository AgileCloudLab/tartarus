#include <cstdint>
namespace tartarus
{
namespace helpers
{
namespace vector
{
    ///
    /// a function for evaluiating if the vector contains a value
    ///   returns true if it does false if does not
    ///   NOTE: ATM it assumes that the type of Val has a == implementation
    ///
    template<typename Vector, typename Value>
    bool contains(Vector vec, Value val)
    {
	for (auto vval : vec)
	{
	    if (vval == val)
	    {
		return true;
	    }
	}
	return false;
    }

    ///
    /// Returns the index from vec for the first occurence of val
    /// returns -1 if none exists
    ///
    template<typename Vector, typename Value>
    int index_of_value(Vector vec, Value val)
    {
	for (int i = 0; i < vec.size(); ++i)
	{
	    if (vec.at(i) == val)
	    {
		return i;
	    }
	}
	return -1;
    }

    template<typename Vector, typename Value>
    uint32_t count(Vector vec, Value val)
    {
	uint32_t c = 0;

	for(auto vval : vec)
	{
	    if (vval == val)
	    {
		++c;
	    }
	}
	return c;
    }
}
}
}
