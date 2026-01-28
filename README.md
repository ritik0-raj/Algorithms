# Algorithms
1.Bubble Sort Report
Aim
To study and analyze the Bubble Sort algorithm, understand its working method, write its pseudocode, and evaluate its time and space complexities in best, average, and worst cases.

Short Description
Bubble Sort is a simple comparison-based sorting algorithm. It works by repeatedly traversing the list, comparing each pair of adjacent elements, and swapping them if they are not in the correct order. This process continues until the array becomes fully sorted.

Pseudocode
BubbleSort(arr, n):
    repeat for i = 0 to n-1:
        repeat for j = 0 to n-i-2:
            if arr[j] > arr[j+1]:
                swap arr[j] and arr[j+1]

Time Complexity
Best Case: O(n)
Occurs when the array is already sorted. Only one pass is required to check that no swaps are needed.
Average Case: O(n²)
Occurs for random order of elements. Every element must be compared multiple times.
Worst Case: O(n²)
Occurs when the array is in reverse order. Maximum number of comparisons and swaps.

Space Complexity
O(1)
Bubble Sort is an in-place sorting algorithm, meaning it does not require extra memory. Only a small temporary variable is used for swapping.

2.Horner’s Rule Report
Aim
To understand and analyze Horner’s Rule for polynomial evaluation, write its pseudocode, and determine its time and space complexities.

Short Description
Horner’s Rule is an efficient algorithm for evaluating a polynomial of degree n with minimal arithmetic operations.
A polynomial:
P(x) = a_n x^n + a_{n-1} x^{n-1} + \cdots + a_1 x + a_0
P(x)=an xn+an−1 xn−1+⋯+a1 x+a0
can be rewritten using Horner’s Rule as:
P(x) = (...((a_n x + a_{n-1})x + a_{n-2})x + \cdots + a_1)x + a_0
P(x)=(...((an x+an−1 )x+an−2 )x+⋯+a1 )x+a0
This reduces the total number of multiplications from n(n–1)/2 (naive method) to just n multiplications, making it highly efficient.
Horner’s Rule is widely used in compilers, calculators, and numerical computing.

Pseudocode

HornerRule(coeff, n, x):
    result = coeff[0]
    for i = 1 to n:
        result = result * x + coeff[i]
    return result

Time Complexity
Best Case: O(n)
A single loop runs for n iterations regardless of input.
Average Case: O(n)
Polynomial evaluation always requires n multiplications and n additions.
Worst Case: O(n)
No variation — Horner’s Rule always performs exactly the same number of operations.

Space Complexity
O(1)
The algorithm uses only a few variables (result, loop index). No extra memory grows with input size. Thus, it is an in-place constant-space algorithm.

3.Linear Search Report
Aim
To study and analyze the Linear Search algorithm, understand its working procedure, write its pseudocode, and evaluate its time and space complexities in best, average, and worst cases.

Short Description
Linear Search is the simplest searching algorithm. It works by sequentially checking every element in the list until the desired element is found or the entire list has been scanned.
Pseudocode

LinearSearch(arr, n, key):
    for i = 0 to n-1:
        if arr[i] == key:
            return i
    return -1

Time Complexity
Best Case: O(1)
Occurs when the key is found at the first position.
Average Case: O(n)
On average, the key is found halfway through the list.
Worst Case: O(n)
Occurs when:
the key is at the last position, or
the key is not present in the array.

Space Complexity
O(1)
Linear Search uses only:
a loop index variable
constant extra memory
Thus, it is an in-place algorithm with constant memory usage.

4.Permutation Generation (Backtracking) Report
Aim
To understand and analyze the permutation-generation algorithm using recursion and backtracking, write its pseudocode, and study its time and space complexities.

Short Description
This algorithm generates all possible permutations of a set of elements using recursion and backtracking.
The idea is:
Fix one element at the current index.
Recursively generate permutations for the remaining indices.
Swap back (backtrack) to restore the original order.
This ensures that every possible arrangement of the given elements is generated.

