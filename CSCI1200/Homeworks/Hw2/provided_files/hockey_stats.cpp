#include "team.h"
#include "player.h"

using namespace std;

/*
These functions below (teamfunction and playerfunction) make sure we do not reinitialize an object that has already been initialized
we do this by taking the teamnames (team 1&2) and the vector of team names and the Team objects (Teamsobjects) and then using the find
we make sure that it is not in the list of vectors. If it isnt we simply initialize the object. This is the same for team and playerfunction.
*/
void teamfunction(string team1, string team2, vector<string>v, vector<Team>& Teamsobjects) {
    string name1 = team1;
    string name2 = team2;
    if (std::find(v.begin(), v.end(), team1) != v.end()) { //basically saying its in there
    }
    else {
        //initialize the object for the first time
        Team teamobj1;
        teamobj1.setname(name1);
        Teamsobjects.push_back(teamobj1);
    }
    if (std::find(v.begin(), v.end(), team2) != v.end()) {
    }
    else {
        //initialize the things for the first time
        Team teamobj2;
        teamobj2.setname(name2);
        Teamsobjects.push_back(teamobj2); //we pushback to add that object to the vector of teamobjects (this is why we call by ref to make sure we actually add to the vector and not its copy)
    }
}

void playerfunction(string player1, vector<string> v, vector<Players>& Playerobjects) {
    string name = player1;
    if (std::find(v.begin(), v.end(), player1) != v.end()) { //basically saying its in there
    }
    else {
        //initialize the object for the first time
        Players player1;
        player1.setPname(name);
        Playerobjects.push_back(player1);
    }
    
}

void printingplayers(string filename,vector<Players>v) {
    std::ofstream outFile; //caution with filename type
    outFile.open(filename);
    outFile<<"Player Name            Team         Goals  Assists  Penalties"<<endl;
    for (std::size_t i = 0; i < v.size(); i+=1) {
        //because I initialized every player as a name with an underscore sometimes we have penalties with an underscore...
        // so we make sure we dont output a penalty violation as a player name by doint this piece of code(skipping an iteration)
        if (v[i].getPteam() == "") {
            continue;
        }
        /*
        below we have code that outputs to the main file. we use left and right as arguments for setf to left or right justify
        we also use width to set the width of the next outFile line. We make sure not to put endline in every line so that we
        still adding to the same player line
        */
        outFile.setf(ios :: left, ios::adjustfield); 
        outFile.width(23);
        outFile<<v[i].getPname();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(13);
        outFile<<v[i].getPteam();
        outFile.setf(ios :: right, ios::adjustfield);
        outFile.width(5);
        outFile<<v[i].getPgoal();
        outFile.setf(ios :: right, ios::adjustfield);
        outFile.width(9);
        outFile<<v[i].getPassists();
        outFile.setf(ios :: right, ios::adjustfield);
        outFile.width(11);
        outFile<<v[i].getPpenalties()<<endl;
    }
}
/*
This is the same as the playerprinting function above except we are printing differet items.
*/
void printingteams(string filename, vector<Team>v) {
    std::ofstream outFile; //caution with filename type
    outFile.open(filename);
    outFile<<"Team Name     W   L   T   Win%  Goals  Penalties"<<endl;
    for (std::size_t i = 0; i < v.size(); i+=1) {
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(14);
        outFile<<v[i].getname();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(4);
        outFile<<v[i].getWins();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(4);
        outFile<<v[i].getLosses();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(4);
        outFile<<v[i].getTies();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(4);
        outFile<< fixed <<setprecision(2);
        outFile<<v[i].getWratio();
        outFile.setf(ios :: right, ios::adjustfield);
        outFile.width(7);
        outFile<<v[i].getGoal();
        outFile.setf(ios :: right, ios::adjustfield);
        outFile.width(11);
        outFile<<v[i].getPenalties()<<endl;
    } 
}
void printingcustomstats(string filename, vector<Players>v) {
    std::ofstream outFile; //caution with filename type
    outFile.open(filename);
    outFile<<"Most Valuable Player: ";
    outFile<<v[0].getPname()<<endl;
    //we calculated this according the amount of points per game for the season"<<endl
    outFile<<"\n"<<endl;
    //Below are the statistics for the points per game for the rest of the season
    outFile<<"Player Name             PPG"<<endl;
    for (std::size_t i = 0; i < v.size(); i+=1) {
        if (v[i].getPteam() == "") {
            continue;
        }
        outFile.setf(ios :: left, ios::adjustfield);
        outFile.width(24);
        outFile<<v[i].getPname();
        outFile.setf(ios :: left, ios::adjustfield);
        outFile<< fixed <<setprecision(2);
        outFile<<v[i].getPPG()<<endl;

    }
}

