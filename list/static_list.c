#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef int Bool;
typedef char ElementType;
typedef struct Node {
    ElementType ch;
    int cur;
}Node, StaticList[MAXSIZE];
Status InitList(StaticList list){
    for(int i = 0; i < MAXSIZE - 1; i++){
        list[i].cur = i + 1;
    }
    list[MAXSIZE-1].cur = 0;
    return OK;
}
int ListLength(StaticList list){
    int len = 0;
    Node tmp = list[MAXSIZE-1];
    while (tmp.cur){
        len++;
        tmp = list[tmp.cur];
    }
    return len;
}
int GetPos(StaticList list){
    int pos = list[0].cur;
    if (list[0].cur){
        list[0].cur = list[pos].cur;
    }
    return pos;
}
Status InsertList(StaticList list, int i, ElementType elm){
    int pos;
    int k = MAXSIZE - 1;
    int len = ListLength(list);
    if (i < 1 || i > len + 1) return ERROR;
    pos = GetPos(list);
    if (pos){
        list[pos].ch = elm;
        for(int j = 1; j <= i - 1; j++){
            k = list[k].cur;
        }
        list[pos].cur = list[k].cur;
        list[k].cur = pos;
        return OK;
    }
    return ERROR;

}
void Free(StaticList list, int k){
    list[k].cur = list[0].cur;
    list[0].cur = k;
}
Status DeleteList(StaticList list, int i, ElementType *elm){
    int k = MAXSIZE - 1;
    int j;
    if (i < 1 || i > GetPos(list)) return ERROR;
    for(j = 1; j <= i - 1; j++){
        k = list[k].cur;
    }
    j = list[k].cur;
    *elm = list[j].ch;
    list[k].cur = list[j].cur;
    Free(list, j);
    return OK;
}
void Visit(ElementType elm){
    printf("%c ", elm);
}
void ListTraverse(StaticList list){
    int i = list[MAXSIZE-1].cur;
    while (i){
        Visit(list[i].ch);
        i = list[i].cur;
    }
    printf("\n");
}
int main(void){
    StaticList arr;
    char ch = 'A';
    char tmp;
    if (InitList(arr)){
        printf("初始化成功!\n");
        for(int i = 1; i <= 5; i++){
            InsertList(arr, i , ch++);
        }
        printf("静态链表的长度是%d\n", ListLength(arr));
        ListTraverse(arr);
        DeleteList(arr, 2, &tmp);
        printf("删除第二个元素:B后，删除的元素%c\n", tmp);
        ListTraverse(arr);
        printf("静态链表的长度为%d\n", ListLength(arr));

    } else{
        printf("初始化失败\n");
    }

    return 0;
}