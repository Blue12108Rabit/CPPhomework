#include<iostream>
using namespace std;
int count(char* str) {
	int i, num = 0;
	for (i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			num++;
	}
	return num;
}
int main() {
	char text[50];
	cout << "请输入一个英文句子： ";
	gets_s(text);
	cout<<"字母个数为："<<count(text);
}