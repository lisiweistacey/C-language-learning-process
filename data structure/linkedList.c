#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//单链表结点
struct LNode {
	int data;
	struct LNode* next;
};

void print(struct LNode* L) {
	while (L != NULL) {
		printf("%d", L->data);
		L = L->next;
	}
	printf("\n");
}


//1
//设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点。
struct LNode* del_x(struct LNode *L, int x) {
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
void del_x2(struct LNode *L, int x){
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
void R_Print(struct LNode *L){
	if(L->next!=NULL){
		R_Print(L->next);
	}//先递归，递归到不满足后，再从后往前输出
	if(L!=NULL)
		printf("%d", L->data);



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
	/* ans = del_x(first, x);
	print(ans);//返回答案链表 */
	//3
	R_Print(first);
}



