#include<iostream>
using namespace std; 
class de
{
	public:
		de()
		{
			a=b=c=0;
		}
		de(int x,int y,int z)
		{
			a=x;
			b=y;
			c=z;
		}
		int add()
		{
			return a+b+c;
		}
		private:
		int a,b,c;
}m[2];
int main(void)
{
	de ay[3]={de(9,3,5),de(6,7,8),de(9,8,8)};
	m[0]=de(6,9,5);
	m[2]=de(7,8,6);
	cout<<m[0].add()<<" ";
	for(int i;i<3;i++)
	{
		cout<<ay[i].add()<<" ";
	}
	cout<<endl;
	return 0;
}
