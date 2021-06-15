#include<iostream>
using namespace std;
class pt
{
	public:
		pt(int a)
		{
			x=a;
		}
		int f(int y)
		{
			return x*y*z;
		}
	    int z;
	private:
		int x;
};
int main()
{
	pt A(5);//定义对象，并初始化A.x=5 
	
	int pt::*pz;//定义pt类的数据成员指针变量 
	pz=&pt::z;//将共有数据成员z的地址赋给指针变量pz 
	A.*pz=50;//给共有数据成员z赋值，与A.z=50等价 
	
	int(pt::*pf)(int);//定义pt类的成员函数指针变量 
	pf=pt::f;//给指针变量pf赋值为f 
	
	pt*ptr=&A;//定义ptr为指向类pt的对象A的指针 
	cout<<"(ptr->*pf)(8)="<<(ptr->*pf)(8)<<endl;//等价f(8) 
	return 0;
}
