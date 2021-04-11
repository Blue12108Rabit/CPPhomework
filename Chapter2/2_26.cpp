#include<iostream>
using namespace std;
int main()
{
	cout << "How many marks did you get in the exam?" << endl;
	int mark;
	cin >> mark;
	if (mark > 100 || mark < 0)
		cout << "Your mark must be between 0 to 100!" << endl;
	else{
		switch (mark / 10){
		case 10:
		case 9:cout << "excellent" << endl;
			break;
		case 8:cout << "good" << endl;
			break;
		case 7:
		case 6:cout << "medium" << endl;
			break;
		default:cout << "bad" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}