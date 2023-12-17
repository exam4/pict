#include <iostream>
#include <fstream>
using namespace std;

class student{
    public:
    int roll;
    string name;
    string address;
    int div;
};

class database{
    student s;
    public:
    void createFile(){
        ofstream file("sample.txt", ios::out);
        if(file.is_open()){
            int total;
            cout << "Enter number of records you want to add: ";
            cin >> total;

            for (int i = 0; i < total ; i++){
                cout << "\nEnter information for student " << i+1 << ":" << endl;
                cout << "Enter Roll Number: ";
                cin >> s.roll;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin,s.name);  //getline function is used only for strings
                cout << "Enter division: ";
                cin >> s.div;
                cout << "Enter city: ";
                cin.ignore(); //ignores input buffer characters
                getline(cin,s.address);

                file << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.address << endl;
            }
        }
        else{
            cout << "Error in opening the file";
            return;
        }
        file.close();
    }

    void displayRecords(){
        ifstream file("sample.txt", ios::in);
        if (file.is_open()){
            while(file >> s.roll >> s.name >> s.div >> s.address){
                cout << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.address << endl;
            }
        }
        else{
            cout << "File not found" << endl;
        }
    }

    void addRecord(){
        ofstream file("sample.txt", ios::app);
            if(file.is_open()){
                cout << "Please enter information of new student: " << endl;
                cout << "Enter roll number: ";
                cin >> s.roll;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin,s.name);
                cout << "Enter division: ";
                cin >> s.div;
                cout << "Enter city: ";
                cin.ignore();
                getline(cin,s.address);

                file << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.address << endl;
            }
            else{
                cout << "Error in opening file" << endl;
            }
            file.close();
        }

        void searchRecord(int key){
        student s;
        ifstream file("sample.txt", ios::in);
        bool found = false;
        if (file.is_open()){
            while(file >> s.roll >> s.name >> s.div >> s.address){
                if (s.roll == key){
                    cout << "RECORD FOUND" << endl;
                    cout  << s.roll <<" \t\t " << s.name << " \t " << s.div << " \t\t" << s.address << endl;
                    found = true;
                }
            }
        }
        else{
            cout << "Error in opening file" << endl;
        }
        if(!found){
            cout << "Student with roll number " << key << " was not found in database" <<  endl;
        }
        file.close();
    }
};

int main(){
    int choice;
    database d;
    do{
        cout << "1. Create Records" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Add new Records" << endl;
        cout << "4. Search Record" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            {
                d.createFile();
                break;
            }
            case 2:
            {
                d.displayRecords();
                break;
            }
            case 3:
            {
                d.addRecord();
                break;
            }
            case 4:
            {
                int key;
                cout << "Enter roll number you want to search: ";
                cin >> key;
                d.searchRecord(key);
                break;
            }
            case 0: break;

            default: cout << "INVALID INPUT" << endl;
        }
    }while(choice!=0);
}
