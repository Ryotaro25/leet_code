### My Approach to the Three Sum Problem

My goal is to find all groups of three unique numbers in an array `nums` that add up to zero.

---

### Initial Idea and Its Problem

First, I thought about using **three loops**: one for `nums[i]`, one for `nums[j]`, and one for `nums[k]`.
This way, I could check every possible combination of three numbers.
After making sure their positions (`i`, `j`, `k`) were all different, I would sort the three numbers `(nums[i], nums[j], nums[k])`.
Then, I'd put this sorted group into a `std::set` to remove any duplicate groups.

This method would take about **O(N^3 * log N)** time.
The `N^3` comes from the three loops going through the `nums` array. The `log N` part comes from inserting into the `std::set`, as `set` operations usually take logarithmic time.
This approach is generally too slow for this kind of problem.

### My Optimized Solution Using Hash Sets
To make it faster, I decided to use **two loops and two hash sets**.
This helps to improve the time complexity.

Here's how my current solution works:

1.  **`visited` Set (for `nums[i]` Duplicates):**
    * I use a `std::set<int>` called `visited`.
    This set helps me keep track of the `nums[i]` values that I have already used as the **first number** in a triplet.
    * Before checking `nums[i]`, I see if it's already in `visited`.
    If it is, it means I've already found all possible triplets starting with this number, so I just **skip it** and move to the next `i`.
    This stops me from doing the same work again and avoids getting duplicate triplets.
    * If `nums[i]` is a new value for the first number, I add it to the `visited` set.

2.  **`seen` Set (for Finding the Third Number):**
    * Inside the first loop (for each `nums[i]`), I create another `std::set<int>` called `seen`.
    This `seen` set is very important.
    It stores all the numbers (`nums[j]` values) that I have **seen so far in the inner loop** for the current `nums[i]`.
    * For each `nums[j]` (which starts from the position `i + 1`), I calculate the `compliment`.
    This is the third number needed so that `nums[i] + nums[j] + compliment` equals zero.
    So, `compliment = -nums[i] - nums[j]`.

    * Then, I check if this `compliment` already **exists in the `seen` set**.
        * If the `compliment` is found in `seen`, it means I have found three different numbers (`nums[i]`, `nums[j]`, and `compliment`) that sum to zero.
        * I put these three numbers into a `std::vector` called `triplet`.
        * To make sure I only get unique groups in the end (for example, `[-1, 0, 1]` is the same as `[0, -1, 1]`), I **sort** the `triplet` and then add it to my `unique_triplets` set.

    * After checking for the `compliment`, I **add the current `nums[j]` to the `seen` set**.
    This makes `nums[j]` available to be used as a `compliment` for later calculations within this `i` loop.

3.  **`unique_triplets` (Storing Final Results):**
    * I use a `std::set<std::vector<int>>` named `unique_triplets` to store all the valid groups of three numbers. Since `std::set` only stores unique items, it automatically handles any remaining duplicate triplets.
    * Finally, I convert this `set` into a `std::vector<std::vector<int>>` to give back the result.

It needs O(n^2 * log n)
