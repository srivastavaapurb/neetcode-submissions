class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0;
        int j=n-1;
        vector<int> l;
        while(i<j){
            if(v[i].first+v[j].first>target) j--;
            else if(v[i].first+v[j].first<target) i++;
            else{
                l.push_back(v[i].second);
                l.push_back(v[j].second);
                break;
            }
        }
        sort(l.begin(),l.end());
        return l;
    }
};
