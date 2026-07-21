class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
       vector<int>nextsmaller(n);
       vector<int>prevsmaller(n);
       stack<int>st1;
       stack<int>st2;
       for(int i=n-1;i>=0;i--)
       {
        while(!st1.empty()&&arr[i]<=arr[st1.top()])
        {
           st1.pop();
        }
        if(st1.empty())
        {
            nextsmaller[i]=n;
        }
        else
        {
            nextsmaller[i]=st1.top();
        }
       st1.push(i);
       }
          for(int i=0;i<n;i++)
       {
        while(!st2.empty()&&arr[i]<arr[st2.top()])
        {
           st2.pop();
        }
        if(st2.empty())
        {
            prevsmaller[i]=-1;
        }
        else
        {
            prevsmaller[i]=st2.top();
        }
       st2.push(i);
       }
       long long sum=0;
       for(int i=0;i<n;i++)
       {
        int temp1=nextsmaller[i]-i;
        int temp2=i-prevsmaller[i];
        sum=(sum+(arr[i]*1LL*(temp1*temp2)))%1000000007;
       } 
       return sum;
    }

};