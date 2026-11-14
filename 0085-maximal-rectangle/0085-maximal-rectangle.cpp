class Solution {
    int solve(vector<int>arr)
    {
         // code here
        int n=arr.size();
        vector<int>nextsmaller(n,0);
        vector<int>prevsmaller(n,0);
        stack<int>st1;
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty()&&arr[i]<=arr[st1.top()])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                nextsmaller[i]=n;
            }
            else
            {
                nextsmaller[i]=st1.top();
            }
            st1.push(i);
            
        }
        for(int i=0;i<n;i++)
        {
            while(!st2.empty()&&arr[i]<=arr[st2.top()])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                prevsmaller[i]=-1;
            }
            else
            {
                prevsmaller[i]=st2.top();
            }
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int res=nextsmaller[i]-prevsmaller[i]-1;
            ans=max(ans,arr[i]*res);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
          vector<int>arr(m,0);
        for(int i=0;i<m;i++)
        {
            arr[i]=matrix[0][i]-'0';
        }
        ans=solve(arr);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    arr[j]=0;
                }
                else
                {
                    arr[j]=arr[j]+1;
                }
            }
            ans=max(ans,solve(arr));
        }
        return ans;      
    }
};