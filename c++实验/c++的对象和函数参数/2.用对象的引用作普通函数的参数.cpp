#include<iostream>
using namespace std;
class cl
{
	public:
		cl()
		{
			x=y=0;
		}
		cl(int i,int j)
		{
			x=i;
			y=j;
		}
		void sy(int i,int j)
		{
			x=i;
			y=j;
		}
		void cy(cl &k)
		{
			x+=k.x;
			y+=k.y;
		}
		void pt()
		{
			cout<<x+y<<","<<y*y<<endl;
		}
	private:
		int x,y;
};
void F(cl k1,cl &k2)
{
	k1.sy(15,8);
	k2.sy(6,19);
}
int main(void)
{
	cl p(8,30),q;
	q.cy(p);
    F(p,q);
	p.pt();
	q.pt();
	return 0;
}
