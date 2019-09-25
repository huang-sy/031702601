#define _CRT_SECURE_NO_DEPRECATE/*为了消除提示的警告，百度的解决方法，屏蔽警告，不知道这样做行不行，先放着吧*/
#include<iostream>
#include<fstream>
//#include<stdio.h>
using namespace std;
int main(int argc, char *argv[])
{
	int m, n;/*m=3或m=5,n为盘面数*/
	//cin >> m >> n;
	FILE* fp1;
	FILE* fp2;
	m = atoi(argv[2]);
	n = atoi(argv[4]);
	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL)
	{
		return -1;
	}
	
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL)
	{
		return -1;
	}
	fclose(fp2);

	for (int nn = 0; nn < n; nn++)/*nn为盘面的循环次数*/
	{
		int a[9][9], b = 0, i, j;/*每为一个新题都重新变量初始化， b记录此题的待填个数（即空格数）*/
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				//cin >> a[i][j];
				fscanf(fp1, "%d", &a[i][j]);
				if (a[i][j] == 0)
				{
					b++;/*0即空格，b记数*/
				}
			}
		}
		fp2 = fopen("output.txt", "a");
		if (fp2 == NULL)
		{
			return -1;
		}
		for (int as = 0; as < b; as++)/*至多循环b次可填好整个盘面*/
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (a[i][j] == 0)/*找到要填的当前格*/
					{
						int c[18], k = 0;/*一个盘面，一行一列格数和至多为18（2*9）*/
						for (int x = 0; x < m; x++)/*找出当前列里所有已有值，依次放入c[]数组*/
						{
							if (a[x][j] != 0)
							{
								c[k] = a[x][j];
								k++;
							}
						}
						for (int y = 0; y < m; y++)/*找出当前列里所有已有值，依次放入c[]数组，不考虑重复*/
						{
							if (a[i][y] != 0)
							{
								c[k] = a[i][y];
								k++;
							}
						}
						int cc[9] = { 1,2,3,4,5,6,7,8,9 }, cx = m;
						for (int ca1 = 0; ca1 < m; ca1++)/*ca1给cc[]*/
						{
							for (int ca2 = 0; ca2 < k; ca2++)/*ca2给c[]*/
							{
								if (cc[ca1] == c[ca2] && cc[ca1] != 0)/*一个个比较cc[]里的数，若有和c[]数组里一样的则置0,最后cc[]数组中的非零值即是当前格的所有可能取值*/
								{
									cc[ca1] = 0;
									cx--;/*cx记录当前格可能取值的情况数，cc[]有一个置0，cx就减1*/
								}
							}
						}
						if (cx == 1)/*当前格取值情况唯一，即可填入当前格*/
						{
							for (int cs = 0; cs < m; cs++)
							{
								if (cc[cs] != 0)/*找到cc[]里唯一的非0值，赋给当前格a[i][j]*/
								{
									a[i][j] = cc[cs];
								}
							}
						}
					}
				}
			}
		}
		
		
		for (i = 0; i < m; i++)/*输出填好的完整格，m*m*/
		{
			for (j = 0; j < m; j++)
			{
				//cout << a[i][j] << " ";
				fprintf(fp2, "%d", a[i][j]);
				fprintf(fp2, " ");
			}
			//cout << endl;
			fprintf(fp2, "\n");
		}
		//cout << endl;
		fprintf(fp2, "\n");

	}

}