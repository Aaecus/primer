#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Bool;
typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node *next;
}QueueNode, *QueueNodePtr;
typedef struct S {
    QueueNodePtr top;
    QueueNodePtr tail;
}Queue, *QueuePtr;
void Visit(ElementType elm){
    printf("%d ", elm);
}
Status InitStack(QueuePtr q){
    q->top = q->tail = (QueueNodePtr)(malloc(sizeof(Queue)));
    if (!q->tail) return ERROR;
    q->top->next = NULL;
    return OK;
}
int GetQueueLength(QueuePtr q){
    int i = 0;
    QueueNodePtr tmp;
    tmp = q->top;
    while (tmp != q->tail){
        i++;
        tmp = tmp->next;
    }
    return i;
}
Bool IsEmptyQueue(QueuePtr q){
    return q->tail == q->top ? TRUE : FALSE;
}
Status ClearQueue(QueuePtr q){
   QueueNodePtr qnode, tmp;
    q->tail = q->top;
    tmp = q->top->next;
    q->top->next = NULL;
    while (tmp){
        qnode = tmp;
        free(tmp);
        tmp = qnode->next;
    }
    return OK;
}
Status Enqueue(QueuePtr q, ElementType elm){
    QueueNodePtr tmp;
    tmp = (QueueNodePtr)(malloc(sizeof(struct Node)));
    if (!tmp)
        return ERROR;
    tmp->data = elm;
    //将新元素赋值给尾巴指针的下一个
    tmp->next = NULL;
    q->tail->next = tmp;
    q->tail = tmp;
    return OK;

}
Status Dequeue(QueuePtr q, ElementType *elm){
    QueueNodePtr tmp;
    if (q->tail == q->top) return ERROR;
    tmp = q->top->next;
    *elm = tmp->data;
    q->top->next = tmp->next;
    if (q->tail == tmp) q->tail = q->top;
    free(tmp);
    return OK;

}
Status TraverseQueue(QueuePtr q){
    QueueNodePtr tmp;
    tmp = q->top->next;
    while (tmp){
        Visit(tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return OK;
}
int main(void){
    //链表实现队列
    //判断队列初始化是否成功
    int i;

    ElementType elm;
    Queue q;
    if (InitStack(&q)){
        printf("初始化成功\n");
        printf("队列是否为空%d\n", IsEmptyQueue(&q));
        printf("队列的长度=>%d\n", GetQueueLength(&q));
        printf("__________________________________\n");
        for(i = 0; i < 5; i++){
            Enqueue(&q, i);
        }
        printf("队列是否为空%d\n", IsEmptyQueue(&q));
        printf("队列的长度=>%d\n", GetQueueLength(&q));
        TraverseQueue(&q);
        printf("__________________________________\n");
        printf("出队列\n");
        for(i = 0; i < 3; i++){
            Dequeue(&q, &elm);
            Visit(elm);
        }
        printf("队列是否为空%d\n", IsEmptyQueue(&q));
        printf("队列的长度=>%d\n", GetQueueLength(&q));
        TraverseQueue(&q);
    } else{
        printf("初始化失败\n");
    }
}