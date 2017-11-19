class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, multiset<string>> hm;

        for (int i = 0; i < strs.size(); i++) {
            string idx = strs[i];
            sort(idx.begin(), idx.end());
            hm[idx].insert(strs[i]);
        }

        for (auto s : hm) {
            vector<string> anagrams(s.second.begin(), s.second.end());
            ans.push_back(anagrams);
        }

        return ans;
    }
};
