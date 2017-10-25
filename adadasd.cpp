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

	printf("��������\n");//��������ѧ��������ͬ��
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

		double Point = 1.0*sum / N*0.618;//�ƽ�ָ��;

		int max = 0;
		int min = 0;

		for (j = 0; j<N; j++)
		{

			if (fabs(data[j] - Point)<fabs(data[max] - Point))//����Զ;
			{
				max = max;
			}
			else
			{
				max = j;
			}

			if (fabs(data[j] - Point)<fabs(data[min] - Point))//�����;
			{
				min = j;
			}
			else {
				min = min;
			}

		}

		score[max] -= 2;//��Զ
		score[min] += N;//���

		printf("ÿ�ν�����£�\n");
		printf("�������");

		for (i = 0; i<N; i++)
			printf("%d ", data[i]);
		printf(" �ָ��  %.3lf\n", Point);
		printf("��%d�η���", N - flag);

		for (i = 0; i<N; i++)
			printf("%d ", score[i]);
		printf("\n");
	}


	printf("\n���շ���:\n");


	for (i = 0; i<N; i++)
	{
		printf("���%d  ", i + 1);
	}
	printf("\n");
	for (j = 0; j<N; j++)
	{
		printf("  %d    ", score[j]);
	}


	return 0;
}
