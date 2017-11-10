# 4sum = 2sum + 2sum
# [-5,5,4,-3,0,0,4,-2] 
#          i  
#       k 
#                    j  

# [-5,5,4,-3,0,0,4,-2] target = 4

# don't sort [[5,-3,4,-2],[5,4,-3,-2],[-5,5,4,0],[-5,5,0,4]]

# expected [[-5,0,4,5],[-3,-2,4,5]]

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        dic = collections.defaultdict(set)
        res = set()
        n = len(nums)
        
        for i in range(n):
            for j in range(i + 1, n):
                sum = nums[i] + nums[j]
                for half in dic[target - sum]:
                    res.add(tuple(list(half) + [nums[i], nums[j]]))
                    
            for k in range(i):
                dic[nums[i] + nums[k]].add((nums[k], nums[i]))
                
        return list(res)
