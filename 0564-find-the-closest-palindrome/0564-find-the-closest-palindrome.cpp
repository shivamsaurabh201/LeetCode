class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            if (n[0] == '0') return "1";
            --n[0];
            return n;
        }
        if (is10x(n) || is1x1(n)) 
            return string(n.size() - 1, '9');
        else if (is9x(n))
            return "1" + string(n.size() - 1, '0') + "1";
        int half = (n.size() & 1) ? stoll(n.substr(0, n.size() / 2 + 1)) : stoll(n.substr(0, n.size() / 2));
        long long great = 
            stoll(to_string(half + 1) + getReverse(to_string(half + 1), n.size() & 1));
        long long small = 
            stoll(to_string(half - 1) + getReverse(to_string(half - 1), n.size() & 1));
        long long equal = 
            stoll(to_string(half) + getReverse(to_string(half), n.size() & 1));
        long long minDiff{LLONG_MAX};
        long long res;
        if (stoll(n) - small < minDiff) {
            minDiff = stoll(n) - small;
            res = small;
        }
        if (stoll(n) != equal && abs(stoll(n) - equal) < minDiff) {
            minDiff = abs(stoll(n) - equal);
            res = equal;
        }
        if (great - stoll(n) < minDiff) {
            minDiff = great - stoll(n);
            res = great;
        }
        return to_string(res);
    }
    string getReverse(string s, bool odd) {
        if (odd) s.pop_back();
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
        return s;
    }
    bool is10x(const string& n) {
        if (n[0] != '1') return false;
        for (int i = 1; i < n.size(); ++i) {
            if (n[i] != '0') return false;
        }
        return true;
    }
    bool is1x1(const string& n) {
        if (n[0] != '1' || n[n.size() - 1] != '1') 
            return false;
        
        for (int i = 1; i < n.size() - 1; ++i) {
            if (n[i] != '0') return false;
        }
        return true;
    }
    bool is9x(const string& n) {
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] != '9') return false;
        }
        return true;
    }
};