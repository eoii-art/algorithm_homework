#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;
void LSC(int m, int n,int c[][MAX],char x[],char y[])
{
    int i, j;
    for (i = 0; i <= m;i++)
        c[0][i] = 0;//��ʼ����0��
    for (i = 0; i <= n;i++)
        c[i][0] = 0;//��ʼ����0��
    for (i = 1; i <= m;i++)
        for (j = 1; j <= n;j++)
        {
            if(x[i]==y[j]){
                c[i][j] = c[i - 1][j - 1] + 1;
                
            }
            else if(c[i][j-1]>c[i-1][j]){
                c[i][j] = c[i][j - 1];
                
            }
            else{
                c[i][j] = c[i-1][j];
                
            }
                
        }
}
void output(int i, int j,int c[][MAX],char x[],char y[])//����������
{
    if(i==0||j==0)//�ݹ���ֹ����
        return;
    if(x[i]==y[j]){
        output(i - 1, j - 1,c,x,y);
        cout << x[i];
    }
    else if(c[i][j-1]>c[i-1][j])
        output(i, j - 1,c,x,y);
    else 
        output(i-1, j, c,x,y);   

}
int main()
{
    char x[MAX], y[MAX];
    int  c[MAX][MAX];
    cout << "�������������У�" << endl;
    while(scanf("%s%s",x+1,y+1)!=NULL)//Ϊ�����±��1��ʼ
    {
        int m = strlen(x)-1;
        int n = strlen(y)-1;
        LSC(m, n, c, x, y);
        cout << "����������г���Ϊ" <<c[m][n]<<endl;
        cout << "�����������Ϊ��";
        output(m,n,c,x,y);
        cout << endl;
        cout << "�������������У�" << endl;
    }
    system("pause");

    return 0;
}