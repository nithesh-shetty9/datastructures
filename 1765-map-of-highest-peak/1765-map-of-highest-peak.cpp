class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
      queue<pair<int,int>>q;
      int n=arr.size();
      int m=arr[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
      for(int i=0;i<arr.size();i++)
      {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j]==1)
            {
                visited[i][j]=1;
                q.push({i,j});
            }
        }
      }
      int dist=0;
      int a[4]={0,0,-1,1};
      int b[4]={-1,1,0,0};
      vector<vector<int>>dis(n,vector<int>(m,0));
      while(!q.empty())
      {
        dist++;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int r=row+a[j];
                int c=col+b[j];
                if(r>=0&&r<n&&c>=0&&c<m&&arr[r][c]==0&&!visited[r][c])
                {
                    visited[r][c]=1;
                    dis[r][c]=dist;
                    q.push({r,c});
                }
            }

        }
      }
      return dis;  
    }
};