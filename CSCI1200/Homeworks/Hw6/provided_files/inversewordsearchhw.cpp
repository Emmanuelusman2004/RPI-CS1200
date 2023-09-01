#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "linkedlist.hpp"

/*
Used for the first set of checks for an excluded word after all included words have been added.
Goes through the entire grid, and checks every possible location/rotation that a word could be.
Only checks East, South, Southeast, and Southwest, but this is fine because it checks both
forwards and reverse simultaneously in each location, so it checks every possible direction.
returns true if the word is in the grid, false if it is not.
*/
bool is_word_in_check1(unsigned int width, unsigned int height, const std::string& Grid, const std::string& word) {
	unsigned int word_size = word.size();
	if(height == 0) {
		return false;
	}

	if(word_size > height && word_size > width) {
		return false;
	}

	bool is_for = false;
	bool is_rev = false;
	bool is_dir_for;
	bool is_dir_rev;
	
	for(unsigned int i = 0; i < height; i++) {
		for(unsigned int j = 0; j < width; j++) {
			if((height-i >= word_size || width-j >= word_size) && ((is_for = (Grid[i*width+j] == word[0])) || (is_rev = (Grid[i*width+j] == word[word_size-1])))) {
				if(word_size == 1) {
					return true;
				}
				if(is_for) {
					is_rev = (Grid[i*width+j] == word[word_size-1]);
				}
				//E
				if(j < width-1 && ((is_dir_for = (is_for && Grid[i*width+j+1] == word[1])) || ( is_dir_rev = (is_rev && Grid[i*width+j+1] == word[word_size-2]))) && width-j >= word_size) {
					if(is_dir_for) {
						is_dir_rev = is_rev && (Grid[i*width+j+1] == word[word_size-2]);
					}

					for(unsigned int k = 2; k < word_size; ++k) {
						if(Grid[i*width+j+k] != word[k]) {
							is_dir_for = false;
						}
						if(Grid[i*width+j+k] != word[word_size-k-1]) {
							is_dir_rev = false;
						}
					}
					if(is_dir_for || is_dir_rev) { 
						return true;
					}
				}
				//S
				if(i < height-1 && ((is_dir_for = (is_for && Grid[(i+1)*width+j] == word[1])) || ( is_dir_rev = (is_rev && Grid[(i+1)*width+j] == word[word_size-2]))) && height-i >= word_size) {
					if(is_dir_for) is_dir_rev = is_rev && (Grid[(i+1)*width+j] == word[word_size-2]);
					for(unsigned int k = 2; k < word_size; ++k) {
						if(Grid[(i+k)*width+j] != word[k]) {
							is_dir_for = false;
						}
						if(Grid[(i+k)*width+j] != word[word_size-k-1]) {
							is_dir_rev = false;
						}
					}
					if(is_dir_for || is_dir_rev) {
						return true;
					}
				}
				//SE
				if(j < width-1 && i < height-1 && ((is_dir_for = (is_for && Grid[(i+1)*width+j+1] == word[1])) || ( is_dir_rev = (is_rev && Grid[(i+1)*width+j+1] == word[word_size-2]))) && width-j >= word_size && height-i >= word_size) {
					if(is_dir_for) is_dir_rev = is_rev && (Grid[(i+1)*width+j+1] == word[word_size-2]);
					for(unsigned int k = 2; k < word_size; ++k) {
						if(Grid[(i+k)*width+j+k] != word[k]) {
							is_dir_for = false;
						}
						if(Grid[(i+k)*width+j+k] != word[word_size-k-1]) {
							is_dir_rev = false;
						}
					}
					if(is_dir_for || is_dir_rev) { 
						return true;
					}
				}
				//SW
				if(j > 0 && i < height-1 && ((is_dir_for = (is_for && Grid[(i+1)*width+j-1] == word[1])) || ( is_dir_rev = (is_rev && Grid[(i+1)*width+j-1] == word[word_size-2]))) && j >= word_size-1 && height-i >= word_size) {
					if(is_dir_for) is_dir_rev = is_rev && (Grid[(i+1)*width+j-1] == word[word_size-2]);
					for(unsigned int k = 2; k < word_size; ++k) {
						if(Grid[(i+k)*width+j-k] != word[k]) {
							is_dir_for = false;
						}
						if(Grid[(i+k)*width+j-k] != word[word_size-k-1]) {
							is_dir_rev = false;
						}
					}
					if(is_dir_for || is_dir_rev) { 
						return true;
					}
				}
			}
		}
	}
	return false;
}

