#include<iostream>
using namespace std;
class Time
{
	public:
		Time(int h,int m,int s)
		{
			hou=h;
			min=m;
			sec=s;
		}
		void GetTime()
		{
			cout<<hou<<":"<<min<<":"<<sec<<endl;
		}
		private:
			int hou,min,sec;
}; 
int main(void)
{
	Time t1(8,18,58);
	t1.GetTime();
	Time *p1=&t1;
    p1->GetTime();
    void(Time::*p2)();//����ָ���๫�ó�Ա������ָ�����p2 
    p2=Time::GetTime;//ʹp2ָ���๫�ó�Ա����GetTime 
    (t1.*p2)();
    return 0;
}
