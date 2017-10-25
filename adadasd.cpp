#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<malloc.h>

int main()
{
	int *data;
	int *score;
	int i = 0;
	int j = 0;
	int sum;
	int  N;

	printf("输入轮数\n");//令轮数与学生个数相同；
	scanf("%d", &N);

	printf("\n");


	data = (int*)malloc(sizeof(int)*N);
	score = (int*)malloc(sizeof(int)*N);

	memset(score, 0, sizeof(int)*N);

	srand(time(NULL));

	int flag = N;
	while (flag--){

		memset(data, 0, sizeof(int)*N);

		sum = 0;

		for (i = 0; i<N; i++)
		{
			data[i] = (int)rand() % 100;
			sum += data[i];
		}

		double Point = 1.0*sum / N*0.618;//黄金分割点;

		int max = 0;
		int min = 0;

		for (j = 0; j<N; j++)
		{

			if (fabs(data[j] - Point)<fabs(data[max] - Point))//求最远;
			{
				max = max;
			}
			else
			{
				max = j;
			}

			if (fabs(data[j] - Point)<fabs(data[min] - Point))//求最近;
			{
				min = j;
			}
			else {
				min = min;
			}

		}

		score[max] -= 2;//最远
		score[min] += N;//最近

		printf("每次结果如下：\n");
		printf("随机数：");

		for (i = 0; i<N; i++)
			printf("%d ", data[i]);
		printf(" 分割点  %.3lf\n", Point);
		printf("第%d次分数", N - flag);

		for (i = 0; i<N; i++)
			printf("%d ", score[i]);
		printf("\n");
	}


	printf("\n最终分数:\n");


	for (i = 0; i<N; i++)
	{
		printf("玩家%d  ", i + 1);
	}
	printf("\n");
	for (j = 0; j<N; j++)
	{
		printf("  %d    ", score[j]);
	}


	return 0;
}
