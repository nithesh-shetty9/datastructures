class Solution {
public:
    int jump(vector<int>& arr) {
         int jump=0;
        int left=0;
        int right=0;
        int n=arr.size();
        while(right<n-1)
        {
            int farthest=0;
            for(int i=left;i<=right;i++)
            {
                farthest=max(farthest,i+arr[i]);
            }if (farthest == right)
                return -1; 
            left=right+1;
            right=farthest;
            jump++;
        }
        return jump;
    }
};