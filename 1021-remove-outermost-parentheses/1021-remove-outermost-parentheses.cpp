class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        int count=0;
        for(char i:s)
        {
            if(i==')')
            {
                count--;
            }
            if(count!=0)
            {
                temp=temp+i;
            }
            if(i=='(')
            {
                count++;
            }
        }
        return temp;
    }
};