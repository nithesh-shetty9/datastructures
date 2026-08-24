class FindSumPairs {
public:
vector<int>nums1;
vector<int>nums2;
unordered_map<int,int>mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
     this->nums1=nums1;
     this->nums2=nums2;
     for(int i:nums2)
     {
        mpp[i]++;
     }   
    }
    
    void add(int index, int val) {
        mpp[nums2[index]]--;
        if(mpp[nums2[index]]==0)
        {
            mpp.erase(nums2[index]);
        }
        nums2[index]=nums2[index]+val;
        mpp[nums2[index]]++;
    }
    
    int count(int tot) {
        return find(nums1,nums2,tot,mpp);
    }
    int find(vector<int>&nums1,vector<int>&nums2,int total,unordered_map<int,int>&mpp)
    {
        int count=0;
        for(int i=0;i<nums1.size();i++)
        {
            int temp=total-nums1[i];
            if(mpp.count(temp))
            {
                count=count+mpp[temp];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */