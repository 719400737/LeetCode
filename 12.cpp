#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> m{{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
        string res;
        vector<int> a(7,0);
        while(num){
            if(num>=1000){
                a[0]=num/1000;
                num%=1000;
            }
            else if(num>=500){
                a[1]=num/500;
                num%=500;
            }
            else if(num>=100){
                a[2]=num/100;
                num%=100;
            }
            else if(num>=50){
                a[3]=num/50;
                num%=50;
            }
            else if(num>=10){
                a[4]=num/10;
                num%=10;
            }
            else if(num>=5){
                a[5]=num/5;
                num%=5;
            }
            else{
                a[6]=num/1;
                num=0;
            }
        }
        for(int i=0;i<7;i++){
            if(i==0)
                res.append(a[i],m[1000]);
            else if(i==1){
                if(a[1]==1 && a[2]==4)
                    res+="CM";
                else if(a[1]==0 && a[2]==4)
                    res+="CD";
                else{
                    res.append(a[1],m[500]);
                    res.append(a[2],m[100]);
                }
            }
            else if(i==3){
                if(a[3]==1 && a[4]==4)
                    res+="XC";
                else if(a[3]==0 && a[4]==4)
                    res+="XL";
                else{
                    res.append(a[3],m[50]);
                    res.append(a[4],m[10]);
                }
            }
            else if(i==5){
                if(a[5]==1 && a[6]==4)
                    res+="IX";
                else if(a[5]==0 && a[6]==4)
                    res+="IV";
                else{
                    res.append(a[5],m[5]);
                    res.append(a[6],m[1]);
                }
            }
        }
        return res;
    }
};

int main(){

    Solution s;
    string res=s.intToRoman(1994);
    cout<<res<<endl;
    return 0;
}