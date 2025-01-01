class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // 在两个数组中都寻找一个分界线，使得两个分界线左边所有的元素，都小于右边的，然后中位数就会在分割线的两边
       if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int totalLeft = (m+n+1)/2; //分割线左边的元素个数

        //在nums1的区间（0，m）寻找恰当的分界线
        // i，j为分割线右边元素的下标，正好对应其左边元素的数目
        //使nums1[i-1]<=nums2[j]&&nums2[j-1]<=nums1[i]
        int left = 0;
        int right = m;
        int median1 = 0,median2 = 0;//前一部分的最大值，后一部分的最小值
        while(left<=right){
            int i = (right+left)/2;//这样写可以防止直接加的时候int溢出
            int j = totalLeft-i;
            int nums1LeftMax =(i==0? INT_MIN:nums1[i-1]) ;
            int nums1RightMin = (i==m? INT_MAX:nums1[i]);
            int nums2LeftMax = (j==0? INT_MIN:nums2[j-1]);
            int nums2RightMin = (j==n? INT_MAX:nums2[j]);
            if(nums1LeftMax <= nums2RightMin){
                median1 = max(nums1LeftMax,nums2LeftMax);
                median2 = min(nums1RightMin,nums2RightMin);
                left = i+1;
            }else{
                right = i-1;
            }
        }
       
        if((m+n)%2 == 0 ){
            return (median1+median2)/2.0;
        }else{
            return median1;
        }
    }    
     
};