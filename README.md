# Lab1 Report Algorithms

# 1.Bubble Sort Report
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

# 2.Horner’s Rule Report
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

# 3.Linear Search Report
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

# 4.Permutation Generation (Backtracking) Report
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


# 5.Tower of Hanoi Report
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


# 6.Selection Sort Report
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

# 7.Boolean Logic (Truth Table Generation) Report
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

# 8.Recursive Tip-Counting Algorithm Report
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

# 9.Missing Number Detection (Parity Pattern) Report
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

# 10. Recursive Insertion Sort
 #Aim
To implement and analyze the performance of recursive insertion sort by measuring the average execution time for varying input sizes.

# Description
This program implements the recursive version of insertion sort, where the array is sorted by recursively sorting the first n-1 elements and then inserting the last element into its correct position.
The program:
Generates random arrays using rand()
Sorts them using recursive insertion sort
Measures execution time using chrono
Repeats the experiment multiple times to calculate average time


#Pseudocode

FUNCTION recursiveInsertionSort(arr, n):
    IF n <= 1:
        RETURN

    CALL recursiveInsertionSort(arr, n-1)

    last = arr[n-1]
    j = n-2

    WHILE j >= 0 AND arr[j] > last:
        arr[j+1] = arr[j]
        j = j - 1

    arr[j+1] = last


FUNCTION fillArray(arr, n):
    FOR i FROM 0 TO n-1:
        arr[i] = random number


MAIN:
    SET repetitions = 100

    FOR n FROM 1000 TO 20000 STEP 1000:
        totalTime = 0

        REPEAT 100 times:
            CREATE array of size n
            fillArray(arr, n)

            start time
            CALL recursiveInsertionSort(arr, n)
            stop time

            ADD time difference to totalTime
            DELETE array

        PRINT n and average time


# Time Complexity
Case	   Complexity
Best Case	  O(n)
Average Case  O(n²)
Worst Case	  O(n²)

 Explanation:
Each element may need to be compared with all previous elements.
Recursive overhead does not change asymptotic complexity.

#Space Complexity
Auxiliary Space	O(n)
Explanation:
Recursive calls use stack space proportional to n.


# 11.Experiment File: Activity Selection Problem (Greedy Algorithm)
#Aim
To implement the Activity Selection Problem using a greedy approach and select the maximum number of non-overlapping activities.

# Short Description
This program solves the Activity Selection Problem by:
Taking input of activities (start and finish times)
Sorting activities based on their finish time
Selecting activities greedily such that each next activity starts after the previous one finishes


#Pseudocode

STRUCT Activity:
    id, start, finish

FUNCTION compare(a, b):
    RETURN a.finish < b.finish

MAIN:
    INPUT n
    CREATE list of activities

    FOR i FROM 0 TO n-1:
        READ start, finish
        ASSIGN id = i + 1

    SORT activities by finish time

    PRINT first activity
    lastFinish = finish time of first activity

    FOR each remaining activity:
        IF start >= lastFinish:
            PRINT activity
            UPDATE lastFinish


# Time Complexity
Step	             Complexity
Sorting activities	O(n log n)
Selecting activities	O(n)
Total Complexity	O(n log n)
 Explanation:
Sorting dominates the runtime.
Greedy selection is linear.

# Space Complexity
Auxiliary Space	O(n)
 Explanation:
Vector stores all activities.
No extra significant memory used beyond input storage.



# 12.Experiment File: K-th Smallest Element using Quick Select
# Aim
To implement the Quick Select algorithm to find the k-th smallest element in an unsorted array efficiently.

 # Description
This program uses the Quick Select algorithm, which is based on the partition logic of Quick Sort.
Working:
A pivot element is selected.
The array is partitioned such that elements smaller than pivot go left and larger go right.
Based on pivot position, the algorithm recursively searches only the required half.


# Pseudocode

FUNCTION partition(arr, low, high):
    pivot = arr[high]
    i = low

    FOR j FROM low TO high-1:
        IF arr[j] <= pivot:
            SWAP arr[i], arr[j]
            i++

    SWAP arr[i], arr[high]
    RETURN i


FUNCTION quickSelect(arr, low, high, k):
    IF low <= high:
        pivotIndex = partition(arr, low, high)

        IF pivotIndex == k:
            RETURN arr[pivotIndex]
        ELSE IF pivotIndex > k:
            RETURN quickSelect(arr, low, pivotIndex - 1, k)
        ELSE:
            RETURN quickSelect(arr, pivotIndex + 1, high, k)

    RETURN -1


