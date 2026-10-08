class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        
        L, R = 0, len(height) - 1
        total = 0
        leftMax = rightMax = 0

        while L < R:
            if height[L] < height[R]:
                if height[L] >= leftMax:
                    leftMax = height[L]
                else:
                    total += leftMax - height[L]
                L += 1
            else:
                if height[R] >= rightMax:
                    rightMax = height[R]
                else:
                    total += rightMax - height[R]
                R -= 1
        return total
