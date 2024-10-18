#include <iostream>
#include <vector>

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

void hasDuplicate(vector<int>& nums) {

    }


int main () {

    vector<string> fruits ;

    fruits = {"grapes", "apples", "papayas"} ; // vectors are dynamically created

    fruits.push_back("lemons") ;

   for (int i = 0; i < fruits.size(); i++)
   {
    cout << fruits[i] << endl ;
   }
   

    return 0 ;
}
