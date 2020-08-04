#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        map<int,long long> m;
        long long res=0;
        int i=1,rr=0;
        for(;i<11;i++){
            if(i==1)
                res=10;
            else
                res+=i*(pow(10,i)-pow(10,i-1));
            m[i]=res;
            if(m[i]<=n)
                continue;
            else
                break;
        }
        if(n<10)
            return n;
        int index=(n-m[i-1])/i;
        int yu=(n-m[i-1])%i;
        int num=pow(10,i-1)+index;
        stringstream ss;
        ss<<num;
        string s;
        ss>>s;
        rr=s[yu]-'0';
        return rr;
    }
};

int main(){

    int n=10;
    while(cin>>n){
    Solution s;
    int res=s.findNthDigit(n);
    cout<<res<<endl;
    }
    return 1;
}