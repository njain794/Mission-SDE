// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the
// largest size subarray
void func(vector<int> arr,
		int k, int n)
{
	// Variable declaration
	int ans = n;
	int sum = 0;
	int start = 0;

	// Loop till N
	for (int end = 0; end < n; end++)
	{
		// Sliding window from left
		sum += arr[end];

		while (sum > k) {
			// Sliding window from right
			sum -= arr[start];
			start++;

			// Storing sub-array size - 1
			// for which sum was greater than k
			ans = min(ans, end - start + 1);

			// Sum will be 0 if start>end
			// because all elements are positive
			// start>end only when arr[end]>k i.e,
			// there is an array element with
			// value greater than k, so sub-array
			// sum cannot be less than k.
			if (sum == 0)
				break;
		}
		if (sum == 0) {
			ans = -1;
			break;
		}
	}

	// Print the answer
	cout << ans;
}

// Driver code
int main()
{
	vector<int> arr{ 1, 2, 3, 4 };
	int k = 8;
	int n = arr.size();

	// Function call
	func(arr, k, n);

	return 0;
}

