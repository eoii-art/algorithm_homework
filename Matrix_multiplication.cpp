#include<iostream>
#define MAX 100
using namespace std;

void MatrixChain(int n,int p[MAX],int m[MAX][MAX],int s[MAX][MAX]){
    int i, j, r,k;
    for (i = 1; i <= n;i++) //����������Ϊ1ʱ���������
        m[i][i] = 0;
    for (r = 2; r <= n;r++)//r:���������� 
        for (i = 1; i <= n - r + 1;i++){//i:��
            j = r + i - 1;
            s[i][j] = i;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (k = i+1; k < j;k++){//�������жϿ�λ��
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
}
void output(int s[MAX][MAX],int i,int j){
    if(i==j)
        cout << "A" << i;
    else{
        cout << "(";
        output(s, i, s[i][j]);
        output(s, s[i][j]+1,j);
        cout << ")";
    }
}

int main()
{
    int n;
    int p[MAX],m[MAX][MAX],s[MAX][MAX];
    /*
    p:��¼ÿ������ά��
    m:��¼��С�˷�����
    s:m[i][j]ȡ����Сֵʱ�Ͽ���λ��
    */
    cout << "����������:" << endl;
    cin >> n;
    cout << "����ÿ����������������һ�����������" << endl;
    for (int i = 0; i <= n;i++)
        cin >> p[i];
    MatrixChain(n, p, m, s);
    cout << "������˵���С������Ϊ��" <<m[1][n]<< endl;
    cout << "��Ӧ�ļ����ŷ�ʽΪ:" << endl;
    output(s, 1, n);
    system("pause");

    return 0;
}