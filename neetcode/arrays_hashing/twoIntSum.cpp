#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std ;

/*

Two Integer Sum

Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.

*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer ;

    int p = -1 ;
    int q = -1 ;

    int i = 0 ;
    
    while( i < nums.size()) {
        int j = i + 1 ;
        while (j < nums. size()){

            if(nums[i] + nums[j] == target) {
                
                    p = i ;
                    q = j ;
              
            }

            j++ ;
        }

        i++ ;
    }
    answer = {p, q} ;
    return answer ;
}// brute force approach → Double loop

vector<int> twoSum2 (vector<int>& nums, int target) {
    unordered_map<int, int> myMap ; // creating the hasmap

    vector<int> answer ; // answer vector

    for(int i = 0 ; i < nums.size() ; i++ ){
        
        int complement = target - nums[i] ;

        if(myMap.count(complement)){ 

            int firstIndex = myMap[complement] ;

            answer = {firstIndex, i} ;
            
            break ;
        }// if the complement of the target - nums[i] (the complement) exists in the hashmap, then the first index is such key of the hasmap and the second key is the actual index where the loop is iterating 

        myMap.insert({nums[i], i}) ; //inserting the vector in the hasmap
    
    }

    return answer ;
} // hashmap solution


int main() {

    vector<int> nums = { 3 , 4 , 5 , 6 } ;

    int target = 10 ;

    vector<int> res = twoSum2(nums, target) ;

    for(int k = 0 ; k < res.size() ; k++ ){
        cout  << " "<< res[k] << "," ;
    }

    return 0 ;
}