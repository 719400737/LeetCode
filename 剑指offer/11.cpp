#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        //二分法查找，此处跟末尾元素进行比较，当数组顺序时跟首比较不可行，
        //注意：当mid元素和end元素相等时，我们无法判断mid该在什么位置，此时将end元素
        int start=0,end=numbers.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(mid==start)
                break;
            if(numbers[mid]>numbers[end])
                start=mid+1;
            else if(numbers[mid]==numbers[end]){
                end=end-1;
            }
            else if(numbers[mid]<numbers[end])
                end=mid;
        }
        if(start+1<numbers.size() && numbers[start]>numbers[start+1])
            return numbers[start+1];
        else
           return numbers[start];
    }
};

int main(){
    vector<int> v={2,1,2,2,2};
    Solution s;
    int res=s.minArray(v);
    cout<<res<<endl;
    return 1;
}