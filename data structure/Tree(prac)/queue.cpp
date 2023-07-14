#include "function.h"

//队列的初始化，这里使用的是带头结点的链表来实现的
void InitQueue(LinkQueue& Q) {
    //不带头结点
    //Q.front = Q.rear = NULL;
    //带头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
    Q.front->next = NULL; //初始为空
}

//入队
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL; //不能忘记
    Q.rear->next = s;
    Q.rear = s;
}

//判空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next; //拿到第一个结点
    x = p->data;
    Q.front->next = p->next;
    if (p == Q.rear) //不能忘记
        Q.rear = Q.front;
    free(p);
    return true;
}