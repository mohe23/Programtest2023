// A+B��3�ı��� B+C��5�ı��� A+B+C��7�ı��� ����N��ʹA+B+C=N�����A��B��C

#include<stdio.h>
#include<stdlib.h>

void Jud(int a,int as,int s){//a��ʾB��ʼֵ as-һ������ѭ���ı���������ֵӦ����5�ı���  s-��ʾN
    int i,j,k,ret=0;//Ĭ�ϲ���������
    for(j=a;j<=as;j++){//j��ʼ��0��ʼ���� j-B
        k = as-j;//�����C  k-C
        i = s-j-k;//�����A
        if(0==((i+j)%3))//��������
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
