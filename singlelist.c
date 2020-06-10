#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List* next;
}list;

list * initlist(){
	int i;
	list * temp = (list*)malloc(sizeof(list));
	list * p = temp;
	for(i=1;i<=5;i++){
		list * new = (list*)malloc(sizeof(list));
		new->data = i;
		new->next = NULL;
		temp->next = new;
		temp = temp->next; //临时节点循环指向下一个
	}
	return p;
}

void display(list * p){
	list * temp = p;
	while(temp){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

list * insertlist(list *p,int afterdata,int insertdata){
	list *temp = p;
	list * newlist =(list *)malloc(sizeof(list));
	while(temp){
		temp = temp->next;
		if(temp->data == afterdata){
			newlist->data = insertdata;
			newlist->next = temp->next;
			temp->next = newlist;
			break;
		}
	}
	return p;
}

list * dellist(list *p ,int deldata){
	list * temp = p;
	while(temp){
		temp = temp->next;
		if(temp->next->data == deldata){
			break;
		}
	}
	list * del= temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
	free(del);
	return p;
}

list * fliplist(list *p){
	list * newHead = NULL;
	list * dolist = p;
	list * node = (list *)malloc(sizeof(list));
	while(dolist){
	 //1. 对之前的链表做头删
	 node = dolist;
	 dolist = dolist->next;//用于循环到下一节点
	 //2. 对新链表做头插
	 node->next = newHead;
	 newHead = node;
	}
	return newHead;
}

void main (){
	list * listtest = initlist();
	display(listtest);
	list * listafterinsert = insertlist(listtest,3,99);
	display(listafterinsert); 	
	list * afertdellist = dellist(listafterinsert,3);
	display(afertdellist);
	list * flip = fliplist(afertdellist);
	display(flip);
}
