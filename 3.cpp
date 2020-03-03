#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
        map<int,int>  m;
        int N=s.size();
        if(N==0)
            return N;
        vector<int> a;//存储第i个的最长长度          
        int res=0;
        for(int i=0;i<N;i++){
            char c=s[i];             
            if(!i){
              a.push_back(1);
              m[c-'a']=i+1;
            }     
            else{
                int tmp=min(i+1-m[c-'a'],a[i-1]+1);
                a.push_back(tmp);
                m[c-'a']=i+1;
            }
                
         res=max(res,a[i]);
        }
      return res;
    }
int main(){

    string s="abcabcbb";
    cout<< lengthOfLongestSubstring(s);
    return 0;
}