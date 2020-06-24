#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        if(beginWord==endWord)
            return 1;
        bool flag=true;
        map<string,vector<string>> comboList;
        for(auto w:wordList){
            if(w==endWord)
                flag=false;
            for(int i=0;i<w.size();i++){
                string temp=w;
                temp[i]='*';
                comboList[temp].push_back(w);
            }
        }
        if(flag)
            return 0;
        map<string,int> visit;
        queue<string> que;
        que.push(beginWord);
        int res=1;
        while(!que.empty()){
            res++;
            for(int i=que.size();i>0;i--){
                auto q=que.front();//取出队列头q
                que.pop();
                for(int i=0;i<q.size();i++){
                    auto temp=q;
                    temp[i]='*';   //修改第i个为*
                    for(auto w:comboList[temp]){ //找到字典中temp的字符串
                        if(w==endWord)
                            return res;
                        if(visit[w]!=0)    //如果访问过，则下一个
                            continue;
                        que.push(w);       //将其push到队列中
                        visit[w]=1;   //设定为已经访问过了
                    }
                }
            }
        }

	    return 0;
    }
};

int main(){
    Solution s;
    string be="hit";
    string en="cog";
    vector<string> word{"hot","dot","lot","log","dog","cog"};
    int res=s.ladderLength(be,en,word);
    cout<<res<<endl;
    return 0;
}