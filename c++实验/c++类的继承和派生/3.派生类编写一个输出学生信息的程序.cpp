#include<iostream>
enum St{
	GOOD,BAD};
using namespace std;
class Student
{
	public:
		Student()
		{
			HisAge=20,HisWeight=80;
			cout<<"\n��ѧ�������������彡����\n";
		}
		~Student()
		{
			cout<<"\n��ѧ�������������彡��\n\n";
		}
		int GetAge()const
		{
			return HisAge;
		}
		void SetAge(int age)
		{
			HisAge=age;
		 } 
		int GetWeight()const
		{
			return HisWeight;
		}
		void SetWeight(int weight)
		{
			HisWeight=weight;
		}
		void Speak()const
		{
			cout<<"\n��ѧ��һ������\n"; 
		}
	protected:
		int HisAge;
		int HisWeight;
};
class Ishe:public Student
{
	public:
		Ishe()
		{
			Hst=BAD;
			cout<<"\n��ѧ���ɼ�����\n";
		}
		~Ishe()
		{
			cout<<"\nIsthe�������\n"; 
		 } 
		St Gat()const
		{
			return Hst;
		}
		void Ste(St Ate)
		{
			Hst=Ate;
		}
		void Display()
		{
			cout<<"\n����һ�������ѧ��\n";
		}
		private:
			St Hst;
};
int main(void)
{
	Ishe Lming;
	Lming.Speak();
	Lming.Display();
	cout<<"\n������������"<<Lming.GetAge()<<"�ꡣ\n";
	cout<<"\n������������\n"<<Lming.GetWeight()<<"���\n"; 
	return 0;
}
