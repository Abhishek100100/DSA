#include <iostream>
#include <vector>
using namespace std;

// Define image dimensions for 1080p
const int IMAGE_HEIGHT = 1080;
const int IMAGE_WIDTH = 1920;

int main() {
    // --- 1. Image and Filter Initialization ---

    // Create a 2D vector to represent the 1080p image.
    // We'll use `vector<vector<int>>` which is a flexible way to create a 2D array.
    // We initialize all pixel values to a sample value (e.g., 10) for this example.
    // In a real application, you would load this from an image file.
    vector<vector<int>> image(IMAGE_HEIGHT, vector<int>(IMAGE_WIDTH, 10));

    // Create another 2D vector for the output image after applying the filter.
    // Initialize all its pixels to 0.
    vector<vector<int>> outputImage(IMAGE_HEIGHT, vector<int>(IMAGE_WIDTH, 0));

    // Define a simple 3x3 "sharpen" filter (kernel).
    // You can change these values to achieve different effects like blurring or edge detection.
    int filter[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };

    cout << "Applying a 3x3 filter to a " << IMAGE_WIDTH << "x" << IMAGE_HEIGHT << " image..." << endl;

    // --- 2. Convolution Operation ---

    // Iterate over each pixel in the image. We start from 1 and end one pixel
    // early (height-1, width-1) to avoid going out of bounds when the 3x3 filter
    // is centered on the current pixel. The border pixels are typically ignored
    // or handled with special padding, but for simplicity, we'll just ignore them here.
    for (int y = 1; y < IMAGE_HEIGHT - 1; ++y) {
        for (int x = 1; x < IMAGE_WIDTH - 1; ++x) {
            
            int sum = 0; // This will store the result of the convolution for the current pixel.

            // Apply the 3x3 filter to the 3x3 neighborhood around the current pixel (x, y).
            for (int ky = 0; ky < 3; ++ky) {
                for (int kx = 0; kx < 3; ++kx) {
                    // Get the pixel value from the image that corresponds to the filter's position.
                    // y + ky - 1 and x + kx - 1 maps the filter's coordinates (0,0 to 2,2)
                    // to the image's neighborhood around (x,y).
                    int pixelValue = image[y + ky - 1][x + kx - 1];
                    
                    // Multiply the pixel value by the corresponding filter value and add to the sum.
                    sum += pixelValue * filter[ky][kx];
                }
            }

            // Assign the final calculated sum to the corresponding pixel in the output image.
            // In a real scenario, you might need to clamp the value (e.g., 0-255 for grayscale).
            outputImage[y][x] = sum;
        }
    }

    cout << "Filtering complete." << endl;

    // --- 3. Display a small sample of the output ---

    // Printing the entire 1920x1080 image would be too much for the console.
    // Let's just print a small 5x5 section from the center of the output image
    // to verify that the calculation worked.
    cout << "\nDisplaying a 5x5 sample from the center of the output image:" << endl;
    for (int y = IMAGE_HEIGHT / 2; y < IMAGE_HEIGHT / 2 + 5; ++y) {
        for (int x = IMAGE_WIDTH / 2; x < IMAGE_WIDTH / 2 + 5; ++x) {
            cout << outputImage[y][x] << "\t";
        }
        cout << endl;
    }

    return 0;
}
