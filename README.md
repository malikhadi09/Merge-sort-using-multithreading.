# MERGE SORT USING MULTITHREADING

# ALGORITHM:

1. Divide the input field into 4 equal parts.
2. Create 4 separate threads, each responsible for sorting one of the 4 parts of the array.
3. Implement the merge sort algorithm in each of the 4 threads.
4. When each thread has finished sorting its part of the array, merge the 4 sorted subarrays into a single sorted array using the merge step of the merge sort algorithm.


# EXPLANATION OF THE CODE:
In merge sort we are sorting an array using merge sort algorithm, merge sort is based on divide and conquer rule where the arrays are divided into two equal halves and then they combined in a sorted manner in “merge_sort” function, here we are dividing the array into 4 threads. We are dividing the input that was taken from the user into 4 equal parts. We are creating 4 separate threads, each of them are responsible for sorting one of the 4 parts of the array.
We are implementing the merge sort algorithm in each of the 4 threads.
After when each thread has finished sorting its part of the array, we are merging the 4 sorted subarrays into a single sorted array that is done in “merge” function.
Now coming to “main()” function , here we are taking array size from the user that is mentioned in an assignment that the size of the array should be accepted from the user and we did that and storing the entered value in ‘n’ variable, same we are taking the array elements from the user. 
Then we are calling merge sort function where we are sorting the array using 4 threads.
And in the last we are printing those sorted array
