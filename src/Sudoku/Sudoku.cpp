#define _CRT_SECURE_NO_DEPRECATE/*Ϊ��������ʾ�ľ��棬�ٶȵĽ�����������ξ��棬��֪���������в��У��ȷ��Ű�*/
#include<iostream>
#include<fstream>
//#include<stdio.h>
using namespace std;
int main(int argc, char *argv[])
{
	int m, n;/*m=3��m=5,nΪ������*/
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

	for (int nn = 0; nn < n; nn++)/*nnΪ�����ѭ������*/
	{
		int a[9][9], b = 0, i, j;/*ÿΪһ�����ⶼ���±�����ʼ���� b��¼����Ĵ�����������ո�����*/
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				//cin >> a[i][j];
				fscanf(fp1, "%d", &a[i][j]);
				if (a[i][j] == 0)
				{
					b++;/*0���ո�b����*/
				}
			}
		}
		fp2 = fopen("output.txt", "a");
		if (fp2 == NULL)
		{
			return -1;
		}
		for (int as = 0; as < b; as++)/*����ѭ��b�ο������������*/
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (a[i][j] == 0)/*�ҵ�Ҫ��ĵ�ǰ��*/
					{
						int c[18], k = 0;/*һ�����棬һ��һ�и���������Ϊ18��2*9��*/
						for (int x = 0; x < m; x++)/*�ҳ���ǰ������������ֵ�����η���c[]����*/
						{
							if (a[x][j] != 0)
							{
								c[k] = a[x][j];
								k++;
							}
						}
						for (int y = 0; y < m; y++)/*�ҳ���ǰ������������ֵ�����η���c[]���飬�������ظ�*/
						{
							if (a[i][y] != 0)
							{
								c[k] = a[i][y];
								k++;
							}
						}
						int cc[9] = { 1,2,3,4,5,6,7,8,9 }, cx = m;
						for (int ca1 = 0; ca1 < m; ca1++)/*ca1��cc[]*/
						{
							for (int ca2 = 0; ca2 < k; ca2++)/*ca2��c[]*/
							{
								if (cc[ca1] == c[ca2] && cc[ca1] != 0)/*һ�����Ƚ�cc[]����������к�c[]������һ��������0,���cc[]�����еķ���ֵ���ǵ�ǰ������п���ȡֵ*/
								{
									cc[ca1] = 0;
									cx--;/*cx��¼��ǰ�����ȡֵ���������cc[]��һ����0��cx�ͼ�1*/
								}
							}
						}
						if (cx == 1)/*��ǰ��ȡֵ���Ψһ���������뵱ǰ��*/
						{
							for (int cs = 0; cs < m; cs++)
							{
								if (cc[cs] != 0)/*�ҵ�cc[]��Ψһ�ķ�0ֵ��������ǰ��a[i][j]*/
								{
									a[i][j] = cc[cs];
								}
							}
						}
					}
				}
			}
		}
		
		
		for (i = 0; i < m; i++)/*�����õ�������m*m*/
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