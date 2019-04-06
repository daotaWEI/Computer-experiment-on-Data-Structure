#include <stdio.h>       
#include <malloc.h> 
#include <stdlib.h> 
#define MaxSize 100
#define OVERFLOW 1



//���峵�������Ϣ
typedef struct CarNode
{
	char AD;//�����������ȥ����Ϣ
	int NO;//�������ƺ�
	int time;//�������ȥ��ʱ��
}CarNode;



//����һ��˳��ջ��Ϊͣ����
typedef struct SqStack	
{ 
	struct CarNode	data[MaxSize];//�ṹ���������г��������Ϣ
	int top;//ջ��ָ��(ʵ��Ϊ�����±�ֵ)
	int num;//��˳��ջ�ĵ�ǰ�泵����
}SqStack;



//���н�㶨��
typedef struct QNode
{
	struct CarNode data;//���������Ϣ��
	QNode *next;//ָ����һ����������ָ����
}QNode;



//����һ����ʽ������Ϊ���
typedef struct LinkQueue
{
	QNode *front;//��ͷָ��
	QNode *rear;//��βָ��
	int num;//���г�������
}LinkQueue;



//����һ���յ�ͣ����,��������ʼ��һ����ջ
SqStack *Init_SqStack()
{
		SqStack *s;//����һ��ָ��˳��ջ��ָ��s
		s=(SqStack*)malloc(sizeof(SqStack));//ͨ��ָ��s�����ַ
		if(!s) exit(OVERFLOW);
	    s->top=0;//ջ��ָ��ĳ�ʼֵΪ0������Ϊջ�ձ��
		s->num=0;//ջ�ĵ�ǰ��ų�������Ϊ0
		return s;//����ָ��һ���ѳ�ʼ���Ŀ�˳��ջ��ָ��s
}



//����һ���յı��,��������ʼ��һ���ն���
LinkQueue *Init_LinkQueue()      
{
		LinkQueue *q;//����һ��ָ����е�ָ��q
	    QNode *p;//����һ��ָ����н���ָ��p������p��Ϊͷָ��
     	q=(LinkQueue*)malloc(sizeof(LinkQueue));//ͨ��ָ��q�����ַ
		if(!q) exit(OVERFLOW);//����ʧ��
    	p=(QNode*)malloc(sizeof(QNode));//ͨ��ָ��p�����ַ,����p��Ϊͷָ��
		if(!p) exit(OVERFLOW);//����ʧ��
		q->front=q->rear=p;//��ͷָ��Ͷ�βָ��һ��ָ��ͷ���p,��Ϊ�ӿձ��
		q->front->next=NULL;//ͷ���next��Ϊ��
		q->num=0;//���е�ǰ��������Ϊ��
		return q;//����ָ��һ���ѳ�ʼ���Ŀն��е�ָ��q
}



//˳��ջջ���ж�
int IsEmpty_SqStack(SqStack *s)
{
	if(s->top ==0)
		return 1;//ջ�շ���1
	else
		return 0;//ջ�ǿշ���0
}



//˳��ջջ���ж�
int  IsFull_SqStack(SqStack *s,int n)	
{
	if(s->top==n)//��������ջ�������Ϊn�����±�top����nʱ���ж�ջ�������ɴ��[0,n-1]�����������Ϣ
		return 1;//ջ������1
	else
		return 0;//ջ��������0
}



//�����жӿ��ж�
int IsEmpty_LinkQueue(LinkQueue *q)		
{
	if(q->front==q->rear)
		return 1;//�ӿշ���1
	else 
		return 0;//�ӷǿշ���0
}



//���복����Ϣ��㵽����q��
void In_LinkQueue(LinkQueue *q,struct CarNode s)
{
		QNode *p;//����һ��ָ����н���ָ��p
		p=(QNode*)malloc(sizeof(QNode));//�����ַ
		if(!p) exit(OVERFLOW);//����ʧ��
		p->data=s;//������Ϣ�������p��data��
		q->num++;//����q����+1

		p->next=NULL;//��β����Ľ��p��next��Ϊ��
		q->rear->next=p;//�����p�����β
		q->rear=p;//��βָ�����
}



//��������ͣ����(��ջ)
void Push_SqStack(SqStack *p,struct CarNode s)  
{
	p->data[p->top]=s;//��ԭ��top��ָ�롱ָ���λ���ϲ����½��������
	p->top++;//�±�top+1����ָ���½�����������һ��λ��
	p->num++;//ջp����+1
}



