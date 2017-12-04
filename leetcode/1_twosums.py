# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        # simple naive implementation, iterate n^2
        for first_index in range(0, len(nums) - 1):
            for second_index in range(first_index + 1, len(nums)):
                if nums[first_index] + nums[second_index] == target:
                    return (first_index, second_index)
        """
        # another solution, this one is a bit faster using python's quick check via hash to only
        # iterate over second loop only if there is a solution.
        for first_index in range(0, len(nums) - 1):
            # from algebra, inverse of addition to derive second value needed
            second_value = target-nums[first_index]
            # this is to avoid using same value [1,2,3], target = 4, should give 0,2 not 1,1
            list_subset = nums[first_index+1:]
            # using in, rather than for loop, should be same to worse performance worst from extra list calls
            if second_value in list_subset:
                return first_index, list_subset.index(second_value)+len(nums[:first_index+1])
