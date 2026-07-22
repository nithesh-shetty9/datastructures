class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
       int n=arr.size();
       vector<int>nextsmaller(n);
       vector<int>prevsmaller(n);
       stack<int>st1;
       stack<int>st2;
       for(int i=n-1;i>=0;i--)
       {
        while(!st1.empty()&&arr[i]<arr[st1.top()])
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
        while(!st2.empty()&&arr[i]<=arr[st2.top()])
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
       vector<long long>smallest(n);
       long long small=0;
       for(int i=0;i<n;i++)
       {
        int temp1=nextsmaller[i]-i;
        int temp2=i-prevsmaller[i];
        long long temp=arr[i]*1LL*(temp1*temp2);
        smallest[i]=temp;
        small=(small+temp);
       } 
       vector<int>nextgreater(n);
       vector<int>prevgreater(n);
       stack<int>st3;
       stack<int>st4;
       for(int i=n-1;i>=0;i--)
       {
        while(!st3.empty()&&arr[i]>arr[st3.top()])
        {
           st3.pop();
        }
        if(st3.empty())
        {
            nextgreater[i]=n;
        }
        else
        {
           nextgreater[i]=st3.top();
        }
       st3.push(i);
       }
          for(int i=0;i<n;i++)
       {
        while(!st4.empty()&&arr[i]>=arr[st4.top()])
        {
           st4.pop();
        }
        if(st4.empty())
        {
            prevgreater[i]=-1;
        }
        else
        {
            prevgreater[i]=st4.top();
        }
       st4.push(i);
       }
       vector<long long>largest(n);
       long long big=0;
       for(int i=0;i<n;i++)
       {
        int temp1=nextgreater[i]-i;
        int temp2=i-prevgreater[i];
        long long temp=arr[i]*1LL*(temp1*temp2);
        largest[i]=temp;
        big=(big+temp);
       }
      return big-small;
       
    }
};