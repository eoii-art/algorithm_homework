#include<iostream>
#define MAX 100
using namespace std;

void optimal_BST(int n,double a[MAX],double b[MAX],double w[MAX][MAX],double m[MAX][MAX],int s[MAX][MAX]){
    int i, j, r,k;
    for (i = 0; i < n;i++){ //初始化
        m[i+1][i] =0;
        w[i + 1][i] = a[i];
    }
    for (r = 1; r <= n;r++)//长度
        for (i = 1; i <= n - r+1;i++){//i:行
            j = r + i-1;//对应的列坐标
            int i1 = s[i][j - 1]>i?s[i][j - 1]:i;
            int j1 = s[i + 1][j]<j?s[i + 1][j]:j;
            s[i][j] = i1;
            w[i][j] = w[i][j-1] +a[j]+b[j];
            m[i][j] = w[i][j]+m[i][i1-1]+m[i1+1][j];//初始化：从i断开
           

            for (k = i1+1; k <=j1;k++){//遍历所有断开位置
                double t = w[i][j]+m[i][k-1] + m[k + 1][j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
}

void output_BST(int s[MAX][MAX],int i,int j){
    if(i==j){
        cout << "x" << i;
        return;
    }
    else if(j>=i){
        cout << "(";       
        output_BST(s, i, s[i][j]-1);
        cout << "(";
        cout << "x" << s[i][j];
        cout << ")";
        output_BST(s, s[i][j]+1,j);
        cout << ")";
    }
}
void output_WPL(int s[MAX][MAX],int i,int j,double m[MAX][MAX],double w[MAX][MAX])
{
    if(j<i)
        return;
    else{
        int root = s[i][j];
        cout << "以x" << root << "为根的子树平均比较次数为:"<<m[i][j]/w[i][j]<<endl;
        output_WPL(s,i,root-1,m,w);
        output_WPL(s,root+1,j,m,w);
    }


}
int main()
{
    int n;
    double a[MAX],b[MAX],m[MAX][MAX],w[MAX][MAX];
    int s[MAX][MAX];
    /*
    a:(xi,xi+1)概率
    b:xi概率
    w:存取概率
    m:最短平均路径
    s:xi到xj元素组成的子树的根
    */
    cout << "输入元素个数:" << endl;
    cin >> n;
    for (int i = 1; i <= n;i++){
    cout << "在BST内结点中找到元素x"<<i<<"的概率为" << endl;
    cin >> b[i];
    }
    
    for (int i = 0; i <= n;i++){
        cout << "所找元素在叶节点(x"<<i<<",x"<<i+1<<")范围内的概率为：";
        cin >> a[i];
    }

    cout << "----------------------" << endl;
    optimal_BST(n,a,b,w, m, s);

    cout << "平均比较次数为：" << m[1][n] << endl;
    cout << "相应的加括号方式为:" << endl;
    output_BST(s, 1, n);
    cout << endl;

    output_WPL(s,1,n,m,w);//按中序遍历顺序输出每个子树的根

    system("pause");    
    return 0;
}