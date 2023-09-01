#include <string>
#include "character.cpp"
#include <iostream>
#include <map>
//You may add additional typedefs, includes, etc. up here

//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};

//Feel free to put forward declarations here


int main(int argc, char** argv){
	// Argument parsing
	if(argc != 4){
		std::cerr << "Proper usage is " << argv[0] << " [database file] [input file] [output file]" << std::endl;
		return -1;
	}

	std::ifstream dbfile(argv[1]);
	if(!dbfile){
		std::cerr << "Failed to open database " << argv[1] << " for reading." << std::endl;
	}

	std::ifstream infile(argv[2]);
	if(!infile){
		std::cerr << "Failed to open input " << argv[2] << " for reading." << std::endl;
	}

	std::ofstream outfile(argv[3]);
	if(!outfile){
		std::cerr << "Failed to open output " << argv[3] << " for writing." << std::endl;
	}

	///////Fill in the rest of main below:

	//need a function to parse the data
	//gonna use maps to create a dataset to hold character names and objects of their class
	//ose overload operator to compare fighters.
	
	//here we open the database file to read the information
	std::string ch_name;
	dbfile >> ch_name >> move_names[1] >> move_names[2] >> move_names[3] >> move_names[4] >> move_names[5] >> move_names[6] >> move_names[7];

	
	int jab, f_tilt, u_tilt, d_tilt, f_smash, u_smash, d_smash;
	map<std::string, Character>characterobj; 

	while (dbfile >> ch_name >> jab >> f_tilt >> u_tilt >> d_tilt >> f_smash >> u_smash >> d_smash) {
		Character obj(ch_name, jab, f_tilt, u_tilt, d_tilt, f_smash, u_smash, d_smash);
		characetrobj[ch_name] = obj;
	}

	
	std::string argument,character, move;
	while (infile >> argument) { 
		if (argument == "-q") {
			infile>>character;
			if (characterobj.find(character) == characterobj.end()) { //if not in the list of characters also takes care of the case that both are invalid
				std::cerr<<"Invalid character name: "<< character <<std::endl;
				std::exit(1);
			}
			infile>>move;
			else if (move != move_name[1] || move != move_names[2] || move != move_names[3] || move != move_names[4] || 
					 move != move_names[5] || move != move_names[6] || move != move_names[7] || move != "all") { 							//if not in the list of moves
			
				std::cerr<<"Invalid move name: " << move << std::endl;
				std::exit(1);
			}
			//now we do the operations




		}
		else if (argument == "-f") {
			infile>>move;			
			if (move != move_name[1] || move != move_names[2] || move != move_names[3] || move != move_names[4] || 
				move != move_names[5] || move != move_names[6] || move != move_names[7]) { 							//if not in the list of moves
			
				std::cerr<<"Invalid move name: " << move << std::endl;
				std::exit(1);
			}
			int limit;
			infile>>limit;
		}
		else if (argument == "-s") {
			infile>>move;
			if (move != move_name[1] || move != move_names[2] || move != move_names[3] || move != move_names[4] || 
				move != move_names[5] || move != move_names[6] || move != move_names[7]) { 							//if not in the list of moves
			
				std::cerr<<"Invalid move name: " << move << std::endl;
				std::exit(1);
			}
			int limit;
			infile>>limit;
		}
		else if (argument == "-d") {
			infile>>move;
			if (move != move_name[1] || move != move_names[2] || move != move_names[3] || move != move_names[4] || 
				move != move_names[5] || move != move_names[6] || move != move_names[7]) { 							//if not in the list of moves
			
				std::cerr<<"Invalid move name: " << move << std::endl;
				std::exit(1);
			}
			int startup_frame;
			infile>>startup_frame;
		}
		else {
			std::cerr<<"Invalid query given"<<std::endl;
			std::exit(1);
		}

	}









	return 0;
}
