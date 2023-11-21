# opsys_proj2

For creating each thread, you should use the pthread_create function.
For joining each thread, you should use the pthread_join function.


You are NOT allowed to use ANY pthread library or other POSIX synchronization primitives including but not limited to: semaphores, mutexes, mutex locks such as pthread_mutex_lock and pthread_mutex_unlock and conditional variables such as pthread_cond_wait and pthread_cond_signal etc. You should solve that race condition (if any) using another way, such as C++ language constructs.
You are also not allowed to use sleep() or sched_yield() 


Goal 1: From the terminal, the program should read in the phrase. This phrase should be saved into a global variable.
Goal 2: The main should create 2 concurrent threads: one thread for printing words that begin with an alphabet, and the second thread for printing words that begin with a number. Each thread should call their own thread function: alpha and numeric respectively. Each thread should be sent their name as an argument through the thread function: alpha or numeric: this is what they will print in the output as shown above.

Goal 3: You will have to solve any race conditions using C++ language constructs, to simulate the working of locks.

Goal 4: If you split the input string into a set of words, say a vector, then such an object should be global. You should simultaneously be iterating over the vector in each of the alpha and the numeric thread functions. Even if you do not split the string, you should still be iterating over the string simultaneously in each of the alpha and the numeric thread functions. The index or the iterator used for iterating should be global.