/* 
Used after adding a single letter when filling the grid. Because only one letter is being added,
only the positions around that letter need to be checked. let_loc is the location of the letter
in the grid, and every direction and postion that includes that location is checked.
is_word_in_check1 would give the same result, but using this function takes less time, as less
positions in the grid need to be checked.
 */
bool is_word_in_check2(unsigned int width, unsigned int height, const std::string& Grid_str, const std::string& word, unsigned int let_loc) {
	unsigned int word_size = word.size();
	if(height == 0) {
		return false;
	}
	if(word_size > height && word_size > width) { 
		return false;
	}
	unsigned int loc_i = let_loc / width;
	unsigned int loc_j = let_loc % width;
	bool is_for;
	bool is_rev;
	unsigned int ind;
	for(unsigned int i = 0; i < word_size; i++) {
		//E
		ind = loc_i*width+loc_j+1-word_size+i;
		if(loc_j+1+i >= word_size && loc_j+i < width && ((is_for = (Grid_str[ind] == word[0])) || (is_rev = (Grid_str[ind] == word[word_size-1])))) {
			if(is_for) {
				is_rev = Grid_str[ind] == word[word_size-1];
			}
			for(unsigned int k = 1; k < word_size; k++) {
				if(Grid_str[ind+k] != word[k]) {
					is_for = false;
				}
				if(Grid_str[ind+k] != word[word_size-k-1]) {
					is_rev = false;
				}
			}
			if(is_for || is_rev) {
				return true; 
			}
		}
		//S
		ind = (loc_i+1-word_size+i)*width+loc_j;
		if(loc_i+1+i >= word_size && loc_i+i < height && ((is_for = (Grid_str[ind] == word[0])) || (is_rev = (Grid_str[ind] == word[word_size-1]))) ) {
			if(is_for) {
				is_rev = Grid_str[ind] == word[word_size-1];
			}
			for(unsigned int k = 1; k < word_size; k++) {
				if(Grid_str[ind+k*width] != word[k]) {
					is_for = false;
				}
				if(Grid_str[ind+k*width] != word[word_size-k-1]) {
					is_rev = false;
				}
			}
			if(is_for || is_rev) {
				return true;
			}
		}
		//SE
		ind = (loc_i+1-word_size+i)*width+loc_j+1-word_size+i;
		if(loc_j+1+i >= word_size && loc_j+i < width && loc_i+1+i >= word_size && loc_i+i < height && ((is_for = (Grid_str[ind] == word[0])) || (is_rev = (Grid_str[ind] == word[word_size-1])))) {
			if(is_for) {
			is_rev = Grid_str[ind] == word[word_size-1];
			}
			for(unsigned int k = 1; k < word_size; k++) {
				if(Grid_str[ind+k*(width+1)] != word[k]) {
					is_for = false;
				}
				if(Grid_str[ind+k*(width+1)] != word[word_size-k-1]) {
					is_rev = false;
				}
			}
			if(is_for || is_rev) {
				return true;
			}
		}
		//SW
		ind = (loc_i+1-word_size+i)*width+loc_j+word_size-1-i;
		if(loc_j+word_size-1 < width+i && loc_j >= i && loc_i+1+i >= word_size && loc_i+i < height && ((is_for = (Grid_str[ind] == word[0])) || (is_rev = (Grid_str[ind] == word[word_size-1])))) {
			if(is_for) { 
				is_rev = Grid_str[ind] == word[word_size-1];
			}
			for(unsigned int k = 1; k < word_size; k++) {
				if(Grid_str[ind+k*(width-1)] != word[k]) {
					is_for = false;
				}
				if(Grid_str[ind+k*(width-1)] != word[word_size-k-1]) {
					is_rev = false;
				}
			}
			if(is_for || is_rev) {
				return true;
			}
		}
	}
	return false;
}


