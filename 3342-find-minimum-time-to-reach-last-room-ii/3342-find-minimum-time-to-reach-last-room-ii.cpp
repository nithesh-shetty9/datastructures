class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        set<pair< pair<int,int>,pair<int,int>>>st;
        int m=moveTime.size();
        int n=moveTime[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        st.insert({{0,1},{0,0}});
        int dc[4]={-1,1,0,0};
        int pc[4]={0,0,-1,1};
        while(!st.empty())
        {
            auto it=*st.begin();
            int row=it.second.first;
            int col=it.second.second;
            int d=it.first.first;;
            int t=it.first.second;
            st.erase(it);
            if(row==m-1&&col==n-1)return d;
            for(int i=0;i<4;i++)
            {
                int r=row+dc[i];
                int c=col+pc[i];
                if(r>=0&&c>=0&&r<m&&c<n)
                {
                    int time=max(d,moveTime[r][c])+t;
                    if(time<dist[r][c])
                    {
                        int newtime=t==1?2:1;
                        st.erase({{dist[r][c],newtime},{r,c}});
                        dist[r][c]=time;
                        st.insert({{dist[r][c],newtime},{r,c}});

                    }
                }
            }

        }
        return -1;
    }
};