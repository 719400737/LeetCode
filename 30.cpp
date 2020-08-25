#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vec;
        multiset<string> s1,s2;//使用hash来判断是否相等没复杂度为n2，超时
        for(auto i:words)
            s1.insert(i);
        if(words.size()==0)
            return vec;
        int m=words[0].size();
        int k=m*words.size();
        for(int i=0;i+k<=s.size();i++){
            string temp=s.substr(i,k);
            for(int j=0;j+m<=k;j+=m){
                string t=temp.substr(j,m);
                s2.insert(t);
            }
            if(s1==s2){
                vec.push_back(i);
            }
            s2.clear();
        }
        return vec;

    }*/
    /*vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vec;
        multiset<string> s1,s2;//使用hash来判断是否相等没复杂度为n2，超时
        for(auto i:words)
            s1.insert(i);
        if(words.size()==0)
            return vec;
        int m=words[0].size();
        int k=m*words.size();
        for(int i=0;i+k<=s.size();i++){
            string temp=s.substr(i,k);
            for(int j=0;j+m<=k;j+=m){
                string t=temp.substr(j,m);
                s2.insert(t);
            }
            if(s1==s2){
                vec.push_back(i);
            }
            s2.clear();
        }
        return vec;

    }*/
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vec;
        map<string,int> m1,m2;
        for(auto i:words)
            m1[i]++;
        if(words.size()==0)
            return vec;
        int m=words[0].size();
        int k=m*words.size();
        int count=0;
        for(int i=0;i<m;i++){
            int left=i,right=i,count=0;
            while(right+m<=s.size()){
                string temp=s.substr(right,m);
                m2[temp]++;
                right+=m;
                count++;
                while(m2[temp]>m1[temp]){
                    string temp2=s.substr(left,m);
                    m2[temp2]--;
                    left+=m;
                    count--;
                }
                if(count==words.size())
                    vec.push_back(left);
            }
            m2.clear();
            
        }
        return vec;

    }


};

int main(){

    string s="aaaaaaaa";
    vector<string> words={"aa","aa","aa"};
    Solution so;
    vector<int> vec=so.findSubstring(s,words);
    for(auto i:vec)
        cout<<i<<endl;
    return 0;
}