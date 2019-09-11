#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int Bool;
typedef char ElementType;
typedef struct Node {
    ElementType data;
    struct Node *left;
    struct Node *right;
}Btree, *BtreePtr;
int count = 1;
typedef ElementType String[24];
String str;
void Assign(String s, char *st){
    s[0] = strlen(st);
    int i;
    for(i = 1; i <= s[0]; i++){
        s[i] = *(st + i - 1);
    }
}
void Visit(ElementType elm){
    printf("%c ", elm);
}
Status InitBtree(BtreePtr *t){
    *t = NULL;
    return OK;
}
Status CreateBtree(BtreePtr *t){
    char ch = str[count++];
    if (ch == '#'){
        *t = NULL;
    } else{
        *t = (BtreePtr)(malloc(sizeof(struct Node)));
        if (!*t) return ERROR;
        (*t)->data = ch;
        CreateBtree(&(*t)->left);
        CreateBtree(&(*t)->right);
    }
    return OK;
}
Bool IsEmptyBtree(BtreePtr t){
    return t == NULL ? TRUE : FALSE;
}
void ClearBtree(BtreePtr *t){
    if (*t){
        if ((*t)->left){
            ClearBtree(&(*t)->left);
        }
        if ((*t)->right){
            ClearBtree(&(*t)->right);
        }
        free(*t);
        *t = NULL;
    }
}
int BtreeDepth(BtreePtr t){
    if (t == NULL) return 0;
    int i, j;
    if (t->left){
        i = BtreeDepth(t->left);
    } else{
        i = 0;
    }
    if (t->right){
        j = BtreeDepth(t->right);
    } else{
        j = 0;
    }
    return i > j ? i + 1 : j + 1;

}
ElementType GetRoot(BtreePtr t){
    if (t == NULL) {
        printf("空树\n");
        return ERROR;
    }
    return t->data;
}
ElementType GetValue(BtreePtr t){
    return t->data;
}
void PreorderTraverse(BtreePtr t){
    if (t == NULL) return;
    Visit(t->data);
    PreorderTraverse(t->left);
    PreorderTraverse(t->right);
}
void InorderTraverse(BtreePtr t){
    if (t == NULL) return;
    InorderTraverse(t->left);
    Visit(t->data);
    InorderTraverse(t->right);
}
void PostorderTraverse(BtreePtr t){
    if (t == NULL) return;
    PostorderTraverse(t->left);
    PostorderTraverse(t->right);
    Visit(t->data);
}
int main(void){
    BtreePtr t;
    InitBtree(&t);
    Assign(str, "ABDH#K###E##CFI###G#J##");
    if(CreateBtree(&t)){
        printf("初始化成功\n");
        printf("树的深度是%d\n", BtreeDepth(t));
        printf("前序遍历\n");
        PreorderTraverse(t);
        printf("\n");
        printf("根节点的值是%c", GetRoot(t));
        printf("\n");
        printf("中序遍历\n");
        InorderTraverse(t);
        printf("\n");
        printf("后序遍历\n");
        PostorderTraverse(t);
        printf("清空树\n");
        ClearBtree(&t);
        printf("树的深度是%d\n", BtreeDepth(t));
    } else{
        printf("初始化失败\n");
    }

    return 0;
}
