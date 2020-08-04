#include<bits/stdc++.h>
using namespace std;
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        //进来的元素放在栈尾
        while(!s1.empty()){
            int v=s1.top();
            s1.pop();
            s2.push(v);
        }
        s1.push(value);
        while(!s2.empty()){
            int v=s2.top();
            s2.pop();
            s1.push(v);
        }
    }
    
    int deleteHead() {
        if(s1.empty())
            return -1;
        int res=s1.top();
        s1.pop();
        return res;
    }
private:
    stack<int> s1;
    stack<int> s2;
};


int main(){



    return 1;
}