Pseudocode

Permute(arr, l, r):
    if l == r:
        print arr
        return
    
    for i = l to r-1:
        swap arr[l] and arr[i]
        Permute(arr, l+1, r)
        swap arr[l] and arr[i]   // backtrack

Time Complexity
Let n be the number of characters.
Total Permutations = n!
Time Complexity: O(n × n!)

Space Complexity
O(n)
Due to:
Recursive call stack of depth n
Array of size n
Backtracking ensures no extra memory beyond recursion depth.


5.Tower of Hanoi Report
Aim
To study and analyze the Tower of Hanoi recursive algorithm, understand its working mechanism, write its pseudocode, and determine its time and space complexities.

Short Description
The Tower of Hanoi is a classic recursive problem. The goal is to move n disks from a source rod to a destination rod using an auxiliary rod, following these rules:
Only one disk can be moved at a time.
A larger disk cannot be placed on top of a smaller disk.
All disks start on the source rod and must end on the destination rod.
The recursive strategy works by:
Moving n−1 disks from the source rod to the auxiliary rod
Moving the largest disk from the source rod to the destination rod
Moving n−1 disks from the auxiliary rod to the destination rod

Pseudocode

ToH(n, src, aux, dest):
    if n == 1:
        print "Move disk 1 from src to dest"
        return
    
    ToH(n-1, src, dest, aux)
    print "Move disk n from src to dest"
    ToH(n-1, aux, src, dest)

Time Complexity
Total number of moves = 2ⁿ − 1
Time Complexity: O(2ⁿ)
The algorithm makes:
One move for the biggest disk
Two recursive calls for n−1 disks Thus, the recurrence is:
T(n)=2T(n−1)+1
T(n) = 2^n - 1
T(n)=2n−1
This is exponential time complexity.

Space Complexity
O(n)
Because:
Recursive function calls go as deep as n levels
No extra arrays or storage are used
Thus, space complexity is determined by recursion depth.


6.Selection Sort Report
Aim
To study and analyze the Selection Sort algorithm, understand its working procedure using recursion, write its pseudocode, and determine the time and space complexities for best, average, and worst cases.

Short Description
Selection Sort is a simple comparison-based sorting algorithm. The algorithm repeatedly selects the smallest element from the unsorted part of the array and swaps it with the element at the current index. This process continues until the entire array is sorted.
In your code, Selection Sort is implemented recursively, where each recursive call fixes the minimum element for one position and sorts the rest of the array.
Selection Sort is easy to understand but inefficient for large datasets due to its quadratic time complexity.

Pseudocode

SelectionSort(arr, n, index):
    if index == n-1:
        return
    
    minIndex = index
    for i = index+1 to n-1:
        if arr[i] < arr[minIndex]:
            minIndex = i

    swap arr[index] and arr[minIndex]
    SelectionSort(arr, n, index+1)

Time Complexity
Let n be the number of elements.
Best Case: O(n²)
Selection Sort performs comparisons even if the array is already sorted.
Average Case: O(n²)
Every element is compared with all remaining elements.
Worst Case: O(n²)
Same number of comparisons regardless of data order.
Breakdown:
Comparisons = n \frac{n(n-1)}{2}  2n(n−1) 
Swaps = n (only one swap per outer loop)
Thus, total complexity = O(n²) for all cases.

Space Complexity
O(1)
Selection Sort is an in-place sorting algorithm.
Recursive version uses:
Constant additional memory for swapping
Call stack of size O(n) (because recursion depth = n)
Thus:
Iterative Selection Sort: O(1)
Recursive Selection Sort: O(n)
Your code uses the recursive version → O(n) space.

7.Boolean Logic (Truth Table Generation) Report
Aim
To generate and analyze the truth table for basic Boolean operations (AND, OR, NOT) using a simple C++ program.

