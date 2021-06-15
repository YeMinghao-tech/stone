#include<iostream>
using namespace std;
class first 
{
	public:
		first()
		{
			cout<<"first类开始\n";
			a=0;
			b=0;
		}
		first(int x,int y)
		{
			a=x;
			b=y;
		}
		~first()
		{
			cout<<"first类结束！\n";
			a=0;
			b=0; 
		}
		void print()
		{
			cout<<"a="<<a<<"b="<<b<<endl;
		}
	private:
		int a,b;
};
class second: public first
{
	public:
		second():first(10,10)
		{
			cout<<"second类开始！\n";
			c=0;
			d=0;
		}
		second(int x,int y):first(x+1,y+1)
		{
			c=x;
			d=y;
	    }
	    second(int x,int y,int m,int n):first(m,n)
	    {
	    	c=x;
	    	d=y;
		}
		void print()
		{
			first::print();
			cout<<"c="<<c<<"d="<<d<<endl;
		}
	private:
		int c,d;
};
class third:public second
{
	private:
		int e;
	public:
		third()
		{
			cout<<"third\n";
			e=0;
		}
		third(int x,int y,int z):second(x,y)
		{
			e=z;
		}
		third(int x,int y,int z,int m,int n):second(x,y,m,n)
		{
			e=z;
		}
		~third()
		{
			cout<<"third类结束！\n";
		}
		void print()
		{
			second:print();
			cout<<"e="<<e<<endl;
		}
};
int main(void)
{
	first obj1;
	obj1.print();
	second obj2;
	obj2.print();
	second obj3(8,8,18,18);
	obj3.print();
	second obj4(19,19);
	obj4.print();
	third obj5;
	obj5.print();
	third obj6(9,8,98);
	obj6.print();
	third obj7(5,20,60,100,80);
	obj7.print();
	
	return 0;
}







