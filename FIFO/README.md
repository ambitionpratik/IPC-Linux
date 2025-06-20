- A FIFO or Named Pipe is a special file that allows unidirectional or bidirectional communication between unrelated processes, unlike regular pipes which work only between related processes.
- FIFO stands for First-In, First-Out.
- It's persistent in the filesystem until deleted.
- It behaves like a regular file but supports sequential access only.

**Key Characteristics**
| Feature            | Value                       |
| ------------------ | --------------------------- |
| Communication      | Unidirectional (usually)    |
| Persistent         | Yes (exists as a file)      |
| Related Processes? | **Not required**            |
| Buffered?          | Yes (kernel pipe buffer)    |
| Sync Behavior      | Blocking read/write         |
| File system entry? | Yes (created with `mkfifo`) |

**Blocking Behavior**
| Scenario                        | Behavior                      |
| ------------------------------- | ----------------------------- |
| `open()` FIFO for read only     | Blocks until a writer appears |
| `open()` FIFO for write only    | Blocks until a reader appears |
| `read()` when no writer exists  | Returns 0 (EOF)               |
| `write()` when no reader exists | `SIGPIPE` or `EPIPE` error    |

**File Permissions & Security**
- FIFO is a file in the filesystem — permissions apply.
- You can use chmod or umask to restrict access.

**Advantages**
- Simple to implement
- No need for shared memory or complex setup
- Good for unrelated processes

**Limitations**
- No message boundaries (byte stream only)
- Slower than shared memory
- No built-in synchronization (unlike semaphores)
- Not suitable for high-throughput or complex communication

**FIFO vs Pipe**
| Feature            | FIFO                     | Pipe                  |
| ------------------ | ------------------------ | --------------------- |
| File system entry  | Yes (`/tmp/myfifo`)      | No                    |
| Related processes? | Not required             | Required (e.g., fork) |
| Communication      | Uni (or Bi with care)    | Uni                   |
| Lifetime           | Persistent until deleted | Temporary             |

**Note:**
mkfifo("/tmp/myFifo", 0666); - This will create a named pipe(fifo) file at /tmp directory.

prw-rw-rw- 1 user user 0 Jun 20 10:30 myfifo --> p stands for named pipe.

**Common Pitfalls**
- If you don’t have write permission in the current directory, mkfifo() will fail.
- If the file already exists, it returns -1 with EEXIST.

