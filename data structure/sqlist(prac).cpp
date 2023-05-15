#include <stdio.h>

#define MaxSize 50
typedef int Elemtype; //让顺序表存储其他类型元素时，可以快速完成代码修改

//静态分配
typedef struct{
    Elemtype data[MaxSize];
    int length; //顺序表当前长度
}SqList;

//插入函数
bool ListInsert(SqList &L, int i, Elemtype element){
    //判断i是否合法，i是插入的位置（不是下标）
    if(i<1 || i>L.length+1){
        return false;
    }
    //如果存储空间满了，也不能插入
    if(L.length >= MaxSize){
        return false;
    }
    //把后面的元素依次往后移，空出位置
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element; //插入元素
    L.length++;
    return true;
}

//删除顺序表中的元素的函数 （要改变的必须加&）
bool ListDelect(SqList &L, int i, Elemtype &e){
    if(i<1 || i>L.length){
        return false;
    }
    if(L.length == 0){
        return false;
    }
    //首先保存要删除的元素的值
    e = L.data[i-1];
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//按值查找，返回位置
int LocateElemtype(SqList L, Elemtype element){
    for(int i = 1; i < L.length; i++){
        if(element == L.data[1]){
            return i+1; //返回位置不是位序
        }
    }
    return 0; //循环结束没找到，返回0，函数调用结束
}

//打印顺序表
void PrintList(SqList L){
    for(int i = 0; i < L.length; i++){
        printf("%3d", L.data[i]); //为了打印到同一行
    }
    printf("\n");
}

//顺序表的初始化及插入操作
int main() {
    SqList L; //先定义一个顺序表
    bool ret; //一般用来表判断
    L.data[0] = 1; //放置元素,赋值
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3; //设置长度
    //插入
    ret = ListInsert(L, 2, 60);
    if(ret){
        printf("insert sqlist success\n");
        PrintList(L);
    }
    else{
        printf("insert sqlist failed\n");
    }
    printf("--------------------------------\n");
    //删除
    Elemtype del; //删除的元素存入del中
    ret = ListDelect(L, 3, del);
     if(ret){
        printf("delete sqlist success\n");
        printf("del element = %d\n", del);
        PrintList(L); //顺序表打印
    }
    else{
        printf("delete sqlist failed\n");
    }
    printf("------------------------\n");
    //查找
    int pos; //存储返回元素的位置
    pos = LocateElemtype(L, 60);
    if(pos){
        printf("element pos = %d\n", pos);
    }
    else{
        printf("don't found this element\n");
    }

    return 0;
}
