class Solution(object):
    def isPalindrome(self, s):
        return s == s[::-1] # if reversed string is same, return true
    def longestPalindrome(self, s):
        longestMatch = 0
        longestStr = ""
        # if it is an empty or single character, return itself.
        if len(s) < 2:
            return s
        # start loop from 0 to n, and second loop of n to i+longestMatch
        # second loop will make sure we dont work harder than necessary
        # check if the two endpoint characters match, if so, test for Palindrome
        for start in range(0, len(s)-1):
            for end in range(len(s)-1,c+longestMatch,-1):
                if s[start] == s[end] and self.isPalindrome(s[start:end+1]):
                    if end-start > longestMatch: 
                        longestMatch = end-start
                        longestStr = s[start:end+1]
        if longestStr == "" and len(s) > 1:
            return s[0]
        return longestStr
