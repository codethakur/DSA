class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            long long arr3[n+m];
            int left = 0;
            int  right = 0;
            int index = 0;
            while(left<n && right<m)
            {
                if(arr1[left]<=arr2[right]){
                    arr3[index] = arr1[left];
                    left++; index++;
                }else{
                    arr3[index] = arr2[right];
                    right++; index++;
                }
            }
            while(left<n){
                arr3[index++]=arr1[left++];
            }
            while(right<m){
                arr3[index++] = arr2[right++];
            }
            for(int i=0; i<n+m; i++)
            {
                if(i<n) arr1[i]=arr3[i];
                else arr2[i-n] = arr3[i];
            }
            
        } 
// Time  O(n+m) + O(m+n)
// Space O(n+m)
};
//`````````````````````````````````````````
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int left = n-1;
            int right = 0;
            while(left>=0 && right<m)
            {
                if(arr1[left]>arr2[right]){
                    swap(arr1[left], arr2[right]);
                    left--; right++;
                }else{
                    break;
                }
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        }
//Time O(mini(n,m)) +log(n) +log(m);
//space O(1)
};
//````````````````````````````````````````````````````
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
//Timelog2(n+m)
//sp O(1)





