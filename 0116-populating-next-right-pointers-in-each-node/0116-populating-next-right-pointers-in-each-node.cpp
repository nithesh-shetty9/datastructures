/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->left!=NULL)
        {
            root->left->next=root->right;
        }
        if(root->right!=NULL&&root->next!=NULL)root->right->next=root->next->left;
        // queue<Node*>q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int n=q.size();
        //     for(int i=0;i<n;i++)
        //     {
        //         Node*head=q.front();
        //         q.pop();
        //          if(i!=n-1)
        //         head->next=q.front();
        //         if(head->left)q.push(head->left);
        //         if(head->right)q.push(head->right);
        //     }

        // }
        // return root;
        connect(root->left);
        connect(root->right);
        return root;

        
    }
};