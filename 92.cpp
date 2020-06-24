#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* Creat(int a[],int N){ 
	ListNode *tail;
	ListNode *prehead=new ListNode(-1);
	ListNode *head=prehead;
	for(int i=0;i<N;i++){
		tail=new ListNode(a[i]);
		head->next=tail;
		head=tail;
	}
	return prehead->next;
}


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *first=prehead;
        ListNode *second=first;
        ListNode *cur=first;

        for(int i=1;i<=n;i++){
            if(i<m){
                first=first->next;//first指向m前一个元素
                second=first;
                cur=first;
            }
            else if(i==m){
                cur=cur->next;
                second=cur->next;
            }   
            else{
                ListNode *tmp=second->next;
                second->next=cur;//i+1元素指向i元素
                cur=second;
                second=tmp;

            }
        }
        first->next->next=second;
        first->next=cur;
        return prehead->next;
    }
};

int main(){
    Solution s;
    int a2[]={1,2,3,4};
    cout<<"Creat list"<<endl;
	ListNode *head=Creat(a2,4);
    head=s.reverseBetween(head,1,4);
	cout<<"l2 mumber :"<<endl;
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
    cout<<endl;
    return 0;
    return 0;
}