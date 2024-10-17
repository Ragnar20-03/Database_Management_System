#include <iostream>
#include <sstream>
#include <vector>
#include <string>
// #include "LinkedList.h"
#include <map>

using namespace std ; 


template < class T > 
class GenericTesting {
    public :
    T data ; 
    GenericTesting( T data)
    {

        this -> data = data ; 
    }
};





int main() 
{
    string command ; 
    vector < GenericTesting<string>  * >stringColumns ; 
    vector <  GenericTesting<int > * >intColumns ; 
     while ( 1 )
     {
        getline(cin, command);


        std::istringstream iss(command);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens[0] == "string")
        {
            GenericTesting<string > * newobj = new GenericTesting < string >  (tokens[1]) ; 
            stringColumns.push_back(newobj);

            cout<<"STRING COLUMNS ARE : \n";
            for (int i = 0 ; i < stringColumns.size() ; i++ )
            {
                cout<<"for1\n";
                cout<<stringColumns[i]->data<<" : \t ";
            }
            cout<<endl<<endl;;
            cout<<"INT COLUMNS ARE : \n";
             for (int i = 0 ; i < intColumns.size() ; i++ )
            {
                cout<<stringColumns[i]->data<<" : \t ";
            }
            cout<<endl;
        }       
       
     }


    return  0 ;
}