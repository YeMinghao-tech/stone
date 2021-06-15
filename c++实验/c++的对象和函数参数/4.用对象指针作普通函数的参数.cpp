#include<iostream>
using namespace std;
class cm
{
	public:
		cm()
		{
			x=y=0;
		}
		cm(int i,int j)
		{
			x=i;
			y=j;
		}
		void sy(int i,int j)
		{
			x=i;
			y=j;
		}
		void cy(cm *k)
		{
			x+=k->x;
			y+=k->y;
		}
		void pt()
		{
			cout<<x+y<<","<<y*y<<endl;
		}
	private:
		int x,y;
};
void D(cm k1,cm *k2)
{
	k1.sy(5,8);
	k2->sy(6,9);
}
int main(void)
{
	cm p(2,6),q;
	q.cy(&p);
	D(p,&q);
	p.pt();
	q.pt();
	return 0;
}
