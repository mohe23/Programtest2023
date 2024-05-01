// ���ʽ��ֵ��ֻ�� +��-��*��/�ĸ�������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>// ʹ�õ�strlen����
#include"structs.h"//ͷ�ļ�����˳��ջSqStack�Ľṹ�嶨��
#define maxsize 20

void Initstack(SqStack *st){// ��ʼ��˳��ջ
    st->ele = (int*)malloc(sizeof(int)*maxsize);//��˳��ջ����1����С��maxsize�����顣
    st->top=-1;//��ʼ����ջ��ָ�롱ֵ��
    st->stacksize=maxsize;//ջ
}

void Push(SqStack *st,int elm){// ��ջ����������elm��ջ
     if(st->top<(st->stacksize-1)){// ջδ�������Խ�Ԫ��elm��ջ��
         st->top++;//��ջ��ָ���1��ֻҪջ���գ�ջ��ָ��ʼ��ָ��ջ��Ԫ�ء�
         st->ele[st->top]=elm;//��Ԫ��elm��ջ��
     }
     else// ջ������
         printf("˳��ջ��������ջʧ�ܣ�\n");
}

int Pop(SqStack *st){// ��ջ��Ԫ�س�ջ
   int e;
   if(st->top!=-1){// ջ���գ���ջ��Ԫ�س�ջ��
       e = st->ele[st->top];//ջ��Ԫ��
       st->top--;//��ջ��ָ��ָ���µ�ջ��Ԫ�ء�
       //printf("��ջ�ɹ���\n");
   }
   else
       printf("��ǰջΪ��ջ����ջʧ��\n");

return e;
}

int EmptyStack(SqStack *st){// �ж�ջst�Ƿ�ջ��
    int ret;
    if(st->top==-1)//�´�������==�����������ǽ�����д��ǰ��ȽϺã���ֹд��
        ret = 1;//ջ�ǿ�ջ
    else
        ret = 0;//ջ���ǿ�ջ

return ret;
}

int GetOrder(char e,char *b,int ble){//����ַ�e�������д洢λ�õ��±ꡣ ble-���鳤��
    int i,ret=-1;//����ֵ
    for(i=0;i<ble;i++){
        if(b[i]==e){
            ret = i;//�ҵ��±�
            break;//�ҵ�����������ѭ��
        }
    }
return ret;
}

int Calab(int a,int b,int order,char *c){// ����a ������ b��ֵ
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

return ret;//���ؼ�����
}

int Operate(char *ch,char *b){// ���ʽ��ֵ������ch-�洢���Ǳ��ʽ b-�洢���ǡ�+��-��*��/�����Ұ���˳��洢
    int i,ret,order,length,lengthb,flag,e1,e2,e3;
    SqStack s1,s2;//����2��ջ
    Initstack(&s1);Initstack(&s2);//��ʼ��2��ջ,ջs1�洢������ ջs2�洢������
    length = strlen(ch);lengthb = strlen(b);//������ʽ����,��������b����
    for(i=0;i<length;i++){//��ʼɨ����ʽ
        if((ch[i]-'0'>=0)&&(ch[i]-'0'<=9)){//��ǰɨ�赽��Ԫ���������ַ�
            Push(&s1,ch[i]-'0');//����������ջ
        }
        else{//ɨ�赽����4��������
            order = GetOrder(ch[i],b,lengthb);//�ҵ����������ch[i]���±�
            Push(&s2,order);//���±���ջs2
        }
    }
    flag = EmptyStack(&s2);//���ջs2�Ƿ�Ϊ��ջ
    while(1!=flag){//ֻҪջs2���գ���ѭ��
        order = Pop(&s2);//������ջ��ջ1��������
        e2=Pop(&s1);//������ջs1��ջ1��Ԫ��
        e1=Pop(&s1);//������ջs1�ٴγ�ջ1��Ԫ��
        e3 = Calab(e1,e2,order,b);//����e1��e2���в������ֵ
        Push(&s1,e3);//����������ջs1��
        flag = EmptyStack(&s2);//�ж�ջs2�Ƿ�Ϊ��
    }
    if(!EmptyStack(&s1))
        ret = Pop(&s1);//���ռ�����Ӧ�ô洢��ջs1�У�ջs1δ��
    else
        printf("Operate����ִ�г���!\n");

return ret;//���ؼ�������
}

/*
int main(){
    int i,le,ret;
    char ca[]="3+6/2";//���ʽ
    char cb[]={'+','-','*','/'}//�洢2��������
    le = strlen(ca);
    ret = Operate(ca,cb);//������ʽ��ֵ
    for(i=0;i<le;i++)
        printf("%c",ca[i]);
    printf("��ֵ��%d\n\n",ret);
return 0;
}
*/
