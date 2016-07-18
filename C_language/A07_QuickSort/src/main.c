/*
	Purpose:
			quick sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InputArr(int*, int);
void ShowData(int*, int);
void QuickSort(int*, int, int, int);

int gProcess = 0;

int main(int argc, char *argv[])
{
	int size, data[100] = {0};
	srand((unsigned)time(NULL));
	printf("please input size of array(under 100): ");
	scanf("%d", &size);
	printf("your input data are: ");
	InputArr(data, size);
	ShowData(data, size);
	QuickSort(data, size, 0, size-1);
	printf("the sort result: ");
	ShowData(data, size);
	return 0;
}

void InputArr(int data[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		data[i] = (rand()%99) + 1;
	}
}

void ShowData(int data[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void QuickSort(int d[], int size, int left, int right)
{
	int i, j, tmp;
	int leftIndex, rightIndex;
	int t;
	
	//step1: the first key is d[left]
	if(left < right)
	{
		leftIndex = left + 1;
		rightIndex = right;
step2:
		printf("[process %d] => ", gProcess++);
		for(t=0; t<size; t++)
		{
			printf("[%2d]", d[t]);
		}
		printf("\n");
		//step2: find a key bigger than d[left] from left to right
		for(i=left+1; i<=right; i++)
		{
			if(d[i] >= d[left])
			{
				leftIndex = i;
				break;
			}
			leftIndex++;
		}
		//step3: find a key smaller than d[left] from right to left
		for(j=right; j>=left+1; j--)
		{
			if(d[j] <= d[left])
			{
				rightIndex = j;
				break;
			}
			rightIndex--;
		}
		//step4-1: if leftIndex < rightIndex, then swap d[leftIndex] and d[rightIndex]
		if(leftIndex < rightIndex)
		{
			tmp = d[leftIndex];
			d[leftIndex] = d[rightIndex];
			d[rightIndex] = tmp;
			goto step2;//step4-2: goto step2
		}
		//step5-1: if leftIndex >= rightIndex, then swap d[left] and d[rightIndex]
		if(leftIndex >= rightIndex)
		{
			tmp = d[left];
			d[left] = d[rightIndex];
			d[rightIndex] = tmp;
			
			/*step5-2: cut in half with base point rightIndex,
						until finished the sort*/
			QuickSort(d, size, left, rightIndex-1);
			QuickSort(d, size, rightIndex+1, right);
		}
	}
}