class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hm;

        for (int i = 0; i < s.size(); i++) {
            hm[s[i]]++;
        }

        sort(s.begin(), s.end(), [&hm](const char a, const char b) {
            if (hm[a] != hm[b]) {
                return hm[a] > hm[b];
            }
            return a < b;
        });

        return s;
    }
};
