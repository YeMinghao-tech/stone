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
		void diplay()
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
	    void display()
		 {
		 	prclass::display();
		 	cout<<"ϴ�»��ļ۸���"<<p_price<<endl;
		}
	private:
		int p_price;
};
int main(void)
{
	return 0;
}
