////#include<stdio.h>
////#define N 17
////#pragma warning (disable:4996)
////typedef struct
////{
////	char VA[N];
////	int AdjMatrix[N][N];
////	int VexN, EdgeN;
////}AM_Graph;
////void creat1(AM_Graph* gPtr)
////{
////	int i, j, k;
////	getchar();
////	printf("������%d�����㣺", gPtr->VexN);
////	for (i = 0; i < gPtr->VexN; i++)
////		scanf("%c", &gPtr->VA[i]);
////	for (i = 0; i < gPtr->VexN; i++)
////		for (j = 0; j < gPtr->VexN; j++)
////			gPtr->AdjMatrix[i][j] = 0;
////	printf("�����ڽӵ����������±꣺\n");
////	for (k = 0; k < gPtr->EdgeN; k++)
////	{
////		scanf_s("%d%d", &i, &j);
////		gPtr->AdjMatrix[i][j] = 1;
////		gPtr->AdjMatrix[j][i] = 1;
////	}
////}
////void print(AM_Graph* gPtr)
////{
////	int i, j;
////	printf("�����ú������ͼ���ڽӾ���Ϊ��\n");
////	for (i = 0; i < gPtr->VexN; i++)
////	{
////		printf("%c", gPtr->VA[i]);
////		for (j = 0; j < gPtr->VexN; j++)
////		printf("%d ", gPtr->AdjMatrix[i][j]);
////		printf("\n");
////	}
////}
////int main()
////{
////	AM_Graph Graph;
////	printf("�����붥�����ͱ�����");
////	scanf_s("%d%d", &Graph.VexN, &Graph.EdgeN);
////	creat1(&Graph);
////	print(&Graph);
////	return 0;
////}
//#include<stdio.h>
//#include<stdlib.h>
//#define N 10
//#pragma warning (disable:4996)
//typedef struct
//{
//	char VA[N];
//	int AdjMatrix[N][N];
//	int VexN, EdgeN;
//}AM_Graph;
//void creat(AM_Graph* gPtr)
//{
//	int i, j, k;
//	getchar();
//	printf("������%d�����㣺", gPtr->VexN);
//	for (i = 0; i < gPtr->VexN; i++)
//		scanf("%c", &gPtr->VA[i]);
//	for (i = 0; i < gPtr->VexN; i++)
//		for (j = 0; j < gPtr->VexN; j++)
//			gPtr->AdjMatrix[i][j] = 0;
//	printf("�����ڽӵ����������±꣺\n");
//	for (k = 0; k < gPtr->EdgeN; k++)
//	{
//		scanf("%d%d", &i, &j);
//		gPtr->AdjMatrix[i][j] = 1;
//		gPtr->AdjMatrix[j][i] = 1;
//	}
//}
//void print(AM_Graph* gPtr)
//{
//	int i, j;
//	printf("�����ú������ͼ���ڽӾ���Ϊ��\n");
//	for (i = 0; i < gPtr->VexN; i++)
//	{
//		printf("%c", gPtr->VA[i]);
//		for (j = 0; j < gPtr->VexN; j++)
//			printf("%d  ", gPtr->AdjMatrix[i][j]);
//		printf("\n");
//	}
//}
//void MapColor(int (*AdjMatrix)[N][N], int s[N])
//{
//	int color, area, m;
//	s[0] = 1;
//	area = 1;
//	color = 1;
//	while (area < N)
//	{
//
//		while (color <= 4)
//		{
//			if (area >= N)
//				break;
//			m = 0;
//			while ((m < area) && (s[m] * AdjMatrix[area][m] != color))
//				m++;
//			if (m < area)
//				color++;
//			else
//			{
//				s[area] = color;
//				area++;
//				color = 1;
//			}
//		}
//		if (color > 4)
//		{
//			area = area - 1;
//			color = s[area] + 1;
//		}
//
//	}
//}
//int main()
//{
//	AM_Graph Graph;
//	printf("�����붥�����ͱ�����");
//	scanf("%d%d", &Graph.VexN, &Graph.EdgeN);
//	creat(&Graph);
//	print(&Graph);
//	int s[N] = { 0 };
//	MapColor(Graph.AdjMatrix, s[N]);
//	printf("��ͼ������Ϊ1~17����ɫ���Ϊ��");
//	for (int i = 0; i < N; i++)
//		printf("%d ", s[i]);
//}