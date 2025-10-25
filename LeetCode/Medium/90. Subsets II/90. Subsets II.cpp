class Solution {
public:
    vector<vector<int>> result ;
    void dfs (vector<int> nums,vector<int> subset, int start){
        result.push_back(subset) ;
        int nums_size = nums.size() ;
        if (start >= nums_size)
            return ;
            
        for (int i = start ; i < nums_size ; i++){
            subset.push_back(nums[i]) ;
            dfs(nums, subset, i + 1) ;
            subset.pop_back() ;

            while (i + 1 < nums_size && nums[i] == nums[i+1])
                i++ ;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int t_pos[11] = {0}, t_neg[11] = {0} ;
        for (auto x : nums){
            if (x>=0)
                t_pos[x]++ ;
            else
                t_neg[-x]++ ;
        }
        nums.clear() ;
        for (int i = -10 ; i<=10 ; i++){
            if (i>=0 && t_pos[i]>0){
                for (int j = 0 ; j < t_pos[i] ; j++)
                    nums.push_back(i) ;
            }
            if (i<0 && t_neg[-i]>0){
                for (int j = 0 ; j < t_neg[-i] ; j++)
                    nums.push_back(i) ;
            }
        }
        dfs(nums, {}, 0) ;
        return result ;
    }
};