My first idea was quite simple, a brute-force approach.
I would use two loops:
an outer loop to pick the starting position of a subarray, and an inner loop to pick the ending position.
Inside the inner loop, I'd calculate the product of that subarray and keep track of the overall maximum product found so far.

This approach has a time complexity of O(N-squared).
Given that the maximum number of elements (N) is around 2×10^4
this means roughly (2×10^4)^2 = 4×10^8 steps.

While C++ can do about 10^8 to 10^9 operations per second,
4×10^8 steps is usually too much for a 1-second time limit,
so this would likely result in a Time Limit Exceeded (TLE) error.

There are some tricky edge cases to consider:
A zero in the array will reset any accumulated product,
effectively making the product from before the zero independent of what comes after it.

Negative numbers are especially tricky.
An even number of negative numbers multiplied together will result in a positive number,
which could become the maximum product.
For example, [-2, -3] has a product of 6.

To handle this, I decided to use a single loop instead of two.
I will keep track of two values as I go through the array:

max_so_far: This is the maximum product ending at the current position.

min_so_far: This is the minimum product ending at the current position.
I need to track the minimum because a very small negative number,
when multiplied by another negative number, can become a large positive number.

In each step of the loop, when I look at the current number (nums[i]):

The new max_so_far can be the current number itself, or the previous max_so_far multiplied by the current number, or the previous min_so_far multiplied by the current number.
I take the maximum of these three options."

Similarly, the new min_so_far can be the current number itself, or the previous max_so_far multiplied by the current number, or the previous min_so_far multiplied by the current number.
I take the minimum of these three options.

By updating these max_so_far and min_so_far values in each iteration,
and keeping track of the overall max_product found, we can solve this problem in O(N) time.