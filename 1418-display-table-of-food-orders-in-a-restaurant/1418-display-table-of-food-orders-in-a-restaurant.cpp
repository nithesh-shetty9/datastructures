class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string,string>mpp1;
        map<pair<string,string>,int>freq;
        set<int>table;
        set<string>foods;
        for(int i=0;i<orders.size();i++)
        {
            foods.insert(orders[i][2]);
            freq[{orders[i][1],orders[i][2]}]++;
            int n=stoi(orders[i][1]);
            table.insert(n);
        }
        for(auto it:freq)
        {
            cout<<it.first.first<<" "<<it.first.second<<endl;
        }
         vector<vector<string>>ans;
         vector<string>temp;
         temp.push_back("Table");
         for(auto it:foods)
         {
            temp.push_back(it);
         }
         ans.push_back(temp);
         for(auto i:table)
         {
            temp.clear();
            string no=to_string(i);
            temp.push_back(no);
            for(auto j:foods)
            {
               string n=to_string(freq[{no,j}]);
               temp.push_back(n);
            }
            ans.push_back(temp);
         }
         return ans;


    }
};