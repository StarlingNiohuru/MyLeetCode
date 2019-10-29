using namespace std;

//Use 2 pointers, slow and fast, to find the circle
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = sumOfDigits(slow);
            fast = sumOfDigits(fast);
            fast = sumOfDigits(fast);
        } while (slow != fast);
        return slow == 1;
    }

private:
    int sumOfDigits(int n) {
        int sum = 0, digit = 0;
        while (n > 0) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        };
        return sum;
    }
};