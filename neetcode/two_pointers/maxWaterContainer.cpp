/*
Max Water Container
You are given an integer array heights where heights[i] represents the height of the i^th  bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Input: height = [1,7,2,5,4,7,3,6]

Output: 36
Example 2:

Input: height = [2,2,2]

Output: 4
Constraints:

2 <= height.length <= 1000
0 <= height[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std ;

int maxArea(vector<int>& heights) {
    int l = 0 ;
    int r = heights.size() - 1 ;

    int product = 0 ;
    int currentProduct = 0 ;

    while(l < r){

        if( heights[l] >= heights[r] ){

            currentProduct = heights[r] * (r - l) ;

            r-- ;

        // if the height from the left is greater than the height from the right, we'll calculate our product based on the lower height and decrease ' r ' to find a greater height, maintaining the left height

        } else if(heights[l] < heights[r]){
        
            currentProduct = heights[l] * (r - l) ;

            l++ ; 

        // same but for the right 
        } else {
            l++ ;
            // if both heights are equal increase the left pointer
        }

        if( currentProduct > product ) {
            
            product = currentProduct ;

        }

    
    }


    return product ; 
}

int main () {

    vector<int> height = { 2, 2, 2 } ;

    cout << "max area: " << maxArea(height) ;



    return 0 ;
}