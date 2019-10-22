#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;
void LSC(int m, int n,int c[][MAX],int s[][MAX],char x[],char y[])
{
    int i, j;
    for (i = 0; i <= n;i++)
        c[0][i] = 0;//初始化第0行
    for (i = 0; i <= m;i++)
        c[i][0] = 0;//初始化第0列
    for (i = 1; i <= m;i++)
        for (j = 1; j <= n;j++)
        {
            if(x[i]==y[j]){
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1;
            }
            else if(c[i][j-1]>c[i-1][j]){
                c[i][j] = c[i][j - 1];
                s[i][j] = 2;
            }
            else{
                c[i][j] = c[i-1][j];
                s[i][j] = 3;
            }
                
        }
}
void output(int i, int j,int s[][MAX],char x[])//输出最长子序列
{
    if(i==0||j==0)//递归终止条件
        return;
    if(s[i][j]==1){
        output(i - 1, j - 1,s,x);
        cout << x[i];
    }
    else if(s[i][j]==2)
        output(i, j - 1, s, x);
    else if(s[i][j]==3)
        output(i-1, j, s, x);   

}

int main()
{
    char x[MAX], y[MAX];
    int s[MAX][MAX], c[MAX][MAX];
    cout << "请输入两个序列:" << endl;
    while(scanf("%s%s",x+1,y+1)!=NULL)//循环读取
    {
        int m = strlen(x)-1;
        cout << m;
        int n = strlen(y)-1;
        cout << n;
        LSC(m, n, c, s, x, y);
        cout << "最长公共子序列长度为" <<c[m][n]<<endl;
        cout << "最长公共子序列为:";
        output(m, n, s, x);
        cout << endl;
        cout << "请输入两个序列:" << endl;
    }
    system("pause");

    return 0;
}
