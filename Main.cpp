/*
工程属性：数据执行保护DEP关掉
shellcode：

*/

#include <Windows.h>
#include <iostream>

char shellCode[] = "\x60\x83\xEC\x30\x3E\xC6\x44\x24\xFF\x00\x83\xEC\x01\x68\x2E\x64\x6C\x6C\x68\x65\x6C\x33\x32\x68\x6B\x65\x72\x6E\x3E\xC6\x44\x24\xFF\x00\x83\xEC\x01\x68\x6F\x75\x00\x00\x68\x76\x65\x20\x59\x68\x49\x20\x4C\x6F\x68\x6A\x0A\x38\x1E\x3E\xC6\x44\x24\xFF\x00\x83\xEC\x01\x66\xB8\x6C\x6C\x3E\x66\x89\x44\x24\xFE\x83\xEC\x02\x68\x33\x32\x2E\x64\x68\x75\x73\x65\x72\x68\x63\x89\xD1\x4F\x68\x32\x74\x91\x0C\x8B\xCC\x51\xE8\x98\x00\x00\x00\x61\xC3\x55\x8B\xEC\x83\xEC\x0C\x56\x64\x8B\x35\x30\x00\x00\x00\x8B\x76\x0C\x8B\x76\x1C\x8B\x36\x8B\x76\x08\x8B\xC6\x5E\x8B\xE5\x5D\xC3\x55\x8B\xEC\x83\xEC\x10\x56\x57\x52\x53\x51\x8B\x55\x08\x8B\x72\x3C\x8D\x34\x32\x8B\x76\x78\x8D\x34\x32\x8B\x7E\x1C\x8D\x3C\x3A\x89\x7D\xFC\x8B\x7E\x20\x8D\x3C\x3A\x89\x7D\xF8\x8B\x7E\x24\x8D\x3C\x3A\x89\x7D\xF4\x33\xDB\xFC\xEB\x01\x43\x8B\x75\xF8\x8B\x34\x9E\x8B\x55\x08\x8D\x34\x32\x8B\x7D\x0C\x8B\x3F\x56\xE8\x8F\x00\x00\x00\x3B\xF8\x75\xE4\x8B\x75\xF4\x33\xFF\x66\x8B\x3C\x5E\x8B\x75\xFC\x8B\x34\xBE\x8B\x55\x08\x8D\x04\x32\x59\x5B\x5A\x5F\x5E\x8B\xE5\x5D\xC2\x0C\x00\x55\x8B\xEC\x83\xEC\x20\x56\x57\x52\x53\x51\xE8\x5A\xFF\xFF\xFF\x89\x45\xFC\x8D\x4D\x0C\x51\x50\xE8\x6D\xFF\xFF\xFF\x89\x45\xF8\x8D\x4D\x30\x51\xFF\x55\xF8\x89\x45\xF4\x8D\x4D\x14\x51\xFF\x55\xF8\x89\x45\xF0\x8D\x4D\x1F\x51\xFF\x75\xF0\xE8\x4A\xFF\xFF\xFF\x89\x45\xEC\x6A\x00\x6A\x00\x8D\x4D\x23\x51\x6A\x00\xFF\x55\xEC\x8D\x4D\x10\x51\xFF\x75\xF4\xE8\x2E\xFF\xFF\xFF\x6A\x00\xFF\xD0\x59\x5B\x5A\x5F\x5E\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x83\xEC\x04\x51\x52\x53\xC7\x45\xFC\x00\x00\x00\x00\x8B\x75\x08\x33\xC9\x8B\x5D\xFC\xC1\xE3\x19\x8B\x55\xFC\xC1\xEA\x07\x0B\xDA\x33\xC0\x8A\x04\x0E\x84\xC0\x74\x08\x03\xD8\x89\x5D\xFC\x41\xEB\xE1\x8B\x45\xFC\x5B\x5A\x59\x8B\xE5\x5D\xC2\x04\x00";

int main()
{
	printf("Hello");
	_asm
	{
		lea eax, shellCode  // 把shellcode地址放入eax
		push eax			// eax压入堆栈 
		retn				// retn做了2件事： 1.pop eip 2.esp + 4 将esp的值（shellcode）给了eip，然后esp+4.
	}

	return 0;
}
