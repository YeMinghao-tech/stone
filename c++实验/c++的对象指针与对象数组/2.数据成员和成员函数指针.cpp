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
	pt A(5);//������󣬲���ʼ��A.x=5 
	
	int pt::*pz;//����pt������ݳ�Աָ����� 
	pz=&pt::z;//���������ݳ�Աz�ĵ�ַ����ָ�����pz 
	A.*pz=50;//���������ݳ�Աz��ֵ����A.z=50�ȼ� 
	
	int(pt::*pf)(int);//����pt��ĳ�Ա����ָ����� 
	pf=pt::f;//��ָ�����pf��ֵΪf 
	
	pt*ptr=&A;//����ptrΪָ����pt�Ķ���A��ָ�� 
	cout<<"(ptr->*pf)(8)="<<(ptr->*pf)(8)<<endl;//�ȼ�f(8) 
	return 0;
}
