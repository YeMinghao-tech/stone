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
		cout<<"输入个数只能是正整数！"<<endl;
		exit(1);
	
	}
	li=new int [le];
	lg=le;
	if(li=NULL)
	{
		cout<<"开辟动态存储空间失败！请查找原因"<<endl;
		exit(1);
	}
	cout<<"Ma类已建立！"<<endl;
}
Ma::~Ma()
{
	delete[]li;
	cout<<"Ma类退出"<<endl; 
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
	cout<<"请输入"<<lg<<""<<"个整数：";
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
			cout<<"Sy类已建立"<<endl;
		}
		~Sy();
};
Sy::~Sy()
{
	cout<<"Sy类退出"<<endl;
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
	cout<<"Ry类已建立！"<<endl;
}
Ry::~Ry()
{
	cout<<"Ry类退出"<<endl; 
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
			cout<<"Ay类已建立！"<<endl;
		}
		~Ay();
};
Ay::~Ay()
{
	cout<<"Ay类退出"<<endl;
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
	cout<<"Ny类建立"<<endl;
}
Ny::~Ny()
{
	cout<<"Ny类退出"<<endl; 
}
int main(void)
{
	cout<<endl<<"程序开始运行："<<endl;
	Ny n(8);
	n.Ip();
	n.Dp();
	cout<<endl<<"输入数据的平均值是"<<n.Ar()<<endl;
	n.St();
	n.Dp();
	n.Rs();
	n.Dp();
	return 0;
}
