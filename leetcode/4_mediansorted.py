"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
"""
class Solution:
    def emptyList(self, nums):
        midpoint = len(nums)//2  # taking the floor
        # will handle the case where there is only one element
        if len(nums) % 2 == 1:
            return float(nums[midpoint])  # we need to return a float, but list is of ints =/
        else:
            # cant be zero, therefore must have 2 elements, shouldnt fail.
            return sum(nums[midpoint-1:midpoint+1])/2  # use floating point divide, no need to type cast
    
    def findMedian(self, nums1, nums2):
        
        if len(nums1) == 1 and nums1 == nums2:
            return float(nums1)
        
        # so now we can assume that both of our lists have elements, 1....n
        midpoint1 = len(nums1)//2
        midpoint2 = len(nums2)//2
        
        # start with our initial medians
        median1 = nums1[midpoint1]  # python 3 isnt backwards compatable, this takes the floor
        median2 = nums2[midpoint2]
        
        while not True:
            # if left median larger than right, take sub-list with elements > than median1, and
            # the sublist with elements < median2
            if median1 > median2:
                
            elif median1 < median2:
            # if the values are equal we've found the median
            else:
                return float(median1)
    
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # the first thought, that my professor would say is obvviouuus would be to merge the lists
        # that however would take n time, so the fact that the lists are sorted for us means that
        # we have something to exploit the time constraint.  Log time tells us we should be moving
        # reducing our search space exponentially.
        
        # second thought would be to pick the median for each median for their prospective lists
        # then for the log part, use binary search to reduce search space to compare to find the
        # median
        
        # in my mind, the trick here is in updating the median as we go to update our search space
        
        # this question doesnt say we cant have empty lists
        if not nums1:
            if not nums2:
                return 0  # they expect 0 not None for when lists are empty
            else:
                return self.emptyList(nums2)
        elif not nums2: # because nums1 is not empty, if nums2 is we can call function, already checked both equal
            return self.emptyList(nums1)
        
        # now the recursive algorithm to find the median of both lists
        return self.findMedian(nums1, nums2)
