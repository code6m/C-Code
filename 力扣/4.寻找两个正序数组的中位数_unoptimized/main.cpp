class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int p = nums1.size()+nums2.size();
        auto i = nums1.begin(),j = nums2.begin();
        int position = 1;

        while(position!=(p+1)/2){

            if(nums1.empty()||!nums2.empty()&&nums2.back()>nums1.back()){
                nums2.pop_back();
                position++;
            }else{
                nums1.pop_back();
                position++;
            }

        }

        if(p%2==0){
            double sum=0;
            if(nums1.empty()||!nums2.empty()&&nums2.back()>nums1.back()){             
                sum+=nums2.back();
                nums2.pop_back();
                position++;
            }else{
                sum+=nums1.back();
                nums1.pop_back();
                position++;
            }
          if(nums2.empty()){
                return (sum+nums1.back())/2;
            }else if(nums1.empty())
                return (sum+nums2.back())/2;
             else
                return (sum+max(nums1.back(),nums2.back()))/2 ;  
        }else{
            if(nums2.empty()){
                return nums1.back();
            }else if(nums1.empty())
                return nums2.back();
             else
                return max(nums1.back(),nums2.back()) ;  
        }
    }
};