FUNCTION kSmallest(arr, n, k):
    RETURN quickSelect(arr, 0, n-1, k-1)


MAIN:
    DEFINE array
    SET k
    PRINT k-th smallest element


# Time Complexity
Case	    Complexity
Best Case	   O(n)
Average Case   O(n)
Worst Case	   O(n²)
Explanation:
On average, partition divides array efficiently.
Worst case occurs when pivot is always smallest/largest (like sorted arrays).

#Space Complexity
Type	        Complexity
Auxiliary Space	  O(1) (iterative)
Recursive Stack	  O(n) worst case
 Explanation:
No extra array is used.
Recursion stack depends on partition depth.


# 13. Experiment File: Fractional Knapsack using Greedy Approach
# Aim
To implement the Fractional Knapsack Problem using different greedy strategies and compare their results:
By Profit
By Weight
By Profit/Weight Ratio

#Description
This program solves the Fractional Knapsack Problem, where items can be taken partially.
Steps:
Input items with profit and weight
Compute profit/weight ratio
Apply three greedy strategies:
Select highest profit first
Select lowest weight first
Select highest profit/weight ratio (optimal)
Fill the knapsack until capacity is reached
Calculate total profit
 The ratio-based method gives the optimal solution.

# Pseudocode

STRUCT Item:
    id, profit, weight, ratio

FUNCTION solve(items, capacity, method):
    totalProfit = 0

    FOR each item in items:
        IF capacity <= 0:
            BREAK

        IF item.weight <= capacity:
            TAKE full item
            capacity -= item.weight
            totalProfit += item.profit
        ELSE:
            TAKE fraction = capacity / item.weight
            totalProfit += item.profit * fraction
            capacity = 0

    PRINT totalProfit


MAIN:
    INPUT n
    INPUT profit and weight for each item

    CALCULATE ratio = profit / weight

    INPUT capacity

    SORT items by:
        1. Profit (descending)
        2. Weight (ascending)
        3. Ratio (descending)

    CALL solve for each method


# Time Complexity
Step	               Complexity
Sorting (each method)	O(n log n)
Greedy selection	    O(n)
Total Complexity	   O(n log n)
 Explanation:
Sorting dominates runtime.
Selection is linear.

# Space Complexity
   Type	    Complexity
Auxiliary Space	O(V)

Explanation:
Storing items and copies for each method.



# 14. Experiment File: Minimum Spanning Tree using Kruskal’s Algorithm
🎯 Aim
To implement Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a given weighted graph.

#Description
This program finds the Minimum Spanning Tree using a greedy approach:
Extract all edges from the graph
Sort edges in ascending order of weight
Use Disjoint Set (Union-Find) to detect cycles
Add edges to MST only if they don’t form a cycle
Stop when V-1 edges are selected
Ensures minimum total weight while connecting all vertices.

#Pseudocode

STRUCT Edge:
    u, v, weight

FUNCTION findParent(parent, i):
    IF parent[i] != i:
        parent[i] = findParent(parent, parent[i])
    RETURN parent[i]

FUNCTION unionSet(parent, rank, x, y):
    FIND roots of x and y

    IF rank[x] < rank[y]:
        parent[x] = y
    ELSE IF rank[x] > rank[y]:
        parent[y] = x
    ELSE:
        parent[y] = x
        rank[x]++

FUNCTION kruskalMST(graph):
    CREATE edge list from graph

    SORT edges by weight

    INITIALIZE parent and rank arrays

    FOR each edge:
        FIND sets of both vertices

        IF sets are different:
            INCLUDE edge in MST
            UNION sets

        STOP when V-1 edges selected


#Time Complexity
Step	              Complexity
Sorting edges	       O(E log E)
Union-Find operations  O(E α(V))
Total Complexity	   O(E log E)
 Explanation:
Sorting dominates runtime
α(V) is inverse Ackermann (very small, almost constant)

#Space Complexity
Auxiliary Space	O(V + E)
 Explanation:
Edge list + parent & rank arrays




# 15. Experiment File: Minimum Spanning Tree using Prim’s Algorithm
# Aim
To implement Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.

