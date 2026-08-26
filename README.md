*This project has been created as part of the 42 curriculum by mwisniew, nfil.*

# Push_Swap

## Description
The `push_swap` project is a core algorithmic challenge in the 42 curriculum. The primary goal is to sort a given sequence of random integers on a stack, using a secondary auxiliary stack and a limited, specific set of instructions, while aiming for the lowest possible number of actions. The program processes a random list of integers as an argument and outputs the sequence of stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) required to arrange the array in ascending order on Stack A.

## Instructions

**Compilation:**
To compile the project, navigate to the root directory of the repository and run:
```bash
make
```
This will compile the source files and generate the `push_swap` executable.

**Execution:**
Run the program by providing a list of integers as arguments.
```bash
./push_swap 4 67 3 87 23
```
You can also provide the integers enclosed in quotes as a single string:
```bash
./push_swap "4 67 3 87 23"
```

**Custom Flags & Modes:**
This implementation supports specialized flags to dictate the sorting strategy or to enable benchmarking. These must be provided before the list of integers:
- `--adaptive`: Automatically chooses the best algorithm based on stack size and the initial disorder of the array (default behavior).
- `--simple`: Forces the $O(n^2)$ simple sort algorithm.
- `--medium`: Forces the $O(n \sqrt{n})$ bucket/chunk sort algorithm.
- `--complex`: Forces the $O(n \log n)$ Longest Increasing Subsequence (LIS) and cost-analysis algorithm.
- `--bench`: Enables benchmark mode, outputting the array's disorder score, the strategy chosen, and the final count of each operation.

Example usage with flags:
```bash
./push_swap --bench --complex 4 67 3 87 23
```

## Threshold Rationale and Complexity Bounds

The system dynamically routes the input array into specific sorting regimes based on predefined thresholds to optimize performance. 

**Threshold Rationale:**
If the stack size is strictly less than 6, the program defaults to the small input logic to bypass the overhead of heavy initializations. For larger inputs, a disorder metric determines the path: a disorder score strictly below $0.2$ triggers the simple sort, a score below $0.5$ triggers the medium sort, and any higher disorder routes to the complex sort. These thresholds ensure that algorithms with heavier time complexity are only invoked when the initial input disorder justifies the computational cost.

**Complexity Argument (Upper Bounds):**
*   **Time:** The upper bounds on execution time depend on the active regime. The simple sort regime runs in $O(n^2)$ time. The medium bucket sort regime caps at $O(n \sqrt{n})$ time. The complex sort calculates exact insertion costs for every element in Stack B by traversing both stacks, bounding its computational time at $O(n^2)$, but yielding a highly optimized operation count strictly bounded by $O(n \log n)$.
*   **Space:** The space complexity is firmly bounded at $O(n)$ across all regimes. This encompasses the memory allocation for the linked lists representing the primary stacks, the coordinate compression arrays, the Longest Increasing Subsequence (LIS) tracking arrays, and the operational cost arrays generated during the complex sort.

## Algorithms Explanation and Justification

To achieve optimal operation counts across various input sizes (especially the standard benchmarks of 100 and 500 numbers), this project dynamically selects from multiple algorithms based on input size and a pre-calculated "disorder" metric.

### 1. Data Preprocessing (Coordinate Compression)
Before sorting begins, the input array is parsed and compressed. Coordinate compression normalizes the raw array values to their relative ranks (from 1 to N). This essentially replaces arbitrary integers with their target indices, greatly simplifying target-finding logic and cost calculations during the sorting phase.

### 2. Small Sort (<= 5 elements)
**Justification:** For extremely small stacks, complex algorithms introduce unnecessary overhead. Hardcoded conditional logic is computationally cheaper and yields a small number of operations.

**Methodology:**
- **3 elements:** A dedicated micro-algorithm (`sort_three`) evaluates the top, middle, and bottom elements, applying rotations and swaps to sort the stack in a maximum of 2 operations.
- **4-5 elements:** The algorithm identifies the absolute minimum values and pushes them to Stack B. The remaining 3 elements are sorted using `sort_three`, and finally, the elements from Stack B are pushed back to the top of Stack A.

### 3. Simple Sort
**Justification:** This is a brute-force approach that serves primarily as a baseline for performance comparison, or when explicitly requested via the `--simple` flag. Due to its $O(n^2)$ complexity, it is inefficient for larger datasets but guarantees a valid sort.

**Methodology:**
Because the initial array undergoes coordinate compression, replacing raw values with ranks from 1 to N, the target sequence is always known. The algorithm iterates through these target values sequentially starting from 1. For each target, it continuously rotates Stack A (`ra`) until the exact target element reaches the top of the stack, and then pushes it to Stack B (`pb`). Once all N elements have been pushed sequentially to Stack B, it pushes everything back to Stack A (`pa`), completing the sort.

### 4. Medium Sort (Bucket sorting)
**Justification:** Since calculating exact insertion costs for every element is inefficient, and simple insertion sort yields too many operations, bucket sorting ensures an operation count that comfortably passes the constraints.

**Methodology:** 
Elements are conceptually grouped into buckets (with the size calculated proportionally as $2\sqrt{n}$), ensuring a required complexity of $O(n \sqrt{n})$. The algorithm scans Stack A from both the top and bottom to efficiently locate elements belonging to the current target buckets, pushing them to Stack B. This serves as a rough preliminary sort. Once Stack A is empty, the algorithm sweeps Stack B to find the highest elements and pushes them back to Stack A in descending order.

### 5. Complex Sort (LIS + Cost Analysis)
**Justification:** To minimize the total number of operations this approach calculates the exact cheapest move at every step, yielding a highly optimized operation count.

**Methodology:**
- **Longest Increasing Subsequence (LIS):** The algorithm scans Stack A to find the LIS. It keeps these elements in Stack A since they are already in relatively sorted order, pushing all other elements to Stack B.
- **Cost Calculation:** For every individual element residing in Stack B, the algorithm calculates the exact number of operations (cost) required to place it into its correct sequential position in Stack A. This heavily utilizes `rr` and `rrr` optimizations to rotate both stacks simultaneously.
- **Execution:** The element with the lowest total operation cost is selected and pushed to Stack A. This process repeats until Stack B is entirely empty. Finally, Stack A is rotated to bring the `1` (minimum value) back to the top.

## Contributions

**mwisniew:**
*   **Algorithm Design & Implementation:** Design, implementation, and optimization of the core sorting strategies (Small, Medium, and Complex sorts).
*   **Optimization:** Cost calculations minimizing the final operation counts for different dataset sizes.
*   **Norm Compliance:** Codebase formatting and structural alignment with Norminette standards.

**nfil:**
*   **Input Handling:** Parsing of raw integer inputs, validation, and configuration of command-line flags and benchmark features.
*   **Project Integration:** Assembly of core logic modules and setup of custom `printf` output options.
*   **Compilation:** `Makefile` management.

## Resources

Albert, M. H., Atkinson, M. D., Nussbaum, D., Sack, J. R., & Santoro, N. (2007). [On the longest increasing subsequence of a circular list](https://api.semanticscholar.org/CorpusID:7047139). *Inf. Process. Lett.*, 101, 55-59.

*Longest increasing subsequence* (2025). cp-algorithms.com. Retrieved August 14, 2026, from https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html

man 3 write

# AI Usage
AI was used in writing this readme.
