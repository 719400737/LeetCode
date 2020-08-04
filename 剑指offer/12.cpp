#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<char>> board;
    vector<vector<int>> flag;
    bool helper(string word,int index,int i,int j){
        if(word[index]==board[i][j] && flag[i][j]==0){
            flag[i][j]=1;
            if(index==word.size()-1){
                return true;
            }
            else{
                if(j-1>=0 && helper(word,index+1,i,j-1))
                    return true;
                else if(j+1<board[0].size() && helper(word,index+1,i,j+1))
                    return true;
                else if(i-1>=0 && helper(word,index+1,i-1,j))
                    return true;
                else if(i+1<board.size() && helper(word,index+1,i+1,j))
                    return true;
                else    flag[i][j]=0;
                return false;
            }
        }
        else    return false;
        

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        bool res;
        vector<vector<int>> f(board.size(),vector<int>(board[0].size(),0));
        this->flag=f;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(helper(word,0,i,j))
                    return true;
            }
        }
        return false;

    }
};

int main(){
    vector<vector<char>> v={{'a','b'}};
    string s1="ba";
    Solution s;
    bool res=s.exist(v,s1);
    cout<<res<<endl;

    return 1;
}