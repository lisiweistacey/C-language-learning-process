#include <stdio.h>
#include "assert.h" 

/*һ���������������ָ����
	���Ա�ĵ�����Ĵ洢�ṹ*/
typedef int SLTDataType; //�����·��ţ���÷�����صĶ�����������
typedef struct SListNode {
	SLTDataType data; //�����������
	struct SListNode* next; //�����һ�����ĵ�ַ
}SListNode, SLN;

/* ���ٽ�� */
SListNode* BuySListNode(SLTDataType dt) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//�����½�㣬���ڴ�����ռ�
	if (newnode == NULL) {
		printf("����ʧ��\n");
		exit(-1);
	}
	else{
		newnode->data = dt; //������Ԫ�ظ���newnode->data
		newnode->next = NULL; //newnode�ĺ��Ϊ��
	}
	return newnode;
}
//ʹ�����������ʱ������Ӧ����������һ��ָ�������շ��ص�newnode��ַ
//SListNode* newnode = BuySListNode(dt);
//tail->next = newnode;

//ժ�ԣ� https://blog.csdn.net/muxuen/article/details/123692955
/* β�� */
// ��������ʹ�õĶ��Ƕ���ָ��pphead����������Ҫ����phead����ʱ����Ҫ�������ָ��
// ����ʹ��һ��ָ�룬ֱ�Ӵ���ͷָ��pheadʱ������Ҫ���ĸ�ָ��ָ��ĵ�ַʱ���Ķ�ֻ���ں����ڲ���Ч��main�����е�pheadָ�벢û�б��ı�
void SListPushBack(SListNode** pphead, SLTDataType x){
	assert(pphead); 
	//void assert(int expression);
	//assert() �������˼���ǣ��������ҵļ��������£��ܹ��������õ���������ʵ���൱��һ�� if ��䣺
	/*if (�������)
	{
		�����������У�
	}
	else
	{
		����&& ��ֹ���򣡣������ɳ��������������Ĵ���
	}*/

	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL){
		//���ԭ����Ϊ�գ�ֱ����ͷָ��=�¿��ٵĽڵ��ַ
		*pphead = newnode;
	}
	else{
		//ԭ����ǿ�
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{   //��Ҫ����β
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
/* ͷ�� */
// ֻ��Ҫ���½ڵ��nextָ��ԭ�����ͷ�����ٽ�headͷָ�����Ϊ�½ڵ�ĵ�ַ
void SListPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);

	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//eg:
/* �������� */
typedef struct people {
	int age;
	struct people* next;
}LinkList;
/* ��ʼ��һ��n������������� */
LinkList* Creat(int n) {
	LinkList* head, * node, * end; //����ͷ�ڵ㣬��ͨ��㣬β�����
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head; //����ǿ�����ͷ����β���һ��
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->age);//��ֵ
		end->next = node;
		end = node;
	}
	end->next = NULL; //��������
	return head;
}

/**/

