/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*>st;
        vector<int>ans;
        if(!root)return {};
        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            for(auto child:root->children)
            {
                if(child)
                {
                    st.push(child);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};