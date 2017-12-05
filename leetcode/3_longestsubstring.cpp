/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // probably want to use the same implementation as python, using
        // the sliding window approach, only implementation should differ
        // not really sure if there is a more efficient means for big benefit
        
        string temp_str = "";
        int max_temp_len = 0;  // I think function should return long, not int
        int current_temp_len = 0;
        
        // start by iterating through string
        for (int index = 0; index < s.length(); ++index){
            char current_char = s[index];
            std::size_t in_str = temp_str.find(current_char);
            // character not in string
            if (in_str == std::string::npos){
                temp_str += current_char;
                current_temp_len = temp_str.length();
                if (current_temp_len > max_temp_len){
                    max_temp_len = current_temp_len;
                }
            // character is in string, now we have to move window
            } else {
                // check if last character in temp_str
                if (in_str == temp_str.length()){
                    temp_str = "";
                } else {
                    // substr will go from index to end, +1 to skip the duplicate
                    temp_str = temp_str.substr(in_str+1);
                    temp_str += current_char;
                }
            }
        }
        return max_temp_len;
    }
};
