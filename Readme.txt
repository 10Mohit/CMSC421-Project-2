This is the Part-2 of CMSC421-Project2.
There are in total 8 files:

bufferus.c -> this is the code file that was made in user space.
bufferus.h -> this the header file taken from the project document.
testbufferus.c -> this is the testing of the code in user space.
buffer.c -> this is the code for circular buffer in kernel space.
buffer.h -> this is the header file taken from the project document.
testbuffer.c -> this is the testing file for the code in kernel space.
Makefile -> Makefile for the circular buffer.


The implementation of the circular buffer is done by using Linked-list.

The operations performed are:

(1). Initialization-
	this call initializes the buffer of fixed-size=20. As it is a circular buffer, the last node is connected to the first node in a circular manner. Also, if there was a successful initialization of the buffer it returns 0, but if there was already a buffer present or any problem with initialization, it returns -1.


(2). Insertion-
	this call inserts the new data into the buffer from the rear end only if there is available space in the buffer. If the call was successful, it returns 0 or else returns -1.

(3). Printing-
	this call prints the buffer and returns 0 as a signal of success. However, if there was a failure, returns -1.

(4). Deletion-
	this call deletes the existing buffer(if it does exist). And frees all memory.


For every call, we check if the buffer is already initialized or not. 
This answer will be the factor determining the next operations., 
