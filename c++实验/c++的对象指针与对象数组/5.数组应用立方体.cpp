#include<iostream>
using namespace std;
class Lft
{
	public:
		Lft(int h=10,int w=12,int len=5):h(h),w(w),l(len)
		{
			
		};//������Ĭ�ϲ����Ĺ��캯�����ò�����ʼ��������ݳ�Ա��ʼ�� 
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
		cout<<"��"<<i+1<<"�������������ǣ�"<<a[i].Tj()<<endl; 
	}
	return 0;
}

