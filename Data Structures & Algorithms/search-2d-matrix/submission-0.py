class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        while left <= right:
            mid = left + (right - left) // 2
            row, col = mid // n, mid % n
            value = matrix[row][col]

            if target < value:
                right = mid - 1
            elif target > value:
                left = mid + 1
            else:
                return True

        return False