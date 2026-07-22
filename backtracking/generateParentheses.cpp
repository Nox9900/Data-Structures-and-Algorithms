

/*
    GENERATE PARENTHESES
    https://leetcode.com/problems/generate-parentheses/description/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n==0) {
            result.push_back("");
            return result;
        }

        for(int i=0; i<n; i++) {
            vector<string> insideString = generateParenthesis(i);
            vector<string> outsideString = generateParenthesis(n-1-i);

            for(const string& inside : insideString) {
                for(const string& outside : outsideString) {
                    result.push_back("(" + inside + ")" + outside);
                }
            }
        }

        return result;
    }
};


class Solution {
public:

    vector<string> ans;

    void solve(int open, int close, int n, string &cur) {

        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            solve(open + 1, close, n, cur);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            solve(open, close + 1, n, cur);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(0, 0, n, cur);
        return ans;
    }
};