#include<iostream>
#include<vector>
#include<sstream> // for the stringstream 
#include<algorithm> // for the ">>" operator, and the reverse method 
using namespace std;


class Solution {
    public:

        // Solution Using the stringStream 
        string reverseWords1(string s) {
            stringstream ss(s);
            vector<string> words;
            string word, result;

            while(ss >> word) words.push_back(word);
            reverse(words.begin(), words.end());

            for(int i=0; i<s.size(); i++) {
                if(i>0) result += " ";
                result += words[i];
            }

            return result;
        }

        // Solution without stringStream
        string reverseWords2(string s) {
            string result;
            int i = s.size() - 1;

            while(i >= 0) {
                while(i >= 0 && s[i] == ' ') i--;
                if(i < 0) break;
            
                int j = i;
                while(j >= 0 && s[i] != ' ') j--;

                if(!result.empty()) result += " ";
                result += s.substr(j+1, i-j);

                i = j-1;
            
            }
            return result;
        }

};