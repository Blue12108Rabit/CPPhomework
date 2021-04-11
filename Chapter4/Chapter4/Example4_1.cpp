#include<iostream>
using namespace std;
class clock{
	public:
		void settime(int newh = 0, int newm = 0, int news = 0);
		void showtime();
	private:
		int hour, minute, second;
};
void clock::settime(int newh, int newm,int news)
{
	hour = newh;
	minute = newm;
	second = news;
}
inline void clock::showtime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	int a, b, c;
	clock myclock;
	cout << "first time set and output" << endl;
	a.settime();
	myclock.showtime();
	cout << "second time set and output:" << endl;
	cin >> a >> b >> c;
	myclock.settime(a,b,c);
	myclock.showtime();
	system("pause");
	return 0;
}