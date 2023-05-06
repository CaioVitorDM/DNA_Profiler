#ifndef perfil_H
#define perfil_H
#include <string>
using std::string;


/*Creation of the class profile and the methods.
The class has 2 vector, one for STRs names and another for STRs values,
and also a string to store the name of the Profile being created.
*/

class Perfil{
	private:
		string name;
		int quant[3];
		string strs[3];
	public:
		Perfil();
		Perfil(string s1, string s2, string s3, string n, int x, int y, int z);
		Perfil(string s1, string s2, string s3, int x, int y, int z);
		Perfil(string s1, string s2, string s3, string n);
		Perfil(string s1, string s2, string s3);
		int get_value(int x);
		string get_str(int x);
		string get_name();
		void set_value(int x, int y);
		void set_str(int x, string n);
		void set_name(string n);
		Perfil operator= (Perfil &p);
		bool operator== (Perfil &p);
		void print_profile();

};

#endif
