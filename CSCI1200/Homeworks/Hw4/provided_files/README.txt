HOMEWORK 4: TOOL RENTAL LISTS


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Satyam Patel / Office Hours, ALAC >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 20 >



ORDER NOTATION:
Use these variables to analyze each phase of computation.  Briefly
justify your answer for each part.


i = # of different inventory items
c = # of different customers
p = # of pending customers
q = max quantity of a particular tool owned by the store
r = max # of tools rented or requested by a customer at one time
p = total # of pending tool rentals
e = # of rental or return events


Load inventory file: O(i) to load inventory file we would have to go through the # of different
inventory items and therefore the order notation would be O(i).

Rental event: O(c*i) For a rental event we need to iterate through the list of tools and the list of customers 
to perform the actions we are doing.

Return event - no pending customer(s): O(c*i) For a return event in my program it would be the same as a rental event for my program.
So we just iterate through the customers and then the tools class to add stuff to the list of pending customers within the class.

Return event - with pending customer(s): O(c*i*p^2) When we return an item we have to iterate through the list of customers then we need
to iterate through te inventory to find what they are returning and then iterate through the list of pending customers for that tool. Once we
find what we are looking for we remove that from the list.

Entire program: O(i^4*c^3*p) this would be the product of all the operations in my code and that why i think it would be this order notation.



MISC. COMMENTS TO GRADER:
(optional, please be concise!)


Hey, I know my code doesn't work and right now I'm just trying my best to maximize the amount of TA points I get. My first issue is that I did not know 
where to start with this code. There were alot of things to think about and I just rushed my code without thinking of how to connect all my pieces of code
together once I thought I was done. If I were to restart this code I would've just went through the file and completed the requests meaniwhile going through
 the input file however I did not do this and now my code doesnt work. I also should've worked slowly through the problem and tried to create more functions to make
my code more readable and correctible. The worst part is that out of all the time I spent on it 
ima get a big fat 0 because my code doesnt work. Please go easy on me...

test cases I wouldve tried if I could make my function work...
Also im not sure really how to make test cases in my code so I made them here.


edge cases:

test a case where people return multiple items at once
test a case where people try to rent an item while they have items already rented

test cases:

test renting
test renting multiple items
test returning an item
test returning multiple items
test returning multiple items but not all the items rented
test returning multiple items and having no more items rented
test renting items not available
test returning items that dont exist
test renting items that do not exist