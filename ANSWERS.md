**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
  - NEW: Process is being created
  - READY: Process is waiting to be assigned to a processor
  - RUNNING: Instructions are being executed
  - WAITING: Process is waiting for some event to occur
  - TERMINATED: Process has finished execution

**2. What is a zombie process?**
  
    A zombie process is a process whose execution is completed but it still has an entry in the process table. 


**3. How does a zombie process get created? How does one get destroyed?**

    Zombie processes usually occur for child processes, as the parent process still needs to read its child’s exit status. Once this is done using the wait system call, the zombie process is eliminated from the process table. 

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

  - A compiled language is one where the program, once compiled, is expressed in the instructions of the target machine.
    - Faster performance by directly using the native code of the target machine
    - Opportunity to apply quite powerful optimisations during the compile stage
  - A non-compiled language is one where the instructions are not directly executed by the target machine, but instead read and executed by some other program (which normally is written in the language of the native machine).
    - Easier to implement
    - No need to run a compilation stage: can execute code directly "on the fly"