class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> op;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int n=i;
            if(i==0) op.push_back(i);
            else{
                while(n>0){
                    cnt+=(n & 1);
                    n >>= 1;
                }
                op.push_back(cnt);
            }
        }
        return op;
    }
};
