#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub=0;
        //vector<string> tmp;
        string tmp;
        map<string,int> m;
        for(auto i:strs){
            tmp=i;
            sort(tmp.begin(),tmp.end());
            if(m.count(tmp)){ //count 判断m中是否有tmp,有则返回true
                res[m[tmp]].push_back(i);
            }
            else{
                vector<string> vec(1,i);
                res.push_back(vec);
                m[tmp]=sub++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<string>> res;
    vector<string> M={"eat","tea","tan","ate"};
    Solution s;
    res=s.groupAnagrams(M);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}