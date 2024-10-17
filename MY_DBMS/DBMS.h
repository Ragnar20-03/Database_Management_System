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
        if (mp[name])
        {
            databases.erase( databases.begin () + mp[name]);
            cout<< "DBMS : Datbase delete succesfully ! \n";
            return 0 ;
        }
        else 
        {
            cout<< "DBMS : Datbase delete Failed ! \n";
            return -1 ; 
        }   
    }   

    DB * switchDatabase (string name )
    {
        DB * ptrToReturn = nullptr ; 
        if (mp[name])
        {
            ptrToReturn = databases[ mp[name] ];
        }
        return ptrToReturn ; 
    }


};