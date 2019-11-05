//https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            sum [i + 1] = sum [i] + nums [i];
    }
    
    void update(int i, int val) {
        int dif = sum[i + 1] - sum[i] - val;
        for (int j = i + 1; j < sum.size(); j++)
            sum[j] -= dif;
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum [i];
    }
    
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
