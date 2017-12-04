// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash_table;
        std::vector<int> index_tuple(2);
        
        // unlike python, we need to implement the hash table before we look up
        for (int iter = 0; iter < nums.size(); ++iter){
            // because we are using map with unique keys, on duplicates, lets check to see if
            // there is a solution, conviently, this reduces the run time by O(n), that is
            // on insert, check if there is already a solution (before adding iter)
						// so runtime as a whole is O(n)
            std::unordered_map<int,int>::iterator target_iter = hash_table.find(target-nums[iter]);
            if (target_iter != hash_table.end()){
                index_tuple = {target_iter->second, iter};
                return index_tuple;
            }
            hash_table.insert({nums[iter], iter});
        }
    }
};
