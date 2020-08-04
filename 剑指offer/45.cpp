#include<bits/stdc++.h>
using namespace std;
bool comp(string s1,string s2){
        string num1=s1+s2,num2=s2+s1;
        long long  n1=stoll(num1);
        long long  n2=stoll(num2);
        if(n1<n2)
            return true;
        else    return false;
    }
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vec;  //其实是在考虑排序算法,具体的排序是比较两个数相加,及调换顺序后相加的比较
        for(auto i:nums){
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end(),comp);
        string res;
        for(auto i:vec)
            res+=i;
        return res;
            
    }
};

int main(){

    vector<int> b={3,301,30001,34,5,9};
    Solution s;
    string res=s.minNumber(b);
    cout<<res<<endl;
    return 1;
}