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

//8 
//给定两个单链表，编写算法找出两个链表的公共结点    (不是值相同，是地址相同)
//方法一：傻瓜方法，时间复杂度太大了
LNode *FindCommonOne(LinkList L1, LinkList L2){
	LNode *p = L1->next, *q = L2->next;
	while(p != NULL){
		while(q != NULL){
			if(p == q){
				return q;
			}	
			q = q->next;
		}
		p = p->next;
	}
	return NULL;
}
//方法二：
//先算出两链表的长度差dist
//再将长链表往后遍历dist个结点
//两个链表同时向后遍历同样的长度，直到找到相同的结点
int Length(LinkList L){
	LNode *p = L->next;
	int num = 0;
	while(p!=NULL){
		num++;
		p = p->next;
	}
	return num;
}
LNode *FindCommonTwo(LinkList L1, LinkList L2){
	int len1 = Length(L1), len2 = Length(L2);
	LNode *longList, *shortList;
	int dist; //差值
	if(len1 > len2){
		longList = L1->next, shortList = L2->next;
		dist = len1 - len2;
	}
	else{
		longList = L2->next, shortList = L1->next;
		dist = len2 - len1;
	}
	//长链表往后遍历dist个结点
	while(dist--){
		longList = longList->next;
	}
	while(longList != NULL){
		if(longList == shortList){
			return longList;
		}
		else{
			//同步遍历搜寻
			longList = longList->next;
			shortList = shortList->next;
		}
	}
	return NULL;
}

//9
//给定一个带表头结点的单链表，设 head 为头指针,结点结构为（data, next), 
//data为整型元素,next为指针,试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）。
//瞎写的
void sort_free_1(LinkList &Head){
	LNode *pre, *p = Head->next;
	LNode *r = p->next;
	p->next = NULL; //断链
	p = r;
	//重排
	while(p != NULL){
		r = p->next;
        pre = Head;
		while(pre->next != NULL && p->data > pre->next->data){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	//打印
	print(Head);
	p = Head;
	while(p != NULL){
		free(p);
	}
}
//答案上的
void sort_free_2(LinkList &head){
	//循环到只剩头结点
	while(head->next != NULL){
		LNode *pre = head, *p = head->next, *u; //u指向被删除结点
		while(p->next != NULL){
			if(p->next->data < pre->next->data)
				pre = p;
			p = p->next;
		}
		printf("%3d", pre->next->data); //打印最小元素值
		u = pre->next;
		pre->next = u->next; //不能丢了！！！
		free(u);
	}
	free(head);
}

//10
//将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
LinkList DisCreat(LinkList &A){
	int n = 0;
	LinkList B = (LinkList)malloc(sizeof(LNode)); //创B链
	B->next = NULL;
	LNode *p = A->next, *ra, *rb;
	A->next = NULL; //清空A链
	while(p != NULL){
		n++;
		if(n%2 == 0){ //偶数
			rb->next = p;
			rb = p;
		}
		else{
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}

//11
LinkList SplitList(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL; //初始化
	LNode *p = A->next, *ra = A;
	LNode *q;
	while (p != NULL)
	{
		ra->next=p;
		ra = p;
		p = p->next;
		if(p!=NULL){
			q = p->next; //记录，防断链
			//B链反向所以用头插
			p->next = B->next;
			B->next = p;
			p = q;
		}
	}
	ra->next = NULL; //A链结束
	return B;
}

//12
void del_same(LinkList &L){
	LNode *p = L->next, *q;
	if(p == NULL)
		return;
	while(p->next != NULL){
		q = p->next;
		if(q->data == p->data){
			p->next = q->next;
			free(q);
		}
		else{
			p = p->next;
		}
	}
}

//13
void MergeList(LinkList &La, LinkList &Lb){
	LNode *r, *pa = La->next, *pb = Lb->next; //r用来记录，防断链
	La->next = NULL; //清空A链表，用作结果链表
	while(pa && pb){ //两链表均不为空时，循环
		if(pa->data <= pb->data){
			r = pa->next; //记录
			pa->next = La->next; //头插
			La->next = pa;
			pa = r;
		}
		else{
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = r;
		}
	} 
	//一个链表已经扫描完了，另外一个链表还剩下元素
	if(pa)
		pb = pa;
	while(pb){
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}
	free(Lb);
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
