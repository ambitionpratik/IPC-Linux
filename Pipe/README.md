A pipe is a unidirectional communication channel used to send data from one process to another. Pipes are commonly used between a parent and child process.

| Feature         | Value                       |
| --------------- | --------------------------- |
| Communication   | Unidirectional (read/write) |
| Scope           | Related processes only      |
| Buffered        | Yes (kernel buffer)         |
| Synchronization | Blocking `read`/`write`     |
| Lifetime        | Until both ends are closed  |

       +--------+      pipe      +--------+
Parent | write  | --------------> | read   | Child
       |  fd[1] |                 | fd[0]  |
       +--------+                 +--------+

Two-Way Communication (Full Duplex)

int pipe1[2]; // Parent -> Child
int pipe2[2]; // Child -> Parent

Kernel Buffering
The pipe uses an internal circular buffer.

Default size: 64KB (can be queried via /proc/sys/fs/pipe-max-size).

If buffer is full: write() blocks.

If buffer is empty: read() blocks.

Use O_NONBLOCK or select()/poll() for non-blocking behavior.

Limitations
Works only between processes with a common ancestor (e.g., parent-child)

Unidirectional

Limited buffer size

No message boundaries (it's byte-stream like a file)

Advantages
Simple and lightweight

Kernel-managed (safe and synchronized)

Portable and standardized