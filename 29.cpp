#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool fuhao=(dividend>0) ^ (divisor>0);//0表示正
        long a=dividend,b=divisor;
        if(dividend<0)
            a*=-1;
        if(divisor<0)
            b*=-1;
        long tmp=0;
        int i=0;
        long res=0;
        while(a>=b){
            i=-1;
            tmp=0;
            if(b==1){
                res=a;
                break;
            }
            while(tmp<=a){
                i++;
                tmp=pow(2,i)*b;
            }
            a=a-b*pow(2,i-1);
            res+=pow(2,i-1);
        }
        if(fuhao)
            res=-res;
        if(res<INT_MIN)
            return INT_MIN;
        else if(res>INT_MAX)
            return INT_MAX;
        return res;
    }
};

int main(){
    int a=-10,b=3;
    Solution s;
    int res=s.divide(a,b);
    cout<<res<<endl;
    return 0;
}