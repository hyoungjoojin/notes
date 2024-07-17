# Arrays

## Majority Element Algorithm
- Given an array, find the majority element (the element present in more than half of the array).

### Moore's Voting Algorithm
- Steps
    1. Set two variables, the majority element candidate and the count of this variable.
    2. Traverse through the array.
        1. If the count is 0, change the majority element to be the current element.
        2. Update the count
            - Increment it by 1 if the current element is the majority element.
            - Decrement it by 1 if it isn't.
    3. Verify that the chosen candidate is actually the majority element.
- Code
    ```c++
    template <typename T> T get_majority_element(const std::vector<T> &list) {
      T majority_candidate;
      int count = 0;

      for (const T &element : list) {
        if (count == 0)
          majority_candidate = element;

        count += (element == majority_candidate ? 1 : -1);
      }

      count = 0;
      for (const T &element : list)
        if (element == majority_candidate)
          count++;

      return (count * 2) >= list.size() ? majority_candidate : -1;
    }
    ```
- How does it work?
    - The main idea is to separate all elements into two sets. One set only contains the target number and the other set contains all other elements.
    - In this case, if the majority element does exist, regardless of the order, the remainder set can never out-number the majority element.
- Complexity: O(N) time, O(1) space.

