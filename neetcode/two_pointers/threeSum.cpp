/*
Three Integer Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1: 

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:

Input: nums = [0,1,1]

Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]

Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5

*/


#include <iostream>
#include <vector>
#include <set>

using namespace std ;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()) ;
    
    vector<vector<int>> result  ;

    for( int i = 0 ; i < nums.size() ; i++ ){
        if(nums[i] > 0) break ; // if the number at which we're starting is greater than 0, then break the loop

        if( i > 0 && nums[i] == nums[i - 1] ) continue ; // case were the next number in the array is the same as the previous 

        // now we use the TwoSum 2 concept of 2 pointer, where we move them across the array from the extremes to the center, considering that we start our left pointer in the next position as index ' i '

        int l = i + 1 ;
        int r = nums.size() - 1 ;

        while( l < r ){

            int sum = nums[i] + nums[l] + nums[r] ;

            if( sum > 0 ){
                r-- ; // when the sum is too big, we substract from the right pointer
            } else if ( sum < 0 ){
                l++ ;
            } else {

                result.push_back({ nums[i], nums[l], nums[r] }) ;
                l++ ;
                r-- ; 
                // insertin the triplet in our vector of results, increasing the left pointer and decreasing the right, in order to not repeat the same solution

                while(l < r && nums[l] == nums[l - 1]){
                    l++ ;
                } // in case the left pointer when updated points to the same number at the right and it's still less than the right pointer, we'll increase it
            }

        } 

    }


    return result ;
}

int main () {
    vector<int> nums = { -1, 0, 1 ,2 , -1, -4 } ;

    // vector<vector<int>> answer = threeSum(nums) ;
 
    return 0 ;
}