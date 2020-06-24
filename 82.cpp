#include<bits/stdc++.h>
using namespace std;

struct  ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* creat(vector<int> nums){
    ListNode* pre=new ListNode(-1);
    ListNode* head=pre;
    for(int i=0;i<nums.size();i++){
        ListNode* temp=new ListNode(nums[i]);
        head->next=temp;
        head=head->next;
    }
    return pre->next;
}
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre=new ListNode(-11);
        pre->next=head;
        ListNode* one=pre, *two=pre,*three=pre;
        two=one->next;
        if(two==NULL)
            return pre->next;
        while(three!=NULL){
            three=two->next;
            if(three==NULL)
                break;
            if(three->val==two->val){
                while(three && three->val==two->val)
                    three=three->next;
                one->next=three;
                two=three;
            }
            else{
                one=one->next;
                two=two->next;
            }
        }
        return pre->next;
    }
};

int main(){
    vector<int> nums={1,2,3,3,4,4};
    ListNode* head=creat(nums);
    Solution s;
    s.deleteDuplicates(head);

    return 0;
}