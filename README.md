# Alphanumeric threading

# Description
By using 2 different threads, separate an input by words and numbers.

# Goals

Goal 1: From the terminal, the program should read the phrase. This phrase should be saved into a global variable. (done)

Goal 2: The main should create 2 concurrent threads: one for printing words that begin with an alphabet and the second for printing words that begin with a number. Each thread should call their thread function: alpha and numeric, respectively. Each thread should be sent its name as an argument through the thread function: alpha or numeric: this is what they will print in the output as shown above. (done)

Goal 3: You will have to solve any race conditions using C++ language constructs to simulate the working of locks. (done)

Goal 4: If you split the input string into a set of words, say a vector, then such an object should be global. You should simultaneously be iterating over the vector in each alpha and the numeric thread function. Even if you do not split the string, you should still be iterating over the string simultaneously in each of the alpha and the numeric thread functions. The index or the iterator used for iterating should be global. (done)
