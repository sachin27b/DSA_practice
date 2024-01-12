// https://leetcode.com/problems/merge-intervals/description/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];


        for(int i = 1; i < intervals.size(); i++)
        {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if(prev_end < curr_start)
            {
                vector<int> interval;
                interval.push_back(prev_start);
                interval.push_back(prev_end);
                ans.push_back(interval);
                prev_start = curr_start;
                prev_end = curr_end;
            }

            else
            {
                prev_end = prev_end > curr_end ? prev_end : curr_end;
            }
        }

        // if(i == intervals.size()-1 || intervals.size() == 1 then below has to be executed
            vector<int> interval;
            interval.push_back(prev_start);
            interval.push_back(prev_end);
            ans.push_back(interval);
        
        return ans;
    }
};
