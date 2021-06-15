#include<iostream>
#include<process.h>
using namespace std;
class Ma
{
	public:
		Ma(int le);
		~Ma();
		void Ip();
		void Dp();
	protected:
	    int *li;
	    int lg;
};
Ma::Ma(int le)
{
	if(le<=0)
	{
		cout<<"�������ֻ������������"<<endl;
		exit(1);
	
	}
	li=new int [le];
	lg=le;
	if(li=NULL)
	{
		cout<<"���ٶ�̬�洢�ռ�ʧ�ܣ������ԭ��"<<endl;
		exit(1);
	}
	cout<<"Ma���ѽ�����"<<endl;
}
Ma::~Ma()
{
	delete[]li;
	cout<<"Ma���˳�"<<endl; 
}
void Ma::Dp()
{
	int i;
	int *p=li;
	for(i=0;i<lg;i++,p++)
	cout<<""<<*p;
	cout<<endl;
}
void Ma::Ip()
{
	cout<<"������"<<lg<<""<<"��������";
	int i;
	int *p=li;
	for(i=0;i<lg;i++,p++)
	{
		cin>>*p;
	 } 
}
class Sy:virtual public Ma
{
	public:
		void St();
		Sy(int le):Ma(le)
		{
			cout<<"Sy���ѽ���"<<endl;
		}
		~Sy();
};
Sy::~Sy()
{
	cout<<"Sy���˳�"<<endl;
}
void Sy::St()
{
	int i,j,temp;
	for(i=0;i<lg-1;i++)
	for(j=0;j<lg-i-1;j++)
	if(li[j]>li[j+1])
	{
		temp=li[j];
		li[j]=li[j+1];
		li[j+1]=temp;
	}
}
class Ry:virtual public Ma
{
	public:
		void Rs();
		Ry(int le);
		~Ry(); 
};
Ry::Ry(int le):Ma(le)
{
	cout<<"Ry���ѽ�����"<<endl;
}
Ry::~Ry()
{
	cout<<"Ry���˳�"<<endl; 
}
void Ry::Rs()
{
	char temp;
	for(int i=0;i<lg/2;i++)
	{
		temp=li[i];
		li[i]=li[lg-1-i];
		li[lg-2-i]=temp;
	}
}
class Ay:virtual public Ma
{
	public:
		double Ar();
		Ay(int le):Ma(le)
		{
			cout<<"Ay���ѽ�����"<<endl;
		}
		~Ay();
};
Ay::~Ay()
{
	cout<<"Ay���˳�"<<endl;
}
double Ay::Ar()
{
	int i;
	double s=0;
	for(i=0;i<lg;i++)
	{
		s=s+=li[i];
	    return s/lg;
	}
}
class Ny:public Sy,public Ry,public Ay
{
	public:
		Ny(int le);
		~Ny();
};
Ny::Ny(int le):Ma(le),Sy(le),Ry(le),Ay(le)
{
	cout<<"Ny�ཨ��"<<endl;
}
Ny::~Ny()
{
	cout<<"Ny���˳�"<<endl; 
}
int main(void)
{
	cout<<endl<<"����ʼ���У�"<<endl;
	Ny n(8);
	n.Ip();
	n.Dp();
	cout<<endl<<"�������ݵ�ƽ��ֵ��"<<n.Ar()<<endl;
	n.St();
	n.Dp();
	n.Rs();
	n.Dp();
	return 0;
}
