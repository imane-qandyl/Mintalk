<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<GUIDE_MINITALK>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

implementation of a signaling system between a server and client using UNIX signals
{inter-process communication (IPC)}
{Portable Operating System Interface(POSIX)}

IPC: Mechanisms for processes to communicate .
POSIX: APIs for IPC, including signals.
SIGUSR1 and SIGUSR2 are tools provided by POSIX to facilitate custom communication between processes.


@make -C printf ensures that the libftprintf.a library is built before attempting to link it.
pid: The process ID of the receiver process
 kill: Sends a signal to a specified process
sigaction: If the signal handler was installed by a call to
NULL: When NULL is passed for oldact, it means that the caller is not interested in saving the old action for the signal.
 pause: Suspends execution until any signal is caught.
usleep(500) : This helps ensure that the receiver process has enough time to handle each signal.
                   
For example, if bit is 3, 0x01 << 3 results in 00001000.
The & operation with c isolates the bit at position bit.
If the isolated bit is non-zero (if condition is true), it means the bit is 1, so SIGUSR1 is sent.
If the isolated bit is zero (else), it means the bit is 0, so SIGUSR2 is sent.

bit = 0:
Compute the mask: 0x01 << 0 → 00000001
Binary representation of c (i.e., 01000001) 'A'
01000001 & 00000001 results in 00000001 (non-zero)
The result is non-zero, so SIGUSR1 is sent.

SIGUSR1 for 1 and SIGUSR2 for 0.

client.c :
responsible for sending a character (A) to a process using signals. The function uses the kill system call to send signals, and it converts the character to a series of bits, each represented by a signal.

For 'A' (binary: 01000001):
Bit 0 (rightmost, value 1): kill(pid, SIGUSR1);
Bit 1 (value 0): kill(pid, SIGUSR2);
Bit 2 (value 0): kill(pid, SIGUSR2);
Bit 3 (value 0): kill(pid, SIGUSR2);
Bit 4 (value 0): kill(pid, SIGUSR2);
Bit 5 (value 0): kill(pid, SIGUSR2);
Bit 6 (value 1): kill(pid, SIGUSR1);
Bit 7 (leftmost, value 0): kill(pid, SIGUSR2)

server:
handle signals and reconstruct a character

Send SIGUSR1 (0) → bit = 0.        i |= (0x01 << 0) → i = 00000001
Send SIGUSR2 (1) → bit = 1.     
Send SIGUSR2 (0) → bit = 2
Send SIGUSR2 (0) → bit = 3
Send SIGUSR2 (0) → bit = 4
Send SIGUSR2 (0) → bit = 5
Send SIGUSR1 (1) → bit = 6   i remains 2 i |= (0x01 << 6) → i = 65 (0100001)
Send SIGUSR2 (0) → bit = 7. i remains 01000001.
bit becomes 8 meaning has received all 8 bits for the character.

server_bonus
The server will print the received message, and when it receives the null terminator, it will send the SIGUSR2 signal back to the client:

client_bonus
 The client will wait for the confirmation signal (SIGUSR2). When the server sends the confirmation, the client will print

act.sa_sigaction : specifies ft_btoa as the function to handle signals.
Initialization of sa_mask: Ensures that no signals are blocked while the ft_btoa is running.

Options for sa_flags: Defines the signal handler's behavior with no special options.

siginfo_t : structure which contains information about the signal.

sigemptyset :  This function initializes the signal set pointed to by 
The sa_mask field indicates any signals that should be blocked while the signal handler is being executed. 

act.sa_flags = 0 :  will only receive the signal number, Features like SA_RESTART, SA_SIGINFO, and others are not enabled.

nb :
Each byte of the message is sent as 8 signals,
si_pid : Sending process ID

sigaction(SIGUSR1, &act, NULL);
sigaction(SIGUSR2, &act, NULL);
This tells the system to use ft_btoa to handle SIGUSR1 and SIGUSR2 signals.


https://man7.org/linux/man-pages/man7/signal.7.html
https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24
