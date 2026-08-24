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
        stack<ListNode*>st1;
        stack<ListNode*>st2;
        ListNode*temp=l1;
        ListNode*res=new ListNode(-1);
        ListNode*p=res;
        while(temp)
        {
            st1.push(temp);
            temp=temp->next;
        }
        temp=l2;
         while(temp)
        {
            st2.push(temp);
            temp=temp->next;
        }
        int carry=0;
        while(!st1.empty()||!st2.empty())
        {
            int sum=0;
            if(!st1.empty())
            {
                sum=sum+st1.top()->val;
                st1.pop();
            }
            if(!st2.empty())
            {
                sum=sum+st2.top()->val;
                st2.pop();
            }
            sum=sum+carry;
            if(sum>9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            int res=sum%10;
            ListNode*newnode=new ListNode(res);
            p->next=newnode;
            p=p->next;
        }
        p=res->next;
        ListNode*q=nullptr;
        ListNode*r=nullptr;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        if(carry==1)
        {
            ListNode*newnode=new ListNode(1);
            newnode->next=q;
            q=newnode;
        }
        return q;
    }
};