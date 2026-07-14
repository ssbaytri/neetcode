class Solution:
    def countSeniors(self, details: List[str]) -> int:
        res = 0
        for one in details:
            if int(one[11:13]) > 60:
                res += 1

        return res