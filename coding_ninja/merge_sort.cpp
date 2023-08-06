link - https://www.codingninjas.com/studio/problems/merge-sort_920442?leftPanelTab=0

void merge(vector<int> &arr, int l, int r, int mid){
    int l_size = mid - l + 1;
    int L[l_size];

    int r_size = r - mid;
    int R[r_size];

    for(int i = l, j = 0; i<=mid; i++, j++){
        L[j] = arr[i];
    }
    for(int i = mid+1, j = 0; i<=r; i++, j++){
        R[j] = arr[i];
    }
    int i = 0;
    int j = 0;
    int k = l;

    while(i<l_size && j<r_size){
        if(L[i]<R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i<l_size){
        arr[k++] = L[i++];
    }

    while(j<r_size){
        arr[k++] = R[j++];
    }
}

void merge_sort(vector < int > & arr, int l, int r){
    if(l==r) return;
    int mid = (l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, r, mid);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    merge_sort(arr, 0, n-1);    
}