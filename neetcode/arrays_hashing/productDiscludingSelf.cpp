/*

Products of Array Discluding Self
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in  O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]
Output: [48,24,12,8]

Example 2:
Input: nums = [-1,0,1,2,3]

Output: [0,-6,0,0,0]
Constraints:

2 <= nums.length <= 1000
-20 <= nums[i] <= 20
*/

#include <iostream>
#include <vector>

using namespace std ;

vector<int> productExceptSelf(vector<int>& nums) {
    int i = 0 ;

    
    vector<int> result ; 

    while (i < nums.size()) {

        int j = 0 ;

        int temp = 1 ;

        while(j < nums.size()){
            if(j != i ){
                temp *= nums[j] ;
            }
            j++ ;
        }

        result.push_back(temp) ;

        i++ ;
    }

    return result ;
    
} // Solution O(n²) double loop

vector<int> productExceptSelf2(vector<int>& nums){
    int i = 0 ;

    int valueJ = nums.size() - 1 ;

    int j = valueJ ;

    vector<int> result ;

    int product = 1 ;

    int counter = 0 ;

    int totalLength = nums.size() ;

    while(counter < totalLength ){
        if( i != j && j >= 0){
            product *= nums[j] ;
            j-- ;
            // counter++ ; 
        }  // only when i != j and j >= 0 we'll make the product, decrease j and increase the counter
        if(j < 0){
            result.push_back(product) ;
            product = 1 ;
            i++ ;
            j = valueJ ;
            counter++ ;
        } // if j < 0, we'll push back the product, then reinitialize it in 1, increasing ' i ' by 1, restarting j at valueJ and increasing the total counter  
        
        if(i == j){
            j-- ;
        } // if both integers are the same, reducing j by 1
    } 

    return result ;
} // O(n) → employing multiple counters in a single loop

int main () {

    vector<int> numbers = { 1,2,4,6 } ;

    vector<int> result = productExceptSelf2(numbers) ;

    for(int i = 0 ; i < result.size() ; i++ ){

        cout << result[i] << " " ;
    } 

    return 0 ;
}