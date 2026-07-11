class Solution {
  public:
  //sort a stack in stack only no extrra space
  void s(stack<int>&st)
  {
      if(st.empty())
      {
          return;
      }
      int temp=st.top();
      st.pop();
      s(st);
      sta(st,temp);
  }
  void sta(stack<int>&st,int temp)
  {
      if(st.empty()||st.top()<temp)
      {
          st.push(temp);
          return;
      }
      int temp2=st.top();
      st.pop();
      sta(st,temp);
      st.push(temp2);
  }
  
    void sortStack(stack<int> &st) {
        // code here
        s(st);
        
    }
};