// Reverses each line of the grid to flip it horizontally. O(w*h)
void flip_grid_hor(unsigned int width, unsigned int height, std::string& Grid_str) {
	for(unsigned int i = 0; i < height; i++) {
		std::reverse(Grid_str.begin()+i*width, Grid_str.begin()+(i+1)*width);
	}
}

// Reverses the entire grid, flipping it horizontally and vertically. O(w*h)
void flip_grid_hor_ver(unsigned int width, unsigned int height, std::string& Grid_str) {
	std::reverse(Grid_str.begin(), Grid_str.end());
}


/*
Swaps letters across the diagonal (think matrix transpose).
Is equivalent to rotating grid 90 degrees anticlockwise, then flipping it vertically.
*/
void flip_grid_sqr(unsigned int length, std::string& Grid_str) {
	for(unsigned int i = 0; i < length; i++) {
		for(unsigned int j = i+1; j < length; j++) {
			std::iter_swap(Grid_str.begin()+i*length+j, Grid_str.begin()+j*length+i);
		}
	}
}

// Returns a boolean indicating whether or not the grid is symmetrical horizontally.
bool is_grid_sym_hor(unsigned int width, unsigned int height, const std::string& Grid_str) {
	for(unsigned int i = 0; i < width; i++) {
		for(unsigned int j = 0; j < height/2; j++) {
			if(Grid_str[j*width+i] != Grid_str[(height-j-1)*width+i]) {
				return false;
			}
		}
	}
	return true;
}

// Returns a boolean indicating whether or not the grid is symmetrical vertically.
bool is_grid_sym_ver(unsigned int width, unsigned int height, const std::string& Grid_str) {
	for(unsigned int i = 0; i < height; i++) {
		for(unsigned int j = 0; j < width/2; j++) {
			if(Grid_str[i*width+j] != Grid_str[i*width+width-j-1]) {
				return false;
			}
		}
	}
	return true;
}

