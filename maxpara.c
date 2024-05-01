// 最大公约数  最小公倍数

#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b){// 辗转相除法 求最大公约数
   int ret;//返回值
   if(b==0)
       ret = a;// 这个是最大公约数
   else
       ret = gcd(b,a%b);//使用递归函数,第1个形参更新为前一次调用时的参数b；第2个形参更新为：第1次调用时，计算的a%b

return ret;
}

int lcm(int a,int b){// 求最小公倍数
    int ret,z;
    z = gcd(a,b);//求出a、b的最大公约数
    ret = a*b/z;// 最小公倍数 = a*b/最大公约数

return ret;
}
/*
int main(){
    int a,b,r,t;
    a=16;b=24;
    r = gcd(a,b);//求出最大公约数
    t = lcm(a,b);//求出最小公倍数
    printf("%d和%d的最大公约数，最小公倍数：%d，%d\n",a,b,r,t);

return 0;
}
*/
