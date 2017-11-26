class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> freqToStr(s.size() + 1, "");
        string ans;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        for (auto &it : freq) {
            char c = it.first;
            int f = it.second;
            freqToStr[f].append(f, c);
        }

        for (int i = freqToStr.size() - 1; i >= 0; i--) {
            if (freqToStr[i].empty()) {
                continue;
            }

            ans.append(freqToStr[i]);
        }

        return ans;
    }
};
