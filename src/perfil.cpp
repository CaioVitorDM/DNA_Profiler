#include <string>
using std::string;
#include <iostream>

#include "perfil.h"

using namespace std;


//Default constructor.
Perfil::Perfil(){
	name = "Desconhecido";
	strs[0] = "AGAT";
	strs[1] = "AATG";
	strs[2] = "TATC";
	quant[0] = 0;
	quant[1] = 0;
	quant[2] = 0;
}

//Parameterized constructor - get the STRs names, the person name and the STRs values.
Perfil::Perfil(string s1, string s2, string s3, string n, int x, int y, int z){
	name = n;
	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	quant[0] = x;
	quant[1] = y;
	quant[2] = z;
}

//Parameterized constructor when missing the name and the STRs values.
Perfil::Perfil(string s1, string s2, string s3){
	name = "Desconhecido";
	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	quant[0] = 0;
	quant[1] = 0;
	quant[2] = 0;
}


//Parameterized constructor when missing the name.
Perfil::Perfil(string s1, string s2, string s3, int x, int y, int z){
	name = "Desconhecido";
	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	quant[0] = x;
	quant[1] = y;
	quant[2] = z;
}

//Parameterized constructor when missing STRs values.
Perfil::Perfil(string s1, string s2, string s3, string n){
	name = n;
	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	quant[0] = 0;
	quant[1] = 0;
	quant[2] = 0;
}

//function to get the value of determined STR.
int Perfil::get_value(int x){
	return quant[x];
}

//Function to get any of the STR.
string Perfil::get_str(int x){
	return strs[x];
}

//Function to get the name.
string Perfil::get_name(){
	return name;
}

//Function to set the value of a STR.
void Perfil::set_value(int x, int y){
	quant[x] = y;
}

//Function to set a STR.
void Perfil::set_str(int x, string n){
	strs[x] = n;
}

//Function to set the name of the profile.
void Perfil::set_name(string n){
	name = n;
}



//Operator overload =
Perfil Perfil::operator= (Perfil &p){
	name = p.name;
	strs[0] = p.strs[0];
	strs[1] = p.strs[1];
	strs[2] = p.strs[2];
	quant[0] = p.quant[0];
	quant[1] = p.quant[1];
	quant[2] = p.quant[2];
	return Perfil(strs[0], strs[1], strs[2], name, quant[0], quant[1], quant[2]);
}

//Operator overload ==

bool Perfil::operator== (Perfil &p){
	if((strs[0] == p.strs[0]) && (strs[1] == p.strs[1]) && (strs[2] == p.strs[2]) && (quant[0] == p.quant[0]) && (quant[1] == p.quant[1]) && (quant[2] == p.quant[2])){
		return true;
	}
	else{return false;}
}



//Function to print the profiles.
void Perfil::print_profile(){
	cout << "\033[1;37m";
	cout << name << endl;
	cout << strs[0] << ": " << quant[0]<< endl;
	cout << strs[1] << ": " << quant[1] << endl;
	cout << strs[2] << ": " << quant[2]<< endl;
	cout << "\033[0m";
}
