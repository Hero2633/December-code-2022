//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#pragma warning (disable:4996)
// struct MessAge//������Ϣ
//{
//	char CityName[15];//������
//	double S;//�������
//};
//typedef struct MessAge VexType;//�����������ͣ�
//typedef struct AdjNode//�ڽӽڵ�
//{
//	int index;//���ڴ洢��ǰ�ڽӽڵ�ı�ţ�
//	struct AdjNode* next;//�������������ڽӽڵ㣻
//}AdjNode;
//typedef struct AdjHead//����ڵ�
//{
//	//������Ϣ
//	VexType data;
//	//���ӹ�ϵ
//	AdjNode* next;//�������Ӻ����ڽӽڵ�Ĺ�ϵ;
//}AdjHead;
//typedef struct ALGraph//����ͼ
//{
//	AdjHead* list;//���ڿ��ƴ洢���ж�������Ա�
//	int VexNum;//������
//	int ArcNum;//����
//}ALGraph;
//
//ALGraph* CreateALGraph()
//{
//	int n = 0;
//	int e = 0;
//	printf("�����붥����������:");
//	scanf("%d%d",&n,&e);
//	ALGraph* Map = (ALGraph*)malloc(sizeof(ALGraph));//����һ���洢һ��ͼ��Ϣ�Ľṹ��
//	Map->list = (AdjHead*)malloc(sizeof(AdjHead) * n);//����һ���洢��������Ա㣻
//	Map->VexNum = n;
//	Map->ArcNum = e;
//	int i = 0;
//	for (i = 0; i < n; i++)//��ʼ��ÿ���������Ϣ
//	{
//		/*printf("�������������");
//		scanf("%s",Map->list[i].data.CityName);
//		printf("������������:");
//		scanf("%lf",&(Map->list[i].data.S));*/
//		Map->list[i].next = NULL;
//	}
//	printf("������ߵ���Ϣ:");
//	int j = 0;
//	for (j = 0; j < e; j++)
//	{
//		int v1, v2;
//		scanf("%d%d",&v1,&v2);//��������ͼû�з������������Ҫ�����������v1��v2
//		//�������������
//		AdjNode* Node1 = (AdjNode*)malloc(sizeof(AdjNode));
//		Node1->index = v1;
//		Node1->next=NULL;
//		AdjNode* Node2 = (AdjNode*)malloc(sizeof(AdjNode));
//		Node2->index = v2;
//		Node2->next = NULL;
//		//1����(v1,v2)��v2��v1���ڽӽڵ�
//		AdjNode* next = NULL;
//		next=Map->list[v1].next;
//		Map->list[v1].next = Node2;
//		Node2->next = next;
//		//2����v2��v1����v1��v2���ڽӽڵ�
//		next = Map->list[v2].next;
//		Map->list[v2].next = Node1;
//		Node1->next = next;
//	}
//	return Map;
//}
//void PrintALGraph(ALGraph* Map)
//{
//	int i = 0;
//	for (i = 0; i < Map->VexNum; i++)
//	{
//		printf("����[%d]->",i);//�����i���������Ϣ������Ϊ�˼�����������������
//		AdjNode* cur = Map->list[i].next;
//		while (cur)
//		{
//			printf("%d->",cur->index);
//			cur = cur->next;
//		}
//		printf("NULL\n");
//	}
//}
//#define N 10
//struct ColorNode
//{
//	int used;
//	int rear;
//	int Node[N];
//};
//int AdjMatrix1[N][N] = {0};//�ڽӾ���
//char* color[N] = { "��ɫ","��ɫ","��ɫ","��ɫ","��ɫ","��ɫ","��ɫ","��ɫ","��ɫ" };
//char* CityName[N] = { "������","�Ӱ���","������","ͭ����","μ����","������","������","������","������","������" };
//void CreateAdjMatriex(ALGraph* Map)//�����ڽӾ���
//{
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		AdjNode* cur = Map->list[i].next;
//		while (cur)
//		{
//			AdjMatrix1[i][cur->index] = 1;
//			cur = cur->next;
//		}
//	}
//}
//
//bool is_Yes(struct ColorNode*ColorSet,int colorParth,int node)//�ж�node�ڵ��ܷ���colorParth����ɫȾɫ
//{
//	int i = 0;
//	for (i = 0; i < ColorSet[colorParth].rear; i++)
//	{
//		if (AdjMatrix1[node][ColorSet[colorParth].Node[i]])
//			return false;
//	}
//	return true;
//}
//int FindMax(int* degree)//Ѱ�ҽڵ�����Ľڵ�
//{
//	int max = -1;
//	int maxi = 0;
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		if (degree[i] > max)
//		{
//			max = degree[i];
//			maxi = i;
//		}
//	}
//	degree[maxi] = -1;
//	return maxi;
//}
//void Welsh_Powell(ALGraph* Map)
//{
//	CreateAdjMatriex(Map);//�����ڽӾ���
//	int degree[N] = { 0 };//�ռ�ÿ���ڵ�Ķ�
//	int i = 0, j = 0;
//	//����ÿ���ڵ�Ķ�
//	for (i = 0; i < N; i++)
//	{
//		AdjNode* cur = Map->list[i].next;
//		while (cur)
//		{
//			degree[i]++;
//			cur = cur->next;
//		}
//	}
//	//��ɫ��
//	struct ColorNode ColorSet[N] = {0};
//	int k = 0;
//	//��ʼȾɫ
//	for (k = 0; k < N; k++)
//	{
//		int node = FindMax(degree);//Ѱ�ҽڵ�����Ľڵ�
//		int colorParth = 0;
//		while (!is_Yes(ColorSet, colorParth, node))//���node�ڵ��ܷ���colorParth����ɫȾɫ
//			colorParth++;
//		//������˵���ҵ�������ɫ����node������ɫ���У�ͬʱ��Ǹ���ɫ��ʹ�ù�
//		ColorSet[colorParth].Node[ColorSet[colorParth].rear++]=node;
//		ColorSet[colorParth].used = 1;
//	}
//	//��ӡȾɫ���
//	int a = 0;
//	for (a = 0; a < N; a++)
//	{
//		if (ColorSet[a].used)//ֻ��ӡ���õ���ɫ
//		{
//			printf("%s:",color[a]);
//			for (int i = 0; i < ColorSet[a].rear; i++)
//			{
//				printf("%s ",CityName[ColorSet[a].Node[i]]);
//			}
//			printf("\n");
//		}
//	}
//}
//void test1()
//{
//	ALGraph* Map = CreateALGraph();//����һ��ͼ
//	Welsh_Powell(Map);//��ͼȾɫ��������
//}
//int main()
//{
//	test1();
//	return 0;
//}
//struct Node
//{
//	char name[15];
//	int S;
//};
//void Swap(struct Node* City1, struct Node* City2)
//{
//	struct Node  City = *City1;
//	*City1 = *City2;
//	*City2 = City;
//}
//void QuickSort(struct Node* City, int left, int right)
//{
//	if (left >= right)
//		return;
//	int prev = left;
//	int cur = prev + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (City[cur].S < City[keyi].S&&++prev!=cur)
//		{
//			Swap(City+cur,City+prev);
//		}
//		cur++;
//	}
//	Swap(City+prev,City+keyi);
//	QuickSort(City, left, prev - 1);
//	QuickSort(City,prev+1,right);
//
//}
//void test2()
//{
//	struct Node City[] = { {"������",10752},{"������",18117},{"������",10189},
//						{"ͭ����",3882},{"μ����",13030},{"�Ӱ���",37000},
//						{"������",43578},{"������",27000},{"������",23391},
//						{"������",19292} };
//	int len = sizeof(City) / sizeof(City[0]);
//	QuickSort(City, 0, len-1);
//	int i = 0;
//	printf("����ʡ���������������:\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%s %d\n",City[i].name,City[i].S);
//	}
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}