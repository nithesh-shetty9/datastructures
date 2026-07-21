#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int sum=0;
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	    sum+=a[i];
	}
	int target=sum/2;
	int count=0;
	sort(a.begin(),a.end());
	int first=0;
    //minimum number of coins to get more than half of the total sum
	for(int i=n-1;i>=0;i--)
	{
	    if(first>target)break;
	   first=first+a[i];
	   count++;
	}
	cout<<count;
}
