#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define MAX_VEXTEX_NUM 20
#define M 20
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//�����ṹ����
typedef struct ArcNode{
	int adjvex;//�û�ָ��Ķ����λ��
	struct ArcNode *nextarc;//ָ����һ������ָ��
}ArcNode;

//�ڽӱ�ͷ�������
typedef struct VNode{
	int data;//������Ϣ
	ArcNode *firstarc;//ָ���һ�������ڸõ�Ļ���ָ��
}VNode,AdjList[MAX_VEXTEX_NUM];

typedef struct{
	AdjList vertices;//һά����洢ͷ���
	int vexnum;//��ǰͼ�Ķ�����
	int arcnum;//��ǰͼ�Ļ���
}ALGraph

void CreateGraph(ALGraph *G){//����һ��ͼ���ڽӱ�
	int m,n,i,j;
	ArcNode *p;
	printf()
}