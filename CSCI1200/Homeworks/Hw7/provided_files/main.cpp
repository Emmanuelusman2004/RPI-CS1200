#include <string>
#include "Character.h"
//#include "Character.cpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>

//You may add additional typedefs, includes, etc. up here

//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};

//Feel free to put forward declarations here

std::set<std::pair<int, std::string>> orderbyframe(std::map<std::string, Character> &characterobj, std::string move) {
	std::set<std::pair<int, std::string>>framecharacter;
	for (std::map<std::string, Character>::iterator p = characterobj.begin(); p != characterobj.end(); p++) {
		std::pair<int, std::string>pair;
		pair.first = p->second.getFrame(move);
		pair.second = p->second.getName();
		framecharacter.insert(pair);
	}
	return framecharacter;
}








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
	//dbfile >> ch_name >> move_names[0] >> move_names[1] >> move_names[2] >> move_names[3] >> move_names[4] >> move_names[5] >> move_names[6];
	int i = 0;
	while (i != 8) {
		dbfile>>ch_name;
		i+=1;
	}
	std::string jab, f_tilt, u_tilt, d_tilt, f_smash, u_smash, d_smash;
	std::map<std::string, Character> characterobj; 

	while (dbfile >> ch_name >> jab >> f_tilt >> u_tilt >> d_tilt >> f_smash >> u_smash >> d_smash) {
		Character obj(ch_name, std::stoi(jab), std::stoi(f_tilt), std::stoi(u_tilt), std::stoi(d_tilt), std::stoi(f_smash), std::stoi(u_smash), std::stoi(d_smash));
		characterobj[ch_name] = obj;
	}

	
	std::string argument,character, move, fileoutput = "";
	while (infile >> argument) { 
		if (argument == "-q") {
			infile>>character;
			infile>>move;
			if (characterobj.find(character) == characterobj.end()) { //if not in the list of characters also takes care of the case that both are invalid
				fileoutput+= "Invalid character name: "+ character + "\n\n";
				continue;
				
			}
			else if (move != move_names[0] && move != move_names[1] && move != move_names[2] && move != move_names[3] && 
					 move != move_names[4] && move != move_names[5] && move != move_names[6] && move != "all") { 							
			
				if (fileoutput == "") {
					fileoutput+="Invalid move name: " + move + "\n\n";
				}
				else {
					fileoutput+="Invalid move name: " + move + "\n\n";
				}
				continue;
			
			}
			//now we do the operations

			

			if (move == "all") {
				std::set<std::string>moveframes;
				std::string moveframe = "";
				moveframe+=character+" jab: ";
				moveframe+=std::to_string(characterobj[character].getJab());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" forward-tilt: ";
				moveframe+=std::to_string(characterobj[character].getFtilt());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" up-tilt: ";
				moveframe+=std::to_string(characterobj[character].getUtilt());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" down-tilt: ";
				moveframe+=std::to_string(characterobj[character].getDtilt());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" forward-smash: ";
				moveframe+=std::to_string(characterobj[character].getFsmash());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" up-smash: ";
				moveframe+=std::to_string(characterobj[character].getUsmash());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				moveframe = "";
				moveframe+=character+" down-smash: ";
				moveframe+=std::to_string(characterobj[character].getDsmash());
				//std::cout<<moveframe<<std::endl;
				moveframes.insert(moveframe);
				

				
				//std::cout<<""<<std::endl;
				int count = 0;
				 for (std::set<std::string>::iterator p = moveframes.begin(); p != moveframes.end(); p++) {
				 	//std::cout<<*p<<std::endl;
					if (fileoutput == "") {
						fileoutput+=(*p);
	
					}
					else {
						if (count == 0) {
							fileoutput+= (*p);
							count +=1;
						}
						else {
							fileoutput+="\n" + (*p); 
						}
					}
				 }
				//std::cout<<""<<std::endl;


				fileoutput+="\n";
			}
			else {
				//here we do the coding to output the move
				std::string moveframe = "";
				moveframe+=character+" "+move + ": ";
				moveframe+=std::to_string(characterobj[character].getFrame(move));
				//std::cout<<moveframe<<std::endl;
				if (fileoutput == "") {
					fileoutput+=moveframe;
				}
				else {
					fileoutput+="\n" + moveframe;
				}

				fileoutput+="\n";
			}


		}
		else if (argument == "-f") { //limit number of fighters with fastest move
			infile>>move;
			int limit;
			infile>>limit;			
			if (move != move_names[0] && move != move_names[1] && move != move_names[2] && move != move_names[3] && 
				move != move_names[4] && move != move_names[5] && move != move_names[6]) { 							//if not in the list of moves
			
				if (fileoutput == "") {
					fileoutput+="\nInvalid move name: " + move + "\n\n";
				}
				else {
					fileoutput+="Invalid move name: " + move + "\n\n";
				}
				continue;
				
			}


			std::set<std::pair<int, std::string>> pairs = orderbyframe(characterobj, move);
			std::set<std::pair<int, std::string>>::iterator p = pairs.begin();
			if (fileoutput == "") {
			fileoutput+= argument + " " + move + " " + std::to_string(limit);
			}
			else {
				fileoutput+= "\n" + argument + " " + move + " " + std::to_string(limit);
			}			
			for (int i = 0; i < limit; i++) {
				//std::cout<<p->second<<std::endl;
				//std::cout<<p->first<<std::endl;
				fileoutput+="\n";
				fileoutput+=p->second;
				fileoutput+=" ";
				fileoutput+=std::to_string(p->first);
				p++;
			}
			//fileoutput+= "\n";









		}
		else if (argument == "-s") { //limit number of fighters with slowest moves
			infile>>move;
			int limit;
			infile>>limit;
			if (move != move_names[0] && move != move_names[1] && move != move_names[2] && move != move_names[3] && 
				move != move_names[4] && move != move_names[5] && move != move_names[6]) { 							//if not in the list of moves
			
				if (fileoutput == "") {
					fileoutput+="\nInvalid move name: " + move + "\n\n";
				}
				else {
					fileoutput+="Invalid move name: " + move + "\n\n";
				}
				continue;
			}
			if (fileoutput == "") {
				fileoutput+= argument + " " + move + " " + std::to_string(limit);

			}
			else {
				fileoutput+= "\n" + argument + " " + move + " " + std::to_string(limit);
			}
			std::set<std::pair<int, std::string>> pairs = orderbyframe(characterobj, move);
			std::set<std::pair<int, std::string>> newset;

			std::map<int, std::set<std::string>> framecharacter;
			for (std::set<std::pair<int, std::string>>::iterator p = pairs.begin(); p != pairs.end(); p++) {
				if (framecharacter.find((p)->first) == framecharacter.end()) {
					// create new set with p->second and associate it with p->first
					framecharacter[p->first] = std::set<std::string>{p->second};
				} 
				else {
					// add p->second to the existing set associated with p->first
					framecharacter[p->first].insert(p->second);
				}
			}

			// for (std::map<int,std::set<std::string>>::reverse_iterator l = framecharacter.rbegin(); l != framecharacter.rend(); l++) {
			// 	for (std::set<std::string>::iterator m = (l)->second.begin(); m != (l)->second.end(); m++) {
			// 		std::cout<< *m + " "<<l->first<<std::endl;
			// 		fileoutput+= "\n" + *m + " " + std::to_string(l->first);
			// 	}
				
			// }
			int count = 0;
			for (std::map<int,std::set<std::string>>::reverse_iterator l = framecharacter.rbegin(); l != framecharacter.rend(); l++) {
			for (std::set<std::string>::iterator m = (l)->second.begin(); m != (l)->second.end(); m++) {
				if (count < limit) {
					//std::cout<< *m + " "<<l->first<<std::endl;
					fileoutput+= "\n" + *m + " " + std::to_string(l->first);
					count++; // increment the counter variable
				} else {
					break; // exit the loop once the limit is reached
				}
			}
		}

			



		fileoutput+= "\n";
		}
		else if (argument == "-d") { //number of limit fighters with same frame
			infile>>move;
			int startup_frame;
			infile>>startup_frame;
			if (move != move_names[0] && move != move_names[1] && move != move_names[2] && move != move_names[3] && 
				move != move_names[4] && move != move_names[5] && move != move_names[6]) { 							//if not in the list of moves
			
				if (fileoutput == "") {
					fileoutput+="\nInvalid move name: " + move + "\n\n";
				}
				else {
					fileoutput+="Invalid move name: " + move + "\n\n";
				}
				continue;
			}
			std::set<std::string>characterframes;
			for (std::map<std::string, Character>::iterator p = characterobj.begin(); p != characterobj.end(); p++) {
				if (p->second.getFrame(move) == startup_frame) {
					characterframes.insert(p->second.getName());
				}
			}
			if (fileoutput == "") {
				fileoutput+= argument + " " + move + " " + std::to_string(startup_frame);				 
			}
			else {
				fileoutput+= argument + " " + move + " " + std::to_string(startup_frame);
			}
			for (std::set<std::string>::iterator p = characterframes.begin(); p != characterframes.end(); p++) {
				//std::cout<<*p<<std::endl;
				fileoutput+="\n" + (*p);
				//std::cout<<""<<std::endl;
			}
			//fileoutput+="\n";
			//then we have to output it to the file...
			













		}
		else {
			std::cerr<<"Invalid query given"<<std::endl;
			std::exit(1);
		}
		fileoutput+="\n";
		

	}


	//std::cout<<"YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"<<std::endl;
	std::cout<<fileoutput<<std::endl;

	outfile<<fileoutput<<std::endl;




	return 0;
}
