#include <stdio.h>
#include <stdlib.h>

/*
二叉树遍历(先序遍历、中序遍历、后序遍历)
说明： 二叉树遍历(先序遍历、中序遍历、后序遍历)
*/

typedef struct BTreeNode
{
	char data;
	struct BTreeNode *lchild;
	struct BTreeNode *rchild;
}BTreeNode,*BTree;

void CreateBnaryTree(BTree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else
	{
		*T=(BTree)malloc(sizeof(BTreeNode));
		(*T)->data=ch;
		CreateBnaryTree(&((*T)->lchild));
		CreateBnaryTree(&((*T)->rchild));		
	}	
}

//先序遍历 
void PreOrderTraverse(BTree T)
{
	if(T==NULL)
		return;
	else
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);	
	}
}
//中序遍历 
void InOrderTraverse(BTree T)
{
	if(T==NULL)
		return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历 
void PostOrderTraverse(BTree T)
{
	if(T==NULL)
		return;
	else
	{
		PostOrderTraverse(T->lchild);		
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}

int main(int argc, char *argv[]) 
{
	BTree T;
	printf("请创建一棵二叉树:\n");
	CreateBnaryTree(&T);
	printf("\n先序遍历的结果为：\n");
	PreOrderTraverse(T);
	printf("\n中序遍历的结果:\n");
	InOrderTraverse(T);
	printf("\n后序遍历的结果:\n");
	PostOrderTraverse(T); 
	return 0;
}
