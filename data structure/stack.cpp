#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //数组
    int top;  //栈顶指针，始终指向栈顶的一个变量
}Sqstack;

//初始化栈
void InitStack(Sqstack &S){
    S.top = -1; //初始化栈顶指针(让栈为空)
}

//判空
bool StackEmpty(Sqstack S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

//入栈
bool Push(Sqstack &S, ElemType x){
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x; //指针加一，再入栈
    return true;
}

bool GetTop(Sqstack S, ElemType &x){
    if(StackEmpty(S))
        return false;
    x = S.data[S.top];
    return true;
}

//出栈
bool Pop(Sqstack &S, ElemType &x){
    if(S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

int main(){
    Sqstack S;
    InitStack(S);
    bool flag = StackEmpty(S);
    if(flag)
        printf("Stack is empty\n");

    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    ElemType x, e;
    flag = GetTop(S, x);
    if(flag){
        printf("get top %d\n", x);
    }
    
    Pop(S, e);
    flag = GetTop(S, x);
    if(flag){
        printf("the pop elem is %d\nget top %d\n", e,x);
    }
    else{
        printf("fail\n");
    }

    return 0;
}