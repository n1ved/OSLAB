# Interprocess Communication using Shared Memory

### Writer Process
```
Step 0 : Start
Step 1 : Create a shared memory segment using shmget()
         by passing a key size and IPC_CREAT flag
Step 2 : Attach the shared memory segment using shmid
Step 3 : Write data to the shared memory segment using shmdt()
Step 4 : Stop
```

### Reader Process
```
Step 0 : Start
Step 1 : Create a unique key
Step 2 : Get shmid using shmget() by passing key and size
Step 3 : Attach the shared memory segment using shmat()
Step 4 : Print the retrieved data
Step 5 : Detach the shared memory segment using shmdt() and shmcntl()
Step 6 : Stop
```


### Flags used
- `IPC_CREAT` : Create a new shared memory segment
- `IPC_RMID` : Remove the shared memory segment
- `0666` : Read and write permission

### Functions used and format
- `shmget(key_t key, size_t size, int shmflg)`
        we used shmflag as `IPC_CREAT | 0666` to create a new shared memory segment
- `shmat(int shmid, void *shmaddr, int shmflg)`
        we used `shmaddr` as `NULL` and `shmflag` as `0` to attach the shared memory segment
        (why?) because we are not interested in the address where the shared memory segment is attached
- `shmdt()`
        to detach the shared memory segment
- `shmctl(int shmid, int cmd, struct shmid_ds *buf)`
        to control the shared memory segment . we used `cmd` as `IPC_RMID` to remove the shared memory segment

         