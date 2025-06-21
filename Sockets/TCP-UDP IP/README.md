# A TCP/IP socket is an endpoint for communication between two machines using the TCP protocol over an IP network.

It provides:
- Reliable, connection-oriented, ordered byte streams
- Bidirectional (full-duplex) communication
- IP-based addressing (AF_INET or AF_INET6)
- TCP as transport (SOCK_STREAM)

# A UDP/IP socket is an endpoint for communication between two machines using the UDP protocol over an IP network.

It provides:
- Unreliable, connection-less, non ordered message
- Bidirectional (full-duplex) communication
- IP-based addressing (AF_INET or AF_INET6)
- UDP as transport (SOCK_DGRAM)

**TCP vs UDP: The Core Difference**
| Feature                | **TCP (SOCK\_STREAM)**             | **UDP (SOCK\_DGRAM)**             |
| ---------------------- | ---------------------------------- | --------------------------------- |
| **Connection Type**    | Connection-oriented                | Connectionless                    |
| **Reliability**        | Reliable (ACK, retransmit)         | Unreliable (no ACKs)              |
| **Ordering**           | Ordered delivery                   | No guarantee                      |
| **Message Boundaries** | Byte stream (no boundaries)        | Message-based (each send = 1 msg) |
| **Overhead**           | Higher (3-way handshake, stateful) | Lower (stateless)                 |
| **Speed**              | Slower but reliable                | Faster but lossy                  |
| **Use Cases**          | HTTP, FTP, SSH, email, DB          | DNS, VoIP, video, gaming          |

