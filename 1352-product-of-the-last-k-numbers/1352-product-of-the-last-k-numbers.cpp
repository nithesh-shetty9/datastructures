class ProductOfNumbers {
public:
vector<int>nums;
unordered_map<int,int>mpp;
int zero=-1;
int prefix=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            zero=nums.size();
        }
        prefix=prefix*num;
        mpp[nums.size()]=prefix;
        if(prefix==0)prefix=1;
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n=nums.size();
        // 3 0  2 5 4;
        int idx=n-k-1;
        if(idx<zero)return 0;
        if(mpp[idx]==0)return prefix;
        int ans=mpp[n-1]/mpp[idx];
        return ans;










        // int sum=1;//o(k)can we reduce this to 0(1)
        // for(int i=nums;.size()-1;i>=0;i--)
        // {
        //     sum=sum*nums[i];
        //     k--;
        //     if(k==0)break;
        // }
        // return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 **/