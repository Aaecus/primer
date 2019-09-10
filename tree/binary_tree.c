/*
 * @auther Aaecus
 * @time 2019年9月10日10:15:50
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
            printf("无父节点的非根节点, %d\n", t[i]);
            return ERROR;
        }
    }
    return OK;
}

Bool IsEmptyBTree(const BTree t){
    return t[0] == Nil ? TRUE : FALSE;
}

Status GetRoot(const BTree t, ElementType *elm){
    //返回根节点的值 如果不为空
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
    //获取指定层数指定序号的节点值
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
            printf("初始化成功\n");
            printf("前序遍历\n");
            PreOrderTraverse(t);
            printf("中序遍历\n");
            InOrderTraverse(t);
            printf("后序遍历\n");
            PostOrderTraverse(t);
            printf("层序遍历\n");
            LevelOrderTraverse(t);

            printf("----------------------\n");
            printf("树的深度是%d\n", BTreeDepth(t));
            GetRoot(t, &root);
            printf("父节点的值是%d\n", GetParent(t, 3));
            printf("根节点的值是%d\n", root);
            printf("左儿子的值是%d\n", GetLeftChild(t, 3));
            printf("右儿子的值是%d\n", GetRightChild(t, 3));
            printf("左兄弟的值是%d, 0表示没有左兄弟\n", GetLeftSibling(t, 3));
            printf("右兄弟的值是%d, 0表示没有右兄弟\n", GetRightSibling(t, 3));
            printf("-------------------------\n");
            printf("给树添加新的节点\n");
            Assign(t, pos, 11);
            LevelOrderTraverse(t);
            printf("树是否为空%d,1为空，0不为空\n", IsEmptyBTree(t));
    }
    }
    return 0;
}