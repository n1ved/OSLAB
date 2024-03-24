# SYSTEM CALLS

## PROGRAM 1

### Aim : 
To write a C program to implement `fork()` , `getpid()` , `wait()` and `exec` system calls

### Algorithm
```
S0 : Start
S1 : Store PID of parent process in parent using getpid()
S2 : Call fork() to create a child process and store its PID in procid
S3 : If procid < 0 do step S4
S4 : Print "Fork failed"
S5 : Otheriwise do step S6
S6 : Print "Child created for process" followed by parent PID
S7 : Call wait() to wait for child process to complete
S8 : Print "Executing process" followed by current PID
S9 : Call exec() to execute any UNIX command
S10 : End
```

## PROGRAM 2

### Aim :
To write a C program to implemete stat() system call

### Algorithm
```
S0 : Start
S1 : Declare struct stat variable sfile
S2 : Call stat() with file name and address of sfile as arguments
S3 : Print file size using sfile.st_size
S4 : Print file permissions using sfile.st_mode
S5 : Stop
```

## PROGRAM 3

### Aim :
To write a C program to implement `readdir()` and `opendir()` system calls

### Algorithm
```
S0 : Start
S1 : Declare a struct dirent variable *d
S2 : Declare a DIR variable *dir
S3 : Call opendir() with directory name as argument and store the return value in dir
S4 : If dir is NULL exit
S5 : Repeat step S6 to S7 until readdir() returns NULL
S6 : Store the return value of readdir() in d
S7 : Print d->d_name
S8 : Call closedir() with dir as argument
S9 : Stop
```