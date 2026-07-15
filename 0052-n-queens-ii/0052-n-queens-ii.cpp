class Solution {
public:
    int totalNQueens(int n) {
        vector<int>trackrow(n,0);
        vector<int>upperdiag(2*n-1,0);
        vector<int>lowerdiag(2*n-1,0);
        int count=0;
        solve(0,n,count,trackrow,upperdiag,lowerdiag);
        return count;
    }
    void solve(int col,int n,int &count,vector<int>&trackrow,vector<int>&upperdiag,vector<int>&lowerdiag)
    {
        if(col==n)
        {
            count++;
            return;
        }
        for(int i=0;i<n;i++)        {
            if(trackrow[i]==0&&lowerdiag[i+col]==0&&upperdiag[n-1+col-i]==0)
            {
                trackrow[i]=1;
                lowerdiag[i+col]=1;
                upperdiag[n-1+col-i]=1;
                solve(col+1,n,count,trackrow,upperdiag,lowerdiag);
                trackrow[i]=0;
                lowerdiag[i+col]=0;
                upperdiag[n-1+col-i]=0;     
            }
        }
    }
};