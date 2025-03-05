#ifndef TYPE_H
#define TYPE_H

#include <ostream>
#include <string>
#include <vector>

#define ResponseBackTrue (nano_unsigned_int16)1
#define ResponseBackFalse (nano_unsigned_int16)0

typedef std::string nano_string;
typedef std::int32_t nano_int;
typedef std::uint16_t nano_unsigned_int16;
typedef std::uint32_t nano_unsigned_int32;
typedef float nano_float32;
typedef double nano_float64;
typedef std::vector<nano_string> nano_1D_array_string;
typedef std::vector<nano_int> nano_1D_array_int;
typedef std::vector<std::uint8_t> nano_1D_array_unsigned_int8;
typedef std::vector<nano_unsigned_int32> nano_1D_array_unsigned_int32;
typedef std::vector<nano_float32> nano_1D_array_float32;
typedef std::vector<nano_float64> nano_1D_array_float64;
typedef std::vector<std::vector<nano_float32>> nano_2D_array_float32;

#endif // TYPE_H
