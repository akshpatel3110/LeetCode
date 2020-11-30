// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    // expected value for the number of calls to rand7()
    // 2 * (1 / (40 / 49)) = 49 / 20
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        return (num <= 40) ? (num % 10 + 1) : rand10();        
    }
};
