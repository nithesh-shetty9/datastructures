class Solution {
     vector<string>res;
public:
    vector<string> addOperators(string s, int target) {
        solve(s,target,"",0,0,0);
    return res;
    }
    void solve(string &s,int target,string temp,int index,long sum,long prev)
    {
        if(index==s.size())
        {
            if(sum==target)
            {
                res.push_back(temp);
            }
            return;
        }
        long currsum=0;
        string curr="";
        for(int i=index;i<s.size();i++)
        {
            //handle zeros if you got zeros like 1205 here 120 5is valid but 12 05 is invalid right if ypu find any leading zeros expecet hat index one return from the function 
            if(i>index&&s[index]=='0')return;
            curr+=s[i];
            currsum=(currsum*10)+s[i]-'0';//1 12 128 
            if(index==0)//to handle multiple digits
            {
                solve(s,target,temp+curr,i+1,currsum,currsum);
            }
            else{
            solve(s,target,temp+"+"+curr,i+1,sum+currsum,currsum);
            solve(s,target,temp+"-"+curr,i+1,sum-currsum,-currsum);
            solve(s,target,temp+'*'+curr,i+1,sum-prev+prev*currsum,prev*currsum);
            }

        }
    }

};