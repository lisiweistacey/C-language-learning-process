#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//采用头插法建立单链表
//LNode*是结构体指针和LinkList是完全等价的
void list_head_insert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode)); //为头指针申请空间得到头结点空间
    L->next = NULL; //初始为空链表，防止脏数据
    printf("please input:");
    ElemType x;
    scanf("%d", &x); //输入结点的值
    LNode *s;
    while(x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}

//采用尾插法建立单链表
void list_tail_insert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; //r为表尾指针，目前指向头结点
    printf("please input:");
    ElemType x;
    scanf("%d", &x);
    while(x != 999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; //尾结点设置尾空
}


//打印链表
void print_list(LinkList L){
    LNode *s = L->next;
    while(s != NULL){
        printf("%3d", s->data);
        s=s->next;
    }
    printf("\n");
}

//按序号查找结点
/* LNode* get_elem(LinkList L, int i){
    if(i<1)
        return NULL;
    int j = 1;
    LNode *p = L->next;
    while(p!=NULL && j<i){
        p = p->next;
        j++;
    }
    return p;
} */

LNode* get_elem(LinkList L, int i){
    if(i<0)
        return NULL;
    int j = 0;
    while(L && j<i){
        L = L->next;
        j++;
    }
    return L;
}

//按值查找结点
LNode* LocationElem(LinkList L, ElemType e){ //不是&L，因为头结点已经确定不变了
    LNode *p = L->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}


//插入
void insert_node(LinkList L, int i, ElemType InsertVal){
    LNode *p, *s;
    p = get_elem(L, i-1); //找到i结点的前驱
    if(NULL != p){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = InsertVal;
        s->next = p->next;
        p->next = s;
    }
}

//删除(不能删头结点)
bool DelectNode(LinkList L, int i){
    LNode *p;
    p = get_elem(L, i-1); //找到i结点的前驱
    if(p->next == NULL){
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    LinkList L; //L为链表头指针，结构体指针类型
    list_head_insert(L); //采用头插法建立单链表
    print_list(L);
    printf("----------------------\n");

    list_tail_insert(L); //尾插法
    print_list(L);
    printf("----------------------\n");

    LNode* search;
    search = get_elem(L, 2); //按值查找
    if(search != NULL){
        printf("Succeeded in searching by serial number\n");
        printf("%d\n", search->data);
    }
    else{
        printf("not found\n");
    }

    search = LocationElem(L, 3);
    if(search != NULL){
        printf("Succeeded in searching by the value\n");
        printf("%d\n", search->data);
    }else{
        printf("not found\n");
    }

    //插入
    insert_node(L, 3, 0);
    print_list(L);

    //删除
    bool r = DelectNode(L, 1);
    if(r == true){
        printf("Succeeded\n");
    }
    else{
        printf("fail\n");
    }
    print_list(L);
    return 0;
}
