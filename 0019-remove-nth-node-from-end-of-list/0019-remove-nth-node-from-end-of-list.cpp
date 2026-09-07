/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp)
        {
            temp=temp->next;
            len++;
        }
        if(len-k<0)return nullptr;
        len=len-k;
        if(len==0){
            ListNode*temp=head;
            head=head->next;
            delete temp;
           return head;
        }
        temp=head;
        ListNode*prev=nullptr;
        while(len)
        {
            len--;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};