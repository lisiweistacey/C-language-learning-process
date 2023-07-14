#define _CRT_SECURE_NO_WARNINGS
#include "function.h"


//遍历
//前序遍历，先序遍历，深度优先遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c", T->c); //visit
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c", T->c); //visit 
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->c); //visit
    }
}

//层次遍历。层序遍历、广度优先遍历
void LevelOrder(BiTree T) {
    LinkQueue Q; //定义一个队列
    InitQueue(Q); //初始化队列
    BiTree p; //存储出队结点
    EnQueue(Q, T); //把根结点入队
    while (!IsEmpty(Q)) {
        DeQueue(Q, p); //出队
        putchar(p->c); //等价于printf("%c", c);
        if (p->lchild) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild) {
            EnQueue(Q, p->rchild);
        }
    }
}

//层次建树(建树必用辅助队列)
int main() {
    BiTree pnew; //用来指向新申请的树结点
    BiTree tree = NULL; //tree是指向树根的，代表树,目前为空树
    char c;
    ptag_t phead = NULL, ptail = NULL, list_pnew = NULL, pcur = NULL;//指针
    //abcdefghij 把每一个字符作为一个结点存入树中
    while (scanf("%c", &c)) {
        if (c == '\n') {
            break; //读到换行就结束
        }
        //calloc申请的空间大小是两个参数直接相乘，并对空间进行初始化，赋值为0
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c; //数据放进去
        list_pnew = (ptag_t)calloc(1, sizeof(tag_t)); //给队列结点申请空间
        list_pnew->p = pnew;
        //如果是树的第一个结点
        if (tree == NULL) {
            tree = pnew; //tree指向树的根结点
            phead = list_pnew; //第一个结点既是队列头，又是队列尾
            ptail = list_pnew;
            pcur = list_pnew; //pcur要指向进入树的父亲元素
        }
        else {
            //让元素先入队列
            ptail->pnext = list_pnew;
            ptail = list_pnew;
            //接下来把b结点放入树中
            if (pcur->p->lchild == NULL) {
                pcur->p->lchild = pnew; // p->pcur左孩子为空，就放入左孩子
            }
            else if (NULL == pcur->p->rchild) {
                pcur->p->rchild = pnew; // p->pcur右孩子为空，就放入右孩子
                pcur = pcur->pnext; //当前结点左右孩子都有了。pcur就指向下一个
            }
        }
    }
    printf("-----前序遍历(深度优先遍历)-----\n");
    PreOrder(tree);
    printf("\n-----中序遍历-----\n");
    InOrder(tree);
    printf("\n-----后序遍历-----\n");
    PostOrder(tree);
    printf("-----层次遍历(广度优先遍历)-----\n");
    LevelOrder(tree);
    return 0;
}