#include<iostream>
using namespace std;
class A {
private:
	bool a;
	int b;
	bool c;
};
class B {
private:
	int a;
	bool b;
	bool c;
};
int main() {
	// �Ƚ϶���ռ�õ��ڴ�
	cout << "-----------�Ƚ϶���ռ�õ��ڴ�----------------" << endl;
	A a; B b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;

	cout << "-----------�Ƚ�����----------------" << endl;
	char s[] = { 'A','B','C' };
	char s1[] = "ABC";
	cout << sizeof(s) << endl; // ����5��Ԫ��
	cout << sizeof(s1) << endl;
	cout << strlen(s1) << endl;

	cout << "-----------ָ��Ƚ�----------------" << endl;
	char* sss = "12\0ab";
	char* sss1 = "12\\0ab";
	cout << sizeof(sss) << endl;
	cout << sizeof(sss1) << endl;
	cout << sizeof(*sss) << endl;
	cout << sizeof(*sss1) << endl;
	cout << strlen(sss) << endl;
	cout << strlen(sss1) << endl;
	cout << "-----------ָ���string��----------------" << endl;
	char* ss = "C++ is good!";
	string ss1 = "C++ is good!";
	cout << sizeof(ss) << endl;
	cout << sizeof(*ss) << endl;
	cout << sizeof(ss1) << endl;
	cout << strlen(ss) << endl;
	cout << ss1.length() << endl;
	cout << ss1.size() << endl;
	system("pause");
	return 0;
}
