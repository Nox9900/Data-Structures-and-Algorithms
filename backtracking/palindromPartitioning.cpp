
/*
    PALINDROME PARTITIONING
    https://leetcode.com/problems/palindrome-partitioning/description/
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(s, 0, curr, result);
        return result;
    }

private:
    void backtrack(string& s, int start, vector<string>& curr ,vector<vector<string>>& result) {
        if(start == s.size()) {
            result.push_back(curr);
            return;
        }

        auto isPalindrome = [](string& s, int left, int right) {
            while(left < right) {
                if(s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        };

        for(int end = start; end < s.size(); end++) {
            if(isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end-start+1));
                backtrack(s, end+1, curr, result);
                curr.pop_back();
            }
        }
    }
};