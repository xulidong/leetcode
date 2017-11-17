/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3.
 *  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        string longest = "";
        for (int i = 0; i < len; i++) {
            string tmp = "";
            for (int j = i; j < len; j++) {
                char ch = s.at(j);
                if (tmp.find(ch) == string::npos) {
                    tmp += ch;
                } else {
                    break;
                }
            }
            if (tmp.length() > longest.length()) {
                longest = tmp;
            }
        }
        return longest.length();
    }
};

int main() {
    Solution sol;

    string str1 = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(str1) << endl;

    string str2 = "bbbbb";
    cout << sol.lengthOfLongestSubstring(str2) << endl;

    string str3 = "pwwkew";
    cout << sol.lengthOfLongestSubstring(str3) << endl;
    return 0;
}