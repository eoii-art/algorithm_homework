#include<iostream>
#define MAX 100
using namespace std;

void MatrixChain(int n,int p[MAX],int m[MAX][MAX]){
    int i, j, r,k;
    for (i = 1; i <= n;i++) //矩阵链长度为1时，无需计算
        m[i][i] = 0;
    for (r = 2; r <= n;r++)//r:矩阵链长度 
        for (i = 1; i <= n - r + 1;i++){//i:行
            j = r + i - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (k = i+1; k < j;k++){//遍历所有断开位置
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                }
            }
        }
}
void output(int m[MAX][MAX],int p[MAX],int i,int j){
    int s = 0;
    if(i==j)
        cout << "A" << i;
    else{
        cout << "(";
        //寻找断开的位置
        if (m[i][j]== m[i + 1][j] + p[i - 1] * p[i] * p[j])
            s = i;
        else for (int k = i+1; k < j;k++)
            if( m[i][j]==m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]){
                s = k;
                break;
            }
        output(m,p, i,s);
        output(m,p ,s+1,j);

        cout << ")";
    }
}

int main()
{
    int n;
    int p[MAX],m[MAX][MAX];
    /*
    p:记录每个矩阵维数
    m:记录最小乘法次数
    s:m[i][j]取得最小值时断开的位置
    */
    cout << "输入矩阵个数:" << endl;
    cin >> n;
    cout << "输入每个矩阵的行数及最后一个矩阵的列数" << endl;
    for (int i = 0; i <= n;i++)
        cin >> p[i];
    MatrixChain(n, p, m);
    cout << "矩阵相乘的最小计算量为：" <<m[1][n]<< endl;
    cout << "相应的加括号方式为:" << endl;
    output(m,p, 1, n);
    system("pause");

    return 0;
}