#pragma warning(disable : 4996)
#include<iostream>
#include<cstring>
using namespace std;
class employee {
private:
	char name[50];
	char streetAdd[50];
	char city[50];
	char postcode[50];
public:
	employee(const char* n, const char* s, const char* c, const char* p);
	void setname(const char *n);
	void display();
};
void employee::setname(const char *n) {
	strcpy(name, n);
}
employee::employee(const char* n, const char* s, const char* c, const char* p) {
	strcpy(name, n);
	strcpy(streetAdd,s);
	strcpy(city,c);
	strcpy(postcode,p);
}
void employee::display() {
	cout << name << " " << streetAdd << " " << city << " " << postcode << endl;
}
int main() {
	employee a1("张三","三里庵","合肥","230000");
	a1.setname("李四");
	a1.display();
}