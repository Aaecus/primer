#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Bool;
typedef char ElementType;
typedef struct Node {
    struct Node *next;
    ElementType data;
}Node, *NodePtr;
typedef struct Stack {
    Node s;
    int length;
}Stack, *StackPtr;

void Visit(ElementType ch){
    printf("%c ", ch);
}
Status InitStack(StackPtr stack){
    (stack->s).next = NULL;
    stack->length = 0;
    return OK;
}
Bool IsEmptyStack(StackPtr stack){
    return stack->length == 0 ? TRUE : FALSE;
}
Status ClearStack(StackPtr stack){
    NodePtr node, tmp;
    node = (stack->s).next;
    while (node){
        tmp = node->next;
        free(node);
        node = tmp;
    }
    (stack->s).next = NULL;
    stack->length = 0;
    return OK;
}
int GetStackLength(StackPtr stack){
    return stack->length;
}
Status GetTop(StackPtr stack, ElementType *elm){
    if (!stack->length) return ERROR;
    *elm = (stack->s).next->data;
    return OK;
}
Status Push(StackPtr stack, ElementType elm){
    NodePtr node = (NodePtr)(malloc(sizeof(Node)));
    if (!node) return ERROR;
    node->data = elm;
    node->next = (stack->s).next;
    (stack->s).next = node;
    stack->length++;
    return OK;
}
Status Pop(StackPtr stack, ElementType *elm){
    if (stack->length == 0) return ERROR;
    NodePtr node, tmp;
    node = (stack->s).next;
    tmp = node->next;
    *elm = node->data;
    free(node);
    (stack->s).next = tmp;
    stack->length--;
    return OK;


}
Status Traverse(StackPtr stack){
    NodePtr tmp;
    tmp = (stack->s).next;
    while (tmp){
        Visit(tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return OK;
}
int main(void){
    Stack s;
    int i, j;
    ElementType elm;
    ElementType top;
    j = InitStack(&s);
    if (j){
        char tmp = 'A';
        for(i = 1; i <= 10; i++){
            Push(&s, tmp++);
        }
        printf("栈初始化成功\n");
        Traverse(&s);
        Pop(&s, &elm);
        printf("出栈的元素是%c\n", elm);
        Traverse(&s);
        printf("栈中的元素个数是%d\n", GetStackLength(&s));
        GetTop(&s, &top);
        printf("栈顶元素是%c\n", top);
    }
    return 0;
}