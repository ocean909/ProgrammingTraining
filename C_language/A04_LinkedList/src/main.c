/*
	Purpose:
			linked list
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list
{
	int num, score;
	char name[10];
	struct list *next;
};

typedef struct list node;
typedef node *link;//what's mean?
link del_ptr(link head, link ptr);

int main(int argc, char *argv[])
{
	link head, ptr, newnode;
	int i, j, findscore = 0, find, data[12][2];
	char namedata[12][10] = {{"Allen"}, {"Scott"}, {"Mary"}, {"Jon"}, {"Mark"}, {"Ricky"}, {"Lisa"}, {"Jasica"}, {"Hanson"}, {"Amy"}, {"Bob"}, {"Jack"}};
	
	srand((unsigned)time(NULL));
	printf("Number score Number score Number score Number score\n");
	printf("===================================================\n");
	for(i=0; i<12; i++)
	{
		data[i][0] = i + 1;//set number 1~12
		data[i][1] = rand()%50 + 51;//set score 51~100
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			//print number and score
			printf("[%2d][%3d] ", data[j*3+i][0], data[j*3+i][1]);
		}
		printf("\n");
	}
	
	head = (link)malloc(sizeof(node));//create list head
	if(!head)
	{
		printf("Error!! memory malloc failed!!\n");
		exit(1);
	}
	
	head->num = data[0][0];
	for(j=0; j<10; j++)
	{
		head->name[j] = namedata[0][j];
	}
	head->score = data[0][1];
	head->next = NULL;
	ptr = head;
	for(i=1; i<12; i++)//cteate list
	{
		newnode = (link)malloc(sizeof(node));
		newnode->num = data[i][0];
		for(j=0; j<10; j++)
		{
			newnode->name[j] = namedata[i][j];
		}
		newnode->score = data[i][1];
		newnode->next = NULL;
		ptr->next = newnode;
		ptr = ptr->next;
	}
	
	while(1)
	{
		printf("please input score of deleted, enter -1 to exit : ");
		scanf("%d", &findscore);
		if(findscore == -1)//exit loop
		{
			break;
		}
		else
		{
			ptr = head;
			find = 0;
			while(ptr != NULL)
			{
				if(ptr->score == findscore)
				{
					ptr = del_ptr(head, ptr);//delete data
					find++;
				}
				ptr = ptr->next;
			}
			if(find == 0)
			{
				printf("##### score not find #####\n");
			}
		}
	}
	
	//print remain list data
	ptr = head;
	printf("\n\tNumber\t  Name\tScore\n");
	printf("===========================================\n");
	while(ptr != NULL)
	{
		printf("\t[%2d]\t[%10s]\t[%3d]\n", ptr->num, ptr->name, ptr->score);
		ptr = ptr->next;
	}
	
	return 0;
}

link del_ptr(link head, link ptr)
{
	link top;
	top = head;
	if(ptr == head)//[case 1]delete head list
	{
		head = head->next;
		printf("has been deleted the student of number %d !!name: %s\n", ptr->num, ptr->name);
	}
	else
	{
		while(top->next != ptr)//find the front of deleted position
		{
			top = top->next;
		}
		
		if(ptr->next == NULL)//[case 2]delete last list
		{
			top->next = NULL;
			printf("has been deleted the student of number %d !!name: %s\n", ptr->num, ptr->name);
		}
		else//[case 3]normal case
		{
			top->next = ptr->next;
			printf("has been deleted the student of number %d !!name: %s\n", ptr->num, ptr->name);
		}
	}
	return head;
}

#if 0
NODE* Insert(NODE* head, NODE* ptr, int nVal)
{
	NODE* insertNode;
	insertNode = (NODE*)malloc(sizeof(NODE));
	if(insertNode == NULL)
	{
		printf("memory malloc failed.\n");
		return ;
	}
	insertNode->pNext = NULL;
	insertNode->Data = nVal;
	
	if(ptr == NULL)//insert first node
	{
		insertNode->pNext = head;
		head = insertNode;
	}
	else
	{
		if(ptr->pNext == NULL)//insert last node
		{
			ptr->pNext = insertNode;
		}
		else//insert middle node
		{
			insertNode->pNext = ptr->pNext;
			ptr->pNext = insertNode;
		}
	}
	return head;
}
#endif