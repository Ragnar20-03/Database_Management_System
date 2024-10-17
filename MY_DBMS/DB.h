#include "Header.h"
#include "Table.h"


class DB {
    public : 
    vector < Table * > tables ; 
    int tableCount  ; 
    string name  ; 
    DB (string name ) 
    {
        this -> name = name ;
        this -> tableCount = 0 ; 
        Table * tobj = new Table ( name );
        if (!tobj )
        {
            cout << "Table Createion failed ! \n";
            return  ;
        }
        else{
            // tables.InsertLast(tobj);
            tables.push_back(tobj);
        }

    }

    
};