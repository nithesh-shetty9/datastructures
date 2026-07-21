#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int a[5][5];
    cout<<"Enter the elements of the 5x5 matrix (only one '1' and rest '0's):"<<endl;
	for(int i=0;i<5;i++)
	{
	    for(int j=0;j<5;j++)
	    {
	        cin>>a[i][j];
	    }
	}
	for(int i=0;i<5;i++)
	{
	    for(int j=0;j<5;j++)
	    {
	        if(a[i][j]==1)
	        {
	            cout<<abs(i-2)+abs(j-2)<<endl;
	        }
	    }
	}
	

}
