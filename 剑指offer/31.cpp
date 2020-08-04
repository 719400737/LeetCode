#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        set<int> s;
        stack<int> sta;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            sta.push(pushed[i]); //借用辅助栈，每个元素压栈
            s.insert(pushed[i]);
            if(!s.count(popped[j])){  //当已经存过某个元素，立即取栈顶与之比较。相等则继续，否则返回false
                continue;
            }
            else{
                while(s.count(popped[j])){
                    int t=sta.top();
                    sta.pop();
                    s.erase(t);
                    if(t==popped[j]){
                        if(j==popped.size()-1)
                            return true;
                        j++;
                    }
                    else    return false;
                }
            }
        }
        while(!sta.empty()){
            int temp=sta.top();
            if(temp!=popped[j++])
                return false;
            sta.pop();
        }
        return true;
    }
};

int main(){
    vector<int> pu={1,2,3,0},po={2,3,0,1};
    Solution s;
    bool res=s.validateStackSequences(pu,po);
    cout<<res<<endl;

    return 1;
}