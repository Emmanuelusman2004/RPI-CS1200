HOMEWORK 9: MINIBLAST


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / office hours, geeksforgeeks, lab, alac >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 10 >


HASH FUNCTION DESCRIPTION

My hashfunction is the one we used in our lab. I made the hashfunction a member function
of the hashtable class i created and called it hash() which would return the unsigned int 
index of where we should insert. it takes in the key(the item we want to hash) and finds the hash value
by doing hash % size(size of table). The hashfunction according to the website it came from (http://www.partow.net/programming/hashfunctions/ has a "on average time complexity of o(1).


HASH TABLE IMPLEMENTATION

My hashtable was implemented as a class with the table being a vector of pairs, the pairs would hold a string in the first position and another vector of ints in the second position. the first position would hold the k length kmer from genome and the second position is used to hold all the occurrences of that kmer within the genome(the indexes). My insert would take in a key and the index to pushback. In the comments you can see how it works specifically. I used linear probing with a while loop and would call resize after inserting which would first check if its necessary and then perform the resize.



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

L = length of the genome sequence
q - query length
p - number of different locations where key is found
k - key size (k-mer size)

How much memory will the hash table data structure require (order notation for memory use)?

since i used a string to store the whole genome it will require an O(L) memory usage. The key size is k, there are at most L-k unique keys. each key has p different locations. the table will take O(L-k) to store all the keys and then O((L-k)*p to save all the positions inside the vectors across the hashtable. So the hashtable i think requires O((L-k)*p) memory.


What is the order notation for performance (running time) of each of
the commands? What about for the hash table's insert, find, and resize?

GENOME: genome is just using the file so for me it was just O(L) since i saved it into a string.

table_size: for me it would require me to create a new table of the new size, it runs similar to resize. this is because for me I already initialized the table at the beginning of my main so when we take inputs, table_size runs to resize the table to the size preferred and not the default. so for me it runs in O((L-k)*p) because we have to go through all the table then hash everything and store it again which is basically creating a new table with the same values. It works even if I put table_size after creating the whole table. so that would be the worst case. 

occupancy: O(1) because i simply set the private member variable using the function setocc(int) to set the occupancy.

kmer: since we call insert O(L-k) times and the hashfunction works with O(1) time and the insert works in O(1) kmer works in O(L-k). however i think it may work in O((L-k)^2) since i insert O(L-k) times and worst case i have to probe through the entire table so it could be that.

query: i call query(querystr) which will call findpost() which iterates through the hashtable to find the position taking O(L-k) and the iterate through to find the comparison within the genome which is O(p*q) so query will take O(p*q) time after completing the other operations.


EXTRA CREDIT
Add a new command to implement the database using one of the other
 data structures that we have covered so far in the course: 
vectors, lists, arrays etc. 

Compare the performance your alternative method to the homework method
by making a table of run times for each of the genomes and query 
sets provided with the homework  and compare the times to build
the index and the times to process the queries. 
Document any new commands you have added in your README file.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

PLEASE LET ME SLIDE WITH SOME POINTS. I know I put alot of comments please dont take off points for the comments. PLEASE IM BEGGING YOUUU. Also lemme keep points for the length of lines PLEASEEEEEEEE.
