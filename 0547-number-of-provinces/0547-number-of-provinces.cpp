class Solution {
public:
class Disjoint{
    public:
    vector<int>parent,rank;
    Disjoint(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
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
    void unionbysize(int u,int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    int result(int n)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(find(i)==i)res++;
        }
        return res;
    }
};
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        Disjoint ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionbysize(i, j);
                }
            }
        }
        return ds.result(n);
    }
};