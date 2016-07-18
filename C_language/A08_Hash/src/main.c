/*
	Purpose:
			Hashing
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INDEX_BOX	7
#define MAX_NUM		13

void CreateTable(int);
void PrintData(int);
int FindNum(int);

struct list
{
	int val;
	struct list *next;
};
typedef struct list node;
typedef node *link;

node indexTable[INDEX_BOX];

int main(int argc, char *argv[])
{
	int i, num, data[MAX_NUM];
	srand((unsigned)time(NULL));
	for(i=0; i<INDEX_BOX; i++)//clear hashing table
	{
		indexTable[i].val = i;
		indexTable[i].next = NULL;
	}
	printf("source data : \n\t");
	for(i=0; i<MAX_NUM; i++)
	{
		data[i] = rand()%99+1;//create data with rand()
		printf("[%2d]", data[i]);//print data
		if(i%8 == 7)
			printf("\n\t");
	}
	printf("\n");
	for(i=0; i<MAX_NUM; i++)
	{
		CreateTable(data[i]);//create hashing table
	}
	while(1)
	{
		printf("please input search data(1-99), input -1 to exit: ");
		scanf("%d", &num);
		if(num == -1)
			break;
		i = FindNum(num);
		if(i == 0)
			printf("### data not found %d ###\n", num);
		else
			printf("find data %d, total find %d times\n", num, i);
	}
	printf("\nHashing table: \n");
	for(i=0; i<INDEX_BOX; i++)
		PrintData(i);
	printf("\n");
	return 0;
}

void CreateTable(int val)
{
	link newNode;
	int hash;
	hash = val % 7;//hashing function
	newNode = (link)malloc(sizeof(node));
	if(!newNode)
	{
		printf("Error! memory malloc failed.\n");
		exit(1);
	}
	newNode->val = val;
	newNode->next = NULL;
	newNode->next = indexTable[hash].next;//add node
	indexTable[hash].next = newNode;
}

void PrintData(int val)
{
	link head;
	int i = 0;
	head = indexTable[val].next;//head point
	printf(" %2d : \t", val);//index address
	while(head != NULL)
	{
		printf("[%2d] - ", head->val);
		i++;
		if(i%8 == 7)//length control
			printf("\n\t");
		head = head->next;
	}
	printf("\b\n");//clear last '-' symbol
}

int FindNum(int num)//hash search
{
	link ptr;
	int i=0, hash;
	hash = num % 7;
	ptr = indexTable[hash].next;
	while(ptr != NULL)
	{
		i++;
		if(ptr->val == num)
			return i;
		else
			ptr = ptr->next;
	}
	return 0;
}