# Description
This program constructs the Minimum Spanning Tree using a greedy approach:
Start from an arbitrary vertex (here, vertex 0)
Repeatedly select the minimum weight edge connecting a visited vertex to an unvisited vertex
Continue until all vertices are included
 Unlike Kruskal’s algorithm, Prim’s grows the MST vertex by vertex.

#Pseudocode

FUNCTION minKey(key, mstSet):
    min = infinity
    FOR each vertex v:
        IF mstSet[v] == false AND key[v] < min:
            min = key[v]
            min_index = v
    RETURN min_index


FUNCTION primMST(graph):
    INITIALIZE:
        key[] = infinity
        mstSet[] = false
        parent[]

    key[0] = 0
    parent[0] = -1

    FOR count FROM 0 TO V-2:
        u = minKey(key, mstSet)
        mstSet[u] = true

        FOR each vertex v:
            IF graph[u][v] exists AND mstSet[v] == false
               AND weight < key[v]:
                parent[v] = u
                key[v] = weight

    PRINT MST using parent[]


FUNCTION printMST(parent, graph):
    FOR i FROM 1 TO V-1:
        PRINT parent[i] - i with weight


# Time Complexity
Step	         Complexity
Finding minimum key	O(V)
Updating vertices	O(V)
Total Complexity	O(V²)
Explanation:
Uses adjacency matrix → leads to O(V²)
Can be optimized to O(E log V) using priority queue

#Space Complexity
Auxiliary Space	O(V)
 Explanation:
Arrays: key[], parent[], mstSet[]






# 16. Experiment File: Shortest Path in Multistage Graph (Dynamic Programming)
#Aim
To implement an algorithm to find the shortest path in a multistage graph using dynamic programming.

# Short Description
This program computes the minimum cost path from a start vertex to an end vertex in a directed multistage graph.
Working:
Graph is represented as an adjacency matrix
Starts from the last stage (destination) and moves backward
Stores minimum cost from each vertex to destination
Tracks the next vertex to reconstruct the path
 This is a bottom-up dynamic programming approach.

# Pseudocode

FUNCTION shortestPathMultistage(V, graph, start, end):
    INITIALIZE cost[] = infinity
    INITIALIZE nextVertex[] = -1

    cost[end] = 0

    FOR i FROM V DOWNTO 1:
        minCost = infinity
        FOR j FROM i+1 TO V:
            IF edge exists AND cost[j] is valid:
                IF graph[i][j] + cost[j] < minCost:
                    minCost = graph[i][j] + cost[j]
                    next = j

        IF valid path found:
            cost[i] = minCost
            nextVertex[i] = next

    IF cost[start] == infinity:
        PRINT no path exists
        RETURN

    PRINT path from start using nextVertex[]
    PRINT minimum cost


# Time Complexity
Step	        Complexity
Nested loops	    O(V²)
Total Complexity	O(V²)
 Explanation:
For each vertex, all possible next vertices are checked.

# Space Complexity
Auxiliary Space	O(V²)
 Explanation:
Adjacency matrix + cost and path arrays





# 17. Experiment File: Matrix Chain Multiplication (Dynamic Programming)
# Aim
To implement Matrix Chain Multiplication (MCM) using dynamic programming to find the minimum number of scalar multiplications required.

# Description
This program determines the most efficient way to multiply a chain of matrices by deciding the optimal parenthesization.
Matrix multiplication is associative, but cost varies
The program uses dynamic programming to minimize operations
It builds a table storing minimum multiplication costs for subproblems
 The goal is to reduce computational cost, not change the result.

#Pseudocode

FUNCTION matrixChainMultiplication(p, n):
    CREATE table m[n][n]

    FOR i FROM 1 TO n-1:
        m[i][i] = 0

    FOR L FROM 2 TO n-1:
        FOR i FROM 1 TO n-L:
            j = i + L - 1
            m[i][j] = infinity

            FOR k FROM i TO j-1:
                cost = m[i][k] + m[k+1][j] 
                       + p[i-1] * p[k] * p[j]

                IF cost < m[i][j]:
                    m[i][j] = cost

    RETURN m[1][n-1]


# Time Complexity
Step	           Complexity
Triple nested loops	O(n³)
Total Complexity	O(n³)
 Explanation:
For each chain length, all partitions are evaluated.

# Space Complexity
  DP Table	O(n²)

 Explanation:
A 2D table is used to store subproblem results.

