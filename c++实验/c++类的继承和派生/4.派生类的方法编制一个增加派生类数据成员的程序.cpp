#include<iostream>
#include<string.h>
using namespace std;
class NBook
{
	public:
	char *Name;
	NBook()
	{
		cout<<"NBook�����У�"<<endl;
	}
	NBook(char*name)
	{
		Name=new char[strlen(name)+1];//new �����ڴ� 
		strcpy(Name,name);
	}
    void DName();
};
void NBook::DName()
{
	cout<<Name;
}
class Page:public NBook
{
	public:
		Page(char*name,long number);
		void DName();
	private:
		long pNumber;
};
Page::Page(char*name,long pnumber):NBook(name)
{
	pNumber=pnumber;
}
void Page::DName()
{
	cout<<"The Name of book is";
	NBook::DName();
	cout<<"\nIts page is"<<pNumber<<endl;
	
}
int main()
{
	NBook Nb;
	Page Pb("ReadBook",278);
	Pb.DName();
	return 0 ;
}


