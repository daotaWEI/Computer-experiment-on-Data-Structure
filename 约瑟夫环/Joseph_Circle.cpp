#include <stdio.h>
#include <stdlib.h>
#include "CycleLinklist.h"

void main(){
	CycleLinklist L,p,q;
	int m,n;
	L=NULL;
	InitList(L);//����ֻ��ͷ���Ŀ�����
	printf("�����������õ�Լɪ�򻷳�ʼ����ֵ:\n");
	scanf("%d",&m);//��ʼ����
	printf("�����������õ�Լɪ�򻷲�������:\n");
	scanf("%d",&n);//������
	CreateCycleLinklist(n,L);//������������һ��Լɪ��
	p=L;
	printf("�����ߵ�˳��������:\n");
	for(int i=1;i<=n;i++){
		q=Locate_m(m,p);//ÿһ����p�������ҵ�����Ϊm����,������mֵ,ָ����˵�ָ��Ϊq
		printf("%d\n",q->num);//�������Ϊm���˵����
		Delete_m(L,p,q);//��p������ɾ������Ϊm����
	}


}