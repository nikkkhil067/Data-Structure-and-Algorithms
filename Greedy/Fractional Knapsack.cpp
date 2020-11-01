/*
Given weights and values of n items, 
we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

Example:
    Input:
    Items as (value, weight) pairs
    arr[] = {{60, 10}, {100, 20}, {120, 30}}
    Knapsack Capacity, W = 50;
    Output:
    Maximum possible value = 240
    by taking items of weight 10 and 20 kg and 2/3 fraction
    of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

In Fractional Knapsack, we can break items for maximizing the total value of knapsack. 
This problem in which we can break an item is also called the fractional knapsack problem.

Input : 
   Same as above
Output :
   Maximum possible value = 240
   By taking full items of 10 kg, 20 kg and 
   2/3rd of last item of 30 kg

A brute-force solution would be to try all possible subset with all different fraction 
but that will be too much time taking.

An efficient solution is to use Greedy approach. 
The basic idea of the greedy approach is to calculate the ratio value/weight for each item and 
    sort the item on basis of this ratio. 
    Then take the item with the highest ratio and 
    add them until we can’t add the next item as a whole and at the end 
    add the next item as much as we can. Which will always be the optimal solution to this problem.
*/

#include <bits/stdc++.h> 
  
using namespace std; 
  
// Structure for an item which stores weight and corresponding 
// value of Item 
struct Item 
{ 
    int value, weight; 
  
    // Constructor 
    Item(int value, int weight) : value(value), weight(weight) 
    {} 
}; 
  
// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
  
// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    //    sorting Item on basis of ratio 
    sort(arr, arr + n, cmp); 
  
    //    Uncomment to see new order of Items with their ratio 
    /* 
    for (int i = 0; i < n; i++) 
    { 
        cout << arr[i].value << "  " << arr[i].weight << " : " 
             << ((double)arr[i].value / arr[i].weight) << endl; 
    } 
    */
  
    int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    // Returning final value 
    return finalvalue; 
} 
  
// driver program to test above function 
int main() 
{ 
    int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n); 
    return 0; 
} 

/*
Output :
Maximum value in Knapsack = 240
*/

/*Time Complexity : As main time taking step is sorting, 
                    the whole problem can be solved in O(n log n) only.
*/ 