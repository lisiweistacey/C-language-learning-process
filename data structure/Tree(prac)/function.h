#include <stdio.h>
#include <stdlib.h>
//����
typedef char BiElemType;
//����������ʽ�洢�ṹ
typedef struct BiTNode {
    BiElemType c;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree; //��㣬ָ��

//tag�ṹ���Ǹ�������ʹ�õ�(����ʱ��)
typedef struct tag {
    BiTree p; //����ĳһ�����ĵ�ֵַ
    struct tag* pnext;
}tag_t, * ptag_t;


//���еĽṹ��(��α�����)

typedef BiTree ElemType;
//��ʽ���н��
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode;
//�ṹ��
typedef struct {
    LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, ElemType x);
bool IsEmpty(LinkQueue Q);
bool DeQueue(LinkQueue & Q, ElemType & x); 
