// 判断1个数是否是素数

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Judge(int num){//判断num是否是素数
    int i, ret=1;//
    for(i=2;i<=sqrt(num);i++){//i<=开平方，可以提高算法的效率
        if(num%i==0){
            ret = 0;//表示num不是素数
            break;//一旦确定不是素数，直接跳出循环即可
        }
    }
return ret;//返回值
}
/*
int main(){
    int a,b,c;
    char d;
    c=2;
    d = c+'0';//将int型数字转变为字符型数字

    printf("d: %c\n\n",d);
    printf("请输入1个整数：");
    scanf("%d",&a);
    b = Judge(a);
    if(1==b)//写程序，脑子要清醒一点。
        printf("%d是1个素数！\n\n",a);
    else
        printf("%d不是1个素数！\n\n",a);
    printf("%%d %%c  %%s\n");//输出“%d”
return 0;
}
*/
