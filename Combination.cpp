#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
 
void Combination_n(const vector<char> &v,vector<char> &cur_v, int index, int number)
{
    if(number==0){     
		for(auto &a:cur_v)
			cout << a;
		cout << endl;
		return;
    }
 
    if(index>=v.size()){
        return;
    }
 
    cur_v.push_back(v[index]);
    Combination_n(v,cur_v,index+1,number-1);
    cur_v.pop_back();
    Combination_n(v,cur_v,index+1,number);
}
 
void Combination(const vector<char> &v)
{
    if(v.empty()){
        return;
    }
 
    vector<char> curr_v;
    for(int i=1; i<=v.size(); ++i){
        Combination_n(v,curr_v,0,i);
    }
 
}
 
int main()
{
    vector<char> v;
    char c;
    while((c = getchar()) != '\n')
        v.push_back(c);
	cout << "组合种类数有" << pow(2, v.size()) - 1<<"种，分别为:"<<endl;
    Combination(v);
    system("pause");
    return 0;
}
