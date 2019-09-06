#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int ElementType;
typedef int Bool;
typedef struct Node {
    ElementType data[MAXSIZE];
    int top;
    int tail;
}Stack, *StackPtr;
void Visit(ElementType elm){
    printf("%d ", elm);
}
Status InitStack(StackPtr s){
    s->top = -1;
    s->tail = MAXSIZE;
    return OK;
}
Bool IsEmptyStack(StackPtr s){
    if (s->top == -1 || s->tail == MAXSIZE) {
        return TRUE;
    } else{
        return FALSE;
    }
}
Status ClearStack(StackPtr s){
    s->top = -1;
    s->tail = MAXSIZE;
    return OK;
}
int GetStackLength(StackPtr s){
    return (s->top + 1) + (MAXSIZE - s->tail);
}

Status Push(StackPtr s, ElementType elm, int stack_num){
    if (s->top - s->tail == 1) return ERROR;
    if (stack_num == 1){
        s->top++;
        s->data[s->top] = elm;

    } else if (stack_num == 2){
        s->tail--;
        s->data[s->tail] = elm;
    }
    return TRUE;
}
Status Pop(StackPtr s, int stack_num, ElementType *elm){
    if (stack_num == 1){
        if (s->top == -1) return ERROR;
        *elm = s->data[s->top];
        s->top--;
    } else if (stack_num == 2){
        if (s->tail == MAXSIZE) return ERROR;
        *elm = s->data[s->tail];
        s->tail++;
    }
    return OK;
}
Status TraverseStack(StackPtr s, int stack_num){
    int i;
    i = 0;
    while (i <= s->top){
        Visit(s->data[i]);
        i++;
    }
    printf("\n");
    i = s->tail;
    while (i < MAXSIZE){
        Visit(s->data[i]);
        i++;
    }
    return OK;
}

int main(void){
    //使用一个数组实现两个栈的空间共享
    Stack s;
    if (InitStack(&s)){
        printf("初始化成功\n");
        printf("是否为空栈，1为空栈，0为非空栈 =>%d\n", IsEmptyStack(&s));
        printf("分别向两个栈中加入数字\n");
        for(int i = 1; i <= 10; i++){
            if (i % 2 == 0){
                Push(&s, i, 1);
            } else{
                Push(&s, i, 2);
            }
        }

        printf("是否为空栈，1为空栈，0为非空栈 =>%d\n", IsEmptyStack(&s));
        printf("栈的长度是%d\n", GetStackLength(&s));

        printf("遍历栈1\n");
        TraverseStack(&s, 1);
        printf("-----------------\n");
        printf("遍历栈2\n");
        TraverseStack(&s, 2);
        printf("-----------------\n");
        printf("清空栈\n");
        ClearStack(&s);
        printf("栈的长度是%d\n", GetStackLength(&s));

    }
    return 0;
}