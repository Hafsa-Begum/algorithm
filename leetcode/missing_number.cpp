// link - https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing;
        sort(nums.begin(), nums.end());
        set<int> v;
        for(int i = 0; i<nums.size(); i++){
            v.insert(nums[i]);
        }

        for(int i = 0; i<=nums.size(); i++){
            if(!v.count(i)){
                missing = i;
            }
        }
        
        return missing;
    }
};