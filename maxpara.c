// ���Լ��  ��С������

#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b){// շת����� �����Լ��
   int ret;//����ֵ
   if(b==0)
       ret = a;// ��������Լ��
   else
       ret = gcd(b,a%b);//ʹ�õݹ麯��,��1���βθ���Ϊǰһ�ε���ʱ�Ĳ���b����2���βθ���Ϊ����1�ε���ʱ�������a%b

return ret;
}

int lcm(int a,int b){// ����С������
    int ret,z;
    z = gcd(a,b);//���a��b�����Լ��
    ret = a*b/z;// ��С������ = a*b/���Լ��

return ret;
}
/*
int main(){
    int a,b,r,t;
    a=16;b=24;
    r = gcd(a,b);//������Լ��
    t = lcm(a,b);//�����С������
    printf("%d��%d�����Լ������С��������%d��%d\n",a,b,r,t);

return 0;
}
*/
