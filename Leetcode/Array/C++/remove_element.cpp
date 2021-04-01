class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // check exception case
        if (nums.empty()){
            return 0;
        }
        
        int idx = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (val != nums[i]){
                nums[idx++] = nums[i];
            }
        }
        return idx;
         
    }
};


