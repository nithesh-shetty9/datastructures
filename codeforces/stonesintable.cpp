#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int res=0;
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
	    if(s[i-1]==s[i])
	    {
	        res++;
	    }
	}
	cout<<res;
	
}