HOMEWORK 2: HOCKEY CLASSES


NAME:  < Emmanuel Usman >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Johnny Sun, Satyam Patel, ALAC Mentors / used lecture slides, youtube for videos on how to use setprecision and left/right formatting and setw() >

Johnny sun: he was a previous student for data structures so he really helped me understand what happens when you initialize an object
and why i need a vector of objects if i wanted to use the classes

Satyam Patel: taught me how to use the sorting function

ALAC: They mainly helped me debug and showed me how to debug when i see an error i dont understand. They fixed alot of errors that I didnt know how to fix
	and im really thankful for them.

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 60+ >



DESCRIPTION OF 3RD STATISTIC:
Please be concise! (< 200 words)
What question you are trying to answer with your statistic? 
What data did you need to organize? 
What was interesting or challenging about the implementation of this statistic? 

I wanted to answer the simple question which is "Who is the best player" between all teams in an accurate way which takes into account the amount of games
played. In the other table it is sorted by whoever made the most goals and assists but here we only care about who made the most out
of the games they played. So we divided the amount of goals the player had by the amount of games they had played to see a statistic that is comparable 
no matter how many games your team actually got to play. We needed to get the amount of goals from the players which was already stored information thanks
to the players class and then get the amount of games their team played which we get by counting their wins losses and ties. After that we simply divide
the goals by losses to get the goals per game or how the NHL calls it, "Points per game(PPG)". I think the most interesting part was that some of the players
ranked at the top of the regular player stats list were not on the same positions as the rankings based on ppg which comes to show how ppg can show another
more objective way of viewing players where we only care about the players contribution to the amount of points which ultimately is all that matters at the end
of the game.




NAME OF FILE WITH SAMPLE OUTPUT FROM 3RD STATISTIC:
Be sure to select (or create) a dataset with interesting results


< hockey_custom_stats, file is included with submission >



MISC. COMMENTS TO GRADER:  


Hey, I just wanna start by saying that I know my program is really inefficient. I noticed how long it takes to compile and realized its because of how
many for loops i use to find objects locations. I didnt really know how else i could refer back to the class objects that were within the list so I hope
its fine that it runs really slowly. I still dont really know how to comment other than explaining my code or sections of the code. Last time I got points
deducted for having too much code so this time i limited it to explanations and no test cases so hopefully I get some forgiveness on the messyness of my code.

