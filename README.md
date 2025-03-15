# Philosophers Implementation Guide
This project simulates the Dining Philosophers Problem, where multiple philosophers alternate between eating, thinking, and sleeping, while synchronizing access to shared resources (forks). The goal is to avoid deadlocks and ensure smooth execution using mutexes for synchronization.

# Key Concepts
  Fork Management
  Each philosopher needs two forks to eat.
  Philosophers can only eat if both forks are available. After eating, they release the forks for others.
  Forks are managed using an array of mutexes (fork_mutex) and an array of integers (forks).

# Deadlock Prevention

  Deadlock occurs when two or more philosophers wait indefinitely for forks held by each other.
  To avoid deadlock, philosophers always pick up forks in a consistent order (smaller index first). This prevents circular waiting, where two philosophers block each other.
Mutexes

  Mutexes are used to ensure that only one philosopher can access a fork at a time.
  Multiple mutexes are used for the forks (fork_mutex) and for other synchronization purposes, like printing (print_mutex), checking death (death_mutex), and eating (eat_mutex).

# Philosopher Routine

Each philosopher runs in its own thread, executing the following routine:
Locking Forks: The philosopher tries to lock the forks in a consistent order using lock_order.
Eating: If the forks are available, the philosopher eats.
Releasing Forks: After eating, the philosopher releases the forks for others to use.
Sleeping and Thinking: Philosophers alternate between sleeping and thinking when not eating.

# Fork Locking Order

The lock_order function ensures that philosophers pick up forks in the same order to prevent deadlock.
By locking the fork with the smaller index first, philosophers avoid circular dependencies.

# State Management

Each philosopher has a state: thinking, eating, or sleeping.
Fork Availability Check: Forks are checked before a philosopher eats, sleeps, or thinks, to ensure no conflicts or resource contention.
Mutexes are used to synchronize all state transitions and resource accesses.
Synchronization and Concurrency
Fork Checking: A philosopher checks if both forks are available before starting to eat. This is done with the fork_checker function, where a mutex is locked to ensure that no other philosopher is modifying the fork states concurrently.
Multiple Mutexes:
fork_mutex: Each fork has its own mutex to prevent race conditions when checking and locking forks.
print_mutex: Used to synchronize printing to avoid interleaved outputs from multiple philosophers.
death_mutex, eat_mutex: Used for synchronizing the checks for philosopher death and eating times, ensuring consistent and thread-safe updates.
Key Functions
lock_order: Ensures that forks are always locked in the same order to avoid deadlock.
fork_checker: Checks if a philosopher can access the forks, locking the mutexes for the respective forks.
lock_forks and release_forks: Lock and unlock the forks for eating, ensuring proper synchronization.
Example Flow

# Initialization:

Philosophers are created and assigned to threads.
Forks are initialized, and mutexes are set up for synchronization.
Philosopher Routine:

Philosophers attempt to pick up forks, eat, sleep, and think, following the rules defined above.
Thread Synchronization:

Threads (one for each philosopher) are created, and each philosopher runs their own routine in parallel.
Mutexes ensure that philosophers do not interfere with each other when accessing shared resources.
This guide provides an overview of the key concepts and functions used in the implementation of the Dining Philosophers problem. The main goals are to prevent deadlocks and ensure smooth execution by correctly managing access to shared resources and synchronizing the philosophers' actions.