Short Description
This program prints the truth table for two Boolean variables A and B. For every possible combination of A and B (0 or 1), the program computes:
A AND B
A OR B
NOT A
NOT B
This helps understand the behavior of fundamental logic gates used in digital electronics and Boolean algebra.
The code uses nested loops to generate all 4 combinations of A and B.

Pseudocode

print "A  B  AND OR NOTA NOTB"
for A = 0 to 1:
    for B = 0 to 1:
        print A, B, (A AND B), (A OR B), (NOT A), (NOT B)

Truth Table Logic


Time Complexity
O(1)
The program always runs exactly 4 iterations (2×2). Time does NOT depend on input size.

Space Complexity
O(1)
Only a few integer variables are used. Memory usage does not grow with input.

8.Recursive Tip-Counting Algorithm Report
Aim
To analyze and understand the recursive algorithm findTips(), write its pseudocode, examine how it works, and determine its time and space complexities.

Short Description
The function:

int findTips(double v)
calculates how many “tips” are required to reduce a given velocity value v until it becomes less than 1.0.
During each recursive call, the velocity is reduced by this formula:

v = v - 0.425v = 0.575v
v=v−0.425v=0.575v
So, each step reduces the velocity to 57.5% of its previous value.
The algorithm counts how many such reductions are needed before the velocity falls below 1.0. This is similar to repeatedly applying exponential decay until a threshold is reached.

Pseudocode

function findTips(v):
    if v < 1:
        return 0
    else:
        return 1 + findTips(0.575 * v)

Working Explanation
Each recursive call represents one tip, decreasing the velocity. The process stops once:
v
<
1.0
v < 1.0
v<1.0
Example:
If v = 10, then:
1st call → 10 → 5.75
2nd call → 5.75 → 3.306
3rd call → 3.306 → 1.900
4th call → 1.900 → 1.092
5th call → 1.092 → 0.628 → stop
So the output = 5 tips

Time Complexity
Let the number of recursive calls be k.
Since the value reduces by a constant ratio each time:
vnew =0.575v
The number of calls required until v < 1 is approximately:
k=log1/0.575 (v)
Time Complexity: O(log v)
The algorithm shrinks the value exponentially, so the time complexity is logarithmic.

Space Complexity
Each function call adds one frame to the recursion stack.
Total depth = k ≈ log(v)
Space Complexity: O(log v)

9.Missing Number Detection (Parity Pattern) Report
Aim
To analyze and understand an algorithm that detects a missing number in a sequence based on parity (odd/even pattern), write its pseudocode, and determine its time and space complexities.

Short Description
The given array contains numbers arranged in an alternating parity pattern (odd → even → odd → even …) or (even → odd → even → odd …).
Example pattern:

3, 4, 5, 6, 7, 8, 9 ...
(Odd, Even, Odd, Even...)
If one number is missing from this sequence, the parity pattern will break at that position.
Example:

3, 4, 5, 7, 8, 9
         ↑
        (6 missing because parity breaks here)
How the algorithm works
It scans the array and checks if two adjacent numbers have the same parity.
If so, the missing number is the average of these two numbers.
missing

missing=2arr[i]+arr[i+1]
This works because only the missing number can cause the parity pattern to break.

Pseudocode

findMissing(arr, n):
    for i = 0 to n-2:
        if parity(arr[i]) == parity(arr[i+1]):
            return (arr[i] + arr[i+1]) / 2
    return -1   // No missing number detected
parity(x):
    return x & 1   // 0 -> even, 1 -> odd

Example
Input:
1 2 3 5 6 7 8 9 ...
At index 2 and 3:
arr[2] = 3 (odd)
arr[3] = 5 (odd)
Parity is same → Missing number = (3 + 5)/2 = 4.

Time Complexity
O(n)
The algorithm performs a single scan of the array to find where the parity breaks.

Space Complexity
O(1)
Only uses:
a loop variable
constant amount of extra memory
Thus, space remains constant.

Limitations
Only works for arrays following a strict odd/even alternating pattern.
Assumes exactly one missing number.
Assumes numbers are increasing by 1 (consecutive sequence).

