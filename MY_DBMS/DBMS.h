#include "Header.h"
#include <vector>
#include "DB.h"

 class DBMS 
{
    public :
    // DLL < DB  * >  databases ;       // pointer to db objects
    // // DLL < DB  > * databases ;    // to actual db objects
    vector < DB * > databases ;
    map < string , int > mp ; 
    int count  ; 

    DBMS ()
    {
        this -> count = 0 ; 
        cout<<"Database Management Sustem is Ready to store your data ...! \n" ; 
    }
    int createDatabase ( string name )
    {
        DB * dobj = new DB (name );
        if (dobj != nullptr)
        {   
            this->databases.push_back( dobj);
            mp[name] = count;   
            this -> count ++ ; 
            cout<<" Database Created Succesfully ! \n";
            return 0 ; 
        }
        return -1 ; 
    }

    void showDatabases ()
    {
        cout<<"Databases  are : \n" ;
        for (int i = 0 ; i < count ; i++ )
        {
            cout<<databases[i]->name <<"\n";
        }
        cout<<endl;
    }

    int deleteDatabase (string name ) 
    {
        if (mp.find(name) != mp.end() && mp[name] != -1)
        {
            // Check if the index is valid
            int index = mp[name];
            if (index >= 0 && index < databases.size())
            {
                databases.erase(databases.begin() + index);
                // Optionally, remove the entry from the map after deletion
                mp.erase(name);
                this -> count -- ; 
                cout << "DBMS: Database deleted successfully! \n";
                return 0;
            }
            else
            {
                cout << "DBMS: Index is out of range! \n";
                return -1;
            }
        }
        else 
        {
            cout << "DBMS: Database delete failed! The database does not exist.\n";
            return -1; 
        }
    }   

    DB * switchDatabase (string name )
    {
        DB * ptrToReturn = nullptr ; 
        if (mp.find(name) != mp.end() ) {
        cout<<"MP OF NAME IS : "<<mp[name]<<endl;
            return databases[mp[name]] ; 
        }
        return nullptr;
    }


};