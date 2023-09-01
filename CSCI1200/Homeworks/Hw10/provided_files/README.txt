HOMEWORK 9: DISTANCE FIELDS & FAST MARCHING METHOD


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< no collaborators / 10 minute alac session >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 10 >



NAIVE ALGORITHM:

Order Notation: o(h^2 * w^2)

Timing Experiment Data:

Naive Method: 
time ./main.out tiny_5x5.ppm out.ppm naive_method grey_bands

real    0m0.050s
user    0m0.008s
sys     0m0.001s

time ./main.out small_10x10.ppm out.ppm naive_method grey_bands

real    0m0.088s
user    0m0.009s
sys     0m0.001s

time ./main.out squiggle_30x30.ppm out.ppm naive_method grey_bands
real    0m0.047s
user    0m0.021s
sys     0m0.002s

time ./main.out lines_100x100.ppm out.ppm naive_method grey_bands

real    0m1.201s
user    0m1.151s
sys     0m0.001s

time ./main.out data_structures_300x300.ppm out.ppm naive_method grey_bands

real    0m40.101s
user    0m40.083s
sys     0m0.001s

Discussion:
the naive method goes through all of the pixels in the image.
For each pixel it scans the entire board to find the black pixels.
It is very inefficient because it has to iterate many times thorugh 
the whole board. It may work fine for these small images but with a
larger image it can take a while as seen in the times above



IMPROVED ALGORITHM:

Order Notation: o(h*w*p)

Timing Experiment Data:

time ./main.out tiny_5x5.ppm out.ppm improved_method grey_bands

real    0m0.012s
user    0m0.000s
sys     0m0.003s

time ./main.out small_10x10.ppm out.ppm improved_method grey_bands

real    0m0.012s
user    0m0.003s
sys     0m0.000s

time ./main.out lines_100x100.ppm out.ppm improved_method grey_band
s

real    0m0.042s
user    0m0.033s
sys     0m0.000s

time ./main.out data_structures_300x300.ppm out.ppm improved_method
 grey_bands

real    0m7.156s
user    0m7.140s
sys     0m0.000s



Discussion:
we stored all the black pixels in a vector of pairs. Then we calculated
the distance which reduces the amount of time we spend searching for the black pixels.
Since we have a vector of them all we have to do is iterate throguht the vector of pixels.
Because of this the notation becomes o(h*w*p). You can see how much it has been reduced in terms 
of running time. I was not able to test the largest case(1000x1000) but in the 300x300 image
its clear that it takes nearly a quarter of the time to execute.





FAST MARCHING METHOD (with a map):

Order Notation: same as naive

prediction with map if i implemented correctly: o(h*w*log(h*w))

Timing Experiment Data: same as naive 

prediction if I completed it:
would be much faster because now we have a map that we iterate through which is much easier
to search throguh compared to a regular vector.

Discussion: 
I wasnt able to get the fast marching method done so i used the same code as 
the naive method to maximize the number of points I could get. I'll explain 
my mediocre excuse as to why I couldnt do it... :(

I did try and predict how it would have worked out if I had a working attempt at it.



DISTANCE FIELD VISUALIZATIONS FOR EXTRA CREDIT:




FAST MARCHING METHOD (with a hash table) FOR EXTRA CREDIT:

Order Notation:

Timing Experiment Data:

Discussion:



MISC. COMMENTS TO GRADER:  
Optional, please be concise!

I was not able to finish the fast marching method with map. So, I used the naive
method and copied it into my fast marching method. I really am trying to maximize points
on this homework. I understand binary priority queues thanks to this homework but wasnt able
to implement it. I worked on the class though to the best of my ability by using the code in
the lecture(i think it was 21.2) where i took inspiration to get the percolate functions.

The reason I couldn't was because of my calc test which I had been studying for all week and
my part time job I was working to try and save up for my next semester's tuition payment. I had to start
the homework on wednesday afternoon after my lab which ended at 8pm which I had been working on since after my calc test.
Im really sorry and know I'm not supposed to be cheaping out the homework like this.

I hope you understand and can be lenient with my grade... :(





