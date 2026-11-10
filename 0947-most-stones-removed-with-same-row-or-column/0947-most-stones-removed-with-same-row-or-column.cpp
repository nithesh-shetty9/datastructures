class Solution {
    class Disjoin{
        public:
        vector<int>parent,size;
        Disjoin(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        int find(int node)
        {
            if(node==parent[node])
            {
                return node;
            }
            return parent[node]=find(parent[node]);
        }
        void merge(int u,int v)
        {
            int ulp_u=find(u);
            int ulp_v=find(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else if(size[ulp_u]>size[ulp_v])
            {
                parent[ulp_v]=ulp_u;
                  size[ulp_u]+=size[ulp_v];
            }
            else
            {
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
         Disjoin ds(maxrow+maxcol+1);
        int n=stones.size();
        int cnt=0;
        for(auto it:stones)
        {
            int u=it[0];
            int v=it[1]+maxrow+1;
            ds.merge(u,v);
        }
        for(int i=0;i<(maxrow+maxcol+1);i++)
        {
            if(i==ds.find(i)&&ds.size[i]!=1)
            {
                cnt++;
            }
        }
        return n-cnt;
    }
};