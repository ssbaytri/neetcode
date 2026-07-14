class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        lengths = []
        count = 0

        for num in nums:
            if num == 0:
                lengths.append(count)
                count = 0
            else:
                count += 1
        lengths.append(count)

        return max(lengths)