# Operating-System-Lab-Projects

In this project, we have added some features to xv6 operating system. The features are as follows:

## Experiment 1: Introduction to xv6

### Task 1: Boot Message

The following message is displayed when the system boots up:

```
Group 1:
- Saman Eslami Nazari : 810199375
- Pasha Barahimi      : 810199385
- Misagh Mohaghegh    : 810199484
```

### Task 2: Console Features

The following features are added to the console:

- `Ctrl+N` : Removes all the digits from the console
- `Ctrl+R` : Reverses the current line
- `Tab`    : Substitutes the current line with a command from the history (if exists)

Also, the following features are added to the console while there were not required in the task:

- `Arrow Up`   : Shows the previous command in the history
- `Arrow Down` : Shows the next command in the history

### Task 3: User Program

A `prime_numbers` program is added to the system. This program finds the prime numbers from $a$ to $b$. The program is called as follows:

```
prime_numbers a b
```

The result is printed in the `prime_numbers.txt` file.

## Experiment 2: System Calls

### Task 1: System Call using registers

The `find_largest_prime_factor` system call is added to the system. This system call finds the largest prime factor of a given number. The system call is called as follows:

```c++
int find_largest_prime_factor(void);
```

The parameter should be passed in the `ebx` register.

### Task 2: System Call using stack

- The `change_file_size` system call is added to the system. This system call changes the size of a file. It will add zeros to the end of the file if the new size is larger than the current size. Otherwise, it will remove the last bytes of the file. The system call is called as follows:

```c++
int change_file_size(char *path, int size);
```

- The `get_callers` system call is added to the system. This system call returns the callers of each system call. The system call is called as follows:

```c++
void get_callers(int callers);
```

- The `get_parent_pid` system call is added to the system. This system call returns the parent process id of the current process. The system call is called as follows:

```c++
int get_parent_pid(void);
```

## Experiment 3: Process Scheduling

### Task 1: Multi-Level Feedback Queue

The `MLFQ` scheduler is added to the system. The scheduler has 3 queues. The first queue has the highest priority and the last queue has the lowest priority. The following queueing policies are used:

- The first queue is a round-robin queue with a time quantum of 1 tick.
- The second queue is lottery queue in which the tickets shows the chance of the process to be executed.
- The third queue is a BJF queue in which the process with the lowest rank is executed.

### Task 2: Add aging to MLFQ

All processes are started in the second queue (except the init and sh processes). If a **runnable** process has not been executed for 8000 ticks, it is moved to the first queue.

### Task 3: System Calls

The following system calls are added to the system:

- `change_scheduling_queue` : Changes the scheduling queue of a process. The system call is called as follows:

```c++
int change_scheduling_queue(int pid, int queue);
```

- `set_lottery_tickets` : Sets the lottery tickets of a process. The system call is called as follows:

```c++
int set_lottery_tickets(int pid, int tickets);
```

- `set_bjf_params_process` : Sets the parameters of the BJF algorithm for a process. The system call is called as follows:

```c++
int set_bjf_params_process(int pid, float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio);
```

- `set_bjf_params_system` : Sets the parameters of the BJF algorithm for the system. The system call is called as follows:

```c++
int set_bjf_params_system(float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio);
```

- `print_process_info` : Prints the information of processes. The system call is called as follows:

```c++
void print_process_info(void);
```

## Experiment 4: Synchronization

### Task 1: Semaphore

As xv6 does not support threads, the only usage of semaphores will be among processes. As a result, an array of 5 semaphores is implemented in the system. The following system calls are added to the system:

- `sem_init` : Initializes a semaphore. The system call is called as follows:

```c++
int sem_init(int index, int value);
```

- `sem_acquire` : Acquires a semaphore. The system call is called as follows:

```c++
int sem_acquire(int index);
```

- `sem_release` : Releases a semaphore. The system call is called as follows:

```c++
int sem_release(int index);
```

### Task 2: Dining Philosophers

The `dining_philosophers` simulation is implemented using semaphores. To prevent deadlock, all the philosophers with even ids pick up the left fork first and then the right fork. The philosophers with odd ids pick up the right fork first and then the left fork. The simulation is called as follows:

```
dining_philosophers
```
