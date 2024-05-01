// 二进制转十进制

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int two2ten(char *b){
    int i,j,v,le,ret;
    j = ret = 0;
    le = strlen(b);//计算字符数组b存储字符个数
    for(i=le-1;i>=0;i--){// 从后向前扫描
        v = pow(2,j);//记住每循环1次，j都加1
        if('1'==b[i]){//当前字符为‘1’
            ret += v;
        }
        j++;//记住每次循环1次，j要加1
    }
return ret;
}
/*
// 要调用main函数时，可以不用删除“/*”,可以在前面直接加上“//”，消掉它
int main(){
    int e;
    char ch[40];
    printf("请输入二进制数：");
    scanf("%s",ch);//输入二进制数
    e = two2ten(ch);//转换成十进制数
    printf("二进制数%s转换成十进制数：%d\n",ch,e);

return 0;
}
*/
