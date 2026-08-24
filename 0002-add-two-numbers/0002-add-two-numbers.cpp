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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*first=l1;
        ListNode*sec=l2;
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*p=dummy;
        while(first||sec||carry)
        {
            int sum=0;
            if(first)
            {
                sum=sum+first->val;
                first=first->next;
            }
            if(sec)
            {
                sum=sum+sec->val;
                sec=sec->next;
            }
            sum=sum+carry;
            int res=sum%10;
            ListNode*newnode=new ListNode(res);
            p->next=newnode;
            p=p->next;
            if(sum!=0&&sum>9)
            {
                carry=1;
            }
            else{
                carry=0;
            }
        }
        return dummy->next;
    }
};