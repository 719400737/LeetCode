#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int add(int a, int b) {//使用二进制求和

        while(b!=0){
            int c=((unsigned int)(a&b)<<1);//a&b是将位数上都为1的数相加在向左移动一位
            a^=b;// 此处是将a和b不同1的位数相加
            b=c; //此时b置为c进行循环
        }
        return a;
    }
};

int main(){
    int a=-1;
    int b=4;
    Solution s;
    int res=s.add(a,b);
    cout<<res<<endl;


    return 0;
}