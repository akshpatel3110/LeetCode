class Solution {
public:
    int findComplement(int num) {
        if (!num) 
            return 1;
        
        int count = 0;
        for (int x = num; x; x >>= 1)
            ++count;
        
        return ~num & ((1ll << count) - 1);
    }
};
