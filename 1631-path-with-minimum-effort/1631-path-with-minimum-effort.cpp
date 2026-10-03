class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>>st;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        st.insert({0,{0,0}});
        int dc[4]={-1,1,0,0};
        int pc[4]={0,0,-1,1};
        while(!st.empty())
        {
            auto it=*st.begin();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==m-1 && col==n-1)
    return d;
            st.erase(it);
            if(row==m-1&&col==n-1)return d;
            for(int i=0;i<4;i++)
            {
                int r=row+dc[i];
                int c=col+pc[i];
                if(r>=0&&c>=0&&c<n&&r<m)
                {
                    int maxi=max(d,abs(heights[row][col]-heights[r][c]));
                    if(maxi<dist[r][c])
                    {
                        st.erase({dist[r][c],{r,c}});
                        dist[r][c]=maxi;
                        st.insert({maxi,{r,c}});
                    }

                }
            }
        }
        return -1;
    }   
};