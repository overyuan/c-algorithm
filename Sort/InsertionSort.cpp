//insertion sort means Select a datum element in the unsorted band, compare the size of the element with the elements in the sorted band to the left of it, and set the The element is inserted in the correct position.
/*insertion sort*/
void insertionSort(vector<int> &nums) {
  int n = nums.size();
  for(int i = 1;i < n;i++){
    int base = nums[i],j=i-1;
    while(j >= 0 && nums[j] > base){
      nums[j+1]=nums[j];
      j--;
    }
    nums[j+1] = base;
  }
}
//Time Complexity:O(n^2);Space Complexity:O(1);Stable.
