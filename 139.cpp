#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> word;
    bool res=false;
public:
    bool find_v(string s){
        vector<string>::iterator it;
        it=find(word.begin(),word.end(),s);
        if(it==word.end())
            return false;
        return true;
    }
    void DFS(string s,int start){
        if(start==s.size()){
            res=true;
            return;
        }
        string str=s.substr(start);
        for(int i=1;i<=str.size();i++){
            if(find_v(str.substr(0,i))){
                DFS(str,i);
            }
            else
                continue;
        }

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        this->word=wordDict;
        DFS(s,0);
        return res;
    }
};


int main(){
    Solution s;
    vector<string> word={"apple","pen"};
    string ss="applepenapple";
    bool res;
    res=s.wordBreak(ss,word);
    cout<<res<<endl;
    return 0;
}