class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        count = 0
        
        while True:
            for s in strs:
                if count >= len(s) or s[count] != strs[0][count]:
                    return strs[0][:count]
            count += 1