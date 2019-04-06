#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxSite 100
#define infinite 10000

//������·��Ȩֵ�Ľṹ��
typedef struct{
	int path;
}ArcCell,AdjMatrix[maxSite][maxSite];


//���徰��ṹ��
typedef struct {
	char placeName[15];//��������
	int placeNo;//������
	char placeInfo[100];//��ž�����Ϣ
}place;

//����У԰��ͼ
typedef struct{
	place placeArray[maxSite];//��������
	AdjMatrix pathArray;//·������
	int placeNum;//��������
	int pathNum;//·��������
}Graph;

//��ʼ��У԰��ͼ
Graph InitGraph(){
	Graph G;
	int i,j;
	G.placeNum = 10;
	G.pathNum = 12;
	for(i=0;i<G.placeNum;i++)
		G.placeArray[i].placeNo = i;//�Ծ�����б��;
	strcpy(G.placeArray[0].placeName,"����������");
	strcpy(G.placeArray[0].placeInfo,"��ѧУ��,��ΰ׳��!");
	strcpy(G.placeArray[1].placeName,"����¥");
	strcpy(G.placeArray[1].placeInfo,"ѧУ�쵼�������칫����!");
	strcpy(G.placeArray[2].placeName,"�����ѧԺ");
	strcpy(G.placeArray[2].placeInfo,"������������,�ɾ�����δ��!");
	strcpy(G.placeArray[3].placeName,"������ϢѧԺ");
	strcpy(G.placeArray[3].placeInfo,"��չ�й�оƬ��ҵ!");
	strcpy(G.placeArray[4].placeName,"�ʶ��㳡");
	strcpy(G.placeArray[4].placeInfo,"����������...����ԭ�򲻱����!");
	strcpy(G.placeArray[5].placeName,"ͼ���");
	strcpy(G.placeArray[5].placeInfo,"����ḻ,ѧ�Ծ۾ӵ�!");
	strcpy(G.placeArray[6].placeName,"ѧ�������");
	strcpy(G.placeArray[6].placeInfo,"ѧ�������,��ḻ����!");
	strcpy(G.placeArray[7].placeName,"ʳ��");
	strcpy(G.placeArray[7].placeInfo,"���ѧ���ͽ�ְ��һ�����͵ĳ���!");
	strcpy(G.placeArray[8].placeName,"27��¥");
	strcpy(G.placeArray[8].placeInfo,"���߱������ڵ�����¥!");
	strcpy(G.placeArray[9].placeName,"32��¥");
	strcpy(G.placeArray[9].placeInfo,"Ů������¥,�׳ƹ���¥!");

	for(i=0;i<G.placeNum;i++)
		for(j=0;j<G.pathNum;j++){
			G.pathArray[i][j].path = infinite;//�Ƚ�ÿ�������·����ʼ��Ϊ�����
		}
		G.pathArray[0][1].path = 200;//�����ź�����¥���200m
		G.pathArray[0][2].path = 500;//�����źͼ����ѧԺ���500m
		G.pathArray[0][4].path = 600;//�����ź��ʶ��㳡���600m
		G.pathArray[1][3].path = 200;//����¥�͵�����ϢѧԺ���200m
		G.pathArray[2][5].path = 150;//�����ѧԺ��ͼ������150m
		G.pathArray[3][5].path = 100;//������ϢѧԺ��ͼ������100m
		G.pathArray[4][5].path = 100;//�ʶ��㳡��ͼ������100m
		G.pathArray[5][6].path = 300;//ͼ��ݺ�ѧ����������300m
		G.pathArray[5][8].path = 500;//ͼ��ݺ�27��¥���500m
		G.pathArray[6][7].path = 50;//ѧ������ĺ�ʳ�����50m
		G.pathArray[6][8].path = 50;//ѧ������ĺ�27��¥���50m
		G.pathArray[8][9].path = 100;//27��¥��32��¥���100m

		for(i=0;i<G.placeNum;i++)//����ͼ�෴����·��������ͬ
			for(j=0;j<G.placeNum;j++)
				G.pathArray[j][i].path=G.pathArray[i][j].path;
			return G;
}

