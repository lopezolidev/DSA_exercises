/*
Trapping Rain Water
You are given an array non-negative integers heights which represent an elevation map. Each value heights[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9
Constraints:

1 <= height.length <= 1000
0 <= height[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std ;

int trap(vector<int>& height) {
    if(height.size() == 0 ) return 0 ;
    
    int l = 0 ;
    int r = height.size() - 1 ;

    int maxLeft = height[l] ;
    int maxRight = height[r] ;

    int result = 0 ;

    while( l < r ){
        if(maxLeft < maxRight){
            l++ ;

            maxLeft = max(maxLeft, height[l]) ;

            result += maxLeft - height[l] ;

        } else {
            r-- ;

            maxRight = max(maxRight, height[r]) ;

            result += maxRight - height[r] ;

        }

    }

    return result ;
}  // Time complexity: O(n) , Space complexity: O(1) → using two pointers approach


int main () {

    vector<int> heights = { 0, 2, 0, 3, 1, 0, 1, 3, 2, 1 } ;

    cout << "max water trapped is: " << trap(heights) ;


    return 0 ;
}