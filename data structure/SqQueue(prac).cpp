#include <stdio.h>

#define MaxSize 5
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];  //数组，只存储MaxSize-1个元素(空一个)
    int front, rear; //队列头 队列尾
}SqQueue;

//初始化循环队列，让头和尾都指向0
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

//判队空
bool isEmpty(SqQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q, ElemType e){
    if((Q.rear + 1)%MaxSize==Q.front) //队列满了
        return false;
    Q.data[Q.rear] = e; //放入元素
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &e){
    if(Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    bool ret = isEmpty(Q);
    if(ret)
        printf("SqQueue is empty\n");
    else
        printf("SqQueue is not empty\n");
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    ret = EnQueue(Q, 6);
    ret = EnQueue(Q, 7);
    if(ret){
        printf("EnQueue succeed\n");
    }
    else{
        printf("failed\n");
    }
    ElemType e;
    ret = DeQueue(Q, e);
    if(ret)
        printf("DeQueue succeed\n");
    else{
        printf("DeQueue failed\n");
    }
    return 0;
}
