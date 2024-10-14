#include<iostream>
#include<string>
#include<map>
#include "DBMS.h"
#include<vector>
using namespace std ;




int main()
{
    DBMS *  dobj = new DBMS();
    string command ="";

    dobj->createDatabase("Database_1") ; 
    DB * current_database = dobj->switch_database("Database_1") ;
    current_database->createTable("table1");
    current_database->createTable("roshan" );
    // current_database->createTable("table2");
    // current_database->createTable("table3");

    // current_database->showTables();
    // current_database->deleteTable("table2");
    current_database->showTables();
    current_database->describe("roshan");
    current_database->addRecord("roshan");

    current_database->showRecords("roshan");
    return 0 ;
}