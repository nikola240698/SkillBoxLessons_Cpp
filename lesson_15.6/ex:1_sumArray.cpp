#include <iostream>
#include <vector>

int main() {

    std::vector vec = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};

    int maxSum = 0;
    int minInd, maxInd;

    std::cout << "Program to determine the range of an array with the maximum sum" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        
        for (int j = vec.size() - 1; j > i; j--) {
            
            int sum = 0;
            
            for (int k = i; k <= j; k++) {
                sum += vec[k];
            }
            
            if (sum > maxSum) {
                maxSum = sum;
                minInd = i;
                maxInd = j;
            }
        }
    }   

    std::cout << "The maximum amount is equal to " << maxSum << std::endl;
    std::cout << "Beginning of array at index " << minInd << std::endl;
    std::cout << "Ending of array at index " << maxInd << std::endl;

    return 0;
}
