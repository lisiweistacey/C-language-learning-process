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
