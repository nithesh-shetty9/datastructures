#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int k;
	int count=0;
	cin>>k;
	int arr[n];
	int temp=0;
	int index=-1;
	for(int i=0;i<n;i++)
	{
	   cin>>arr[i];
	}
	//INDEX BASE The give k wil be k-1 as 0 is considered 1
	for(int i=0;i<n;i++)
	{
	   if(arr[i]>0&&arr[i]>=arr[k-1])
	   {
	       count++;
	   }
	}
	cout<<count;
}
