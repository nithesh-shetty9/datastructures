#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_map<string,int>mpp;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        if(mpp.find(temp)!=mpp.end())
        {
            cout<<temp<<mpp[temp]<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
        mpp[temp]++;
    }

}
