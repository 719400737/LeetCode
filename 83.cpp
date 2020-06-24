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
        ListNode* cur=pre,*next=cur->next;
        if(!next)
            return pre->next;
        while(next){
            if(next->val==cur->val){
                while(next && next->val==cur->val)
                    next=next->next;
            }
            
            cur->next=next;
            cur=cur->next;
            if(cur)
                next=cur->next;
            else    break;
            
        }

        return pre->next;
    }
};

int main(){
    vector<int> nums={1,2,3,3};
    ListNode* head=creat(nums);
    Solution s;
    s.deleteDuplicates(head);

    return 0;
}