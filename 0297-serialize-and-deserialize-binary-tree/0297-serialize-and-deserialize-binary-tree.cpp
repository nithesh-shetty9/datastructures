/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

void serial(TreeNode*root,string &res)
{
    if(!root)
    {
        res+="N ";
        return;
    }
    res+=to_string(root->val);
    res+=" ";
    serial(root->left,res);
    serial(root->right,res);

}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string res="";
      serial(root,res);
      return res;  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return deserial(data,index);

    }
    TreeNode*deserial(string &data,int &index)
    {
         while(index < data.size() && data[index] == ' ')
            {
                index++;
            }
            string val="";
        while(index<data.size()&&data[index]!=' ')
        {
            val+=data[index];
              index++;
        }
        if(val=="N")
        {
            return nullptr;
        }
        TreeNode*root=new TreeNode(stoi(val));
        root->left=deserial(data,index);
        root->right=deserial(data,index);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));