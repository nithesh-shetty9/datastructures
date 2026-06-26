class Solution {
public:
/*
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
An expression is balanced if:

Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.
---------------------------------------------------------
Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "([]"
Output: false
Explanation: The expression is not balanced as there is a missing ')' at the end.
Input: s = "([{]})"
Output: false
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
*/


    bool isBalanced(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
                //only push the opeing brackets
                
            }
            else {
                //if the first string char itself is close then reject directly
                if (st.empty())
                    return false;
                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '{' && c == '}') ||
                    (st.top() == '[' && c == ']'))
                    st.pop();
                else
                //if some different bracket and current string char is close bracket
                //for eg if top is [ and s[i] is } then reject directly
                    return false;
            }
        }
        return st.empty();
    }
    /*tc=0(n);
    sc=0(n);*/
};