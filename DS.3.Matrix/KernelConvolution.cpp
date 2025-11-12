#include <iostream>
#include <vector>

// Use the standard namespace
using namespace std;

// Function to perform 2D convolution (kernel multiplication)
vector<vector<int>> convolve(const vector<vector<int>>& image,
                               const vector<vector<int>>& kernel) {
    int imageHeight = image.size();
    int imageWidth = image[0].size();
    int kernelHeight = kernel.size();
    int kernelWidth = kernel[0].size();

    // Calculate padding needed for the output image to have the same dimensions as the input
    // This assumes an odd-sized kernel
    int padHeight = kernelHeight / 2; 
    int padWidth = kernelWidth / 2;

    // Initialize output image with zeros
    vector<vector<int>> outputImage(imageHeight, vector<int>(imageWidth, 0));

    // Iterate over each pixel in the output image
    for (int i = 0; i < imageHeight; ++i) {
        for (int j = 0; j < imageWidth; ++j) {
            int sum = 0;
            // Iterate over each element in the kernel
            for (int k = 0; k < kernelHeight; ++k) {
                for (int l = 0; l < kernelWidth; ++l) {
                    // Calculate the corresponding image pixel coordinates
                    int imageRow = i - padHeight + k;
                    int imageCol = j - padWidth + l;

                    // Check for boundary conditions (simple zero-padding)
                    if (imageRow >= 0 && imageRow < imageHeight &&
                        imageCol >= 0 && imageCol < imageWidth) {
                        // Apply kernel element
                        sum += image[imageRow][imageCol] * kernel[k][l];
                    }
                    // Pixels outside the boundary are treated as 0 (implicitly, since we only add if inside)
                }
            }
            outputImage[i][j] = sum;
        }
    }
    return outputImage;
}

// Function to print an image (2D vector)
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            // Print each pixel followed by a tab
            cout << pixel << "\t";
        }
        // Move to the next line after each row
        cout << endl;
    }
}

int main() {
    // Example grayscale image (represented as a 2D vector)
    vector<vector<int>> image = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };

    // Example 3x3 kernel (e.g., a simple blur kernel)
    // Using 1/9 would normalize it, but for integer math, we'll just use 1s
    vector<vector<int>> kernel = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    cout << "Original Image:" << endl;
    printImage(image);

    cout << "\nKernel:" << endl;
    printImage(kernel);

    // Perform convolution
    vector<vector<int>> resultImage = convolve(image, kernel);

    cout << "\nResulting Image after Convolution:" << endl;
    printImage(resultImage);

    return 0;
}