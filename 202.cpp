#include<bits/stdc++.h>
using namespace std;
class Solution {
    int helper(int n){
        int res=0,num=0;
        while(n>0){
            num=n%10;
            n/=10;
            res+=num*num;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;  //使用map来判断是否产生了环，若为环则直接返回false
        m[n]=1;
        while(n!=1){
            n=helper(n);
            if(m.count(n))
                return false;
            m[n]=1;
        }
        return true;
        
    }
};

int main(){

    int n=19;
    Solution s;
    s.isHappy(n);
    return 0;
}