#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int string2int(string s)
{
    int len = s.length();
    int result=0;
    for (int i = 0; i <len;i++)
    {
        result = 10 * result + s[i] - '0';

    }
    return result;
}
string int2string(int x)
{
    string result;
    stringstream temp;
    temp << x;
    temp>>result;
    return result;
}
string reverse(string s)
{
    string result;
    for (auto temp = s.end()-1; temp >= s.begin(); temp--)
        result.push_back(*temp);
    return result;
}
string SimpleMultiply(string x,string y)
{
    if(x.length()==0||y.length()==0)
        return int2string(0);
    return int2string(string2int(x) * string2int(y));
}
string Plus(string x,string y)
{
    int i, more = 0,sum=0;
    int length = max(x.length(), y.length());
    string s(length + 1, '0');
    x = reverse(x);
    y = reverse(y);
    for (i = 0; i < x.length() && i < y.length();i++)
    {
        sum = x[i] - '0' + y[i] - '0' + more;
        s[i] = sum % 10+'0';
        more = sum / 10;

    }
    if(i!=x.length())
        for (; i < x.length();i++)
        {
            sum = x[i] - '0' + more;
            s[i] = sum % 10+'0';
            more = sum / 10;

        }
    else
        for (; i < y.length();i++)
        {
            sum = y[i] - '0' + more;
            s[i] = sum % 10+'0';
            more = sum / 10;
        }
    if(more!=0)
        s[i] += more;
    else
        s.pop_back();
    s = reverse(s);
    return s;
   
   
}
string Minus(string x,string y)
{
    int i;
    x = reverse(x);
    y = reverse(y);
    string s(x.length(), '0');
    for (i = 0; i < y.length();i++)
    {
        if(x[i]<y[i])
        {
            x[i] += 10;
            x[i + 1] -= 1;
        }
        s[i] = x[i] - y[i] + '0';
    }
    for (; i < x.length();i++)
        s[i] = x[i];
    for (i = x.length() - 1; i > 0; i--)
        if(s[i]=='0')
            s.pop_back();
        else
            break;
    s = reverse(s);
    return s;
}
string add_pre_zero(string x,int num)
{
    string s(num, '0');
    s.append(x);
    return s;
}

string add_zero(string x,int num)
{
    string s(num, '0');
    x.append(s);
    return x;
}

string multiply(string x,string y)
{
    int xlength = x.length();
    int ylength = y.length();
    int n = max(xlength, ylength);
    if(n==xlength)
        y=add_pre_zero(y, n - ylength);
    else
        x=add_pre_zero(x, n - xlength);
    if(n==1)
        return SimpleMultiply(x, y);
    string xLeft = x.substr(0, n / 2);
    string xRight = x.substr(n / 2);
    string yLeft = y.substr(0, n / 2);
    string yRight = y.substr(n / 2);
    string s1 = multiply(xLeft, yLeft);
    string s2 = multiply(xRight, yRight);
    string s3 = multiply(Plus(xLeft, xRight),Plus(yLeft,yRight));
    string s4 = Minus(Minus(s3 , s1) , s2);
    string result = Plus(Plus(add_zero(s1,2 * (n - n / 2)), add_zero(s4,n - n / 2)), s2);
    return result;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << multiply(x, y) << endl;
    system("pause");
    return 0;
}
