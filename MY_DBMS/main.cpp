#include "Header.h"
#include "DBMS.h"


int main () 
{
    DBMS * dbmsObj = new DBMS () ;
    DB * currentDatabase = nullptr ; 
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

        cout<<"Token of 0 : "<<tokens[0]<<endl;
        // Check the number of tokens
        if (tokens.size() == 0) {
            continue; // If no input, skip the iteration
        }
        if (tokens[0] == "clear")
        {
            system("clear");

        }
        // Command: create database database_name
        if (tokens[0] == "create" && tokens.size() == 3 && tokens[1] == "database") {
            dbmsObj->createDatabase(tokens[2]);
        }
        // Command: switch database database_name
        else if (tokens[0] == "switch" && tokens.size() == 3 && tokens[1] == "database") {
            currentDatabase = dbmsObj->switchDatabase(tokens[2]);
            if (currentDatabase == nullptr)
            {
                cout << " NO Database of This name ! \n";
            }
            else {
                cout<< " Switched database to :->  " << currentDatabase->name << endl;
            }
        }
        // Command: show databases
        else if (tokens[0] == "show" && tokens.size() == 2 && tokens[1] == "databases") {
            dbmsObj->showDatabases();
        }
        // Command: delete database database_name
        else if (tokens[0] == "delete" && tokens.size() == 3 && tokens[1] == "database") {

            dbmsObj->deleteDatabase(tokens[2]);
        }
        // Command: create table table_name
        else if (tokens[0] == "create" && tokens.size() == 3 && tokens[1] == "table") {
            currentDatabase->createTable(tokens[2]);
        }
        // Command: show tables
        else if (tokens[0] == "show" && tokens.size() == 2 && tokens[1] == "tables") {
            currentDatabase->showTables();
        }
        // Command: Remove tables
        else if (tokens[0] == "delete" && tokens.size() == 2 && tokens[1] == "table") {
            currentDatabase->deleteTable(tokens[2]);
        }
        // Unknown command
        else {
            // dbmsObj->deleteDatabase(tokens[2]);
            // std::cout << " Failed to recognize Command ! \n";
        }
    }
    return  0 ;
}

// create database database_name 
// switch database database_name
// shoe databases
// create table table_name