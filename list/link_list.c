#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Bool;
typedef int Status;
typedef int ElementType;
typedef struct ListNode{
    ElementType data;
    struct ListNode *next;
}ListNode, *ListNodePtr;
typedef ListNodePtr List;
void visit(ElementType elm){
    printf("%d ", elm);
}
Status InitList(List *l){
    *l = (List)(malloc(sizeof(struct ListNode)));
    if (!(*l)) return ERROR;
    (*l)->next = NULL;
    return OK;
}
Bool IsEmptyList(List l){
    return l->next == NULL ? TRUE : ERROR;
}
int ListLength(List l){
    int length = 0;
    ListNodePtr tmp = l->next;
    while (tmp){
        length++;
        tmp = tmp->next;
    }
    return length;
}
Status ClearList(List l){
    List p, q;
    p = l->next;
    while (p){
        q = p->next;
        free(p);
        p = q;
    }
    l->next = NULL;
    return OK;
}
Status GetElem(List l, int i, ElementType elm){
}
int LocateElem(List l, ElementType elm){
}
Status InsertList(List l, int i, ElementType elm){
    ListNodePtr q, p;
    int j = 1;
    q = l;
    while (q && j < i){
        q = q->next;
        j++;
    }
    if (!q || j > i) return ERROR;
    p = (ListNodePtr)(malloc(sizeof(ListNode)));
    p->data = elm;
    p->next = q->next;
    q->next = p;
    return OK;

}
Status ListDelete(List l, int i, ElementType *elm){
    int j = 1;
    ListNodePtr p, q;
    p = l;
    while (p->next && j < i){
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *elm = q->data;
    free(q);
    return OK;
}
Status ListTraverse(List l){
    ListNodePtr tmp = l->next;
    while (tmp){
        visit(l->data);
        tmp = tmp->next;
    }
    printf("\n");
    return OK;
}
int main(void){

}