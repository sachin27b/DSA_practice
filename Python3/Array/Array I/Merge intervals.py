from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        size = len(intervals)
        intervals.sort()
        answer: List[List[int]] = []
        answer.append(intervals[0])
        for idx in range(1, size, 1):
            if(answer[-1][1] >= intervals[idx][0] and answer[-1][1] <= intervals[idx][1]):
                answer[-1][1] = intervals[idx][1]
            elif(answer[-1][1] < intervals[idx][0]):
                answer.append(intervals[idx])
        return answer
    

class_obj = Solution()
print(class_obj.merge([[1,3],[2,6],[8,10],[15,18]]))