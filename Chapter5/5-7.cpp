#include<iostream>
using namespace std;
class cat {
public:
	cat(int age) :
		itsAge(age) {
		numOfCats++;
	}
	virtual ~cat()
	{
		numOfCats--;
	}
	virtual int getAge()
	{
		return itsAge;
	}
	virtual void setAge(int age)
	{
		itsAge = age;
	}
	static int getNumOfCats()
	{
		return numOfCats;
	}
private:
	int itsAge;
	static int numOfCats;
};
int cat::numOfCats = 0;
void telepathicFuncton();
int main()
{
	const int maxCats = 5;
	cat* catHouse[maxCats];
	int i;
	for (i = 0; i < maxCats; i++)
	{
		catHouse[i] = new cat(i);
		telepathicFuncton();
	}
	for (i = 0; i < maxCats; i++)
	{
		delete catHouse[i];
		telepathicFuncton();
	}
	return 0;
}
void telepathicFuncton() {
	cout << "There are " << cat::getNumOfCats() << " cats alive" << endl;
}