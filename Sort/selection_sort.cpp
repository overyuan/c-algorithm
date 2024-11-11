/*selection_sort*/
//each round the smallest element is selected from the unsorted interval and placed at the end of the sorted interval.
vector<int> nums;
void SeletionSort(vector<int> &nums){
  int n = nums.size();
  for(int i=0;i<=n-1;i++){
    //找到最小元素
    int k=i;
    for(int j=i+1;j<=n-1;j++){
      if(nums[j]<nums[i]) k=j;
    }
    swap(nums[k],nums[i]);//交换
  }
}
//Time Complexity:O(n^2);Space Complexity:O(1);unstable.
