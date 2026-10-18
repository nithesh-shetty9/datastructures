class Solution {
public:
    int findCircleNum(vector<vector<int>>&arr) {
        vector<int>visited(arr.size()+1,0);
        int V=arr.size();
        int cnt=0;
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {
                cnt++;
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();
                    for(int j=0;j<V;j++)
                    {
                        if(arr[curr-1][j]==1&&!visited[j+1])
                        {
                            visited[j+1]=1;
                            q.push(j+1);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};