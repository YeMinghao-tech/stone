#include<iostream>
using namespace std;
class de
{
	public:
		de()
		{
			a=0;
			b=0;
		}
		de(int x,int y)
		{
			a=x;
			b=y;
		}
		void adlist()
		{
			cout<<"a="<<a<<"b="<<b;
			cout<<"a+b="<<a+b<<endl;
		}
		private:
			int a,b;
			
};
int main(void)
{
	int x=6,y=8;
	de ar[2][3];
	for(int i=0;i<2;i++)
	 for(int j=0;j<3;j++)
	   ar[i][j]=de(i+11,j+8);
	de(*pa)[3]=ar;//定义指向对象数组的指针，并赋初值 
	
	for(int i=0;i<2;i++)
     for(int j=0;j<3;j++)
	  (*(*(pa+i)+j)).adlist();
	return 0;
}
