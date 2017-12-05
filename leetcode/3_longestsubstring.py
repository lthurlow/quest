"""
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # first thought, add characters if unique, when we find a duplicate
        # find the occurance of that letter and remove everything before it.
        # keep a rolling window of the substring.
        # O(s+l) time/space, s is input, l is subsequence // find on l
        temp_str = ""
        max_temp_len = 0
        current_temp_len = 0
        for index in range(len(s)):
            current_letter = s[index]
            if current_letter not in temp_str:
                temp_str += current_letter
                current_temp_len = len(temp_str)
                if current_temp_len > max_temp_len:
                    max_temp_len = current_temp_len
            else:
                # find duplicate
                duplicate = temp_str.index(current_letter)
                # remove all the characters before the duplicate we are adding
                # if duplicate was the last character we saw, set empty string
                if duplicate == len(temp_str):
                    temp_str = ""
                # otherwise remove all the previous characters before duplicate
                else:
                    temp_str = temp_str[duplicate+1:]
                    temp_str += current_letter
                # no need to update current_temp_len or max_temp_len as we are not adding
        return max_temp_len
