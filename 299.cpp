#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0;
        int b=0;
        map<char,int> m;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                a++;
            char c=secret[i];
            m[c]++;
        }
        for(int i=0;i<guess.size();i++){
            char c=guess[i];
            if(m[c]>0){
                b++;
                m[c]--;
            }
        }
        b-=a;
        string res;
        res+=to_string(a);
        res+='A';
        res+=to_string(b);
        res+='B';
        return res;
    }
};

int main(){

    

    return 0;
}