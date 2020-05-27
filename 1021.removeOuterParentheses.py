class  Solution:
    def removeOuterParentheses(self, S: str) -> str:
            t = ''
            leftnum, rightnum = 1, 0
            i = 1
            while i < len(S):
                if  S[i] == '(':
                    leftnum += 1
                else:
                    rightnum += 1

                if  leftnum == rightnum:
                    i +=  1
                    leftnum = 1
                    rightnum = 0
                else:
                    t = t + S[i]
                i += 1
            return  t