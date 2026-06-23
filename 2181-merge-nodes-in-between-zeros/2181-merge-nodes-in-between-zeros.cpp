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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        struct ListNode *dummy1=new ListNode(-1);
        ListNode *q=dummy1;

        ListNode*p=head;
        while(p!=NULL)
        {
            if(p->val!=0)
            {
                sum=sum+p->val;
            }
            else if(sum!=0)
            {
                struct ListNode *t=new ListNode;
                t->val=sum;
                t->next=NULL;
                q->next=t;
                q=t;
                sum=0;

            }
            p=p->next;
        }
        return dummy1->next;

        
    }
};