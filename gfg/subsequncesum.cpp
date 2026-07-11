class Solution {
    /*
    Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals to k.

Examples:

Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
Output: true
Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
Input: arr = [2, 3, 5, 7, 9], k = 100. 
    */
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        bool res=false;
        solve(arr,k,res,0,0);
        if(res)
        {
            return true;
        }
        return false;
    }
    void solve(vector<int>&arr,int k,bool &res,int index,int sum)
    {
        if(sum==k)
        {
            res=true;
            return;
        }
        if(index==arr.size()||sum>k||res)//stop explaorinh other branches
        {
            return;
        }
        solve(arr,k,res,index+1,sum+arr[index]);
        solve(arr,k,res,index+1,sum);
    }
    /*
    class Solution {
    bool find(vector<int>& arr, int k, int sum, int index)
    {
        if(sum>k)return false;
        if(sum == k) return true;

        if(index >= arr.size()) return false;

        return find(arr, k, sum + arr[index], index + 1) ||
               find(arr, k, sum, index + 1);
    }

public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return find(arr, k, 0, 0);
    }
}
    */
};