/*
	Purpose:
			double linked list
			not finished.
*/
#include <stdio.h>
#include <stdlib.h>

struct _NODE
{
	int data;
	struct _NODE* leftLink;
	struct _NODE* rightLink;
};

typedef struct _NODE node;
typedef node* link;
typedef node* _insertAfter;
typedef node* _delete;

_HEAD CreateDouble(int* arr, int num);
_HEAD Insert(_HEAD head, _insertAfter ptr, int nVal);
_HEAD Delete(_HEAD head, _DELETE del);

int main(int argc, char *argv[])
{

	return 0;
}

_HEAD CreateDouble(int* arr, int num)
{
	link leftLinkNode = NULL;
	link pNewNode = NULL;
	int i = 0;
	_HEAD head = (_HEAD)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("memory malloc failed.\n");
		return NULL;
	}
	else
	{
		memset(head, 0, sizeof(node));
		head->data = *(arr+0);
		leftLinkNode = head;
		for(i=1; i<num; i++)
		{
			pNewNode = (link)malloc(sizeof(node));
			memset(pNewNode, 0, sizeof(node));
			pNewNode->data = *(arr+0);
			leftLinkNode->rightLink = pNewNode;
			pNewNode->leftLink = leftLinkNode;
			leftLinkNode = pNewNode;
		}
	}
	return head;
}

_HEAD Insert(_HEAD head, _insertAfter ptr, int nVal)
{
	link pNewNode = (link)malloc(sizeof(node));
	_HEAD pNewHead = (link)malloc(sizeof(node));
	memset(pNewNode, 0, sizeof(node));
	pNewNode->data = nVal;
	if(head == NULL)//empty double list
	{
		memset(pNewHead, 0, sizeof(node));
		pNewHead->data = nVal;
		return pNewHead;
	}
	else
	{
		if(ptr == NULL)
		{
			printf("error: ptr is not node of list\n")
		}
		if(ptr == head)//insert head list
		{
			head = head->rightLink;
			head->leftLink = pNewNode;
			pNewNode->rightLink = head;
			head = pNewNode;
		}
		else
		{
			if(ptr->rightLink == NULL)//insert last list
			{
				ptr->rightLink = pNewNode;
				pNewNode->leftLink = ptr;
			}
			else//insert middle list
			{
				pNewNode->rightLink = ptr->rightLink;
				ptr->rightLink->leftLink = pNewNode;
				ptr->rightLink = pNewNode;
				pNewNode->leftLink = ptr;
			}
		}
	}
	return head;
}

_HEAD Delete(_HEAD head, _DELETE del)
{
	if(head == NULL)
	{
		printf("empty list.\n");
		return NULL;
	}
	if(del == NULL)
	{
		printf("error: cat not delete node in list\n");
		return NULL;
	}
	if(del == head)//delete head list
	{
		head = head->rightLink;
		head->leftLink = NULL;
	}
	else
	{
		if(del->rightLink == NULL)//delete last list
		{
			del->leftLink->rightLink = NULL;
		}
		else//delete middle list
		{
			del->leftLink->rightLink = del->rightLink;
			del->rightLink->leftLink = del->leftLink;
		}
	}
	free(del);
	return head;
}