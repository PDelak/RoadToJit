#include <windows.h>
#include <vector>
#include <iostream>

typedef unsigned char byte;
typedef int(*pfunc)(void);

void execute()
{
	std::vector<byte> code_vector = {
		0xB8, 0x0C, 0x00, 0x00, 0x00, 0xC3
	};
	
	byte* buf = (byte*)VirtualAllocEx(GetCurrentProcess(), 0, code_vector.size(), MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	memcpy(buf, &code_vector[0], code_vector.size());
	pfunc func = (pfunc)buf;
	std::cout << func() << std::endl;

	VirtualFreeEx(GetCurrentProcess(), buf, code_vector.size(), MEM_RELEASE);
}

int main()
{
	execute();
	return 0;
}
