#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct{// 顺序栈的结构体定义
    int *ele;//存放元素的数组
    int top;//栈顶指针，若top==-1，表示栈空；若top==(stacksize-1)，则栈满。这里没有按照教
    int stacksize;//栈的最大容量
}SqStack;


#endif // STRUCTS_H_INCLUDED
