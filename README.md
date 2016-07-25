# Message passing example for EPSP

This program demonstrates message passing using EBSP on the Parallella. Each of the 16 cores sends 10 messages to randomly selected cores, with each message consisting of a string of less than 64 characters. Once every core has sent its message, we synchronize and each core displays all the messages in its queue.

