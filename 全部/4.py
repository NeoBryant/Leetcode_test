from typing import List

# 先将两个正序数组合并，再求合并后的数组的中位数
# O(m+n)
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = list()
        f1 = 0
        f2 = 0
        r1 = len(nums1)
        r2 = len(nums2)
        
        while f1 != r1 or f2 != r2:
            if f1 != r1 and f2 != r2:
                if nums1[f1] < nums2[f2]:
                    nums.append(nums1[f1])
                    f1 += 1
                else: 
                    nums.append(nums2[f2])
                    f2 += 1
            else:
                if f2 == r2:
                    nums.append(nums1[f1])
                    f1 += 1
                elif f1 == r1:
                    nums.append(nums2[f2])
                    f2 += 1
        # print(nums)
        if len(nums)%2 == 0:
            return (nums[int(len(nums) / 2) - 1] + nums[int(len(nums) / 2)])/2
        else:
            return nums[int(len(nums) / 2)]


test = Solution()

nums1 = [1,2]
nums2 = [3,4,5]
result = test.findMedianSortedArrays(nums1, nums2)
print(result)
