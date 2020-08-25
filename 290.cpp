#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        set<string> se;
        stringstream ss(str);
        for(int i=0;i<pattern.size();i++){
            string temp;
            ss>>temp;
            if(temp=="")
                return false;
            if(m.count(pattern[i])){
                if(m[pattern[i]]==temp)
                    continue;
                else
                    return false;
            }   
            else{
                if(se.count(temp))
                    return false;
                se.insert(temp);
                m.insert(make_pair(pattern[i],temp));
            }
        }
        string temp;
        ss>>temp;
        if(temp!="")
            return false;
        return true;
    }
};

int main(){

    

    return 0;
}