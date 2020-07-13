#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) { //将新进来的数据放在队列的头，每次插入数据需要将队列进行调整
        int m=que.size();
        que.push(x);
        for(int i=0;i<m;i++){
            int temp=que.front();
            que.push(temp);
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res=que.front();
        que.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res=que.front();
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

int main(){


    return 0;
}