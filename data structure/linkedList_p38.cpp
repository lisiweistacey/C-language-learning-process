#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//单链表结点
typedef struct LNode {
	int data;
	struct LNode *next;
}*LinkList, LNode;

void print(LinkList L) {
	while (L != NULL) {
		printf("%d", L->data);
		L = L->next;
	}
	printf("\n");
}


//1
//设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点。
LinkList del_x(LinkList &L, int x) {
	struct LNode* p;//创建一个指针p，指向待删除的结点
	//先写退出递归的条件
	if (L == NULL)
		return NULL;
	if (L->data == x) {
		p = L; //令p指向被删除的结点
		L = L->next; //将p指向的结点断开
		free(p);
		return del_x(L, x);

	}
	else {
		L->next = del_x(L->next, x);
		return L;
	}
}

//2
//在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点不唯一、试编写算法以实现上述操作。
void del_x2(LinkList &L, int x){
	struct LNode *p = L->next, *pre = L, *q; //pre用来记录p的前一个结点,p用来遍历，q用来记录要删的
	while(p!=NULL){
		if(p->data == x){
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else{
			pre = p; //后移
			p = p->next;
		}
	}
}

//3
//反向输出可以考虑用递归
void R_Print(LinkList L){
	if(L->next!=NULL){
		R_Print(L->next);
	}//先递归，递归到不满足后，再从后往前输出
	if(L!=NULL)
		printf("%d", L->data);
}

//4
//试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法（假设最小值结点是唯一的)。
LinkList DelectMin(LinkList &L){
	LNode *pre = L, *p = pre->next; //p为工作指针， pre指向p的前驱
	LNode *minpre = pre, *min_p = p;//保存最小值结点及其前驱结点
	while(p != NULL){
		if(p->data < min_p->data){
			min_p = p;
			minpre = pre;
		}
		pre = p; //继续扫描下一个
		p = p->next;
	}
	//找到后，开始删除
	minpre->next = min_p->next; //删除
	free(min_p);  //释放
	return L;
}


//5
//试编写算法将带头结点的单链表就地逆置，所谓"就地"是指辅助空间复杂度为 O (1).
//方法1：将头结点摘下来，后面的结点使用头插法一个一个插到头结点后面
LinkList Reverse_1(LinkList L){
	LNode *p = L->next;
	LNode *s;
	L->next = NULL; //摘头结点，就是与后面结点分离开 
	while(p != NULL){
		s = p->next; //存储防断链
		p->next = L->next;
		L->next = p;
		p = s;
	}
	return L;
}
//方法二：一个一个反转指针
LinkList Reverse_2(LinkList L){
	LNode *pre = L, *p = L->next, *r = p->next; //定义三个相邻的指针
	p->next = NULL; //处理第一个结点
	while(r != NULL){ //r若为空，则说明p是最后一个结点
		//往后指针依次往后移一位
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	L->next = p; //头指针指向原来的最后一个结点
	return L;
}

//6
//有一个带头结点的单链表 L ，设计一个算法使其元素递增有序。
//方法：将原来的链表从第一个结点后处断开，后依次遍历每一个结点，如果data大于第一个结点，就插到第一个结点后，小于就插到第一个结点之前
void Sort(LinkList L){
	LNode *pre, *p = L->next, *r = p->next;
	p->next = NULL;
	p = r;
	while(p != NULL){
		r = p->next;
		pre = L;
		while(p->data > pre->next->data && pre->next != NULL){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r; //扫描原单链表的下一个结点
	}
}

//7
//设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）。
void DelectBetween(LinkList &L, int x, int y){
	LNode *pre = L, *p = L->next;
	if(x>y){
		int tem = y;
		y = x;
		x = tem;
	}
	while(p != NULL && x!=y){
		if(p->data > x && p->data < y){
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else{
			pre = p;
			p = p->next;
		}
	}
}


int main() {
	int x, n; //x是要删除的结点，n是链表的长度
	struct LNode* first, * tail, * ans;
	//1
	scanf("%d%d", &n, &x);
	//3
	//scanf("%d%d", &n);
	for (int i = 1; i <= n; i++) {
		struct LNode* temp = (struct LNode*)malloc(sizeof(struct LNode));
		scanf("%d", &temp->data);
		temp->next = NULL;
		if (i == 1) {
			first = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	//1
	ans = del_x(first, x);
	print(ans);//返回答案链表
	//3
	R_Print(first);
}
