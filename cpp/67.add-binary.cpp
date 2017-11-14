class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int aBit = 0;
        int bBit = 0;
        int carry = 0;
        int sum = 0;
        string ans;

        while (i >= 0 || j >= 0 || carry > 0) {
            aBit = (i >= 0) ? a[i--] - '0' : 0;
            bBit = (j >= 0) ? b[j--] - '0' : 0;
            sum = aBit + bBit + carry;
            carry = (sum & 2) ? 1 : 0;

            ans.push_back((sum & 1) ? '1' : '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
