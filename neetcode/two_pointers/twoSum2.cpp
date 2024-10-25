/*
Two Integer Sum II
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use  O(1) additional space.

Example 1:

Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
Explanation:
The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2].

Constraints:

2 <= numbers.length <= 1000
-1000 <= numbers[i] <= 1000
-1000 <= target <= 1000

*/

#include <iostream>
#include <vector>

using namespace std ;

vector<int> twoSum(vector<int>& numbers, int target) {
    
    vector<int> result ;

    int i = 0 ;
    int j = i + 1 ;


    while (i < numbers.size() ){
        if( numbers[i] + numbers[j] == target ){
            result.push_back(i + 1) ;
            result.push_back(j + 1) ;

            break ;        
        }
        j++ ;

        if( j == numbers.size() ){
            i++ ;
            j = i + 1 ;
        }
    }

    return result ;
}   // Brute force approach - Time complexity O(n!), Space complexity: O(1) → no additional memory needed 

vector<int> twoSum2(vector<int>& numbers, int target) {
    int l = 0 ; 
    int r = numbers.size() - 1 ;

    while(l < r){

        int currentSum = numbers[l] + numbers[r] ;

        if( currentSum < target ){
            l++ ;
        } else if( currentSum > target ){
            r-- ;
        } else {
            return {l + 1, r + 1 } ;
        }

    }
    return {} ;
}// solution with time complexity of: O(n); space complexity: O(1) → no additional memory required 

int main (){
    
    vector<int> numbers = { -1,0} ;

    int target = -1 ;

    vector<int> response = twoSum2(numbers, target) ;

    cout << response[0] << " " << response[1] << endl ;
 

    return 0 ;
}