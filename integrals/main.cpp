#include <iostream>
#include <cstdint>


int main() {

	int max_int = 2147483647;
	int min_int =  -2147483647;

	//unsigned int max_uint = 4294967295;
	unsigned int min_uint = 0;
	//unsigned int max_uint = -1;
	unsigned int max_uint = 0xFFFFFFFF;

	short max_short = 32767;
	short min_short = 32768;
	//unsigned max_ushort = 65535;
	//unsigned max_ushort = -1;
	unsigned short max_ushort = 0xFFFF;

	long max_long = 2147483647;
	long min_long = -2147483648;
	unsigned max_ulong = -1;

	long long max_ll = 9223372036854775807;
	long long min_ll = -9223372036854775808;
	unsigned long long max_ull = 18446744073709551615;

	std::int32_t i = 0; // always 32 bits
	std::uint32_t ui = 0;
	std::int16_t i16 = 0; // always 16 bits
	std::int64_t i64 = 0; // always 64 bits


	std::cout << "sizeof int: " << sizeof(int) << std::endl;
	std::cout << "max uint: " << max_uint << std::endl;

	std::cout << std::endl;

	std::cout << "sizeof short: " << sizeof(short) << std::endl;
	std::cout << "max ushort: " << max_ushort << std::endl;

	std::cout << std::endl;

	std::cout << "sizeof long: " << sizeof(long) << std::endl;
	std::cout << "max ulong: " << max_ulong << std::endl;






	return 0;
}