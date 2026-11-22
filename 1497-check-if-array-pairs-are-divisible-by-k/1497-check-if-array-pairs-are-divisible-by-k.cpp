class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int pairs=0;
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            int mod=((arr[i]%k)+k)%k;
            if(mod==0&&mpp[mod]>=1)
            {
                    pairs++;
                    mpp[mod]--;
            }
            else if(mpp[k-mod]>=1)
            {
                pairs++;
                mpp[k-mod]--;
            }
            else
            {
                mpp[mod]++;
            }
        }
        cout<<pairs<<endl;
        return pairs==n/2;
    }
};