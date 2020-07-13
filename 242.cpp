#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.size()!=t.size())
            return false;
        for(auto i:s)
            m[i]++;
        for(auto j:t){
            if(m.count(j)){
                m[j]--;
                if(m[j]<0)
                    return false;
            }
            else    return false;
        }
        return true;
    }
};

int main(){



    return 1;
}