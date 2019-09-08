#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 10
typedef int Status;
typedef char ElementType;
typedef int Bool;
typedef struct Node {
    ElementType data[MAXSIZE];
    int top;
    int tail;
}Queue, *QueuePtr;
void Visit(ElementType elm){
    printf("%c ", elm);
}
Status InitQueue(QueuePtr q){
    q->top = 0;
    q->tail = 0;
    return OK;
}
Bool IsEmptyQueue(QueuePtr q){
    return q->tail == q->top ? TRUE : FALSE;
}
Status ClearQueue(QueuePtr q){
    q->top = q->tail = 0;
    return OK;
}
int GetQueueLength(QueuePtr q){
    return (q->tail - q->top + MAXSIZE ) % MAXSIZE;
}
int Enqueue(QueuePtr q, ElementType elm){
    if ((q->tail + 1) % MAXSIZE == q->top) return ERROR;
    q->data[q->tail] = elm;
    q->tail = (q->tail + 1) % MAXSIZE;
    return OK;
}
Status Dequeue(QueuePtr q, ElementType *elm){
    if (q->tail == q->top) return ERROR; //队列空
    *elm = q->data[q->top];
    q->top = (q->top + 1) % MAXSIZE;
    return OK;
}
Status QueueTraverse(QueuePtr q){
    int i, j;
    i = q->top;
    j = q->tail;
    while (i != j){
        Visit(q->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    return OK;
}
int main(void){
    //用数组实现队列,循环队列
    Queue q;
    if (InitQueue(&q)){
        char ch = 'A';
        printf("队列初始化成功\n");
        printf("队列的长度是%d\n", GetQueueLength(&q));
        printf("队列是否为空, 1为空，0为=>%d\n", IsEmptyQueue(&q));
        for(int i = 1; i <= 10; i++){
            Enqueue(&q, ch++);
        }
        printf("----------------------入队列\n");
        for(int i = 0; i <9; i++){
            printf("%c ", q.data[i]);
        }
        printf("\n");
        printf("----------------------入队列\n");
        QueueTraverse(&q);
        printf("队列的长度是%d\n", GetQueueLength(&q));
        printf("队列是否为空, 1为空，0为=>%d\n", IsEmptyQueue(&q));

        printf("出队列\n");
        printf("---------------------出队列\n");
        ElementType elm;
        for(int i = 0; i < 5; i++){
            Dequeue(&q, &elm);
            printf("%c ", elm);
        }
        printf("\n");
        printf("队列是否为空?=>%d\n", IsEmptyQueue(&q));
        printf("队列的长度%d\n", GetQueueLength(&q));
        QueueTraverse(&q);
        printf("----------------------入队列\n");
        for(int i = 0; i < 5; i++){
            Enqueue(&q, ch++);
        }
        QueueTraverse(&q);
        printf("队列是否为空?=>%d\n", IsEmptyQueue(&q));
        printf("队列的长度%d\n", GetQueueLength(&q));
    }
    return 0;
}