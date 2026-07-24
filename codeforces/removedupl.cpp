#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>a(n,0);
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	    mpp[a[i]]++;
	}
	cout<<mpp.size()<<endl;
	for(int i=0;i<n;i++)
	{
	    if(mpp.count(a[i]))
	    {
	        mpp[a[i]]--;
	        if(mpp[a[i]]==0)
	        {
	            cout<<a[i]<<" ";
	        }
	    }
	}
	
}
