#include "function.h"

//���еĳ�ʼ��������ʹ�õ��Ǵ�ͷ����������ʵ�ֵ�
void InitQueue(LinkQueue& Q) {
    //����ͷ���
    //Q.front = Q.rear = NULL;
    //��ͷ���
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); //����ͷ���
    Q.front->next = NULL; //��ʼΪ��
}

//���
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL; //��������
    Q.rear->next = s;
    Q.rear = s;
}

//�п�
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next; //�õ���һ�����
    x = p->data;
    Q.front->next = p->next;
    if (p == Q.rear) //��������
        Q.rear = Q.front;
    free(p);
    return true;
}