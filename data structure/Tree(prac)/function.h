#include <stdio.h>
#include <stdlib.h>
//建树
typedef char BiElemType;
//二叉树的链式存储结构
typedef struct BiTNode {
    BiElemType c;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree; //结点，指针

//tag结构体是辅助队列使用的(建树时用)
typedef struct tag {
    BiTree p; //树的某一个结点的地址值
    struct tag* pnext;
}tag_t, * ptag_t;


//队列的结构体(层次遍历用)

typedef BiTree ElemType;
//链式队列结点
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode;
//结构体
typedef struct {
    LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, ElemType x);
bool IsEmpty(LinkQueue Q);
bool DeQueue(LinkQueue & Q, ElemType & x); 
