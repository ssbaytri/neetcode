class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        s = set(nums)
        best = 0

        for num in s:
            if num - 1 not in s:
                length = 1
                curr = num
                while curr + 1 in s:
                    length += 1
                    curr += 1
                best = max(best, length)

        return best
