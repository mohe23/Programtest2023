// A+B是3的倍数 B+C是5的倍数 A+B+C是7的倍数 输入N，使A+B+C=N，输出A，B，C

#include<stdio.h>
#include<stdlib.h>

void Jud(int a,int as,int s){//a表示B初始值 as-一个控制循环的变量，它的值应该是5的倍数  s-表示N
    int i,j,k,ret=0;//默认不符合条件
    for(j=a;j<=as;j++){//j开始从0开始加起 j-B
        k = as-j;//计算出C  k-C
        i = s-j-k;//计算出A
        if(0==((i+j)%3))//符合条件
            printf("%d %d %d\n",i,j,k);

    }
}
/*
int main(){
     int k1,s1,sum;
    k1=57;s1=60;sum=175;
    Jud(k1,s1,sum);
return 0;
}*/
/*
void findnums(int n){
    //int i,j,k;
    int k1,s1,sum;
    k1=55;s1=60;sum=175;
    Jud(k1,s1,sum);

}
*/
