#ifndef _CycleLinklist_
#define _CycleLinklist_

//������(��)�Ľṹ
typedef struct LNode{
	int key;//ÿ���˳��е�����
	int num;//ÿ���˵ı��
	struct LNode *next;//ָ����һ�����
}LNode, *CycleLinklist;

//�����յĵ���ѭ������
void InitList(CycleLinklist &L){
	L = (LNode*)malloc(sizeof(LNode));//����ͷ���
	if(!L) exit(1);//�쳣�˳�
	L->key=0;
	L->num=0;
	L->next=L;//�ձ��ж�
}

//�����û���������n��������ѭ������
void CreateCycleLinklist(int n,CycleLinklist &L){
	CycleLinklist p,q;

	q = L;//ʹ��q����ʱ����Lָ���ͷ����ָ��

	printf("������ÿ�������е�����:\n");
	for(int i=1;i <= n;i++){
		p=(LNode*)malloc(sizeof(LNode));//������
		if(!p) exit(1);
		scanf("%d",&p->key);
		p->num=i;
		L->next=p;
		L=p;
	}

	L->next=q->next;//βָ��ָ���һ�����
	/*����Ҫע�⣬�����Ҷ���ĵĵ���ѭ�������Ǵ�ͷ���ģ�Ϊ�˷���֮����������ҵ�
	  ����Ϊm�Ľ�㣬���ҷ�ֹ������ʱ���ͷ���Ҳ���ȥ����������Ҫ��βָ��ָ���һ
	  ����㣬������ͷ���*/
	free(q);
}


/*���˵��Դ����ĵ�:���������һ��ʼ����һֱ������󣬾���debug����ʱ���֣�mֵһֱ��20��ԭ����û�н������������Ϊ&m��
  ����m���������ں����ڣ�Ӧ�ý���&�������ر���ֵ*/




//��λ����mֵ����
CycleLinklist Locate_m(int &m,CycleLinklist &p){
	CycleLinklist q;
	for(int j=1;j<m;j++) p=p->next;
		q=p->next;//��ʱ��λ������mֵ����q
	    m=q->key;//����Ҫȡ������,����mֵ,�Ա��ٽ�����һ��ѭ��
	    return q;
	}


//ɾ����λ�ı���mֵ����
void Delete_m(CycleLinklist &L,CycleLinklist p,CycleLinklist q){
	p->next=q->next;//p�Ƕ�λ��m���˵�ǰһ��,q��Ҫɾ������
	free(q);
}

#endif