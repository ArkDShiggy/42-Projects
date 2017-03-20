The is a function that reads the next line of a file.
The code was supposed to be contained in no more than 5 functions of no more than 25 lines.
Because of this and because I also tried to handle the presence of '\0' in the file, the code looks very messy.
Also the function does handle the use of multiple file descriptors(fd) by storing the data for each fd in the node
of a linked list, however that data is not freed properly which can cause soe issues.

I later made another cleaner version (get_next_line2.c) that simply returns an error if it sees a '\0',
doesn't handle multiple file descriptorsand uses the "exit" function which was not authorised.