int main(int argc, char* argv[]) { //this makes sure we can take the arguments that are part of our command in the terminal
    ifstream myFile;
    myFile.open(argv[1], ios::in);
    if (myFile.is_open()) 
    {
    string word;
    vector<string>list(0); //list with strings of each word in the file
    while (myFile >> word) {
        list.push_back(word); //put all words from file into vector so we can compare each line and word individually in order.
    }
    vector<string>players(0);
    vector<string>teams(0);
    vector<Team>Teamsobjects; //this vector holds objects locations in memory same with the one below it. It stores the initialized objects for each class
    vector<Players>Playersobjects;
    for (std::size_t i = 0; i < list.size(); i+=1) {
    /*
    in this block of code we are trying to initialize every player and team by iterating and finding every team in our list
    of words from the file and we are trying to find players the same way by finding the words which contain an underscore
    we call our functions above to make sure we are not reinitializing objects.
    */
        string elem = list[i];
         //this above is a shortcut i like to do instead of always refering to list[i], I like to call it 
         // elem like the piece we are looking at instead of a location we are looking at
        if (elem == "at") {
            string team1 = list[i-1];
            string team2 = list[i+1];
            teamfunction(team1,team2,teams,Teamsobjects);
            teams.push_back(team1);
            teams.push_back(team2);
        }
        else if (elem.find("_")<elem.length()) {
            playerfunction(elem, players, Playersobjects);
            players.push_back(elem);
        }
    }
    /*
    Now this function is trying to iterate throught the list of words to just add the information to the class objects (teams or players)
    since everything is initialized we no longer need to check and can just add goals and penalties to the objects.
    */
    
    for (std::size_t i = 0; i < list.size(); i+=1) {
        string elem = list[i];
        if (elem == "penalty") {          
            /*
            we iterate through the vector of words and when the elem(the word) is penalty we...
            1. look through the vector of objects for the vector which name matches the elem
            2. we add a penalty to that players object
            3. if object's team is not initialized or is default value ("") we simply find the elem before penalty (i-1) and set team name
            4. then we do another loop repeating steps 1 and 2 for that team
            */
            for (std::size_t j = 0; j < Playersobjects.size(); j+=1) {    
                if (list[i+1]==Playersobjects[j].getPname()) {
                    Playersobjects[j].addPpenalties();
                    if (Playersobjects[j].getPteam() == "") {
                        Playersobjects[j].setPteam(list[i-1]);
                    }
                }
            }
            for (std::size_t k = 0; k < Teamsobjects.size(); k+=1) {
                if (list[i-1]==Teamsobjects[k].getname()) {
                    Teamsobjects[k].addPenalties();
                }
            }

        }
        /*
        here we have the same logic as the previous we just find goal and then see the item before which is the team and then the item after is the scorer.
        we then try to add a goal to the player and if the player doesnt have a team we set a team for him like we did before(line 183)
        after that we do the same thing for the team and add goals to the team name.
        
        */
        else if (elem == "goal") {
            //for loop iterates throuhg vector of objects
            for (std::size_t j = 0; j < Playersobjects.size(); j+=1) {
                if (list[i+1]==Playersobjects[j].getPname()) {  //here we have the if statement trying to match the object with the name we are looking to add to
                    Playersobjects[j].addPgoal();
                    if (Playersobjects[j].getPteam() == "") { //if the player team is not initialized we do so
                        Playersobjects[j].setPteam(list[i-1]);
                    }
                }
            }
            for (std::size_t k = 0; k < Teamsobjects.size(); k+=1) { //here we iterate through the team vector of class objects looking for the team we want to add a goal to
                if (list[i-1]==Teamsobjects[k].getname()) {    
                    Teamsobjects[k].addGoal();
                }
            }
        }

        /*
        here we find out who to add assists to. first we find out whether within the parenthesis there are two players or one player that gave an assist.
        after that we simply get the elements for the player names then iterate through the vector of objects to see the matching player and team so we can add an assist to them and
        of course check if their team is initialized.
        */
        else if (elem == "(") {
            if (list[i+3] == ")") { //this part checks to see if the assist was done by two people ( <--i name1 <-- i+1 name2 <-- i+2 ) <--i+3
                for (std::size_t j = 0; j < Playersobjects.size(); j+=1) {
                if (list[i+1]==Playersobjects[j].getPname()) {
                    Playersobjects[j].addPassists();
                    if (Playersobjects[j].getPteam() == "") { //this makes sure we initialize the players team if not done already. Its like a backup
                        Playersobjects[j].setPteam(list[i-3]);
                    }
                    }
                }
                for (std::size_t j = 0; j < Playersobjects.size(); j+=1) {
                if (list[i+2]==Playersobjects[j].getPname()) { 
                    Playersobjects[j].addPassists();
                    if (Playersobjects[j].getPteam() == "") {
                        Playersobjects[j].setPteam(list[i-3]);
                    }
                    }
                }
            }
            else {
                for (std::size_t j = 0; j < Playersobjects.size(); j+=1) { 
                if (list[i+1]==Playersobjects[j].getPname()) {
                    Playersobjects[j].addPassists();
                    if (Playersobjects[j].getPteam() == "") {
                        Playersobjects[j].setPteam(list[i-3]);
                    }
                    }
                }
            }

            
        }
        /*
        Here we are iterating through the last contents of a game. since final is I we know that i+1 is gonna be the team, i+2 will be the score, i+3 will be the other team and i+4 will be the other
        teams score. We then compare and see which is greater. Afterwards we just iterate through the list of objects looking for the team that won and add a win and add a loss to the other team. If the scores are the same
        we just add a tie.
        */
        else if (elem == "FINAL") {
            string team1name = list[i+1];
            int team1score = stoi(list[i+2]);  //here we have to convert the string into a number so we can initialize it without issues
            string team2name = list[i+3];
            int team2score = stoi(list[i+4]);
            if (team1score > team2score) {
                for (std::size_t j = 0; j < Teamsobjects.size(); j+=1) {
                    if (team1name == Teamsobjects[j].getname()) {
                        Teamsobjects[j].addWins();
                    }
                }
                for (std::size_t k = 0; k < Teamsobjects.size(); k+=1) {
                    if (team2name == Teamsobjects[k].getname()) {
                        Teamsobjects[k].addLosses();
                    }
                }
            }
            else if (team1score < team2score) {
                for (std::size_t j = 0; j < Teamsobjects.size(); j+=1) {
                    if (team1name == Teamsobjects[j].getname()) {
                        Teamsobjects[j].addLosses();
                    }
                }
                for (std::size_t k = 0; k < Teamsobjects.size(); k+=1) {
                    if (team2name == Teamsobjects[k].getname()) {
                        Teamsobjects[k].addWins();
                    }
                }
            }
            else {
                for (std::size_t j = 0; j < Teamsobjects.size(); j+=1) {
                    if (team1name == Teamsobjects[j].getname()) {
                        Teamsobjects[j].addTies();
                    }
                }
                for (std::size_t k = 0; k < Teamsobjects.size(); k+=1) {
                    if (team2name == Teamsobjects[k].getname()) {
                        Teamsobjects[k].addTies();
                    }
                }
            }
        }
    /*
    Since we already calculated the wins, losses and ties we now have to calculate and set the win ratio for each team. So we calculate it by the given formula
    then we have to again find the location in memory which that object is using the loop and iterating through the vector of objects and then set the ratio using the method within my class.
    */    
    for (std::size_t i = 0; i < Teamsobjects.size(); i+=1) {
            if (Teamsobjects[i].getWins() != 0 && Teamsobjects[i].getLosses() != 0) {
            double wratio;
            wratio = (Teamsobjects[i].getWins() + 0.5*Teamsobjects[i].getTies())/((1.0*Teamsobjects[i].getWins())+(1.0*Teamsobjects[i].getLosses())+(1.0*Teamsobjects[i].getTies()));
            Teamsobjects[i].setWratio(wratio);
            }
        }
    }

    /*
    Here we sort the players and teams using a function which is defined in their classes.
    */
    sort(Teamsobjects.begin(),Teamsobjects.end(),compareteams);
    sort(Playersobjects.begin(),Playersobjects.end(),compareplayers);

    /*
    here we call the function which allows us to write to a file whatever we need. (player stats prints the formatted table stats and team creates the file with the team stats.)
    */
    if (string(argv[3]) == "--team_stats") {
    printingteams(std::string(argv[2]), Teamsobjects);
    }
    else if (string(argv[3]) == "--player_stats") {
    printingplayers(std::string(argv[2]),Playersobjects);
    }
    else if (string(argv[3]) == "--custom_stats") {
    /*
    here is the piece for custom stats. below we are finding the number of games. We use a loop to find out which team in the vector of team objects matches the players team so
    that we can get the total number of games. then we perform the calculation for the points per game. After that we sort based on who has the greatest amount of points per game 
    and call the function which writes everything onto the output file.
    */
        for (std::size_t i = 0; i < Playersobjects.size(); i+=1) {
            int games;
            for (std::size_t i = 0; i < Teamsobjects.size(); i+=1) {
                if (Playersobjects[i].getPteam() == Teamsobjects[i].getname()) {
                    games = ((Teamsobjects[i].getWins())+(Teamsobjects[i].getLosses())+(Teamsobjects[i].getTies()));
                }
            }
            float ppg = 1.0 * ((1.0 *Playersobjects[i].getPgoal())/(1.0*games));
            Playersobjects[i].setPPG(ppg);
            
        }
        sort(Playersobjects.begin(),Playersobjects.end(),compareppg);
        printingcustomstats(argv[2], Playersobjects);
    }
    }
}
