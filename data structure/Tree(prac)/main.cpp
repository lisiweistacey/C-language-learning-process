#define _CRT_SECURE_NO_WARNINGS
#include "function.h"


//����
//ǰ����������������������ȱ���
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c", T->c); //visit
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//�������
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c", T->c); //visit 
        InOrder(T->rchild);
    }
}
//�������
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->c); //visit
    }
}

//��α��������������������ȱ���
void LevelOrder(BiTree T) {
    LinkQueue Q; //����һ������
    InitQueue(Q); //��ʼ������
    BiTree p; //�洢���ӽ��
    EnQueue(Q, T); //�Ѹ�������
    while (!IsEmpty(Q)) {
        DeQueue(Q, p); //����
        putchar(p->c); //�ȼ���printf("%c", c);
        if (p->lchild) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild) {
            EnQueue(Q, p->rchild);
        }
    }
}

//��ν���(�������ø�������)
int main() {
    BiTree pnew; //����ָ��������������
    BiTree tree = NULL; //tree��ָ�������ģ�������,ĿǰΪ����
    char c;
    ptag_t phead = NULL, ptail = NULL, list_pnew = NULL, pcur = NULL;//ָ��
    //abcdefghij ��ÿһ���ַ���Ϊһ������������
    while (scanf("%c", &c)) {
        if (c == '\n') {
            break; //�������оͽ���
        }
        //calloc����Ŀռ��С����������ֱ����ˣ����Կռ���г�ʼ������ֵΪ0
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->c = c; //���ݷŽ�ȥ
        list_pnew = (ptag_t)calloc(1, sizeof(tag_t)); //�����н������ռ�
        list_pnew->p = pnew;
        //��������ĵ�һ�����
        if (tree == NULL) {
            tree = pnew; //treeָ�����ĸ����
            phead = list_pnew; //��һ�������Ƕ���ͷ�����Ƕ���β
            ptail = list_pnew;
            pcur = list_pnew; //pcurҪָ��������ĸ���Ԫ��
        }
        else {
            //��Ԫ���������
            ptail->pnext = list_pnew;
            ptail = list_pnew;
            //��������b����������
            if (pcur->p->lchild == NULL) {
                pcur->p->lchild = pnew; // p->pcur����Ϊ�գ��ͷ�������
            }
            else if (NULL == pcur->p->rchild) {
                pcur->p->rchild = pnew; // p->pcur�Һ���Ϊ�գ��ͷ����Һ���
                pcur = pcur->pnext; //��ǰ������Һ��Ӷ����ˡ�pcur��ָ����һ��
            }
        }
    }
    printf("-----ǰ�����(������ȱ���)-----\n");
    PreOrder(tree);
    printf("\n-----�������-----\n");
    InOrder(tree);
    printf("\n-----�������-----\n");
    PostOrder(tree);
    printf("-----��α���(������ȱ���)-----\n");
    LevelOrder(tree);
    return 0;
}