//�����˳�ͣ����(��ջ)
int Pop_SqStack(SqStack *s,struct CarNode c)
{
	SqStack *p;//����һ��˳��ջ��Ϊ��ʱͣ����
	int t;//ͣ����ʱ��
    p=Init_SqStack();//��ʼ����ʱͣ����

	s->top--;//�Ƚ�topָ��ָ�����½���ĳ������

	while(s->data[s->top].NO !=c.NO)//���Ҳ������ƺ�ΪP.NO�ĳ���
	{
	    Push_SqStack(p,s->data[s->top]);//��ʱ������ʱͣ����
		s->top--;//topָ������
		s->num--;//��������-1
	}

	/*
	  ���������½���ͣ�����ĳ����ĵ���ʱ����Ϊ��ǰʱ�䣬���˳�����ͣ��ʱ��Ĵ��¼�������: 
	  ͣ����ʱ��: t=�˳���������ȥʱ��-�˳������ĵ���ʱ��
	*/


	t=c.time - s->data[s->top].time;//����ͣ��ʱ��
	s->num--;//ͣ����������-1

	/*ͣ����topָ�뵱ǰָ���˳�������λ��*/


	while(IsEmpty_SqStack(p)==0)//��ʱͣ�����ǿ�
	{
		Push_SqStack(s,p->data[--p->top]);
		p->num--;//��ʱͣ������������-1
	}
	return t;//����ͣ��ʱ��
}


//�����������б��
struct CarNode Out_LinkQueue(LinkQueue *q)   //����
{
		QNode *p;
		p=q->front->next;//�ȱ����³������еĳ������
		q->front->next=p->next;
		q->num --;

		//�ر�ע�⵱����ֻ��һ��Ԫ��ʱҪ��ֹfree���βָ�붪ʧ
		if(	q->front->next==NULL)//�������ֻ��һ������Ԫ��ʱ������Ԫ�ر�ɾ�����βָ��Ĵ���
			q->rear=q->front;
		return p->data;//���س����еĳ�����Ϣ
		free(p);
}


/*�������㷨��������*/
int main()
{

	SqStack *park;//����һ��ͣ����
	LinkQueue *path;//����һ�����
	struct CarNode car;//������������
	int n,t;//nΪ�Զ����ͣ�������������tΪͣ����ʱ��

	park=Init_SqStack();//��ʼ��ͣ����
	path=Init_LinkQueue(); //��ʼ�����
    printf("�ϻ�ʵ��2: ͣ��������ϵͳ\n");
	printf("\n");
	printf("������ͣ�����ɴ���������������:\n");
	scanf("%d",&n);
	printf("�����복����Ϣ,����������������ߡ���ȥ����Ϣ(��A/D��ʾ),�������պ���,�Լ��������ȥ��ʱ��,��: A,1,5:\n");
    scanf("%c,%d,%d",&car.AD,&car.NO,&car.time);
	while(car.AD!='E')
	{
	   if(car.AD=='A' )//�������ﴦ��
	   {								
				 if(IsFull_SqStack(park,n)==1)  //ͣ������
				 {
					In_LinkQueue(path,car);   //���������еȴ�
				    printf("�������ڱ���ϵĵ�%d��ͣ��λ��\n",path->num);
					printf("\n");
					printf("��������복����Ϣ\n");
				 }
				 else
				 {
					 Push_SqStack(park,car);		//����ͣ����
					printf("��������ͣ�����ڵĵ�%d��λ��\n",park->num);
					printf("\n");
					printf("��������복����Ϣ\n");
				 }
	   }
			   
	   if(car.AD=='D' )	//������ͣ�����뿪����
	   {
                t=Pop_SqStack(park,car);//��ջ
				printf("��������ͣ������ͣ��ʱ��Ϊ%d,��Ҫ֧��ͣ���ѹ���%dԪ\n",t,10*t);//
				printf("\n");
				printf("��������복����Ϣ\n");
			    if(IsEmpty_LinkQueue(path)==0)   //��ͣ�����󣬱���г����Ŷ�����Ҫ��ջ
			      Push_SqStack(park,Out_LinkQueue(path));	  
	   }
		scanf("%c,%d,%d",&car.AD,&car.NO,&car.time);//�������복����Ϣ		
	}
	
	printf("�������\n");
	return 1;
}
