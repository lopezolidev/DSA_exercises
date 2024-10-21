#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std ;

/*
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

bool hasDuplicate(vector<int>& nums) {
    bool answer = false ;

    for (int i = 0 ; i < nums.size() ; i++ ) {
        
        for(int j = i+1 ; j < nums.size() ; j++){
        
            cout <<"i: " << i << endl ;
            cout << "j: " << j << endl ;

            if(nums[i] == nums[j]){

                answer = true ;
        
            }
        
        }
    
    }

    return answer ;
    } // brute force approach

bool hasDuplicate2(vector<int> nums){
    sort(nums.begin(), nums.end()) ;

    int i = 1 ;
    while( i < nums.size()){ 
        if(nums[i-1] == nums[i]){
            return true ;
        }

        i++ ;
    }
    return false ;

} // sort solution

bool hasDuplicate3(vector<int> nums){
    unordered_set<int> seen ;

    for( int i = 0 ; i < nums.size() ; i++ ){

        if(seen.count(nums[i])){
            return true ;
        }

        seen.insert(nums[i]) ;
    }
    return false ;

} // hashmap (unordered set) solution


int main () {

    vector<int> numbers = { 1,2,3,3 } ;

    // bool res = hasDuplicate(numbers) ;
   
    // bool res = hasDuplicate2(numbers) ;

    bool res = hasDuplicate3(numbers) ;

    if(res){
        cout << "TRUE" ;
    } else {
        cout << "FALSE" ;
    }

    return 0 ;
}
