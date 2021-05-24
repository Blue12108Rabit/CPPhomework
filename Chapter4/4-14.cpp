#include<iostream>
using namespace std;
class tree {
public:
	void grow(int y);
	int age();
	tree();
private:
	int ages;
};
tree::tree()
{
	ages = 0;
}
void tree::grow(int y)
{
	ages = y;
}
int tree::age()
{
	return ages;
}
int main()
{
	tree x;
	int y;
	cout << "Please input the tree's age : ";
	cin >> y;
	x.grow(y);
	cout << "Tree's age is " << x.age() << endl;
	return 0;
}

