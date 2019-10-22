#include<iostream>
#define MAX 10000
using namespace std;


void Bubble_sort(int a[],int l,int r)
{
    int i, P;
    int flag;
    for (P = r-l; P >=0;P--){
        flag = 0;
        for (i = l; i < l+P;i++)
            if(a[i]>a[i+1]){
                swap(a[i], a[i + 1]);
                flag = 1;
            }
        if(flag==0)
            break;
    }
}
 

int Partition(int a[],int l,int r,int x)
{
    int i = l - 1;
    int j=r+1;
    for (;;)
    {
        while (a[++i] < x&&i<r)
            ;
        while(a[--j]>x)
            ;
        
        if(i>=j)
            break;
        swap(a[i], a[j]);
    }
    return j;       
}

 
int Select(int a[],int l,int r,int k)
{
    int i;
    if(r-l<=75){
        Bubble_sort(a,l,r);
        return a[l + k-1];
    }
    for (i = 0; i <= (r - l - 4) / 5;i++){
        Bubble_sort(a,l+5*i,l+5*i+4);
        swap(a[l + i], a[l + 5 * i + 2]);
    }
    int x = Select(a, l, l + (r - l - 4) / 5,(r - l - 4) / 10);
    i=Partition(a, l, r, x);
    int j = i - l + 1;
    if(k<=j)
        return Select(a, l, i,k);
    else
        return Select(a, i+1, r, k-j);


}
int main()
{
    int a[MAX];
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    
   cout<<"第"<<k<<"小的数为"<<Select(a, 0, n - 1, k);
    system("pause");
    return 0;
}