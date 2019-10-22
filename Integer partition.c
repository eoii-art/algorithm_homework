#include<stdio.h>
void output(int a[],int n)
{
    for (int i = 0; i < n - 1;i++)
        printf("%d+", a[i]);
    printf("%d\n", a[n-1]);
}
int Solve(int n,int m,int len,int a[])
{
    if(m==1)
    {
        if (n==0)
        {
            output(a, len);
            return 1;
        }
        else if(n>0){
            a[len] = 1;
            return Solve(n - 1, m, len + 1, a);
        }
    }
    else if(n==1){
        a[len] = 1;
        output(a, len + 1);
        return 1;
    }
    else if(n<m)
        return Solve(n, n, len, a);
    else if(m==n){
        a[len] = n;
        output(a, len + 1);
        return Solve(n, n - 1, len, a)+1;
    }
    else if(n>m){
        a[len] = m;
        return Solve(n - m, m, len, a) + Solve(n, m - 1, len, a);
    }


    return 0;
}

int main()
{
    int number,time;
    int a[100] = {0};
    while(scanf("%d", &number)){
        time=Solve(number, number,0,a);
        printf("\n%d有以上%d种不同划分\n-------------\n",number,time);
    }
    return 0;
}
