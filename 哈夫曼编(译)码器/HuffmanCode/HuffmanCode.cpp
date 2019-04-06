#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int weight;
	char ch;
	int parent,lchild,rchild;//��̬��������洢�շ�����
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;//��̬��������洢�շ��������

HuffmanTree HT;
HuffmanCode HC;
int n=0;
int *we;
char *ch;

void select(HuffmanTree HT, int j, int &s1, int &s2);//ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2
void Init();//����I:���ն˶����ַ�����СΪn,�Լ�n���ַ���n��Ȩֵ,������������
void Encoding(HuffmanCode &HC);//����E:���кշ�������
void TreePrinting();//����D:���й����������������
void HuffmanCoding(HuffmanTree &HT,int n,char *ch,int *we);//��ʼ���շ������������ĺ���
void Free();//�ͷ����н��


//����I:���ն˶����ַ�����СΪn,�Լ�n���ַ���n��Ȩֵ,������������
void Init(){

	int i;
	printf("�������ַ����ĸ�����\n");
	scanf("%d",&n);
	while(n<2){
		printf("����ĸ����������ٴ��ڻ����2������������");
		scanf("%d",&n);
	}
	ch = (char *)malloc(n*sizeof(char));
	printf("�����������ַ�:\n");
	getchar();//����Ҫ����һ������

	for(i=0;i<n;i++){
		scanf("%c",&ch[i]);
	}
	
	we=(int *)malloc(n*sizeof(int));
	printf("�������Ӧ��ÿ���ַ���Ȩ��:\n");
	for(i=0;i<n;++i)
		scanf("%d",&we[i]);
	HuffmanCoding(HT,n,ch,we);
	printf("�ɹ�������������!\n");

}


//ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2
void select(HuffmanTree HT, int j, int &s1, int &s2){
	int i;
	
	//�ҵ���һ��parentΪ0�Ľ��,��Ϊ�ȽϵĻ���
	for(i=1;i<=j;i++)
		if(HT[i].parent==0){
			s1 = i;
			break;
		}

	//�ҵ�parentΪ0��weight��С���,�����Ϊs1
	for(;i<=j;i++){
		if((HT[i].parent==0)&&(HT[i].weight<HT[s1].weight))
			s1=i;
	}
	
	HT[s1].parent=1;//Ҫע���ֹͬ����㱻�ҵ����Σ���ʱ�ñ��1

    //�ҵ���һ��parentΪ0�Ľ��,��Ϊ�ȽϵĻ���
	for(i=1;i<=j;i++){
		if(HT[i].parent==0){
			s2=i;
			break;
			}
	}

    //�ҵ�parentΪ0��weight�ڶ�С�Ľ��,�����Ϊs2
	for(;i<=j;i++){
		if((HT[i].parent==0)&&(i!=s1)&&(HT[i].weight<HT[s2].weight)){
		    s2=i;
		}
	}
}


//��ʼ���շ������������ĺ���
void HuffmanCoding(HuffmanTree &HT,int n,char *ch,int *we){
	int m;
	m=2*n-1; //һ��n��Ҷ�ӽ��Ĺ�����������2n-1�����
	int i,s1,s2;
	HT=(HTNode*)malloc((m+1)*sizeof(HTNode));
	

	HTNode *p;//����һ��ָ��p���ڱ���

	//��ʼ������������Ҷ��
	for(p=HT+1,i=1 ; i<=n ; ++p,++i,++we,++ch){
		p->ch = *ch;
		p->weight = *we;
		p->parent = p->lchild = p->rchild = 0;
	}
    
	//��ʼ���������������з�Ҷ�ӽ��
	for(; i<=m ; ++i,++p){
		p->ch = 0 ;
		p->weight =0;
		p->parent = p->lchild = p->rchild = 0;
	}

	//���ƹ��������������еķ�Ҷ�ӽ����и�ֵ
	for(i=n+1;i<=m;++i){
		select(HT,i-1,s1,s2);//��ʼҪ����i-1=n��Ҷ�ӽ�㣬i++ÿ��ѭ�������µĽ���HT
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}



//����E:���кշ�������
void Encoding(HuffmanCode &HC){

	HC = (char**)malloc((n+1)*sizeof(char*));//����n���ַ������ͷָ������
	char *cd;//���������Ĺ����ռ�
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1] = '\0';//ÿ������Ľ�����
	int i,start,c,f;
	for(i=1;i<=n;++i){//����ַ������������
		start = n-1;//���������λ��
		for(c=i,f=HT[i].parent ; f!=0 ; c=f,f=HT[f].parent){//��Ҷ�ӵ������������
			if(HT[f].lchild==c) cd[--start]='0';//���ӡ�0��������--start����Ҷ�ӽ�㿪ʼ
			else cd[--start]='1';//�Һ��ӡ�1����
		}
			HC[i] = (char *)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
			strcpy(HC[i],&cd[start]);//��cd���Ʊ��봮��HC
		}
		free(cd);
		printf("����ɹ���");
}





//����D:���й����������������
void TreePrinting(){
	int i;
	for(i=1;i<2*n;i++){
		printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
	printf("��ӡ����!\n");
}

void Free(){
	free(HT);
	free(HC);
	free(we);
	free(ch);
}

int main(){
	char choice;

	while(1){
		printf("*****�ϻ�ʵ��3����������/������*****\n");
		printf("�˵�������\n");
		printf("I:��ʼ��\n");
		printf("E:����\n");
		printf("D:����\n");
		printf("Q:�˳�\n");
		scanf("%c",&choice);
		
		switch(choice){
		    case 'I': Init(); break;
		    case 'E': Encoding(HC); break;
		    case 'D': TreePrinting(); break;
			case 'Q': Free();exit(1);
		    default:printf("�������!\n");
		}
		getchar();
	}
	return 0;
	}


