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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(auto it:lists)
        {
            while(it)
            {
                arr.push_back(it->val);
                it=it->next;
            }
        }
        if (arr.empty()) return nullptr; 
        sort(arr.begin(),arr.end());
        ListNode*ans=new ListNode(arr[0]);
        ListNode*dummy=ans;
        for(int i=1;i<arr.size();i++)
        {
            dummy->next=new ListNode(arr[i]);
            dummy=dummy->next;
        }
        return ans;
        
    }
};