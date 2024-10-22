#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std ;

/*
Top K Elements in List

Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
Constraints:

1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.

*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashMap ;

    vector<vector<int>> frequency(nums.size() + 1) ;
 
    for(int n : nums ){
        hashMap[n]++ ;
    } // filling the hash map with the repetitions of each number from the integers vector

    for(const auto& entry : hashMap){

        frequency[entry.second].push_back(entry.first) ;

    } // "flipping" the hashmap, making a Bucket data structure, using the entries of the hash map

    vector<int> answer;
    
    for (int i = frequency.size() - 1 ; i > 0 ; --i) {

        for (int n : frequency[i]) {

            answer.push_back(n) ;

            if( answer.size() == k){
                return answer ;
            }
        } 
    } // filling the answers vector with the top K most frequent elements

    return answer ;

} // implementing bucketSort algorithm

int main() {

    vector<int> nums = { 1, 2, 2, 3, 3, 3 } ; 

    int k = 2 ;

    vector<int> answer = topKFrequent(nums, 2) ;

    for(int i = 0 ; i < answer.size() ; i++ ){
        cout << answer[i] << " " ;
    } 

    return 0 ;
}