#include <stdio.h>
#include "assert.h" 

/*一个结点包括数据域和指针域
	线性表的单链表的存储结构*/
typedef int SLTDataType; //定义新符号，与该符号相关的都是链表内容
typedef struct SListNode {
	SLTDataType data; //存放数据内容
	struct SListNode* next; //存放下一个结点的地址
}SListNode, SLN;

/* 开辟结点 */
SListNode* BuySListNode(SLTDataType dt) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//生成新结点，向内存申请空间
	if (newnode == NULL) {
		printf("分配失败\n");
		exit(-1);
	}
	else{
		newnode->data = dt; //将数据元素赋给newnode->data
		newnode->next = NULL; //newnode的后继为空
	}
	return newnode;
}
//使用这个函数的时候，我们应该先让另外一个指针来接收返回的newnode地址
//SListNode* newnode = BuySListNode(dt);
//tail->next = newnode;

//摘自： https://blog.csdn.net/muxuen/article/details/123692955
/* 尾插 */
// 这里我们使用的都是二级指针pphead，当我们需要更改phead本身时，需要传入二级指针
// 假设使用一级指针，直接传入头指针phead时，当需要更改该指针指向的地址时，改动只会在函数内部生效，main函数中的phead指针并没有被改变
void SListPushBack(SListNode** pphead, SLTDataType x){
	assert(pphead); 
	//void assert(int expression);
	//assert() 其表达的意思就是，程序在我的假设条件下，能够正常良好的运作，其实就相当于一个 if 语句：
	/*if (假设成立)
	{
		程序正常运行；
	}
	else
	{
		报错&& 终止程序！（避免由程序运行引起更大的错误）
	}*/

	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL){
		//如果原链表为空，直接让头指针=新开辟的节点地址
		*pphead = newnode;
	}
	else{
		//原链表非空
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{   //需要先找尾
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
/* 头插 */
// 只需要将新节点的next指向原链表的头部，再将head头指针更改为新节点的地址
void SListPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);

	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//eg:
/* 创建链表 */
typedef struct people {
	int age;
	struct people* next;
}LinkList;
/* 初始化一个n个链表结点的链表 */
LinkList* Creat(int n) {
	LinkList* head, * node, * end; //定义头节点，普通结点，尾部结点
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head; //如果是空链表，头结点和尾结点一样
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->age);//赋值
		end->next = node;
		end = node;
	}
	end->next = NULL; //结束创建
	return head;
}

/**/

