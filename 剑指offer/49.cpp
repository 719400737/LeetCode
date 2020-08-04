#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v={1};
        int res=0,count=1;
        int a=0,b=0,c=0; //3个指针，分别表示2的倍数，3的倍数，5的倍数
        while(count<n){
            int num=min(min(v[a]*2,v[b]*3),v[c]*5);//取出最小的一个加入数组中，并判断那个指针需要移动
            v.push_back(num);
            count++;
            if(num==v[a]*2)
                a++;
            if(num==v[b]*3)
                b++;
            if(num==v[c]*5)
                c++;
        }
        res=v.back();
        return res;
    }
};

int main(){
    int n;
    Solution s;
    int res;
    while(cin>>n){
        res=s.nthUglyNumber(n);
        cout<<res<<endl;
    }


    return 1;
}