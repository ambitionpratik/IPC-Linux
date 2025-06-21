A Unix Domain Socket is a file-based IPC mechanism that enables two or more processes on the same host to communicate via sockets, but without using the networking stack.

Instead of IP addresses and ports (AF_INET), UDS uses file paths in the filesystem.

**Types of Unix Domain Sockets**
| Socket Type      | Description                                                           |
| ---------------- | --------------------------------------------------------------------- |
| `SOCK_STREAM`    | Byte stream, reliable, connection-oriented (like TCP)                 |
| `SOCK_DGRAM`     | Datagram, connectionless, message-oriented (like UDP)                 |
| `SOCK_SEQPACKET` | Message-based, connection-oriented with guaranteed message boundaries |

**File-based Nature**
- The socket appears as a file: /tmp/mysocket.sock
- You can use:
  
    ls -l /tmp/mysocket.sock → shows srwxr-xr-x (socket file)

    unlink(path) to remove the file after use
  
**Summary**
| Feature            | Unix Domain Socket            |
| ------------------ | ----------------------------- |
| Domain             | `AF_UNIX` or `AF_LOCAL`       |
| Addressing         | Filesystem path (`/tmp/sock`) |
| Socket Types       | `SOCK_STREAM`, `SOCK_DGRAM`   |
| Performance        | Very high (no IP stack)       |
| Security           | File permissions              |
| Cross-host support | ❌ No (local only)             |
| Linux support      | ✅ All major Unix-like OSes    |
