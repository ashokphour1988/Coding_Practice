public int numIdenticalPairs(int[] nums) {

    // Calculate the frequency of each number
    int[] count = new int[102];

    for (int num : nums) {
      count[num]++;
    }

    int totalCount = 0;

    // Caclulate total number of pairs possible
    for (int i : count) {
      totalCount += ((i) * (i-1))/2;
    }

    return totalCount;
  }


/*

Always make sure that we understand the problem statement first. There is an array of integers nums and we need to determine the number of good pairs. A pair (i , j ) is said to be good, if nums[i] == nums[j] and i < j. We need to determine how many pairs can we form that hold this condition.

Let us look at some sample test cases:

Input: nums = [ 1 , 2 , 3 , 1 , 1 , 3 ]
Output: 4
Explanation:
There are 4 good pairs. (0 , 3) , (0 , 4) , (3 , 4) , (2 , 5)
nums[0] = 1, which is equal to nums[3] = 1 && 0 < 3
nums[2] = 3, which is equal to nums[5] = 3 && 2 < 5

Input: nums = [ 1 , 2 , 3 ]
Output: 0
Explanation:
The array does not have any element that are equal to each other.

*/


