// Description:
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
// return the length of last word in the string.
// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// Example:
// Input: "Hello World"
// Output: 5


// Starting from the end of the array

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for (int i = s.length() - 1; i >= 0 ; --i) {
            if (s[i] != ' ') {
                len++;
            } else if (s[i] == ' ' && len != 0){
                break;
            }
        }
        return len;
    }
};