#include<iostream>
#define MAX 100
using namespace std;

void optimal_BST(int n,double a[MAX],double b[MAX],double w[MAX][MAX],double m[MAX][MAX],int s[MAX][MAX]){
    int i, j, r,k;
    for (i = 0; i < n;i++){ //��ʼ��
        m[i+1][i] =0;
        w[i + 1][i] = a[i];
    }
    for (r = 1; r <= n;r++)//����
        for (i = 1; i <= n - r+1;i++){//i:��
            j = r + i-1;//��Ӧ��������
            int i1 = s[i][j - 1]>i?s[i][j - 1]:i;
            int j1 = s[i + 1][j]<j?s[i + 1][j]:j;
            s[i][j] = i1;
            w[i][j] = w[i][j-1] +a[j]+b[j];
            m[i][j] = w[i][j]+m[i][i1-1]+m[i1+1][j];//��ʼ������i�Ͽ�
           

            for (k = i1+1; k <=j1;k++){//�������жϿ�λ��
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
        cout << "��x" << root << "Ϊ��������ƽ���Ƚϴ���Ϊ:"<<m[i][j]/w[i][j]<<endl;
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
    a:(xi,xi+1)����
    b:xi����
    w:��ȡ����
    m:���ƽ��·��
    s:xi��xjԪ����ɵ������ĸ�
    */
    cout << "����Ԫ�ظ���:" << endl;
    cin >> n;
    for (int i = 1; i <= n;i++){
    cout << "��BST�ڽ�����ҵ�Ԫ��x"<<i<<"�ĸ���Ϊ" << endl;
    cin >> b[i];
    }
    
    for (int i = 0; i <= n;i++){
        cout << "����Ԫ����Ҷ�ڵ�(x"<<i<<",x"<<i+1<<")��Χ�ڵĸ���Ϊ��";
        cin >> a[i];
    }

    cout << "----------------------" << endl;
    optimal_BST(n,a,b,w, m, s);

    cout << "ƽ���Ƚϴ���Ϊ��" << m[1][n] << endl;
    cout << "��Ӧ�ļ����ŷ�ʽΪ:" << endl;
    output_BST(s, 1, n);
    cout << endl;

    output_WPL(s,1,n,m,w);//���������˳�����ÿ�������ĸ�

    system("pause");    
    return 0;
}