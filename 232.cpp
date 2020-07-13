#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) { //push进来的应该放在栈的最后,使用两个栈来协作完成
        while(!st1.empty()){
            int v=st1.top();
            st1.pop();
            st2.push(v);
        }
        st1.push(x);
        while(!st2.empty()){
            int v=st2.top();
            st2.pop();
            st1.push(v);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=st1.top();
        st1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res=st1.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
};

int main(){



    return 1;
}