/*
Longest Consecutive Sequence
Given an array of integers nums, return the length of the longest consecutive sequence of elements.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [2,20,4,10,3,4,5]
Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:
Input: nums = [0,3,2,5,4,6,1,1]
Output: 7

Constraints:

0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std ;

int longestConsecutive(vector<int>& nums) {
    vector <int> result ;

    if(nums.size() == 0){
        return 0 ;
    }

    int i = 0 ;
    int j = 0 ;
    int min = nums[0] ;
    while( i < nums.size() ) {
        if( nums[i] < min ){
            min = nums[i] ;
        }
        i++ ;
    } // loop to find the minimum number

    result.push_back(min) ;

    i = 0 ;
    int next = 0 ;
    next = min ;
    while( i < nums.size() ){
        if( nums[j] == next + 1){
            result.push_back(nums[j]) ;
            next = nums[j] ;
            j++ ;
        } else {
            j++ ;
        }
            // appending the number to the vector if the number if consequent to the already stored at next

        if(j == nums.size() ){
            j = 0 ;
            i++ ;
        } // restart loop to increase ' i ' and restar j to 0

    }

    return result.size() ;
} // loop version without using a hashmap or hashset

int longestConsecutive2(vector<int>& nums){
    unordered_set<int> setNums(nums.begin(), nums.end()) ;

    int longest = 0 ;

    for(int n : nums){
        // we'll only check the number if it has no immediate lower values
        if( !setNums.count(n-1) ){
            
            int length = 1 ; //initial length of such sequence of numbers
            
            while( setNums.count(n + length)  ){
                length++ ;
            } // if the subsequent number exists in our set we'll increment the length of this value

            longest = max(longest, length) ; 
            // when there're no more subsequent values in our set, we'll find the max value between length variable and longest
        }
    
    } // this loop will repeat itself until we've found and compare all the possible lengths 


    return longest ;
}

int main() {

    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6} ;

    cout << "size: " << longestConsecutive2(nums) ;
 
    
    return 0 ;
}