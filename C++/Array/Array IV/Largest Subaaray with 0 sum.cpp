// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1 
#include<unordered_map>
#include<algorithm>

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        /* at each element in the array we maintain a prefix sum. using a unordered
        hash map we store the sum as key and index as value.
        |- - - - - - - - - - - - -|
        |-------------------------| sum = x
                        |---------| sum = k
        |---------------| sum = x - k
        this is the intuition.
        since we are finding maximum length subarray with sum = 0(k) we will check the
        hash map at each element if there was a subarray with sum = x - k. in our case
        we will check previous subarray with sum = x. */
        unordered_map<int, int> sum_index;
        int sum = 0, max_length = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            if(sum == 0)
            {
                max_length = i + 1;
            }
            else if(sum_index.find(sum) != sum_index.end())
            {
                max_length = max(max_length, i - sum_index[sum]);
            }
            
            else
            {
                sum_index[sum] = i;
            }
        }
        return max_length;
        
    }
};
