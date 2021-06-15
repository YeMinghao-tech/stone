#include<iostream>
using namespace std;
class de
{
	public:
		de()
		{
			a=0;b=0;
		}
		de(int x,int y)
		{
			a=x;
			b=y;
		}
		void adlist()
		{
			cout<<""<<a<<""<<b;
			cout<<""<<a+b<<endl;
		}
		private:
			int a,b;
};
int main(void)
{
	de m1,m2(7,8),m3(10,8),m4(21,18);
	de *x[4]={&m1,&m2,&m3,&m4};
	for(int i;i<4;i++)
	x[i]->adlist();
	return 0;
}
