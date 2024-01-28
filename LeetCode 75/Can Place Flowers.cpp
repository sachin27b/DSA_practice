//https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, size = flowerbed.size();
        while(i < size-1 && n > 0)
        {
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                i += 2;
            }
            else if(flowerbed[i] == 1)
            {
                i += 2;
            }
            else// case: 0 followed by 1.
            {
                i += 1;
            }
        }

        if(size > 2 && flowerbed[size-1] == 0 && flowerbed[size-2] == 0)
        {
            n--;
            flowerbed[size-1] = 0;
        }
        else if(size == 1 && flowerbed[0] == 0)
        {
            n--;
            flowerbed[0] = 1;
        }
        if(n > 0)
            return false;
        else
            return true;
    }
};
