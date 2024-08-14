#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSearch(const vector<int> &arr, int i, int target) {
    vector<int> result;  // This will store the indices where the target is found.

    if (i >= arr.size()) {
        return result;  // Base case: Return an empty vector if index i is out of bounds.
    }

    if (arr[i] == target) {
        result.push_back(i);  // Add the current index to the result if the target is found.
    }

    vector<int> nextResult = linearSearch(arr, i + 1, target);  // Recursive call for the next index.
    result.insert(result.end(), nextResult.begin(), nextResult.end());  // Merge the result of the recursive call.

    return result;  // Return the accumulated result.
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 6, 4};
    vector<int> res = linearSearch(arr, 0, 4);
    
    cout << "Indices where 4 is found: ";
    for (int index : res) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
