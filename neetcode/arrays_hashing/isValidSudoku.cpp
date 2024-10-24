/*
Valid Sudoku
You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

* Each row must contain the digits 1-9 without duplicates.
* Each column must contain the digits 1-9 without duplicates.
* Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
* Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.

Example 1:

Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: true

Example 2:

Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: false

Explanation: There are two 1's in the top-left 3x3 sub-box.

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std ;

bool isValidSudoku(vector<vector<char>>& board) {


    int row[10] = {0} ; 

    int i = 0 ;
    int j = 0 ;

    while(i < board.size() ){

        if( board[i][j] != '.'){
            
            if( row[ int( board[i][j]) - int('0')] == 1 ){
                
                return false ;
            
            } 
            
            row[ int( board[i][j] ) - int('0')] += 1 ;
            j++ ; 

            
        } 
        
        if( board[i][j] == '.' ){

            j++ ;

        } 
        
        if( j > 8 ){
           
            j = 0; 
            i++ ;
            row[0] = 0 ;
            row[1] = 0 ;
            row[2] = 0 ;
            row[3] = 0 ;
            row[4] = 0 ;
            row[5] = 0 ;
            row[6] = 0 ;
            row[7] = 0 ;
            row[8] = 0 ;
            row[9] = 0 ;
         
        }

    } // loop to check if rows are valid in the sudoku

    int col[10] = {0} ;

    int k = 0 ;
    int m = 0 ;

    while( k < board.size() ) {
        if( board[m][k] != '.'){
            
            if( col[ int( board[m][k]) - int('0') ] == 1 ){
                
                return false ;
            
            } 
            
            col[ int( board[m][k] ) - int('0') ]++ ;
            m++ ;
        } else {
            m++ ;
        }

        if(m == 9){
            m = 0; 
            k++ ;
            col[0] = 0 ;
            col[1] = 0 ;
            col[2] = 0 ;
            col[3] = 0 ;
            col[4] = 0 ;
            col[5] = 0 ;
            col[6] = 0 ;
            col[7] = 0 ;
            col[8] = 0 ;
            col[9] = 0 ;
        }

    } // loop to check if columns are are valid in the sudoku

    // now to check if the cell is already in the same square

    unordered_map<int, unordered_set<char>> square ;

    // key = (r / 3) * 3 + c / 3

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char cell = board[r][c] ;

            if( cell == '.'){
                continue ;
            } // if such cell is ' . ' we don't check in the square nor in the row or the col
            
            if (   square[(r/3) * 3 + c/3].count(cell) ){
                return false ;
            } // hashing each square (of 9 cells) like a number of rows integer divided by 3, multiplied by 3 + columns divided by 3. In such key, we have a hashset of characters, where if such character we're in that moment is already in the hashset, then we return false 

            square[ (r/3) * 3 + c/3 ].insert(cell) ; 
            //if such cell is not present in the hashset, we'll insert it
        }
        
    }

    return true ;
} //  multiple counter version with cell checking using special hashing key


int main () {

    vector<vector<char>> board ;
    board.push_back({'1', '2', '.', '.', '3', '.', '.', '.', '.'});
    board.push_back({'4', '.', '.', '5', '.', '.', '.', '.', '.'});
    board.push_back({'.', '9', '1', '.', '.', '.', '.', '.', '3'});
    board.push_back({'5', '.', '.', '.', '6', '.', '.', '.', '4'});
    board.push_back({'.', '.', '.', '8', '.', '3', '.', '.', '5'});
    board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    board.push_back({'.', '.', '.', '.', '.', '.', '2', '.', '.'});
    board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '8'});
    board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});


    if(isValidSudoku(board)){
        cout << "is valid" ;
    } else {
        cout << "is not valid" ;
    }

    return 0 ;
}
