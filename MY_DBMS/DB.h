#include<iostream>
#include<vector>
#include<string>
using namespace std ; 




template < typename T > 
class Column {
    public : 
    vector<T>    records ; 
    T name ; 

    Column ( T name ){
        this -> name = name ; 
    }
    void addData(T data )
    {
        records.push_back(data );
    }
};

template < typename T > 
class Table { 
    public : 
    string name ; 
    vector <  Column <T> * > columns ; 
    Table(string name  )
    {
        this -> name = name;
    }

    void addColumn (T column_name )
    {
        columns.push_back(new Column <T > (column_name) );
        cout<<"Column Added Sucesfully";
    }

    void describe () 
    {
        cout<<name<<" Is : "<<endl;
        for (int i = 0 ; i < columns.size() ; i++ )
        {
            cout<<columns[i]->name<<" | "<<endl;
        }
        cout<<endl;
    }
    void addRecord ( string column_name , T data)
    {
        for (int i = 0 ; i < columns.size() ; i++ )
        {
            if (columns[i] -> name == column_name)
            {
                columns[i]->addData ( data);
            }
        }
        cout<<"data added succesfully !\n";
    }

    void showRecords ( )
    {
        for (int i = 0 ; i < columns.size() ; i++ )
        {
                cout<<"record is : "<<columns[i]->records.size() <<endl;
            for (int j = 0 ; j < columns[i]->records.size() ; j++ )
            {
                cout<< " : "<<columns[i]->records[j]<<endl;
            }
        }
        cout<<endl<<endl;
    }

};

class DB {
    public :
    
    string name ; 
    vector< Table<string> * > tables ; 

    DB (string name )
    {
        this -> name  = name ;
    }

    void createTable ( string name )
    {
        Table <string> * newTable = new Table<string>(name);
        this->tables.push_back(newTable);
        newTable->addColumn("ID");
        newTable->addColumn("Name");
        newTable->addColumn("Roll");
        cout<<"Table added Succesfully ! \n";
    }
    
    void showTables ( )
    {
        cout<<"Tables are : \n";
        for (int i = 0 ; i < tables.size() ; i++ )
        {
            cout<<tables[i]->name<<"\n";
        }
        cout<<"\n";
    }

    void deleteTable ( string name) {
        for (int i = 0 ; i < tables.size() ; i++ )
        {
            if (tables[i]->name == name )
            {
                cout<<"Table removed Succesfully ! \n";
                tables.erase(tables.begin() + i );
                return ; 
            }
        }
        cout<<"No such Table ! \n";
    }

    void describe(string name )
    {
        for (int i = 0 ; i < tables.size() ; i++ )
        {
            if ( tables[i]->name == name)
            {
                tables[i]->describe();
            }
        }
    }

    void addRecord ( string table_name){
        for (int i = 0 ; i < tables.size() ; i++)
        {
            if (tables[i]->name == table_name)
            {
                tables[i]->addRecord("ID" , "1");
                tables[i]->addRecord("ID" , "2");
                tables[i]->addRecord("ID" , "3");
                tables[i]->addRecord("ID" , "4");
                tables[i]->addRecord("Name" , "I Am not telling");
                cout<<"data added succesfully !\n";
            }
        }
    }

    void showRecords(string table_name)
    {
        cout<<"size is : "<<tables.size() <<endl; 
        for (int i = 0 ; i < tables.size() ; i++)
        {
            if (tables[i]->name == table_name)
            {
                tables[i]->showRecords();
                cout<<"Returnning !\n";
            }
        }
    }
};