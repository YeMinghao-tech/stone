#include<iostream>
using namespace std;
const int len=16;
class prclass
{
	public:
		void geprice()
		{
			cout<<"��������Ʒ��:";
			cin>>nameg;
			cout<<"��������Ʒ�۸�:";
			cin>>price;
		}
		void display()
		{
			cout<<""<<nameg<<endl;
			cout<<""<<price<<endl; 
		}
	protected:
		char nameg [len];
		int price;
};
class ccs:public prclass
{
	public:
		void geprice()
		{
			prclass::geprice();
			cout<<"���������۸�:";
			cin>>c_price;
		}
		void display1()
		{
			prclass::display();
			cout<<"����ļ۸���:"<<c_price<<endl;
		}
	private:
		int c_price;
};
class pps:public prclass
{
	public:
		void geprice()
		{
			prclass::geprice();
			cout<<"������ϴ�»��ļ۸�";
			cin>>p_price;
	    }
	    void display1()
		 {
		 	prclass::display();
		 	cout<<"ϴ�»��ļ۸���"<<p_price<<endl;
		}
	private:
		int p_price;
};
int main(void)
{
	ccs a;
	pps b;
	a.geprice();
	a.display1();
	b.geprice();
	b.display1();
	return 0;
}
