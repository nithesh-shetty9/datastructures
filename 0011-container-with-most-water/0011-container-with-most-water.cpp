class Solution {
public:
    int maxArea(vector<int>& arr) {
       int i=0;
      int j=arr.size()-1;
      int ans=0;
      while(i<j)
      {
          int mini=min(arr[i],arr[j]);
          ans=max(ans,mini*(j-i));
          if(arr[i]<arr[j])
          {
              i++;
          }
          else
          {
              j--;
          }
      }
      return ans;
    }
};