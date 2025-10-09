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

    // --- 2. Convolution Operation with Border Handling ---

    // Iterate over every single pixel in the image, including the borders.
    for (int y = 0; y < IMAGE_HEIGHT; ++y) {
        for (int x = 0; x < IMAGE_WIDTH; ++x) {
            
            int sum = 0; // This will store the result of the convolution for the current pixel.

            // Apply the 3x3 filter to the 3x3 neighborhood around the current pixel (x, y).
            for (int ky = 0; ky < 3; ++ky) {
                for (int kx = 0; kx < 3; ++kx) {
                    // Calculate the coordinates of the image pixel to sample.
                    // The filter's center is at (1,1), so we subtract 1 from ky and kx to get the offset.
                    int sourceY = y + ky - 1;
                    int sourceX = x + kx - 1;
                    
                    int pixelValue = 0; // Default to 0 for pixels outside the image (this is "zero-padding").

                    // Check if the calculated coordinates are within the image bounds.
                    if (sourceY >= 0 && sourceY < IMAGE_HEIGHT && sourceX >= 0 && sourceX < IMAGE_WIDTH) {
                        // If it's a valid pixel, get its value from the input image.
                        pixelValue = image[sourceY][sourceX];
                    }
                    
                    // Multiply the pixel value (either from the image or 0 for padding)
                    // by the corresponding filter value and add to the sum.
                    sum += pixelValue * filter[ky][kx];
                }
            }

            // Assign the final calculated sum to the corresponding pixel in the output image.
            // In a real scenario, you might need to clamp the value (e.g., to 0-255 for grayscale).
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
    
    // Also, let's display the top-left corner to see how the border was handled.
    cout << "\nDisplaying the top-left 5x5 corner of the output image:" << endl;
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            cout << outputImage[y][x] << "\t";
        }
        cout << endl;
    }

    return 0;
}

