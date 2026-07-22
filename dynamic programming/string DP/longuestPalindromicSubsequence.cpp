/*
    LONGUEST PALINDROMIC SUBSEQUENCE
    https://leetcode.com/problems/longest-palindromic-subsequence/
*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> res(n, 1);
        for(int i=n-2; i>=0; i--) {
            int prev = 0;
            for(int j=i+1; j<n; j++) {
                int tmp = res[j];
                if(s[i] == s[j]) res[j] = prev + 2;
                else res[j] = max(res[j], res[j-1]);
                prev = tmp;
            }
        }
        return res[n-1];
    }
};

// OPTIMAL
class Solution {
public:

    int longestPalindromeSubseq(string s) {
      int n = s.length();
        if (n <= 1) return n;
        bool pal = true;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                pal = false;
                break;
            }
        }
        if (pal) return n;
        int dp[1001] = {0};
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) dp[j] = prev + 2;
                else dp[j] = max(dp[j], dp[j - 1]);
                prev = tmp;
            }
        }
        return dp[n - 1];
    }
};