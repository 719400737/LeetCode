#include<bits/stdc++.h>

using namespace std;
struct BTnode
{
    int m_nValue;
    BTnode *m_pLeft;
    BTnode *m_pRight;
};
void helper(BTnode* root){
    if(root==NULL)
        return;
    helper(root->m_pLeft);
    cout<<root->m_nValue<<endl;
    helper(root->m_pRight);
    
}
int main(){
    

    return 0;
}
