#include<iostream>
using namespace std;
class Pt
{
	public:
	Pt()
	{
		x=1;
		y=1;
	}
	Pt(int a,int b)
	{
		x=a;
		y=b;
	}
	void Z()
	{
		x++;
		y++;
	}
	void f(Pt &p)
	{
		x+=p.x;
		y+=p.y;
	}
	void List()
	{
		cout<<"x="<<x+y<<"y="<<y*x<<endl;
	}
	private:
		int x,y;
};
int main(void)
{
	Pt A1(6,8),A2;
	A1.Z();
	A2.f(A1);
	A2.Z();
	A2.List();
	return 0;
}
