HOMEWORK 5: LINKED TRAIN CARS


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< office Hours, Mike(Lab TA), ALAC / Youtube, Geeksforgeeks, c++.com, lab 07 >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 10 >



DESCRIPTION OF IMPROVED SHIPFREIGHT ALGORITHM FOR EXTRA CREDIT 
Aiming for optimal (fastest train speed, most freight, fewest number
of engines used, and fewest resulting trains) for any input.  Note:
Student choice on how to prioritze between these goals.  Describe your
priorization and your implementation.



DESCRIPTION OF IMPROVED SEPARATE ALGORITHM FOR EXTRA CREDIT 
Aiming for optimally comfortable trains (smaller values for average
distance to dining and/or larger values for closest engine to sleeper)
and/or optimally handling cases with > 2 engines.  Student choice on how 
to prioritze between these goals.  Describe your priorization and your
implementation.


MISC. COMMENTS TO GRADER:  
Optional, please be concise!

Within my separate I have a commented section which shows my attempt at the
full proof alg. In there it did not work for some reason even though my the 
logic seemed correct. I could not end up fixing it in time.

My ship freight was not working because it adds one car too much. therefore I
decided to solve this problem by after adding the car we...

1. popping last element in newtrain and passing it to pushfront
2. pushfront back into all_freight to order it correctly
3. then we just put the train into the pointer and restart.

I think something was wrong with my pushfront or popback but I couldnt figure out what.

Im about to fail hw because i've been screwing up even though I try really hard,
pls let me slide a little. PLS IM BEGGING YOU. IF NOT ILL FAIL DS EVEN WITH A PERFECT LAB SCORE D:>

