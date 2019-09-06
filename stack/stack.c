#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 10


typedef int Status;
typedef int Bool;
typedef int ElementType;
typedef struct Node {
    ElementType data[MAXSIZE];
    int top;
}Stack, *StackPtr;
void Visit(ElementType data){
    printf("%d ", data);
}
Status InitStack(StackPtr s){
    s->top = -1;
    return OK;
}
Bool IsEmptyStack(StackPtr s){
    return s->top == -1 ? TRUE : FALSE;
}
Status ClearStack(StackPtr s){
    s->top = -1;
    return OK;
}
int GetStackLength(StackPtr s){
    return s->top + 1;
}
Status GetTop(StackPtr s, ElementType *elm){
    if (s->top == -1) return ERROR;
    *elm = s->data[s->top];
    return OK;
}
Status Push(StackPtr s, ElementType elm){
    if (s->top == MAXSIZE - 1) return ERROR;
    s->top++;
    s->data[s->top] = elm;
    return OK;
}
Status Pop(StackPtr s, ElementType *elm){
    if (s->top == -1) return ERROR;
    *elm = s->data[s->top];
    s->top--;
    return OK;
}
Status Traverse(StackPtr s){
    if (s->top == -1) return ERROR;
    for(int i = 0; i <= s->top; i++){
        Visit(s->data[i]);
    }
    return OK;
}
int main(void){
    Stack s;
    int i, j;
    ElementType elm;
    ElementType top;
    i = InitStack(&s);
    if (i){
        printf("栈初始化成功\n");
        for(j = 1; j <= 10; j++){
            Push(&s, j);
        }
        Traverse(&s);
        Pop(&s, &elm);
        printf("出栈的元素是%d\n", elm);
        Traverse(&s);
        printf("栈中的元素个数是%d\n", GetStackLength(&s));
        GetTop(&s, &top);
        printf("栈顶元素是%d\n", top);
    }
}