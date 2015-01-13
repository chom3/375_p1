This program will take in an input of numbers line by line from a text file, and gives keys equal to the difference
between the other two keys in the array. The keys will be in an increasing order.
The resulting keys will be output into another textfile specified in the arguments of the line. 


In order to run:
./submission [INPUT TEXT FILE] [OUTPUT TEXT FILE]

The implemented algorithm incorporates two nested for loops and binary_search from the STL.
The time complexity for this algorithm is n*n*nlog(n) = n^3log(n).