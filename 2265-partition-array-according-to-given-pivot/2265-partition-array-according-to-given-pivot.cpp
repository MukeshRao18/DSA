// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> less, equal, greater;
        
//         for(int num : nums) {
//             if (num < pivot) less.push_back(num);
//             else if (num == pivot) equal.push_back(num);
//             else greater.push_back(num);
//         }
        
//         vector<int> result;
//         result.insert(result.end(), less.begin(), less.end());
//         result.insert(result.end(), equal.begin(), equal.end());
//         result.insert(result.end(), greater.begin(), greater.end());
        
//         return result;
//     }
// };
class Solution{
    public:
      vector<int> pivotArray(vector<int>& nums,int p){
        vector<int> result(nums.size(),p);
        int i1=0,j1=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<p) {
                result[i1]=nums[i];
                i1++;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>p) {
                result[j1]=nums[i];
                j1--;
            }
        }
        return result ;
      }
} ;
