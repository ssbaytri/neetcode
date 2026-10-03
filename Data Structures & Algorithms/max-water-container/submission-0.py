class Solution:
    def maxArea(self, heights: List[int]) -> int:
        L, R = 0, len(heights) - 1
        best = 0

        while L < R:
            w = R - L
            h = min(heights[L], heights[R])
            best = max(best, w * h)

            if heights[L] < heights[R]:
                L += 1
            else:
                R -= 1

        return best