class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxi=0;
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int area=abs(min(arr[i],arr[j])*(i-j));
            maxi=max(maxi,area);
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        return maxi;
    }
};
