#include <vector>
#include <iostream> // For printing

using namespace std;

// Function to multiply two matrices
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    
    // Get dimensions
    // A is m x n
    // B is n x p
    // Result C will be m x p
    
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    // --- Safety Check ---
    // The number of columns in A must equal the number of rows in B
    if (n != B.size()) {
        cout << "Error: Matrix dimensions are not compatible for multiplication." << endl;
        return {}; // Return an empty matrix
    }

    // --- Create the Result Matrix ---
    // Initialize an (m x p) matrix filled with zeros
    vector<vector<int>> C(m, vector<int>(p, 0));

    // --- The Core Multiplication Algorithm ---
    // O(n^3) complexity
    for (int i = 0; i < m; ++i) {     // Loop over rows of A (and C)
        for (int j = 0; j < p; ++j) { // Loop over columns of B (and C)
            // Now, calculate C[i][j]
            // This is the dot product of row i from A and col j from B
            for (int k = 0; k < n; ++k) { // Loop over columns of A / rows of B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Helper function to print a matrix
void printMatrix(const vector<vector<int>>& mat) {
    if (mat.empty()) return;
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// --- Example Usage ---
int main() {
    // A = [[1, 2],
    //      [3, 4]]
    vector<vector<int>> A = { {1, 2}, 
                              {3, 4} };

    // B = [[5, 6],
    //      [7, 8]]
    vector<vector<int>> B = { {5, 6}, 
                              {7, 8} };

    // C = A * B
    // C = [[1*5 + 2*7, 1*6 + 2*8],
    //      [3*5 + 4*7, 3*6 + 4*8]]
    // C = [[19, 22],
    //      [43, 50]]
    
    vector<vector<int>> C = matrixMultiply(A, B);

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "\nMatrix B:" << endl;
    printMatrix(B);
    cout << "\nResult C = A * B:" << endl;
    printMatrix(C);

    return 0;
}