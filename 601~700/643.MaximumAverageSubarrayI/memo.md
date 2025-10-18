Input: nums = [1,12,-5,6-,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

12   3
5    -1.25
-6   -1,5
50   12.5

right - left + 1 < k
right++

right - left + 1 = k
max(max_average, average)

right - left + 1 >= k
left++

doubleには正規化数という概念がある
https://ja.wikipedia.org/wiki/IEEE_754

https://en.cppreference.com/w/cpp/types/numeric_limits.html
https://en.cppreference.com/w/cpp/types/climits.html