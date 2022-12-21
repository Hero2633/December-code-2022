//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#pragma warning (disable:4996)
// struct MessAge//顶点信息
//{
//	char CityName[15];//城市名
//	double S;//城市面积
//};
//typedef struct MessAge VexType;//顶点数据类型；
//typedef struct AdjNode//邻接节点
//{
//	int index;//用于存储当前邻接节点的标号；
//	struct AdjNode* next;//用于链接其它邻接节点；
//}AdjNode;
//typedef struct AdjHead//顶点节点
//{
//	//顶点信息
//	VexType data;
//	//链接关系
//	AdjNode* next;//用于链接和其邻接节点的关系;
//}AdjHead;
//typedef struct ALGraph//整个图
//{
//	AdjHead* list;//用于控制存储所有顶点的线性表；
//	int VexNum;//顶点数
//	int ArcNum;//边数
//}ALGraph;
//
//ALGraph* CreateALGraph()
//{
//	int n = 0;
//	int e = 0;
//	printf("请输入顶点数，边数:");
//	scanf("%d%d",&n,&e);
//	ALGraph* Map = (ALGraph*)malloc(sizeof(ALGraph));//创建一个存储一个图信息的结构体
//	Map->list = (AdjHead*)malloc(sizeof(AdjHead) * n);//创建一个存储顶点的线性便；
//	Map->VexNum = n;
//	Map->ArcNum = e;
//	int i = 0;
//	for (i = 0; i < n; i++)//初始化每个顶点的信息
//	{
//		/*printf("请输入城市名：");
//		scanf("%s",Map->list[i].data.CityName);
//		printf("请输入城市面积:");
//		scanf("%lf",&(Map->list[i].data.S));*/
//		Map->list[i].next = NULL;
//	}
//	printf("请输入边的信息:");
//	int j = 0;
//	for (j = 0; j < e; j++)
//	{
//		int v1, v2;
//		scanf("%d%d",&v1,&v2);//由于无向图没有方向，因此我们需要对输入进来的v1，v2
//		//分两种情况链接
//		AdjNode* Node1 = (AdjNode*)malloc(sizeof(AdjNode));
//		Node1->index = v1;
//		Node1->next=NULL;
//		AdjNode* Node2 = (AdjNode*)malloc(sizeof(AdjNode));
//		Node2->index = v2;
//		Node2->next = NULL;
//		//1、以(v1,v2)，v2是v1的邻接节点
//		AdjNode* next = NULL;
//		next=Map->list[v1].next;
//		Map->list[v1].next = Node2;
//		Node2->next = next;
//		//2、（v2，v1），v1是v2的邻接节点
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
//		printf("顶点[%d]->",i);//输出第i个顶点的信息，这里为了简便我们用序号来代替
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
//int AdjMatrix1[N][N] = {0};//邻接矩阵
//char* color[N] = { "红色","橙色","黄色","绿色","青色","蓝色","紫色","黑色","白色" };
//char* CityName[N] = { "榆林市","延安市","咸阳市","铜川市","渭南市","宝鸡市","西安市","商洛市","汉中市","安康市" };
//void CreateAdjMatriex(ALGraph* Map)//创建邻接矩阵
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
//bool is_Yes(struct ColorNode*ColorSet,int colorParth,int node)//判断node节点能否用colorParth项颜色染色
//{
//	int i = 0;
//	for (i = 0; i < ColorSet[colorParth].rear; i++)
//	{
//		if (AdjMatrix1[node][ColorSet[colorParth].Node[i]])
//			return false;
//	}
//	return true;
//}
//int FindMax(int* degree)//寻找节点度最大的节点
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
//	CreateAdjMatriex(Map);//创建邻接矩阵
//	int degree[N] = { 0 };//收集每个节点的度
//	int i = 0, j = 0;
//	//计算每个节点的度
//	for (i = 0; i < N; i++)
//	{
//		AdjNode* cur = Map->list[i].next;
//		while (cur)
//		{
//			degree[i]++;
//			cur = cur->next;
//		}
//	}
//	//颜色集
//	struct ColorNode ColorSet[N] = {0};
//	int k = 0;
//	//开始染色
//	for (k = 0; k < N; k++)
//	{
//		int node = FindMax(degree);//寻找节点度最大的节点
//		int colorParth = 0;
//		while (!is_Yes(ColorSet, colorParth, node))//检查node节点能否用colorParth项颜色染色
//			colorParth++;
//		//到这里说明找到合适颜色，将node放入颜色集中，同时标记该颜色被使用过
//		ColorSet[colorParth].Node[ColorSet[colorParth].rear++]=node;
//		ColorSet[colorParth].used = 1;
//	}
//	//打印染色结果
//	int a = 0;
//	for (a = 0; a < N; a++)
//	{
//		if (ColorSet[a].used)//只打印被用的颜色
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
//	ALGraph* Map = CreateALGraph();//创建一个图
//	Welsh_Powell(Map);//对图染色并输出结果
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
//	struct Node City[] = { {"西安市",10752},{"宝鸡市",18117},{"咸阳市",10189},
//						{"铜川市",3882},{"渭南市",13030},{"延安市",37000},
//						{"榆林市",43578},{"汉中市",27000},{"安康市",23391},
//						{"商洛市",19292} };
//	int len = sizeof(City) / sizeof(City[0]);
//	QuickSort(City, 0, len-1);
//	int i = 0;
//	printf("陕西省各行政区面积排名:\n");
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