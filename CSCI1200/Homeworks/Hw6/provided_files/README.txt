HOMEWORK 6: INVERSE WORD SEARCH


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES: 
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<  / Geeksforgeeks, cplusplus, ALAC, youtube >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.

ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 40+ >


ALGORITHM ANALYSIS:
What's the order notation of your algorithm?
Not too good with order notation but theres at most 4 loops within my inverse word search running at the same time so worst case scenario
O((n^4) times the number of recursive calls) and the number of recursive calls depends on the length of the grid and the height.
I will guess that my alg is O((((w*h)^4)*(w*h)). This looks horrible but thats what I think. In simpler terms i think my inv word search runs worst case O(n^4).


TEST CASE SUMMARY:
How did your program perform on the different test cases?  Summarize
the running times.  (It's ok if it didn't finish the harder examples.)
What new test cases did you create and how did it perform on those
tests?

Puzzle 1: 
all solutions: real    0m0.061s    
Puzzle 2: 
all solutions: real    0m0.049s
Puzzle 3:
all_solutions: real    0m0.095s
Puzzle 4:
all_solutions: real    0m0.075s
Puzzle 5:
all_solutions: real    0m0.390s
Puzzle 6:
all_solutions: real    0m0.757s
Puzzle 7:
all_solutions: real    0m0.084s
Puzzle 8:
all_solutions: real    0m0.116s

student test cases:

testcase1:
this just tests for an invalid file that just has the measurements, no words in it.

all_solutions: real    0m7.832s

testcase2:
testing a file that has no solutions (i think it has no solutions) and seeing what it outputs

all_solutions: real    0m0.052s

testcase3:
testing a large file to see if it runs even though theres no words only plusses and minuses.

all_solutions: real    0m0.044s




MISC. COMMENTS TO GRADER:  
Optional, please be concise!

I really tried hard on this hw over break. I'm really proud of the code I 
just hope I can finally get a good score on my hw. I also split up lines 
so that I wouldnt lose points for having too much code on one line
so please give me the points for the spacing. The comments explain what 
each segment of code does and the functions.
