#include<iostream>
using namespace std;
class biry
{
	public:
		biry()
		{
			year=2000;
			month=1;
			day;
		}
		biry(int y,int m,int d)
		{
			year=y;
			month=m;
			day=d;
		}
		void show()
		{
			cout<<year<<"/"<<month<<"/"<<day<<endl;
		}
		private:
			int year,month,day;
};
int main()
{
	biry mybir(2015,1,19),myby(2004,8,28);
	biry *pa,*pb;
	pa=&mybir;
	pb=&myby;
	pa->show(),pb->show();
	mybir.show(),myby.show();
	return 0;
}
