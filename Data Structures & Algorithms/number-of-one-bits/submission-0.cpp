class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n>0){
            cnt+=(n & 1); // n's rightmost is 1 or not
            n >>= 1;  // drop rightmost bit
        }
        return cnt;
    }
};
