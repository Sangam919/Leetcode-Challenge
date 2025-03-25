class Solution {
public:
    bool isPowerOfThree(int n) {
        int c=0;
        while(n>0)
        {
            if(n % 3 == 1)
            {
                c+=1;
            }
            if(c>1 || n % 3 == 2)
            {
                return false;
            }
            n=n/3;
        }
        return c == 1;
    }
};
