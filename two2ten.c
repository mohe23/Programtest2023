// ������תʮ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int two2ten(char *b){
    int i,j,v,le,ret;
    j = ret = 0;
    le = strlen(b);//�����ַ�����b�洢�ַ�����
    for(i=le-1;i>=0;i--){// �Ӻ���ǰɨ��
        v = pow(2,j);//��סÿѭ��1�Σ�j����1
        if('1'==b[i]){//��ǰ�ַ�Ϊ��1��
            ret += v;
        }
        j++;//��סÿ��ѭ��1�Σ�jҪ��1
    }
return ret;
}
/*
// Ҫ����main����ʱ�����Բ���ɾ����/*��,������ǰ��ֱ�Ӽ��ϡ�//����������
int main(){
    int e;
    char ch[40];
    printf("���������������");
    scanf("%s",ch);//�����������
    e = two2ten(ch);//ת����ʮ������
    printf("��������%sת����ʮ��������%d\n",ch,e);

return 0;
}
*/
