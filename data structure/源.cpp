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
//��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ��
//�ճ���λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�

/*ɾ��˳���sq����СֵԪ�ؽ�㣬��ͨ�����ò���value���ز���*/
bool del_min(struct Sqlist* sq, int* value) {
	if (sq->length == 0) {
		printf("����");
		return false;
	}
	int min_pos = 0;//��¼��СֵԪ�ص��±�
	*value = sq->data[0];
	for (int i = 1; i < sq->length; i++) {
		if (*value > sq->data[i]) {
			min_pos = i; 
			*value = sq->data[i]; //������Сֵ
		}
	}
	sq->data[min_pos] = sq->data[sq->length - 1];//�����һ��Ԫ�����
	sq->length--; //���ȼ�һ 
	return true;
}

//02
//���һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
bool reversal(struct Sqlist *sq) {
	if (sq->length == 0)
		return false;
	int temp;//�������м�ֵ
	for (int i = 0; i < sq->length / 2; i++) {
		temp = sq->data[i];
		sq->data[i] = sq->data[sq->length - i -1];
		sq->data[sq->length - i - 1] = temp;
	}
	return true;
}

//03
//�Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨,
//���㷨ɾ�����Ա�������ֵΪx������Ԫ�ء�

/*˼·����k��¼˳����в�����x������Ԫ��(����Ҫ���������Ԫ��)
ɨ��ʱ��������x��Ԫ���ƶ����±�Ϊk��λ�ã�����kֵ*/
bool del_x(struct Sqlist* sq, int x) {
	if (sq->length == 0)
		return false;
	int k = 0;//��¼ֵ������x��Ԫ�ص��±�
	for (int i = 0; i < sq->length; i++) {
		if (sq->data[i] != x) {
			sq->data[k] = sq->data[i];
			k++;
		}
	}
	sq->length = k;
}

//04
//������˳�����ɾ����ֵ�ڸ���ֵs��t֮��(Ҫ��s<t)������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
bool del_st_index(struct Sqlist* sq, int s, int t) {
	int i, j;
	if (s >= t || sq->length == 0)
		return false;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] >= s) {
			break; //�ҵ�ֵ���ڻ����s��Ԫ��
		}
	}
	if (i >= sq->length)
		return false;
	for (j = 0; j < sq->length && sq->data[j] <= t; j++);
	for (; j < sq->length; j++, i++) {
		sq->data[i] = sq->data[j]; //ֵ����t��Ԫ����ǰ������ֵ���ڻ����s��Ԫ��λ�ÿ�ʼ
	}
	sq->length = i;
	return true;
}

//05
//��˳�����ɾ����ֵ�ڸ���ֵs��t֮��(����s��t,Ҫ��s<t)������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
bool del_st(struct Sqlist* sq, int s, int t) {
	int k = 0;
	if (s >= t || sq->length == 0)
		return false;
	for (int i = 0; i < sq->length; i++) {
		if (sq->data[i] >= s && sq->data[i] <= t) {
			k++;
		}
		else {
			sq->data[i - k] = sq->data[i]; //����ǰԪ��ǰ��k��λ��
		}
	}
	sq->length = sq->length - k;
}