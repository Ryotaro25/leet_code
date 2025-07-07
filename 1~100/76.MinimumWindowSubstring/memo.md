## Explaining the Minimum Window Substring Solution
When I first tackled this problem, my initial thought was to use a **brute-force approach**. 
This would involve two nested loops: the **outer loop** to mark the starting point of a substring in `s`,
and the **inner loop** to mark its end.
Inside the inner loop, I would check if the current substring contained all characters from `t`.

To perform this check efficiently, I'd use a **hash map** (or `map` in C++) to store the frequencies of each character in `t`. 
Then, for each potential substring, I'd compare its character counts against those in `t`. 
This method is quite slow, with a time complexity of roughly **$O(n^2 * m)$**, where n is the length of `s` and m is the length of `t`.

### Optimizing with the Sliding Window
To significantly improve the performance, I decided to use the **sliding window technique**.
This approach helps us avoid redundant calculations by maintaining a "window" over the string `s` and adjusting its size.

Here's how it works:

1.  **Expand the window (right pointer):**
I start by expanding the window to the right, adding characters from `s` one by one.
I keep track of the character counts within my current window using another hash map.

2.  **Shrink the window (left pointer):**
Once the current window contains all the characters from `t` (meaning it "satisfies the condition"), I try to shrink the window from the left.
I do this by moving the left pointer inward.
As I shrink the window, I update the character counts. 
If shrinking the window means I no longer have all the required characters from `t`, I stop shrinking and go back to expanding the window from the right.

3.  **Update the minimum:** 
Every time I have a valid window (one that satisfies the condition),
I compare its size with the smallest valid window I've found so far and update if the current one is smaller.

This sliding window approach brings the time complexity down to about **$O(n)$**.
It's much more efficient because each character in `s` is visited by the left and right pointers at most a constant number of times.

---

### Further Refinements and Data Structures
To optimize space and keep track of the window efficiently,
I used a `struct` called `WindowBounds` in C++.
This `struct` stores three important pieces of information: the `window_size`,
and the `left` and `right` pointers that define the boundaries of the smallest valid window found so far.

I also used a few additional variables and a hash map for tracking:

* **`letter_to_cnt_for_t` (map):**
This stores the required frequency of each character from string `t`.

* **`letter_to_cnt_for_s` (map):**
This dynamically stores the frequency of characters within my current sliding window in `s`.

* **`num_unique_letter`:**
This counts how many *distinct* characters are in `t`.

* **`num_satisfied_letter`:**
This is a crucial variable. It tells me how many distinct characters from `t` currently have their frequency requirements met within my sliding window. For example, if `t = "AABC"` and my window has two 'A's and one 'B', then 'A' and 'B' are satisfied, so `num_satisfied_letter` would be 2.

The logic for updating `num_satisfied_letter` is key:

* When I **expand the window** (move `right`):
If the character `s[right]` is one of the characters required by `t`, and its count in my current window (`letter_to_cnt_for_s[s[right]]`) becomes equal to its required count in `t` (`letter_to_cnt_for_t[s[right]]`), then I increment `num_satisfied_letter`.

* When I **shrink the window** (move `left`):
If the character `s[left]` is required by `t`, and its count in my current window drops *below* its required count in `t`, then I decrement `num_satisfied_letter`.

This efficient tracking allows me to know instantly when my window has all the characters from `t` and when it no longer does.

Finally, after iterating through all possible windows,
if `candidate_result.window_size` is still in its initial state (e.g., -1),
it means no valid window was found, so I return an empty string.
Otherwise, I use the stored `left` and `right` pointers to extract and return the minimum window substring.