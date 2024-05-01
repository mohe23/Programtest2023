// 表达式求值，只有 +、-、*、/四个操作符

#include<stdio.h>
#include<stdlib.h>
#include<string.h>// 使用到strlen函数
#include"structs.h"//头文件中有顺序栈SqStack的结构体定义
#define maxsize 20

void Initstack(SqStack *st){// 初始化顺序栈
    st->ele = (int*)malloc(sizeof(int)*maxsize);//给顺序栈创建1个大小是maxsize的数组。
    st->top=-1;//初始化“栈顶指针”值。
    st->stacksize=maxsize;//栈
}

void Push(SqStack *st,int elm){// 进栈操作，若把elm进栈
     if(st->top<(st->stacksize-1)){// 栈未满，可以将元素elm进栈。
         st->top++;//将栈顶指针加1，只要栈不空，栈顶指针始终指向栈顶元素。
         st->ele[st->top]=elm;//将元素elm进栈。
     }
     else// 栈已满，
         printf("顺序栈已满，进栈失败！\n");
}

int Pop(SqStack *st){// 将栈顶元素出栈
   int e;
   if(st->top!=-1){// 栈不空，将栈顶元素出栈。
       e = st->ele[st->top];//栈顶元素
       st->top--;//将栈顶指针指向新的栈顶元素。
       //printf("出栈成功！\n");
   }
   else
       printf("当前栈为空栈，出栈失败\n");

return e;
}

int EmptyStack(SqStack *st){// 判断栈st是否栈空
    int ret;
    if(st->top==-1)//下次遇到“==”条件，还是将数字写在前面比较好，防止写错
        ret = 1;//栈是空栈
    else
        ret = 0;//栈不是空栈

return ret;
}

int GetOrder(char e,char *b,int ble){//求出字符e在数组中存储位置的下标。 ble-数组长度
    int i,ret=-1;//返回值
    for(i=0;i<ble;i++){
        if(b[i]==e){
            ret = i;//找到下标
            break;//找到后立即跳出循环
        }
    }
return ret;
}

int Calab(int a,int b,int order,char *c){// 计算a 操作符 b的值
    int ret;
    switch(c[order]){
    case '+':
        ret = a+b;
        break;
    case '-':
        ret = a-b;
        break;
    case '*':
        ret = a*b;
        break;
    case '/':
        ret = a/b;
        break;
    }

return ret;//返回计算结果
}

int Operate(char *ch,char *b){// 表达式求值函数，ch-存储的是表达式 b-存储的是“+、-、*、/”，且按照顺序存储
    int i,ret,order,length,lengthb,flag,e1,e2,e3;
    SqStack s1,s2;//创建2个栈
    Initstack(&s1);Initstack(&s2);//初始化2个栈,栈s1存储操作数 栈s2存储操作符
    length = strlen(ch);lengthb = strlen(b);//计算表达式长度,计算数组b长度
    for(i=0;i<length;i++){//开始扫描表达式
        if((ch[i]-'0'>=0)&&(ch[i]-'0'<=9)){//当前扫描到的元素是数字字符
            Push(&s1,ch[i]-'0');//将操作数进栈
        }
        else{//扫描到的是4个操作符
            order = GetOrder(ch[i],b,lengthb);//找到代表操作符ch[i]的下标
            Push(&s2,order);//将下标入栈s2
        }
    }
    flag = EmptyStack(&s2);//求出栈s2是否为空栈
    while(1!=flag){//只要栈s2不空，就循环
        order = Pop(&s2);//操作符栈出栈1个操作符
        e2=Pop(&s1);//操作数栈s1出栈1个元素
        e1=Pop(&s1);//操作数栈s1再次出栈1个元素
        e3 = Calab(e1,e2,order,b);//计算e1、e2进行操作后的值
        Push(&s1,e3);//将计算结果进栈s1；
        flag = EmptyStack(&s2);//判断栈s2是否为空
    }
    if(!EmptyStack(&s1))
        ret = Pop(&s1);//最终计算结果应该存储在栈s1中，栈s1未空
    else
        printf("Operate函数执行出错!\n");

return ret;//返回计算结果。
}

/*
int main(){
    int i,le,ret;
    char ca[]="3+6/2";//表达式
    char cb[]={'+','-','*','/'}//存储2个操作符
    le = strlen(ca);
    ret = Operate(ca,cb);//计算表达式的值
    for(i=0;i<le;i++)
        printf("%c",ca[i]);
    printf("的值：%d\n\n",ret);
return 0;
}
*/
