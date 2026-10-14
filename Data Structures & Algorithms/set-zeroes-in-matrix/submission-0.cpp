class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> a=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    for(int k=0;k<m;k++){
                        matrix[i][k]=0;
                    }
                    for(int z=0;z<n;z++){
                        matrix[z][j]=0;
                    }
                }
            }
        }
    }
};
