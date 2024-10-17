#include "Header.h"
#include "Table.h"


class DB {
    public : 
    vector < Table * > tables ; 
    int tableCount  ; 
    map < string , int > mp ; 
    string name  ; 
    DB (string name ) 
    {
        this -> name = name ;
        this -> tableCount = 0 ; 
    }

    int createTable (string name )
    {
        if (mp[name])
        {
            cout<<" Table Already exists in database  ! \n";
            return -1 ;
        }
        Table * tobj = new Table ( name );
        if (!tobj )
        {
            cout << "Table Createion failed ! \n";
            return  0;
        }
        else{
            // tables.InsertLast(tobj);
            cout<< " Table created Succesfully  ! \n";
            mp[name] = tableCount ++; 
            tables.push_back(tobj);
        }
    }

    void showTables () 
    {
        if (tableCount == 0 )
        {
            cout<< " No tables present in this database ! \n";
        }
        cout << "Tables for the : "<< this -> name << "Are : \n";
        for (int i = 0 ; i < tableCount ; i++ )
        {
            cout<< tables[i]<<endl;
        }
        cout<<endl ; 
    }

    int deleteTable(string name ) 
    {
        if (!mp[name])
        {
            cout<< " Table Not Exists ! \n";
            return -1 ; 
        }

        tables.erase(tables.begin() + mp[name]) ; 
        tableCount -- ; 
        mp.erase(name);

        cout<<"Table Deleted Succesfully ! \n";
        return 0 ; 
    }
    
};