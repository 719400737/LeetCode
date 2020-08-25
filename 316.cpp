#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> m;
        for(auto i:s){ //保存每个元素的出现次数
            m[i]++;
        }
        string res;
        stack<char> st;
        set<char> se;
        for(int i=0;i<s.size();i++){
            if(!se.count(s[i])){  
                //判断当前元素是否已经在栈中，如果在直接忽略该元素，并将map中数据-1
                while(!st.empty() && st.top()>s[i] && m[st.top()]>1){
                    //如果没有在栈中，我们需要将该元素入栈，入栈以前，我们需要判断该元素的前一个元素是否应该去掉
                    m[st.top()]--;
                    se.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                se.insert(s[i]);
            }
            else{
                m[s[i]]--;
            }
        }
        while(!st.empty()){
            char c=st.top();
            res+=c;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution s;
    string temp="bbcaac";
    string res=s.removeDuplicateLetters(temp);
    cout<<res<<endl;

    return 0;
}