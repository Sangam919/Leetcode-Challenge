class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n = 1, sum = 0;

    while (sum < num) {
        sum += n; 
        n += 2;  
    }

    return (sum == num);
        
    }
};
