#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;
void LSC(int m, int n,int c[][MAX],char x[],char y[])
{
    int i, j;
    for (i = 0; i <= m;i++)
        c[0][i] = 0;//初始化第0行
    for (i = 0; i <= n;i++)
        c[i][0] = 0;//初始化第0列
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
void output(int i, int j,int c[][MAX],char x[],char y[])//输出最长子序列
{
    if(i==0||j==0)//递归终止条件
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
    cout << "请输入两个序列：" << endl;
    while(scanf("%s%s",x+1,y+1)!=NULL)//为了让下标从1开始
    {
        int m = strlen(x)-1;
        int n = strlen(y)-1;
        LSC(m, n, c, x, y);
        cout << "最长公共子序列长度为" <<c[m][n]<<endl;
        cout << "最长公共子序列为：";
        output(m,n,c,x,y);
        cout << endl;
        cout << "请输入两个序列：" << endl;
    }
    system("pause");

    return 0;
}