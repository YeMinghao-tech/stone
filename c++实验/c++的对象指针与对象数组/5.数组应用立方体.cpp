#include<iostream>
using namespace std;
class Lft
{
	public:
		Lft(int h=10,int w=12,int len=5):h(h),w(w),l(len)
		{
			
		};//声明有默认参数的构造函数，用参数初始化表对数据成员初始化 
		int Tj()
		{
			return(h*w*l);
		}
		private:
			int h,w,l;
};
int main(void)
{
	Lft a[3]=
	{
		Lft(10,7,8),
		Lft(15,18,25),
		Lft(12,20,28)
	} ;
	for(int i=0;i<3;i++)
	{
		cout<<"第"<<i+1<<"个立方体的体积是："<<a[i].Tj()<<endl; 
	}
	return 0;
}

