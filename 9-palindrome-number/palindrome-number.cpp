class Solution {
public:
    bool isPalindrome(int x) {
        int og = x;
        long long rev = 0;
        while(x > 0) {
            rev = (rev*10) + (x%10);
            x /= 10;
        }
        if (rev == og)
            return true;
        return false;
    }
};