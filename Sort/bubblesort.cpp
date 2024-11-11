/*Bubble Sort*/
//Bubble sort achieves sorting by successively comparing and exchanging neighbouring elements.
void BubbleSort(vector<int> &nums){
  int n = num.size();
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++){
      if(nums[j]>nums[j+1]){
        swap(nums[j],nums[j+1]);
      }
    }
  }
}
//Time Complexity:O(n^2);Space Complexity:O(1);Stable.
