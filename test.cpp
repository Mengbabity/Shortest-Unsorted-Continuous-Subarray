class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        
        int res=0;

        int left=0,right=n-1;
        int imax=INT_MIN,imin=INT_MAX;
        
        while(left+1<n && nums[left+1]>=nums[left])
            left++;
        
        while(right-1>=0 && nums[right-1]<=nums[right])
            right--;
        
        if(right>left)
        {
            for(int i=left;i<=right;i++)
            {
                if(nums[i]>imax)
                    imax=nums[i];
                
                if(nums[i]<imin)
                    imin=nums[i];
            }
            
            while(left>=0 && nums[left]>imin)
                left--;
            while(right<n && nums[right]<imax)
                right++;
            
            res=right-left-1;
        }
        
        return res;
        
    }
};
