#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List* next;
}list;

list * initlisthead(){ //头插法初始化
	list* p;
        list* temp = (list*)malloc(sizeof(list));
        temp->next = NULL;
        int n;
        for(n=2;n<6;n++){
                 p = (list*)malloc(sizeof(list));
                 p->data = n;
                 p->next = temp->next;
                 temp->next = p;
	}
	return p;
}

list * initlistheadsimplify(){ //头插法初始化简化版
	list* p = (link*)malloc(sizeof(list));
	int n;
	for(n=1;n<10;n++){
		link* temp = (list*)malloc(sizeof(list));
		temp->data = n;
		temp->next = p;
		p = temp;
	}
	return p;
}

list * initlist(){
	list* p = (link*)malloc(sizeof(list));
	p = NULL;
	link* temp = (list*)malloc(sizeof(list));
	temp->data = 1;
	temp->next = NULL;
	p = temp;
	int n;
	for(n=2;n<6;n++){
		link* a = (list*)malloc(sizeof(list));
		a->data = n;
		a->next = NULL;
		temp->next = a;
		temp = temp->next; 
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
