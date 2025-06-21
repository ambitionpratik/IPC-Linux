Shared Memory is one of the fastest IPC (Inter-Process Communication) mechanisms in Linux. It allows multiple processes to access a common memory region for reading and writing, enabling very high-speed data exchange — but you must handle synchronization yourself.

**Why Use Shared Memory?**
- Extremely fast – no copying between kernel/user space.
- Ideal for large data volumes or real-time systems.
- Needs synchronization (e.g., semaphores, mutexes) to avoid race conditions.

**- There are two major APIs:**
| API      | Functions Used                                | Notes                                  |
| -------- | --------------------------------------------- | -------------------------------------- |
| System V | `shmget`, `shmat`, `shmdt`, `shmctl`          | Older, more portable in legacy systems |
| POSIX    | `shm_open`, `mmap`, `ftruncate`, `shm_unlink` | File-descriptor based, modern          |

