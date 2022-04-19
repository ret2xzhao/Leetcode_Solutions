class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;
        std::vector<int> res;
        for (size_t pos=0; pos<nums.size(); ++pos) {
            if (hash_map.count(target-nums[pos])) {
                res.push_back(hash_map.at(target-nums[pos]));
                res.push_back(pos);
                return res;
            }
            else {
                hash_map.insert({nums[pos], pos});
            }
        }
        return res;
    }
};
