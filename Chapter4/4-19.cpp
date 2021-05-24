#include<iostream>
using namespace std;
enum core{single,dual,quad};
enum words{bit64,bit32};
enum multithreading{support,notsupport};
class cpu {
public:
	cpu(unsigned frequence, core type,words length,multithreading mode):
		frequence(frequence),coretype(type),wordsize(length),mode(mode){}
	void show();
private:
	unsigned frequence;
	core coretype;
	words wordsize;
	multithreading mode;
};
void cpu::show()
{
	cout << "frequence:  " << frequence << endl;
	cout << "core:   ";
	switch (coretype)
	{
	case single:cout << "single-core" << endl; break;
	case dual:cout << "dual-core" << endl; break;
	case quad:cout << "quad-core" << endl; break;
	}
	cout << "words:   ";
	switch (wordsize)
	{
	case bit32:cout << "32-bits len" << endl; break;
	case bit64:cout << "64-bits len" << endl; break;
	}
	cout << "multithreading:   ";
	switch (mode)
	{
	case support:cout << "suport multithreading" << endl; break;
	case notsupport:cout << "not suport multithreading" << endl; break;
	}
}
int main()
{
	cpu cpu1(3000000000, quad, bit64, support);
	cpu cpu2(1500000000, dual, bit32, notsupport);
	cout << "size of class cpu1: " << sizeof(cpu1) << endl;
	cpu1.show();
	cout << "size of class cpu2: " << sizeof(cpu1) << endl;
	cpu2.show();
	return 0;
}

