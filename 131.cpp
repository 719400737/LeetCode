#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    bool ishui(string s){ //判断s是否是回文函数，只考虑了同小写
        for(int left=0,right=s.size()-1;left<right;left++,right--){
            if(s[left]==s[right])
                continue;
            else
                return false;    
        }
        return true;
    }
    void DFS(string s,int start){ //回溯算法，给定字符串，和开始位置
        string str=s.substr(start);  //截断字符串
        if(start==s.size()){        //满足条件时，将path放入res
            res.push_back(path);
        }
        for(int i=1;i<=str.size();i++){  //循环，找到一个位置i，从开始到i看做一个字符串，剩余进入回溯
            if(ishui(str.substr(0,i))){
                path.push_back(str.substr(0,i));
                DFS(str,i);
                path.pop_back();
            }
            else
            {
                continue;
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        DFS(s,0);
        return res;
    }
};

int main(){
    Solution s;
    string ss="aabccbd";
    vector<vector<string>> res;
    res=s.partition(ss);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}