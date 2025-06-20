A message queue is a kernel-managed linked list of messages stored in memory. Processes can send and receive structured messages without needing to share memory or worry about synchronization like shared memory.

**There are two main APIs:**

- System V Message Queues
- POSIX Message Queues

**Key Concepts**

- Identified by a key (via ftok) and queue ID.
- Each message has:

  1) mtype: A positive long integer, used for filtering.
  2) mtext: Actual message data.
    
- Messages are stored in order of arrival, but receivers can fetch based on mtype.

**System V APIs**
| Function   | Purpose                           |
| ---------- | --------------------------------- |
| `msgget()` | Create or get a message queue     |
| `msgsnd()` | Send a message to the queue       |
| `msgrcv()` | Receive a message from the queue  |
| `msgctl()` | Control operations (e.g., delete) |

struct msg_buffer {

long mtype; // Message Type, can be used by process to fetch it's data.
    
char mtext[MAX_TEXT]; // Actual message
    
};
