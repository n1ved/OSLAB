# Banker's Algorithm

### Algorithm
```
Step 1 : Start
Step 2 : get number of process and number of resources
Step 3 : get allocation matrix of size number of process * number of resources
Step 4 : get max matrix of size number of process * number of resources
Step 5 : get available matrix of size number of resources
Step 6 : calculate need matrix of size number of process * number of resources by subtracting allocation matrix from max matrix
Step 7 : repeat step 8 to 12 until all process are completed
Step 8 : find an index i such that exec[i] = false and need[i] <= available
Step 9 : if exist execute step 10 to 12
Step 10 : available = available + allocation[i]
Step 11 : exec[i] = true
Step 12 : print i
Step 13 : stop
```


