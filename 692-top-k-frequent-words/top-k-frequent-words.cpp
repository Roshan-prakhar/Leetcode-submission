class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int K) {
        unordered_map<string,int> hash;

        for(int i=0;i<words.size();++i)
        {
            hash[words[i]]++;
        }
        map<int,vector<string>,greater<int>>freq; //freq of cnt
        for(auto it:hash)
        {
            string str=it.first;
            int cnt=it.second;

            freq[cnt].push_back(str);
        }

        vector<string> ans;

        for(auto &it:freq)
        {
            vector<string> temp=it.second;

            sort(temp.begin(),temp.end());

            for(int i=0;i<temp.size();++i)
            {
                if(ans.size()==K)
                    break;

                ans.push_back(temp[i]);
            }

            if(ans.size()==K)
                break;
        }

        return ans;
    }
};