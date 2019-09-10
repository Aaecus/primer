/*
 * @auther Aaecus
 * @time 2019��9��10��10:15:50
 * */
#include <stdio.h>
#include <math.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define Nil 0

typedef int Status;
typedef int Bool;
typedef int ElementType;
typedef ElementType BTree[MAXSIZE];
typedef struct {
    int level;
    int pos;
}Position;

void Visit(ElementType elm){
    printf("%d ", elm);
}

Status InitBTree(BTree t){
    int i;
    for(i = 0; i < MAXSIZE; i++){
        t[i] = Nil;
    }
    return OK;
}

Status CreateBtree(BTree t){
    for(int i = 0; i < 10; i++){
        t[i] = i + 1;
        if (i != 0 && t[(i+1)/2-1] == Nil && t[i] != Nil){
            printf("�޸��ڵ�ķǸ��ڵ�, %d\n", t[i]);
            return ERROR;
        }
    }
    return OK;
}

Bool IsEmptyBTree(const BTree t){
    return t[0] == Nil ? TRUE : FALSE;
}

Status GetRoot(const BTree t, ElementType *elm){
    //���ظ��ڵ��ֵ �����Ϊ��
    if (t[0] == Nil) return ERROR;
    *elm = t[0];
    return OK;
}

int BTreeDepth(const BTree t){
    int i;
    int level = 0;
    if (t[0] == Nil) return level;
    for(i = MAXSIZE - 1; i >= 0; i--){
        if (t[i] != Nil) break;
    }
    i++;
    do {
        level++;
    }while (i >= pow(2, level));
    return level;
}
ElementType GetValue(BTree t, Position p){
    //��ȡָ������ָ����ŵĽڵ�ֵ
    return t[(int)powl(2, p.level-1) + p.pos - 2];
}
Status Assign(BTree t, Position e, ElementType elm){
    int i = (int)powl(2, e.level-1) - 1 + e.pos - 1;
    if (elm != Nil && t[(i+1)/2-1] == Nil) {
        return ERROR;
    } else if (elm == Nil && (t[i*2+1] != Nil || t[i*2+2] != Nil)){
        return ERROR;
    }
    t[i] = elm;
    return OK;
}
ElementType GetParent(BTree t, ElementType elm){
    if (t[0] == Nil) return ERROR;
    int i;
    for(i = MAXSIZE - 1; i >= 1; i++){
        if (t[i] == elm){
            return t[(i + 1) / 2 - 1];

        }
    }
    return Nil;
}

ElementType GetLeftChild(BTree t, ElementType elm){
    int i;
    if (t[0] == Nil) return Nil;
    for(i = 0; i <= MAXSIZE - 1; i++){
        if (t[i] == elm){
            return t[ i * 2 + 1];
        }
    }
    return Nil;
}
ElementType GetRightChild(BTree t, ElementType elm){
    int i;
    if(t[i] == Nil) return Nil;
    for(i = 0; i <= MAXSIZE - 1; i++){
        if(t[i] == elm){
            return t[2 * i + 2];
        }
}
    return Nil;
}
ElementType GetLeftSibling(BTree t, ElementType elm){
    if (t[0] == Nil) return ERROR;
    int i;
    for(i = 1; i <= MAXSIZE; i++){
        if (t[i] == elm && i % 2 == 0){
            return t[i - 1];
        }
    }
    return Nil;

}
ElementType GetRightSibling(BTree t, ElementType elm){
    int i;
    if (t[0] == Nil) return ERROR;
    for(i = 1; i <= MAXSIZE - 1; i++){
        if (t[i] == elm && i % 2)
            return t[i+1];
    }
    return Nil;
}

Status PreTraverse(BTree t, int i){
    if (t[i] == Nil)
        return ERROR;
    Visit(t[i]);
    PreTraverse(t,(i+1)*2-1);
    PreTraverse(t, (i+1)*2);
}
Status InTraverse(BTree t, int i){
    if (t[i] == Nil)
        return ERROR;
    InTraverse(t,(i+1)*2-1);
    Visit(t[i]);
    InTraverse(t, (i+1)*2);
}
Status PostTraverse(BTree t, int i){
    if (t[i] == Nil)
        return ERROR;
    PostTraverse(t,(i+1)*2-1);
    PostTraverse(t, (i+1)*2);
    Visit(t[i]);
}
Status PreOrderTraverse(BTree t){
    if (t[0] == Nil) return ERROR;
    PreTraverse(t, 0);
    printf("\n");
}
Status InOrderTraverse(BTree t){
    if (t[0] == Nil) return ERROR;
    InTraverse(t, 0);
    printf("\n");

}
Status PostOrderTraverse(BTree t){
    if (t[0] == Nil) return ERROR;
    PostTraverse(t, 0);
    printf("\n");

}
Status LevelOrderTraverse(BTree t){
    int i, j;
    for(i = MAXSIZE-1; i >= 0; i--){
        if (t[i] != Nil)
            break;
    }
    for(j = 0; j <= i; j++){
        if (t[j] != Nil){
            Visit(t[j]);
        }
    }
    printf("\n");
}

int main(void){
    BTree t;
    ElementType elm;
    ElementType root;
    Position pos = {4,4};
    if(InitBTree(t)){
        if (CreateBtree(t)){
            printf("��ʼ���ɹ�\n");
            printf("ǰ�����\n");
            PreOrderTraverse(t);
            printf("�������\n");
            InOrderTraverse(t);
            printf("�������\n");
            PostOrderTraverse(t);
            printf("�������\n");
            LevelOrderTraverse(t);

            printf("----------------------\n");
            printf("���������%d\n", BTreeDepth(t));
            GetRoot(t, &root);
            printf("���ڵ��ֵ��%d\n", GetParent(t, 3));
            printf("���ڵ��ֵ��%d\n", root);
            printf("����ӵ�ֵ��%d\n", GetLeftChild(t, 3));
            printf("�Ҷ��ӵ�ֵ��%d\n", GetRightChild(t, 3));
            printf("���ֵܵ�ֵ��%d, 0��ʾû�����ֵ�\n", GetLeftSibling(t, 3));
            printf("���ֵܵ�ֵ��%d, 0��ʾû�����ֵ�\n", GetRightSibling(t, 3));
            printf("-------------------------\n");
            printf("��������µĽڵ�\n");
            Assign(t, pos, 11);
            LevelOrderTraverse(t);
            printf("���Ƿ�Ϊ��%d,1Ϊ�գ�0��Ϊ��\n", IsEmptyBTree(t));
    }
    }
    return 0;
}