// link - https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = m-1, y = n-1, k = m+n-1;
        while(x>=0 && y>=0){
            if(nums1[x]>nums2[y]){
                nums1[k--] = nums1[x--];
            }
            else{
                nums1[k--] = nums2[y--];
            }
        }
        while(y>=0){
            nums1[k--] = nums2[y--];
        }
    }
};