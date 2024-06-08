class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // handling edge case
        int size=nums.size();
        // if(size==1){
        //     return nums[0];
        // }

        int s=0,e=size-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;

            if(mid%2==0 && mid<size-1 && nums[mid]==nums[mid+1] || mid%2!=0 && mid>0 && nums[mid]==nums[mid-1]){
                s=mid+1;
            }
            else if(mid%2==0 && mid>0 && nums[mid]==nums[mid-1] || mid%2!=0 && mid<size-1 && nums[mid]==nums[mid+1]){
                e=mid-1;
            }
            else{
                return nums[mid];
            }
        }
        return 0;
    }
};