#include <stdio.h>
#include <stdlib.h>
typedef struct lineStack{
    int data;
    struct lineStack * next;
}lineStack;
lineStack* push(lineStack * stack,int a){
    lineStack * line=(lineStack*)malloc(sizeof(lineStack));
    line->data=a;
    line->next=stack;
    stack=line;
    return stack;
}
lineStack * pop(lineStack * stack){
    if (stack) {
        lineStack * p=stack;
        stack=stack->next;
        printf("弹栈元素：%d ",p->data);
        if (stack) {
            printf("栈顶元素：%d\n",stack->data);
        }else{
            printf("栈已空\n");
        }
        free(p);
    }else{
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}
int main() {
    lineStack * stack=NULL;
    stack=push(stack, 1);
    stack=push(stack, 2);
    stack=push(stack, 3);
    stack=push(stack, 4);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}
