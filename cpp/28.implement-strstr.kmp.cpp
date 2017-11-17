class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int m = haystack.size();
        int n = needle.size();

        // longest prefix suffix length
        vector<int> lpsLen(n, 0);

        for (i = 1, j = 0; i < n; ) {
            if (needle[i] == needle[j]) {
                j++;
                lpsLen[i] = j;
                i++;
            } else if (j > 0) {
                j = lpsLen[j - 1];
            } else {
                lpsLen[i] = 0;
                i++;
            }
        }

        for (i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == n) {
                    return i - n;
                }
            } else if (j > 0) {
                j = lpsLen[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }
};
