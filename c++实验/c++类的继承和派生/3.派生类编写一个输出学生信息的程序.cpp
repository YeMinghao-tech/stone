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
			cout<<"\n该学生是李铭，身体健康！\n";
		}
		~Student()
		{
			cout<<"\n该学生是李铭，身体健康\n\n";
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
			cout<<"\n该学生一切正常\n"; 
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
			cout<<"\n该学生成绩优良\n";
		}
		~Ishe()
		{
			cout<<"\nIsthe类结束！\n"; 
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
			cout<<"\n他是一个优秀的学生\n";
		}
		private:
			St Hst;
};
int main(void)
{
	Ishe Lming;
	Lming.Speak();
	Lming.Display();
	cout<<"\n李铭的年龄是"<<Lming.GetAge()<<"岁。\n";
	cout<<"\n李铭的体重是\n"<<Lming.GetWeight()<<"公斤。\n"; 
	return 0;
}
