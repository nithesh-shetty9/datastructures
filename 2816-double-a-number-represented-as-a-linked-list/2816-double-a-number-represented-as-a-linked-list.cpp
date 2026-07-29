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
    ListNode*rev(ListNode*head)
    {
        ListNode*p=head;
        ListNode*q=nullptr;
        ListNode*r=nullptr;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    } 
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode*dummy=new ListNode(-1);
        ListNode*track=dummy;
        int carry=0;
        head=rev(head);
        ListNode*temp=head;
        while(temp)
        {
            int sum=(temp->val*2)+carry;
            int data=sum%10;
            ListNode*newNode=new ListNode(data);
            track->next=newNode;
            track=track->next;
            carry=sum/10;
            temp=temp->next;
        }
        head=rev(dummy->next);
        if(carry!=0)
        {
         ListNode*newNode=new ListNode(carry);
         newNode->next=head;
         head=newNode;
        }
        return head;
    }
};