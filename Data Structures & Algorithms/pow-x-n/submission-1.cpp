class Solution {
private:
    double f(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        double a=f(x,n/2);
        if(n%2==0) return a*a;
        return x*a*a;
    }
public:
    double myPow(double x, int n) {
        if(n>0) return f(x,n);
        return 1/f(x,-1*n);
    }
};
