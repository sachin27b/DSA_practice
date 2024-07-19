\\ https://leetcode.com/problems/powx-n/description/
class Solution {
public:
    double myPow(double x, int n) {
        
        double num = x, ans = 1.0;
        long long pow = abs(n);
        while(pow >= 1)
        {
            if(pow % 2 == 0)
            {
                num = num * num; 
                pow = pow / 2;
            }

            else
            {
                pow = pow - 1;
                ans = ans * num;
            }
        }

        if(n < 0)
        {
            ans = 1 / ans;
        }

        return ans;
    }
};
