#include<stdio.h>
int  judge(int x);
int main()
{
	int i;
	int cnt=0;
	int sum=0;
	int max;
	for(i=100;i<=999;i++)
	{
		int t=i;
		int b;
		int a1=1,a2=0,a3=0;
		do
		{
			b=t%10;
			a1*=b;
			a2+=b;
			a3+=b*b;
			t/=10;
		}while(t>0);
		if(judge(i)==0&&judge(a1)==0&&judge(a2)==0&&judge(a3)==0){
		cnt++;
		sum+=i;
		max=i;
	    }
	}
	printf("���������ĸ���Ϊ%d\n",cnt);
	printf("���г�������֮��Ϊ%d\n",sum);
	printf("���ĳ�������Ϊ%d\n",max); 
}
int  judge(int x)
{
	int i;
	for(i=2;i<=x;i++)
	{
		if(x%i==0&&i!=x)
		break;
		if(x%i==0&&i==x)
		return 0;
	}
	return 1;
}
