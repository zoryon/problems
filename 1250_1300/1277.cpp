/*  
 *  TITLE: 1277. Count Square Submatrices with All Ones
 *  DESCRIPTION: Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
 *
 *  CONSTRAINTS:
 *      - 1 <= arr.length <= 300
 *      - 1 <= arr[0].length <= 300
 *      - 0 <= arr[i][j] <= 1
*/  

// Solutions
// C++
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int total = 0;

        // Looping through rows
        for (int i = 0; i < matrix.size(); i++) {
            // Looping through columns
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) { // First row / col cannot form a square bigger than 1x1
                        matrix[i][j] = 1; // Only 1x1 possible
                    } else {
                        // matrix[i][j] is the size of the square
                        // matrix[i-1][j] = TOP RIGHT
                        // matrix[i][j-1] = LEFT
                        // matrix[i-1][j-1] = TOP LEFT DIAGONAL
                        // min finds the smallest neighbor, which limits the square size
                        matrix[i][j] = 1 + min({ matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1] });
                    }
                    total += matrix[i][j];
                }
            }
        }

        return total;
    }
};