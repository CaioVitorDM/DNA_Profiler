#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::vector;
#include <string.h>

#include "perfil.h" 
#include "functions.h"

using namespace std;


int main(int argc, char *argv[]){

//association of the files names to their respective variables.
string filename_csv = argv[2];
string filename_txt = argv[4];



//Inital print section of the program.
cout << "\033[1;37m===================================================\033[0m" << endl;
cout << "\033[1;37m     Welcome to the basic DNA profiler, v1.0\033[0m" << endl;
cout << "\033[1;37m     Copyright (C) 2022, Caio Vitor Dantas M.\033[0m" << endl;
cout << "\033[1;37m===================================================\033[0m" << endl;


cout << endl;

cout << "\033[1;36mThis program loads a DNA database and an unknown\033[0m" << endl;
cout << "\033[1;36mDNA  sequence and tries to  find a match between\033[0m" << endl;
cout << "\033[1;36mthe input DNA sequence and the DNA database.\033[0m" << endl;

cout << endl;

//prints the message of what the program is doing
cout << "\033[1;37m[+] Preparing to read the DNA Database file [\033[0m" << "\033[4;31m" << filename_csv << "\033[0m" << "\33[1;37m]\33[0m" <<endl;

//Opening and validation of the csv file, the database.

ifstream dna_database;
ifstream unknown_dna;
vector<string> vector;
string dna_sequence;

if(strcmp(argv[1], "-d") == 0){
	dna_database.open(filename_csv);
	if(!dna_database.is_open()){
		cout << endl;
		cout << "\033[1;37m===================================================\033[0m" << endl;
		cerr << "\033[1;31mCouldn't open file: \033[0m" << "\033[4;31m" << filename_csv << "\033[0m" << endl;
		cout << "\033[1;37m===================================================\033[0m" << endl;
		cout << endl;
		exit(EXIT_FAILURE);
	}
	else{
		//does the loop until the files end.
		while(dna_database.peek()!=EOF){
			string aux;
			getline(dna_database, aux, ',');
			vector.push_back(aux);
			//puts the values of the file in the vector.
		}
	}

}

dna_database.close(); //closes the .csv file.





//prints the second message of what is happening in the program
cout << "\033[1;37m[+] Preparing to read the unknown DNA sequence file [\033[0m" << "\033[4;31m" << filename_txt << "\033[0m" << "\33[1;37m]\33[0m" <<endl;

//Opening and validation of the text file, the sequence.
if(strcmp(argv[3], "-s") == 0){
	unknown_dna.open(filename_txt);
	if(!unknown_dna.is_open()){
		cout << endl;
		cout << "\033[1;37m===================================================\033[0m" << endl;
		cerr << "\033[1;31mCouldn't open file: \033[0m" << "\033[4;31m" << filename_txt << "\033[0m" << endl;
		cout << "\033[1;37m===================================================\033[0m" << endl;
		cout << endl;
		exit(EXIT_FAILURE);
	}
	else{
		// get the DNA sequence from the file and put it in the string dna_sequence;
		getline(unknown_dna, dna_sequence, '\n');
	}
}

unknown_dna.close(); //closes the .txt file.




//Prints the message to tell the user the archives are being processed.
cout << "\033[1;37m[+] Processing data, please wait.\033[0m" <<endl;
cout << endl;
	
	//creates the profiles with the csv file elements.
	Perfil p1(vector[1], vector[2], vector[3], vector[4], stoi(vector[5]), stoi(vector[6]), stoi(vector[7]));
	Perfil p2(vector[1], vector[2], vector[3], vector[8], stoi(vector[9]), stoi(vector[10]), stoi(vector[11]));
	Perfil p3(vector[1], vector[2], vector[3], vector[12], stoi(vector[13]), stoi(vector[14]), stoi(vector[15]));


//Prints the message if both archives were opened succefully.
cout << "\033[1;37m[+] Input files succefully read.\033[0m" <<endl;

//Prints the massage that the program is searching for a match.
cout << "\033[1;37m[+] Searching the database for a match... please wait.\033[0m" <<endl;

//Prints the DNA sequence.
cout << "\033[1;37m[+] DNA sequence: \033[0m" << endl << "\033[4;37m" << dna_sequence << "\033[0m" << endl;
cout << endl;


Perfil desconhecido(vector[1], vector[2], vector[3], strs_values(dna_sequence, vector[1]), strs_values(dna_sequence, vector[2]), strs_values(dna_sequence, vector[3]));

/*Checking if the profile generated from the sequence matches 
any profile from the database. If it does, prints the match 
profile. If it doesn't, prints the error message. To do that,
it was used operator overlay.*/
if(desconhecido == p1){
		cout << "\033[1;37mMatch ID(99,9%) : \033[0m";
		p1.print_profile();
	}
	else if(desconhecido == p2){
		cout << "\033[1;37mMatch ID(99,9%) : \033[0m";
		p2.print_profile();
	}
	else if(desconhecido == p3){
		cout << "\033[1;37mMatch ID(99,9%) : \033[0m";
		p3.print_profile();
	}
	else{
		cout << "\033[1;37m>>> Sorry, no match in our database.\033[0m" << endl;
	}

	//Cleaning the alocated vector.
	vector.clear();
}
