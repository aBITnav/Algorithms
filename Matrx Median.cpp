int Solution::findMedian(vector<vector<int> > &A) {
int m = A.size();
int n = A[0].size();

// median is the middle of a sorted list of numbers. So, median
// is greater than or equal to half of N + 1 numbers or more 
// eg. 123 4 567, N = 7, median is greater than or equal 4 numbers
//eg. 123 4 444, N = 7, median is greater than or equal to 7 numbers
// So to find the median, we need to find a number that is 
// greater than or equal to at least half of N + 1 numbers
int max = A[0][0], min = A[0][0];

// Let's try to apply binary search to find that mid element
// Let's find the min and max of the array. Since each row is
// already sorted, the first element is the smallest and the last
// element is the biggest in the row. So, we only need to compare
// the first element of every row to find the smallest element and
// compare the last element of every row to find the largest
for(int i = 0; i < m; i ++) {
    if(A[i][0] < min) min = A[i][0];
    if(A[i][n-1] > max) max = A[i][n-1];
}

// mid has to be greater than or equal half the elements
int required = (m * n + 1) / 2;
// min <= max will fail when we have the median no. before the mid
// position to after the mid position
// eg. 113 3 333, here, initially mid is 2, since its sum < required
// min becomes 3. max is 3. mid is 3. Since sum > required for 3
// max is 3. Again mid is 3, again max is 3.. this goes into an 
// infinite loop. And anyway if the median exists between 3 and 3
// it means the median is 3!, we can exit the loop and print it
while(min < max) {
    int sum = 0;
    int mid = (min + max) / 2;
    for(int i = 0; i < m; i ++) {
        // Count the number of elements lower than or equal to mid
        // i.e How many numbers is mid greater than or equal to
        // in each row using upper_bound function in STL
        sum += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
    }
    // If the element is more than or equal the required no. of elements
    // or more, then it is the median
    // eg. 123 4 567, here, required = 4, mid = 4, 4 has 4 nos. less 
    // than or equal to it, sum == required, therefore 4 is the median
    // eg. 123 4 444, here, required = 4, mid = 4, 4 has 7 nos. less
    // than or equal to it,  sum > required, therefore 4 is the median
    // But, consider these counter examples
    // eg. 11 1 33, here, required = 3, mid = 2, 2 has 3 nos. less than
    // or equal to it, sum == required, but 2 is not the median, because 
    // it does not exist in the matrix
    // eg. 11 1 13, here, required = 3, mid = 2, 2 has 4 nos. less than or
    // equal to it, sum > required, but 2 is not the median, since it does
    // not exist in the array.
    // So, in both the cases sum > required and sum == required, there is 
    // no guarantee that the element is the median, since it may not exist
    // in the matrix. We can only say that the median may be equal to this
    // element (in case it is present in the matrix) or lesser than this 
    // element (in case it is not present in the matrix) i.e it is the max
    // value the median can be
    // if(sum >= required) return mid;
    if(sum >= required) {
        max = mid;
    }
    // If fewer number of elements are lesser than 
    // or equal to the element, try the next higher one
    //if(sum < required) min = mid + 1;
    else min = mid + 1;    
    //else max = mid;
}
// return max or min, they are the same since we exited the loop on that condition
return max;
}
