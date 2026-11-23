class ProductOfNumbers {
public:
vector<int>nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int sum=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum=sum*nums[i];
            k--;
            if(k==0)break;
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 **/