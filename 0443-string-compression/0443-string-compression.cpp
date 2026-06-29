class Solution {
public:
    int compress(vector<char>& chars) {
      char curr=chars[0];
      int left=0;
      int n=chars.size();
      int point=0;
      while(left<n)
      {
        int size=0;
        char now=chars[left];
        while(left<n&&chars[left]==now)
        {
            left++;
            size++;
        }
        if(size==1)
        {
            chars[point]=now;
            point++;
        }
        else
        {
            chars[point]=now;
            point++;
            string u=to_string(size);
            cout<<size;
            for(auto i:u)
            {
                chars[point]=i;
                point++;
            }
        }
      }
      return point; 
    }
};