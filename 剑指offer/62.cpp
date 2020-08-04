#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) { //一共n个人，每次干掉第m个
        int pos=0;  //最有只有一个人时，其位置为0
        for(int i=1;i<n;i++){ //依次反推找到其原始位置  i表示现在几个数
            pos=(pos+m)%(i+1);//规律是，当前位置往后推m位，在对（i+1）取模
        }
        return pos;
    }
};

int main(){



    return 0;
}