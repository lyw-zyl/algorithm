#include<stdio.h>
#include<string.h>
int main() {
	int objnumber,i,j,sumT=0,suma=0,sumb=0,sumbefore;
	int a[100],mechinea[100],mechineb[100];

	printf("请输入任务个数：");
	scanf("%d", &objnumber);
	fflush(stdin);

	printf("请输入每个任务所需时间：", objnumber);
	for (i = 0; i < objnumber; i++) {
		scanf("%d", &a[i]);
		sumT = sumT + a[i];
	}

	for (i = 0; i < objnumber-1; i++)
	{
		for (j = 0; j < objnumber-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < objnumber; ) {
		for (j = 0; j <= i; j++) {
			mechinea[j] = a[j];
			suma = suma + mechinea[j];
		}
		for (j = i+1; j < objnumber; j++) {
			mechineb[j] = a[j];
			sumb = sumb + mechineb[j];
		}
		if (suma < sumb) {
			sumT = sumb;
			sumbefore = sumT;
			i++;
			memset(mechinea, 0, 100);
			memset(mechineb, 0, 100);
			suma = 0;
			sumb = 0;
		}
		else if (suma == sumb) {
			printf("最短时间是：%d", suma);
		}
		else {
			sumT = suma;
			if (suma > sumbefore) {
				printf("最短时间是：%d", sumbefore);
				return 0;
			}
			else {
				printf("最短时间是：%d", suma);
				return 0;
			}	
		}
	}
}