/*
Looks for the first empty ('0') character in the grid and fills it with a valid letter.
Then, it checks if the grid has any excluded words in it using is_word_in_check2. If there are
no excluded words, it recursively calls itself. Once every letter has been tried, the character
is set back to empty and the function is returned, as the recursive calls have already dealt
with each of the empty characters following it. If there are no empty characters, then the grid
is inserted into the Grids solution set, as it must be a valid solution. Then, if the grid is
not already in the set, its horizontal and/or vertical flips are also inserted into Grids, and
then if the grid is square, a 90 degree rotations and each of its horizontal and/or vertical
flips are also inserted into Grids, as they are also valid solutions.
*/
void check_exclude_fill(unsigned int width, unsigned int height, std::string& Grid_str,
							    std::vector<std::string>& Grids, Node* exclude_node,
							    bool& find_all, unsigned int i_0) {
	if(!find_all && Grids.size() > 0) { 
		return;
	}
	bool is_valid;
	unsigned int grid_size = height*width;
	for(unsigned int i = i_0; i < grid_size; i++) {
		if(Grid_str[i] == '0') {
			for(char c = 'a'; c <= 'z'; c++) {
				Grid_str[i] = c;
				is_valid = true;
				for(Node* exclude_node_it = exclude_node; exclude_node_it; exclude_node_it = exclude_node_it->next) {
					if(exclude_node_it->value.find(c) != std::string::npos && is_word_in_check2(width, height, Grid_str, exclude_node_it->value, i)) {
						is_valid = false;
						break;
					}
				}
				if(is_valid) {
					check_exclude_fill(width, height, Grid_str, Grids, exclude_node, find_all, i); 
				}
			}
			Grid_str[i] = '0';
			return;
		}
	}
	unsigned int grids_size = Grids.size();
	Grids.push_back(Grid_str);
	if(!find_all || Grids.size() == grids_size) return;
	flip_grid_hor(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor_ver(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor_ver(width, height, Grid_str);
	if(height != width) return;		
	flip_grid_sqr(width, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor_ver(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor(width, height, Grid_str);
	Grids.push_back(Grid_str);
	flip_grid_hor(width, height, Grid_str);
	flip_grid_sqr(width, Grid_str);
}


/*
If there are no words left to be included, a check is done for excluded words using
is_word_in_check1, then check_exclude_fill is called.
If there are still words to be included, checks are done throughout the grid to determine each
possible location that the word could be inserted. If there is symmetry in the grid before a
word is inserted, then only one half of the grid is checked, and the solutions that would be
missed are accounted for in check_exclude_fill by putting horizontal and/or vertical
flips into the solution set. This leads to many fewer recursive calls, and the cost is minimal.
Included words are inserted into the grid horizontally, vertically, and diagonally, and once a
word is inserted in a valid location, a recursive call is made using the next Node in the linked
list of included words and the updated symmetry of the grid.
*/
void inv_word_search(unsigned int width, unsigned int height,
					 const std::string& Grid_str,
					 std::vector<std::string>& Grids,
					 Node* include_node, Node* exclude_node,
					 bool is_sym_hor, bool is_sym_ver, bool& find_all)
{
	if(!find_all && Grids.size() > 0) return;
	if(!include_node) {
		for(Node* exclude_node_it = exclude_node; exclude_node_it; exclude_node_it = exclude_node_it->next) 
			if(is_word_in_check1(width, height, Grid_str, exclude_node_it->value)) {
				return;
			}
		std::string Grid_str_copy(Grid_str);
		check_exclude_fill(width, height, Grid_str_copy, Grids, exclude_node, find_all, 0);
		return;
	}
	bool is_space_for;
	bool is_space_rev;
	bool is_space_for_up;
	bool is_space_rev_up;
	std::string word = include_node->value;
	unsigned int word_size = word.size();
	// Whether or not the word is a palindrome is computed.
	bool is_palindrome = true;
	for(unsigned int i = 0; i < word_size/2; i++)
		if(word[i] != word[word_size-i-1]) 
			is_palindrome = false;
	// Checks that the word is small enough to fit in the grid horizontally.
	if(width >= word_size) {
		unsigned int new_height = height*(2-is_sym_hor)/2+is_sym_hor*height%2;
		unsigned int new_width = (width - word_size+ 1)/(1+(is_sym_ver && is_palindrome))+(is_sym_ver && is_palindrome)*width%2;
		for(unsigned int i = 0; i < new_height; i++) {
			for(unsigned int j = 0; j < new_width; j++) {
				is_space_for = true;
				is_space_rev = (word_size > 1 && !is_sym_hor) || (!is_sym_ver && !is_palindrome);
				for(unsigned int k = 0; k < word_size; k++) {
					if(Grid_str[i*width+j+k] != word[k] && Grid_str[i*width+j+k] != '0')
						is_space_for = false;
					if(is_space_rev && Grid_str[i*width+width-j-k-1] != word[k] && Grid_str[i*width+width-j-k-1] != '0')
						is_space_rev = false;
					if(!(is_space_for || is_space_rev)) break;
				}
				if(is_space_for || is_space_rev) {
					if(is_space_for) {
						std::string Grid_str_copy(Grid_str);
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[i*width+j+k] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, (is_sym_hor && i == height/2 && height%2 == 1) 
						|| is_grid_sym_hor(width, height, Grid_str_copy), (is_sym_ver && is_palindrome && 2*j == width - word_size) 
						|| is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
					if(is_space_rev) {
						std::string Grid_str_copy(Grid_str);
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[i*width+width-j-k-1] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, is_grid_sym_hor(width, height, Grid_str_copy),
						 is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
				}
			}
		}
	}
/* 
Checks that the word is small enough to fit in the grid vertically, that the word has length
greater than 1 (because inserting a word of length 1 vertically is equivalent to doing so
horizontally), if the grid is square, that it is neither symmetrical horizontally nor
vertically (the 90 degree rotation done in check_exclude_fill will acocunt for these
solutions), and if only one solution is being found, that no solution has been found yet. 
*/
	if(height >= word_size && word_size > 1 && (!is_sym_hor || !is_sym_ver || height != width) && (find_all || Grids.size() == 0)) {
		unsigned int new_width = width*(2-is_sym_ver)/2+is_sym_ver*width%2;
		unsigned int new_height = (height - word_size + 1)/(1+(is_sym_hor && is_palindrome))+(is_sym_hor && is_palindrome)*height%2;
		for(unsigned int i = 0; i < new_width; i++) {
			for(unsigned int j = 0; j < new_height; j++) {
				is_space_for = true;
				is_space_rev = !is_sym_ver || (!is_sym_hor && !is_palindrome);
				for(unsigned int k = 0; k < word_size; k++) {
					if(Grid_str[(j+k)*width+i] != word[k] && Grid_str[(j+k)*width+i] != '0')
						is_space_for = false;
					if(is_space_rev && Grid_str[(height-j-k-1)*width+i] != word[k] && Grid_str[(height-j-k-1)*width+i] != '0')
						is_space_rev = false;
					if(!(is_space_for || is_space_rev)) break;
				}
				if(is_space_for || is_space_rev) {
					std::string Grid_str_copy(Grid_str);
					if(is_space_for) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(j+k)*width+i] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						(is_sym_hor && is_palindrome && 2*j == height - word_size) || is_grid_sym_hor(width, height, Grid_str_copy), 
						(is_sym_ver && i == width/2 && width%2 == 1) || is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
					if(is_space_rev) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(height-j-k-1)*width+i] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						is_grid_sym_hor(width, height, Grid_str_copy), is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
				}
			}
		}
	}
	// Checks that the word is small enough to be put into the grid diagonally, that the word has
	// length greater than 1, and if only one solution, that none have been found yet.
	if(height >= word_size && width >= word_size && word_size > 1 && (find_all || Grids.size() == 0)) {
		for(unsigned int i = 0; i < height - word_size + 1; i++) {
			for(unsigned int j = 0; j < width - word_size + 1; j++) {
				
				is_space_for = true;
				is_space_rev = !is_sym_ver || (!is_sym_hor && !is_palindrome);
				is_space_for_up = !is_sym_hor || (!is_sym_ver && !is_palindrome);
				is_space_rev_up = !is_palindrome || is_space_rev || is_space_for_up;
				
				for(unsigned int k = 0; k < word_size; k++) {
					if(Grid_str[(i+k)*width+j+k] != word[k] && Grid_str[(i+k)*width+j+k] != '0')
						is_space_for = false;
					if(is_space_rev && Grid_str[(i+k)*width+width-j-k-1] != word[k] && Grid_str[(i+k)*width+width-j-k-1] != '0')
						is_space_rev = false;
					if(is_space_for_up && Grid_str[(height-i-k-1)*width+j+k] != word[k] && Grid_str[(height-i-k-1)*width+j+k] != '0')
						is_space_for_up = false;
					if(is_space_rev_up && Grid_str[(height-i-k-1)*width+width-j-k-1] != word[k] && Grid_str[(height-i-k-1)*width+width-j-k-1] != '0')
						is_space_rev_up = false;
					if(!(is_space_for || is_space_rev || is_space_for_up || is_space_rev_up)) break;
				}

				if(is_space_for || is_space_rev || is_space_for_up || is_space_rev_up) {
					std::string Grid_str_copy(Grid_str);
					if(is_space_for) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(i+k)*width+j+k] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						is_grid_sym_hor(width, height, Grid_str_copy), is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
					if(is_space_rev) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(i+k)*width+width-j-k-1] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						is_grid_sym_hor(width, height, Grid_str_copy), is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
					if(is_space_for_up) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(height-i-k-1)*width+j+k] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						is_grid_sym_hor(width, height, Grid_str_copy), is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
					if(is_space_rev_up) {
						for(unsigned int k = 0; k < word_size; k++)
							Grid_str_copy[(height-i-k-1)*width+width-j-k-1] = word[k];
						inv_word_search(width, height, Grid_str_copy, Grids, include_node->next, exclude_node, 
						is_grid_sym_hor(width, height, Grid_str_copy), is_grid_sym_ver(width, height, Grid_str_copy), find_all);
					}
				}
			}
		}
	}
	return;
}


int main(int argc, char* argv[]) {
	if(argc < 4) {
		std::cerr << "Incorrect number of arguments" << std::endl;
	}

	std::ifstream file_in(argv[1]);
	if(!file_in) {
		std::cerr << "Input file not found" << std::endl;
	}

	std::ofstream file_out(argv[2]);
	std::string s_arg(argv[3]);
	bool find_all;

	if(s_arg == "all_solutions") {
		find_all = true;
	}

	else if(s_arg == "one_solution") {
		find_all = false;
	}

	else {
		std::cerr << "Unknown solution type provided"<< std::endl;
		return 3;
	}

	std::string cmd = "";
	unsigned int width = 0;
	unsigned int height = 0;
	Node* include_node = NULL;
	Node* include_node_head = NULL;
	Node* exclude_node = NULL;
	Node* exclude_node_head = NULL;
	Node* temp_node = NULL;
	std::vector<std::string> Grids;
	std::string included_letters = "";


	// Grid width and height input and their validity in confirmed.
	file_in >> width;
	file_in >> height;

	
/*
while loop reads in words from inout file. 
Included words are put into a linked list sorted from longest to shortest, because it will be more
efficient if we fill the board with larger words because this leaves less spaces leading to less recursive calls of inv_word_search.
Excluded words are put into a linked list sorted from shortest to longest, as the smaller words are not only more likely
to appear, but also take less time to check, leading to less time spent checking excluded
words. Linked lists are faster to iterate through also.
*/
	while(file_in >> cmd) {
		if(cmd == "+") {
			file_in >> cmd;

			if(!include_node_head || cmd.size() > include_node_head->value.size()) {
				include_node = new Node;
				include_node->value = cmd;
				include_node->next = include_node_head;
				include_node_head = include_node;
			}

			else {
				for(include_node = include_node_head; include_node; include_node = include_node->next) {
					if(!include_node->next || cmd.size() >= include_node->next->value.size()) {
						temp_node = include_node->next;
						include_node->next = new Node;
						include_node = include_node->next;
						include_node->value = cmd;
						include_node->next = temp_node;
						break;
					}
				}
			}
		}

		else if(cmd == "-") {
			file_in >> cmd;
			for(unsigned int i = 0; i < cmd.size(); i++) {
				if(cmd[i] < 'a' || cmd[i] > 'z') {
					std::cerr << "ONLY LOWERCASE LETTERS CAN BE IN EXCLUDED WORDS." << std::endl << cmd << " CONTAINS " 
					<< cmd[i] << ", AN INAVLID CHARACTER." << std::endl;
					delete include_node_head;
					delete exclude_node_head;
				}
			}

			if(cmd.size() <= width || cmd.size() <= height) {
				if(!exclude_node_head || cmd.size() <= exclude_node_head->value.size()) {
					exclude_node = new Node;
					exclude_node->value = cmd;
					exclude_node->next = exclude_node_head;
					exclude_node_head = exclude_node;
				}

				else {
					for(exclude_node = exclude_node_head; exclude_node; exclude_node = exclude_node->next) {
						if(!exclude_node->next || cmd.size() < exclude_node->next->value.size()) {
							temp_node = exclude_node->next;
							exclude_node->next = new Node;
							exclude_node = exclude_node->next;
							exclude_node->value = cmd;
							exclude_node->next = temp_node;
							break;
						}
					}
				}
			}
		}
	}

 	
 	// Creates an "empty" (filled with 0s) grid to pass to the recursive function, but
 	// first checks that there is enough area in the grid for every included letter.
	std::string Grid_str(width*height, '0');
	if(width*height >= included_letters.size()) {
		inv_word_search(width, height, Grid_str, Grids, include_node_head, exclude_node_head, true, true, find_all);
	}

	// Prints out the results from the Grids unordered_set if there are any.
	if(Grids.size() > 0) {
		if(find_all) {
			file_out << Grids.size() << " Solution(s)" << std::endl;
		}

		for(std::vector<std::string>::iterator it = Grids.begin(); it != Grids.end(); ++it) {
			file_out << "Board: " << std::endl;
			for(unsigned int i = 0; i < height; ++i) {
				file_out << "  ";
				for(unsigned int j = 0; j < width; ++j) {
					file_out << (*it)[i*width+j];
				}
				file_out << std::endl;
			}
		}
	}
	else {
		file_out << "No solutions found :(" << std::endl;
	}

	delete include_node_head;
	delete exclude_node_head;
	
	return 0;
}