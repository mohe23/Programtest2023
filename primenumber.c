// �ж�1�����Ƿ�������

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Judge(int num){//�ж�num�Ƿ�������
    int i, ret=1;//
    for(i=2;i<=sqrt(num);i++){//i<=��ƽ������������㷨��Ч��
        if(num%i==0){
            ret = 0;//��ʾnum��������
            break;//һ��ȷ������������ֱ������ѭ������
        }
    }
return ret;//����ֵ
}
/*
int main(){
    int a,b,c;
    char d;
    c=2;
    d = c+'0';//��int������ת��Ϊ�ַ�������

    printf("d: %c\n\n",d);
    printf("������1��������");
    scanf("%d",&a);
    b = Judge(a);
    if(1==b)//д��������Ҫ����һ�㡣
        printf("%d��1��������\n\n",a);
    else
        printf("%d����1��������\n\n",a);
    printf("%%d %%c  %%s\n");//�����%d��
return 0;
}
*/
