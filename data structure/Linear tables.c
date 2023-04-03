#include <stdio.h>
#define MaxSize 50
struct Sqlist
{
	int data[MaxSize];
	int length;
};
int main() {

}

//01
//从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
//空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

/*删除顺序表sq中最小值元素结点，并通过引用参数value返回参数*/
bool del_min(struct Sqlist* sq, int* value) {
	if (sq->length == 0) {
		printf("出错");
		return false;
	}
	int min_pos = 0;//记录最小值元素的下标
	*value = sq->data[0];
	for (int i = 1; i < sq->length; i++) {
		if (*value > sq->data[i]) {
			min_pos = i; 
			*value = sq->data[i]; //返回最小值
		}
	}
	sq->data[min_pos] = sq->data[sq->length - 1];//用最后一个元素来填补
	sq->length--; //长度减一 
	return true;
}

//02
//设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
bool reversal(struct Sqlist *sq) {
	if (sq->length == 0)
		return false;
	int temp;//交换的中间值
	for (int i = 0; i < sq->length / 2; i++) {
		temp = sq->data[i];
		sq->data[i] = sq->data[sq->length - i -1];
		sq->data[sq->length - i - 1] = temp;
	}
	return true;
}

//03
//对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素。

/*思路：用k记录顺序表中不等于x的数据元素(即需要保存的数据元素)
扫描时将不等于x的元素移动到下标为k的位置，更新k值*/
bool del_x(struct Sqlist* sq, int x) {
	if (sq->length == 0)
		return false;
	int k = 0;//记录值不等于x的元素的下标
	for (int i = 0; i < sq->length; i++) {
		if (sq->data[i] != x) {
			sq->data[k] = sq->data[i];
			k++;
		}
	}
	sq->length = k;
}

//04
//从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
bool del_st_index(struct Sqlist* sq, int s, int t) {
	int i, j;
	if (s >= t || sq->length == 0)
		return false;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] >= s) {
			break; //找到值大于或大于s的元素
		}
	}
	if (i >= sq->length)
		return false;
	for (j = 0; j < sq->length && sq->data[j] <= t; j++);
	for (; j < sq->length; j++, i++) {
		sq->data[i] = sq->data[j]; //值大于t的元素往前不，从值大于或等于s的元素位置开始
	}
	sq->length = i;
	return true;
}

//05
//从顺序表中删除其值在给定值s与t之间(包含s和t,要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
bool del_st(struct Sqlist* sq, int s, int t) {
	int k = 0;
	if (s >= t || sq->length == 0)
		return false;
	for (int i = 0; i < sq->length; i++) {
		if (sq->data[i] >= s && sq->data[i] <= t) {
			k++;
		}
		else {
			sq->data[i - k] = sq->data[i]; //将当前元素前移k个位置
		}
	}
	sq->length = sq->length - k;
}

//06
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同。
bool del_same(struct Sqlist* sq) {
	if (sq->length == 0)
		return false;
	int i, j; //i为存储第一个不相同元素，j为工作指针
	for (i = 0, j = 1; j < sq->length; j++) {
		if (sq->data[i] != sq->data[j]) { //查找下一个与上一个元素不同的元素
			sq->data[++i] = sq->data[j]; 
		}
	}
	sq->length = i + 1;
	return true;
}

//07
//将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
bool merge_list(struct Sqlist* sq1, struct Sqlist* sq2, struct Sqlist* sq3) {
	//将有序顺序表1和2合并成一个新的有序顺序表3
	if (sq1->length + sq2->length > sizeof(sq3)) //大于顺序表的最大长度
		return false; //装不下
	int i = 0, j = 0, k = 0;
	//
	while (i < sq1->length && j < sq2->length) {
		if (sq1->data[i] <= sq2->data[j]) //两两比较，小者存入结果
			sq3->data[k++] = sq1->data[i++];
		else
			sq3->data[k++] = sq2->data[j++];
	}
	//还剩下一个没有比较完的有序顺序表（长的那个）
	while (i < sq1->length)
		sq3->data[k++] = sq1->data[i++];
	while (j < sq2->length)
		sq3->data[k++] = sq2->data[j++];
	sq3->length = k;
	return true;
}
