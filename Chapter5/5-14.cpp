#include<iostream>
using namespace std;
class boat;
class car {
private:
	int weight;
public:
	car(int j) {
		weight = j;
	}
	friend int getTotalWeight(car& acar, boat& aboat);
};
class boat {
private:
	int weight;
public:
	boat(int j){
		weight = j;
	}
	friend int getTotalWeight(car& acar, boat& aboat);
};
int getTotalWeight(car& acar, boat& aboat) {
	return acar.weight + aboat.weight;
}
int main()
{
	car c1(3);
	boat b1(9);
	cout << getTotalWeight(c1, b1) << endl;
	return 0;
}
 