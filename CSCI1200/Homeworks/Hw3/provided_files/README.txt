HOMEWORK 3: MATRIX CLASS


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< No collaborators / youtube,geeksforgeeks,lessons,w3schools >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 12 >



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

get = O(1)

set = O(n)

num_rows = O(1)

get_column = O(n^m)

operator<< = O(n^m)

quarter = O(n^m)

operator== = O(n^m)

operator!= = O(n^m)

swap_rows = O(n)

rref (provided in matrix_main.cpp) = O(n^n^m) not too sure if this is how id represent n^3



TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?

well my strategy for debugging was one I learned from my lab mentor Justin.
He taught me that whenever I have an error I dont know where it originates
I should just comment out my code and run in and then uncomment parts of it
until my code stops working. Then isolate that code and work through it slowly
without thinking about what I want it to do but what it is actually doing.
I would use valgrind everytime I ran and would pay attention to the heap summary.
I tested the corner cases by putting odd number of rows and columns matrixes
to make sure the quarter would work correctly. I also called functions
like get and set for rows out of the index/max size of the matrix.





EXTRA CREDIT: 
Indicate here if you implemented resize() for extra credit.  
Also document the order notation for your resize() function.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

Hey so my code I feel is not the best it can be but if I had more time heres how
I would attempt to improve it.

I would first try to use more of the member functions
instead of reusing code from other member functions. This would make it more efficient
and also make my code much more neater and less messy. 

I did get to finishing my quarter function but I for some reason my lower left and lower right quarters
would result in a memory error which I did not know how to resolve. I wanted to go
to office hours but I left campus at 5 to head home. My code is still there
and I hope you could look at it and see I tried my best to complete quarter.
The commented segment of quarter is what produced my memory error.

I also made sure each line of my code is >90 characters so please give me those points...

