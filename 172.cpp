#include<bits/stdc++.h>
using namespace std;
class Solution {
    long long helper(long long n){
        long long five=5;
        int res=0;
        while(n>=five){  //除5可以得到基础有多少个5组成
            res+=n/five; //但如果可以被25（5*5）整除的话，结果应当+1；
            five*=5;  //所以依次查看可以由多少25 组成，125组成。等等
        }
        return res;
    }
public:
    long long trailingZeroes(long long n) {
        //先写一个n可以有多少拆成多少个5相×
        long res=0;
        res=helper(n);
        return res;
    }
};

int main(){
    int n,res;
    Solution s;
    while(cin>>n){
        res=s.trailingZeroes(n);
        cout<<res<<endl;
    }
    

    return 0;
}