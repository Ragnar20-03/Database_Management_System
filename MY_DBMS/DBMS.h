#include "DB.h"
#include<iostream>
using namespace std ; 
#include<map>
class DBMS  { 
    public : 
    map < string ,   DB * > database_map ;

    void createDatabase ( string name ) 
    {
            DB* newDatabase = new DB(name);
            this->database_map[name] = newDatabase;
            cout<<"database created Succesfully !"<<endl;
    }
    

    DB *  switch_database ( string name )
    {
        if ( database_map [ name ])  
        {
            cout<<"database Switched to : " <<name << endl; 
            return database_map[name];
        }
        else {
            cout<<"No such database  ! "<<endl; 
            return nullptr; 
        }
    }
} ;