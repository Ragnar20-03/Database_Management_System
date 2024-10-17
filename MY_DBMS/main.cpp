#include "Header.h"
#include "DBMS.h"


int main () 
{
    DBMS * dbmsObj = new DBMS () ;
    string command ; 
    if (!dbmsObj)
    {
        cout<< " Failed TO start  Database Management System :  \n ";
        return 0 ; 
    }
    cout << "DBMS Started Succesfully ! ........\n";

    while  (1 ) 
    {
        cout<<"inside while \n" ;
        cout << "$-> \t";
        getline(cin, command);

        std::istringstream iss(command);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        // Check the number of tokens
        if (tokens.size() == 0) {
            cout<<"inside if \n";
            continue; // If no input, skip the iteration
        }

        // Command: create database database_name
        if (tokens[0] == "create" && tokens.size() == 3 && tokens[1] == "database") {
            dbmsObj->createDatabase(tokens[2]);
        }
        // Command: switch database database_name
        else if (tokens[0] == "switch" && tokens.size() == 3 && tokens[1] == "database") {
            dbmsObj->switchDatabase(tokens[2]);
        }
        // Command: show databases
        else if (tokens[0] == "show" && tokens.size() == 2 && tokens[1] == "databases") {
            dbmsObj->showDatabases();
        }
        // Unknown command
        else {
            std::cout << " Failed to recognize Command ! \n";
        }
    }
    return  0 ;
}

// create database database_name 
// switch database database_name
// shoe databases
// create table table_name