#include <iostream>
#include <string>
#include "perfil.h"

using namespace std;

//Function to get the amount of a certain STR in the sequence.

/*This function works like a throne algorithm. We have the value
-1 stored in the variable "maior" and the variable cont that stores
the counting of the values and starts with 0. The function goes through all the string,
at first it starts at the first letter and checks if the first and the next three
letters match the ones in the STR passed as a parameter. If it does, it will
add 1 in the counter and jump 3 positions to go to the next four letters to be checked.
If it doesn't, it'll go to the else, check if the counter variable is greater than the maior
variable. If it is, maior will receive the value of the counter. The great thing here is that 
maior has the value -1, so even the function doesn't find any occurrence of the STR in the sequence
the value 0 will pass to the variable maior, using like a throne algorithm idea.*/

//This function is always linear, so it has O(n) complexity and that means less cpu usage.


int strs_values(string seq, string str)
{
    int maior = -1;
    int cont = 0;
    for(int i = 0; i <= seq.length(); i++)
    {
        if(seq[i] == str[0] && seq[i+1] == str[1] && seq[i+2] == str[2] && seq[i+3] == str[3])
        {
           	cont++;
            i+=3;
        }
        else
        {
            if(maior < cont)
                maior = cont;
            
            cont = 0;
        }
    }
    
    return maior;
}
