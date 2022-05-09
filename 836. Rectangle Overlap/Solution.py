class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        xMatch = not(rec1[2] <= rec2[0] or rec2[2] <= rec1[0])
        yMatch = not(rec1[3] <= rec2[1] or rec2[3] <= rec1[1])
        if xMatch and yMatch:
            return True
        else:
            return False
