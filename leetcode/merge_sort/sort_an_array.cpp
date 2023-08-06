// link - https://leetcode.com/problems/sort-an-array/

class Solution {
public:

    vector<int> v;
    void merge(int l, int r, int mid){
        int left_size = mid - l + 1;
        int L[left_size+1];

        int right_size = r - mid;
        int R[right_size+1];

        for(int i = l, j = 0; i<=mid; i++, j++)
            L[j] = v[i];

        for(int i = mid+1, j = 0; i<=r; i++, j++)
            R[j] = v[i];
        
        L[left_size] = INT_MAX;
        R[right_size] = INT_MAX;

        int lp = 0, rp = 0;

        for(int i = l; i<=r; i++){
            if(L[lp]<=R[rp]){
                v[i] = L[lp];
                lp++;
            }
            else{
                v[i] = R[rp];
                rp++;
            }
        }
    }
    void merge_sort(int l, int r){
        if(l==r) return;
        int mid = (l+r)/2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, r, mid);  
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        v = nums;
        merge_sort(0, n-1);
        
        return v;
    }
};