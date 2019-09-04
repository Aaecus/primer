#include <stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int ElementType;
typedef struct {
    ElementType data[MAXSIZE];
    int length;
}List, *ListPtr;
void visit(ElementType data){
    printf("%d ", data);
}
Status InitList(ListPtr l){
    l->length = 0;
    return OK;
}
Status isListEmpty(ListPtr l){
    return l->length == 0 ? 1 : 0;
}
Status ClearList(ListPtr l){
    l->length = 0;
    return OK;
}
int ListLength(ListPtr l){
    return l->length;
}
Status GetElem(ListPtr l, int i, ElementType *elm){
    if (l->length == 0 || i < 1 || i > l->length) return ERROR;
    *elm = l->data[l->length - 1];
    return OK;
}
int LocateElem(ListPtr l, ElementType elm){
    for(int i = 0; i < l->length; i++){
        if (l->data[i] == elm){
            return i + 1;
        }
    }
    return 0;
}
Status InsertList(ListPtr l,int i, ElementType elm){
    int k;
    if (l->length == MAXSIZE) return ERROR;
    if (i < 1 || i > l->length + 1)
        return ERROR;
    if (i <= l->length){
        for(k = l->length - 1; k >= i - 1; k--){
            l->data[k + 1] = l->data[k];
        }
    }
    l->data[i - 1] = elm;
    l->length++;
    return OK;
}
Status DeleteList(ListPtr l, int i, ElementType *elm){
  if (l->length == 0) return ERROR;
  if (i < 1 || i > l->length)
      return ERROR;
  *elm = l->data[l->length - 1];
  if (i < l->length){
      for(int k = i - 1; k < l->length; k++){
          l->data[k] = l->data[k+1];
      }
  }
  l->length--;
    return OK;

}
Status ListTraverse(ListPtr l){
    for(int i = 0; i < l->length; i++){
        visit(l->data[i]);
    }
    printf("\n");
    return OK;
}
Status UnionList(ListPtr l1, ListPtr l2){
    int l1_len, l2_len;
    l1_len = l1->length;
    l2_len = l2->length;
    ElementType elm;
    for(int i = 1; i <= l2_len; i++){
        GetElem(l2, i, &elm);
        if (!LocateElem(l1, elm)){
            InsertList(l1, ++l1_len, elm);
        }
    }
    return OK;
}
int main(void){
    List la, lb;
    ElementType elm;
    int i = InitList(&la);
    if (i){
        printf("%初始化成功\n");
        printf("线性表的长度是%d\n", la.length);

        for(int j = 1; j <= 5; j++){
            InsertList(&la, j, j);
        }
        printf("线性表的长度是%d\n", la.length);
        printf("在表头插入五个数据后, la.data = ");
        ListTraverse(&la);
        printf("线性表是否为空? 1=yes, 0=no| %d\n", isListEmpty(&la));

        ClearList(&la);
        printf("线性表是否为空 %d\n", isListEmpty(&la));

        for(int i = 1; i <= 10; i++){
            InsertList(&la, i, i);
        }
        ListTraverse(&la);
        printf("线性表的长度是%d\n", la.length);

        printf("在表头插入0后\n");
        InsertList(&la, 1, 0);
        ListTraverse(&la);
        printf("线性表的长度是%d\n", la.length);

        for(int i = 3; i <=4; i++){
            int k = LocateElem(&la, i);
            if (k){
                printf("第%d个元素的值为%d\n", k, i);
            } else{
                printf("没有值为%d的元素\n", i);
            }
        }
    }
    return 0;
}