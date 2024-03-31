# Scheduling Algorithms

### 1. First Come First Serve (FCFS)
```
Step 0 : Start
Step 1 : Declare a structure to store process details
Step 2 : Create an array of structure to store processes 
Step 3 : Read the number of processes
Step 4 : Read the process details of all processes 
Step 5 : Create a variable to store the total time and initialize it to 0
Step 6 : Create a variable to store the waiting time and initialize it to 0
Step 7 : For every process in the array repeat steps 8 to 11
Step 8 : Set waiting time of the process as total time
Step 9 : Increment total time by burst time of the process
Step 10 : Increment total waiting time by waiting time of the process
Step 11 : Set process turn around time as sum of burst time and waiting time
Step 12 : Print the process details
Step 13 : Print total time taken for execution
Step 14 : Calculate average waiting time and print it
Step 15 : Stop
```

### 2. Shortest Job First (SJF) (Non-Preemptive)
```
Step 0 : Start
Step 1 : Declare a structure to store process details
Step 2 : Create an array of structure to store processes
Step 3 : Read the number of processes
Step 4 : Read the process details of all processes
tep 5 : Create a variable to store the total time and initialize it to 0
Step 6 : Create a variable to store the waiting time and initialize it to 0
Step 7 : Sort the processes based on burst time using any sorting algorithm
Step 8 : For every process in the array repeat steps 9 to 12
Step 9 : Set waiting time of the process as total time
Step 10 : Increment total time by burst time of the process
Step 11 : Increment total waiting time by waiting time of the process
Step 12 : Set process turn around time as sum of burst time and waiting time
Step 13 : Print the process details
Step 14 : Print total time taken for execution
Step 15 : Calculate average waiting time and print it
Step 16 : Stop
```

### 3. Round Robin (RR)
```
Step 0 : Start
Step 1 : Declare a structure to store process details
Step 2 : Create an array of structure to store processes
Step 3 : Read the number of processes
Step 4 : Read the time quantum
Step 5 : Create a variable to store the total time and initialize it to 0
Step 6 : Create a variable to store the waiting time and initialize it to 0
Step 7 : Create a variable called total burst time and initialize it to 0
Step 8 : Create a variable called iterator and initialize it to time quantum
Step 9 : Create a variable to keep track of current PID and initialize it to 0
Step 10 : Repeat steps 11 to 14 until for all processes
Step 11 : Read the burst time of the current process
Step 12 : Create a copy of the burst time
Step 13 : Increment total burst time by burst time of the current process
Step 14 : Initialize occurance of the current process as 0
Step 15 : Repeat steps 16 to 26 for i = 0 to total burst time
Step 16 : If iterator % time quantum is 0 and i != 0, then do steps 17 to 18 , else go to 19
Step 17 : Move to the next process
Step 18 : Reset the iterator to time quantum
Step 19 : Repeat steps 20 to 21 until burst time copy of the current process is not 0
Step 20 : Move to the next process
Step 21 : Reset the iterator to time quantum
Step 22 : Increment the occurance of the current process by 1
Step 23 : Increment the total time by 1
Step 24 : Decrement the burst time copy of the current process by 1
Step 25 : Increment iterator by 1
Step 26 : Set waiting time of the process as i - (occurance + 1);
Step 27 : Print the process details
Step 28 : Repeat steps 29 for all processes
Step 29 : Increment total waiting time by waiting time of the process
Step 30 : Print total time taken for execution
Step 31 : Calculate average waiting time and print it
Step 32 : Stop
```

### 4. Priority Scheduling (Non-Preemptive)
```
Step 0 : Start
Step 1 : Declare a structure to store process details
Step 2 : Create an array of structure to store processes
Step 3 : Read the number of processes
Step 4 : Read the process details of all processes
tep 5 : Create a variable to store the total time and initialize it to 0
Step 6 : Create a variable to store the waiting time and initialize it to 0
Step 7 : Sort the processes based on Priority using any sorting algorithm
Step 8 : For every process in the array repeat steps 9 to 12
Step 9 : Set waiting time of the process as total time
Step 10 : Increment total time by burst time of the process
Step 11 : Increment total waiting time by waiting time of the process
Step 12 : Set process turn around time as sum of burst time and waiting time
Step 13 : Print the process details
Step 14 : Print total time taken for execution
Step 15 : Calculate average waiting time and print it
Step 16 : Stop



