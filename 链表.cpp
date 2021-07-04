#include<stdlib.h> 
#include<stdio.h>
#include<string.h> 
//���ݵ����
//��������������������
//���ݵ�����
struct bookInfo
{
	char name[20];
	float price;
	int num;//������� 
}; 

struct Node
{
	struct bookInfo data;
	struct Node* next;
};
struct Node* list=NULL;

//������ͷ 
struct Node*creatHead()
{
	//��̬�ڴ�����
	struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
	headNode->next=NULL;
	return headNode; 
};
 
//�����ڵ㣺Ϊ������׼��
//���û����ݱ�Ϊ�ܹ������ 
struct Node* creatNode(struct bookInfo data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}; 
 
//����  ��ͷ������
void insertNodeByhead(struct Node* headNode,struct bookInfo data)
{
	struct Node *newNode=creatNode(data);
	//�����Ӻ�Ͽ� 
	newNode->next=headNode->next;
	headNode->next=newNode;
 } 
// void insertNodeByTail(struct Node*headNode,int data)
// {
// 	struct Node*pMove=headNode;
// 	while(pMove->next!=NULL)
// 	{
// 		pMove = pMove->next;
//	 }
//	 struct Node*newNode = creatNode(data);
//	 pMove->next=newNode;
// };��β������ 

struct Node*searchByName(struct Node* headNode,char *bookName)
{
	struct Node*posNode = headNode->next;
	while(posNode!=NULL&&strcmp(posNode->data.name,bookName))
	{
		posNode = posNode->next;
	}
	return posNode;//���ؿ���û�ҵ������طǿ����ҵ��� 
}
void printfList(struct Node* headNode)
{
	struct Node*pMove=headNode->next;
	printf("����\t�۸�\t����\n"); 
	while(pMove!=NULL)
	{
		printf("%s\t%.1f\t%d\n",pMove->data.name,pMove->data.price,pMove->data.num);
		pMove=pMove->next;
	}
}

//ָ��λ��ɾ��
void deleteNodeByname(struct Node*headNode,char* bookName)
{
	struct Node* posLeftNode=headNode;
	struct Node* posNode=headNode->next;
	//�鼮�������ַ��� ,�ַ����ȽϺ������� 
	while(posNode!=NULL&&strcmp(posNode->data.name,bookName))
	{
		posLeftNode=posNode;
		posNode=posLeftNode->next;
	}
	if(posNode==NULL)
	return;
	else
	{
		printf("ɾ���ɹ���");
		posLeftNode->next=posNode->next;
		free(posNode);
		posNode=NULL;
	}
 } 
 
 //д����--->�˵�---->ģ��
void makeMenu()
{
	
	printf("         �Ĵ���ѧͼ�����ϵͳ    \n");
	printf("         0.�˳�ϵͳ\n"); 
	printf("         1.�Ǽ��鼮\n"); 
	printf("         2.����鼮\n"); 
	printf("         3.�����鼮\n"); 
	printf("         4.�黹�鼮\n");  
	printf("         5.�鼮����\n"); 
	printf("         6.ɾ���鼮\n"); 
	printf("         7.�����鼮\n"); 
	printf("---------------------------------\n");
	printf("�����루0~7��"); 
} 
//ֱ���ļ�����
//����� 
void saveInfoToFile(const char*fileName,struct Node* headNode)
{
	FILE *fp = fopen(fileName,"w");
	struct Node*pMove=headNode->next;
	while(pMove != NULL)
	{
		fprintf(fp,"%s\t%.1f\t%d\n",pMove->data.name,pMove->data.price,pMove->data.num);
		pMove=pMove->next;
	 } 
	fclose(fp); 
}
//�ļ�������
void readInfoFromFile(const char* fileName,struct Node*headNode)
{
	FILE *fp=fopen(fileName,"r");//��һ�δ��ļ��϶������� 
	if(fp==NULL)
	{   //�����ھʹ�����������ļ� 
		fp=fopen(fileName,"w+");
	}
	struct bookInfo tempData;
	while(fscanf(fp,"%s\t%f\t%d\n",tempData.name,&tempData.price,&tempData.num)!=EOF)
	{
		insertNodeByhead(list,tempData);
	}
	fclose(fp);
} 
void bubbleSort(struct Node*headNode)
{
	for(struct Node* p=headNode->next;p!=NULL;p=p->next)
	{
		for(struct Node*q=headNode->next;q->next!=NULL;q=q->next)
		{
			if(q->data.price > q->next->data.price)
			{
				//����ֵ 
				struct bookInfo temp=q->data;
				q->data=q->next->data;
				q->next->data=temp;
			}
		}
	}
	printfList(headNode);
}

//������
 void keyDown()
{
	int userKey=0;
	struct bookInfo temp;//������ʱ�������洢�鼮��Ϣ 
	scanf("%d",&userKey);
	switch(userKey)
	{
		case 0:
			printf("���˳���\n");
			printf("�˳��ɹ���\n");
			system("pause");
			exit(0);//�ر��������� 
			break;
		case 1:
			printf("���Ǽǡ�\n");
			printf("�����鼮����Ϣ��name,price,num��:");
			scanf("%s%f%d",temp.name,&temp.price,&temp.num); 
			insertNodeByhead(list,temp);
			saveInfoToFile("bookinfo.txt",list);
			break;
		case 2:
			printf("�������\n");
			printfList(list);
			break;
		case 3:
		{	
			printf("�����ġ�\n");
			printf("����Ҫ����鼮���֣�name��:");//�鼮���ڣ����Խ��ģ�����-1�� �����������ʧ�� 
			scanf("%s",temp.name);
			struct Node*result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("û������鼮���޷����ģ�\n");
			}
			else
			{
				if(result->data.num==0)
				{
					printf("�鼮����Ϊ0���޷����ģ�\n"); 
				}
				else
				{
					result->data.num--;
					printf("���ĳɹ�����ǰ�鼮����Ϊ%d\n",result->data.num); 
				}
			}
	        saveInfoToFile("bookinfo.txt",list);
			break;
	    }
		case 4:
		{
			printf("���黹��\n");//�鼮����-1 
			printf("����Ҫ�����鼮���֣�name��:"); 
			scanf("%s",temp.name);
			struct Node*result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("û������鼮���޷��黹��\n");
			}
			else
			{
				result->data.num++;
				printf("�黹�ɹ�����ǰ�鼮����Ϊ%d\n",result->data.num); 
			}
			saveInfoToFile("bookinfo.txt",list);
			break;
	    }
	    case 5:
	    	printf("������\n");
	    	bubbleSort(list);
	    	break;
		case 6:
			printf("��ɾ����\n");
			printf("������ɾ���鼮������");
			scanf("%s",temp.name);
			deleteNodeByname(list,temp.name);
			saveInfoToFile("bookinfo.txt",list);
			break;
		case 7:
		{
				
			printf("�����ҡ�\n");
			printf("������Ҫ���ҵ�����");
			scanf("%s",temp.name);
		    struct Node* result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("û���ҵ����鼮��");
			}
			else
			{
				printf("����\t�۸�\t����\n");
				printf("%s\t%.1f%d",result->data.name,result->data.price,result->data.num);
			}
			break;
	    }
		default:
			printf("��error��\n");
			break;
	}
}
int main()
{
	list=creatHead();
	readInfoFromFile("bookinfo.txt",list);
	while(1)
	{
		makeMenu();
		keyDown();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;	
}
