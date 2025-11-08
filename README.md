# SYSC4001_A2_P2

1. Explain what the fork system call does

The fork() system call is used to create a new process. When a process executes fork(), the operating system makes a copy of the address space of the original process, known as the child process while the original becomes the parent process. Both processes, the parent and the child will continue to execute independently from the instructions following the fork() call. However, the difference between the parent and child process is that the child process will receive a return value of zero whereas the parent process will receive the process ID of the child (PID).

2. Explanation of exec() function

The exec() function is called after the fork() system call, to load the selected program into memory and begin execution. It’s used to invoke the loader, being passed the name of the executable file. After a fork() system call, the child process uses the exec() system call to load a binary file into memory while destroying the memory image of the program containing the exec() system call, thus replacing the process’s memory/address space with the new program. Because of this, exec() doesn’t return control unless an error occurs.
