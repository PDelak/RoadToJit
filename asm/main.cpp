#include <iostream>
#include <vector>

typedef unsigned char byte;

extern "C" int foo();
extern "C" int testParam(int);
extern "C" int testParams(int, int);
extern "C" int callFunction(void* addr);
extern "C" int passStruct(void* addr);


std::vector<byte> intToBytes(int value)
{
	std::vector<byte> result;
	result.push_back(value >> 24);
	result.push_back(value >> 16);
	result.push_back(value >> 8);
	result.push_back(value);
	return result;
}

std::vector<byte> get_address(void* addr)
{
	std::vector<byte> result;
	auto addrBytes = intToBytes(reinterpret_cast<int>(addr));
	std::copy(addrBytes.rbegin(), addrBytes.rend(), std::back_inserter(result));
	return result;
}

void test()
{
	std::cout << "test" << std::endl;
}

struct s
{
	int a;
	int b;
	s(int p1, int p2): a(p1), b(p2) {}
};


int main()
{
	std::cout << foo() << std::endl;
	std::cout << testParam(55) << std::endl;
	std::cout << testParams(12,24) << std::endl;
	std::cout << callFunction(test) << std::endl;
	s obj(1,2);
	passStruct(&obj);
	std::cout << "s.a = " << obj.a << std::endl;
	std::cout << "s.b = " << obj.b << std::endl;
	return 0;
}