//���·����ѯ
void Floyd(Graph *G){
	int v,u,w,k,j,t;
	int flag = 1;//���ڱ�����������Ƿ���ȷ�����������ݷ���Ҫ����flag��Ϊ0

    int D[10][10],S[10][10];//D[10][10]��Ŷ����붥��֮���ֱ��·��

	for(v=0;v<G->placeNum;v++){
		for(w=0;w<G->placeNum;w++){
			D[v][w]=G->pathArray[v][w].path;//����ʼ·�����ݴ��������D[v][w]��
			S[v][w]=w;//��ʼ���м䶥��
			//for(u=0;u<G->placeNum;u++)
			//	p[v][w][u] = 0;//����ά�������ڴ��������֮���Ƿ���ֱ��·������������Ϊ1��������Ϊ0
			//if(D[v][w]<infinite){
			//	p[v][w][v] = 1;
			//	p[v][w][w] = 1;
		}
	}

	//uΪ�м��
	for(u=0;u<G->placeNum;++u){
		//vΪ���
		for(v=0;v<G->placeNum;++v)
			//wΪ�յ�
			for(w=0;w<G->placeNum;w++){
				if(D[v][u]+D[u][w]<D[v][w]){
					D[v][w]=D[v][u]+D[u][w];//������С·��
					S[v][w]=S[v][u];//������С·���м䶥�㣬��һ���м��
					//for(i=0;i<G->placeNum;i++)
					//	p[v][w][i] = p[v][u][i]||p[u][w][i];//��ȡ��������֮�����·�������������о�����
				}
			}
		
	}
	while(flag){
		printf("����������صı��:\n");
		scanf("%d",&k);
		printf("������Ŀ�ĵصı��:\n");
		scanf("%d",&j);
		if(k<0||k>=G->placeNum||j<0||j>=G->placeNum){
			printf("������ĵص����ڱ���ͼ��û����ؼ�¼,����������!\n");
		}
		else if(k==j){
			printf("�����غ�Ŀ�ĵ���ͬ,����������!\n");
		}else{
			flag=0;//�������ݺϷ�
			printf("�ӳ����ص�Ŀ�ĵص����(��)·��Ϊ:\n%s",G->placeArray[k].placeName);
			t=S[k][j];
			while(t!=j){
				printf("-->%s",G->placeArray[t].placeName);
				t=S[t][j];
			}
			printf("-->%s\n",G->placeArray[j].placeName);
			printf("��·�߳�Ϊ:%dm\n",D[k][j]);
		}
	}
}


//ѭ����������
void Interface(Graph *G)
{
	int i;
	printf("************���ݵ��ӿƼ���ѧУ԰����ϵͳ************\n");
	printf("\n");
	printf("У԰������Ϣ����\n");
	for(i=0;i<G->placeNum;i++){
		printf("���:%4d ����:%s\n",G->placeArray[i].placeNo,G->placeArray[i].placeName);
	}

	printf("\n");
	printf("*********************����ѡ��***********************\n");
	printf("���������������·��������1\n");
	printf("\n");
	printf("�鿴���������Ϣ������2\n");
	printf("\n");
	printf("�˳�����ϵͳ������3\n");
}

//��ѯ������Ϣ
void SearchInfo(Graph *G){
	int k,flag=1;
	printf("������Ҫ��ѯ�ľ�����\n");
	while(flag){
		scanf("%d",&k);
		if(k<0||k>=G->placeNum){
			printf("�����Ų�����!���������뾰����:\n");
		}else{
			flag=0;
		}
	}
	printf("�þ���������Ϣ����:\n");
	printf("\n");
	printf("���:%4d  ����:%s   ���:%s\n",G->placeArray[k].placeNo,G->placeArray[k].placeName,G->placeArray[k].placeInfo);
	printf("\n");
	printf("\n");
	printf("\n");
}





void main(){
	int c;
	Graph G = InitGraph();
	Interface(&G);
	scanf("%d",&c);
	while(c!=3){
		switch(c){
		case 1:Floyd(&G);Interface(&G);break;
		case 2:SearchInfo(&G);Interface(&G);break;
		case 3:exit(0);break;
		default:break;
		}
		scanf("%d",&c);
	}
}