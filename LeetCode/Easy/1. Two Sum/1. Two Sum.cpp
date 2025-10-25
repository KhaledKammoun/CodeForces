class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m ;
        int n = nums.size() ;
        for (int i = 0 ; i<n ;i++){
            int x = target-nums[i];
            if (m.count(x))
                return {m[x],i} ;
            m[nums[i]]=i ;
        }
        return {0,1} ;
    }
};