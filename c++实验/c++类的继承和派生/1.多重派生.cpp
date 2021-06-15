#include<iostream>
using namespace std;
const int len=16;
class prclass
{
	public:
		void geprice()
		{
			cout<<"请输入物品名:";
			cin>>nameg;
			cout<<"请输入物品价格:";
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
			cout<<"请输入冰箱价格:";
			cin>>c_price;
		}
		void display1()
		{
			prclass::display();
			cout<<"冰箱的价格是:"<<c_price<<endl;
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
			cout<<"请输入洗衣机的价格";
			cin>>p_price;
	    }
	    void display1()
		 {
		 	prclass::display();
		 	cout<<"洗衣机的价格是"<<p_price<<endl;
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
