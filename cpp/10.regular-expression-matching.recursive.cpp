class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        if (p.size() > 1 && p[1] == '*') {
            if (isMatch(s, p.substr(2))) {
                return true;
            }
            if (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)) {
                return true;
            }
            return false;
        } else {
            if (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1))) {
                return true;
            }
            return false;
        }
    }
};
