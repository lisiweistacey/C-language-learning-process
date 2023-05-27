#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

//结构体
typedef struct{
    LinkNode *front, *rear; //结构体指针
}LinkQueue;

//队列的初始化，这里使用的是带头结点的链表来实现的
void InitQueue(LinkQueue &Q){
    //不带头结点
    //Q.front = Q.rear = NULL;
    //带头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
    Q.front->next = NULL; //初始为空
}

//判空
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

//入队
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL; //不能忘记
    Q.rear->next = s;
    Q.rear = s;
}

//出队
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next; //拿到第一个结点
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear) //不能忘记
        Q.rear = Q.front;
    free(p);
    return true;
}

int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);
    ElemType e;
    bool ret = DeQueue(Q, e);
    if(ret){
        printf("DeQueue succeed, element = %d\n", e);
    }
    else{
        printf("DeQueue failed\n");
    }
    return 0;
}
