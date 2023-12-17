#include <iostream>
using namespace std;

struct student
{
    string name;
    int roll;
    float sgpa;
};

class database
{
public:
    struct student s[5];

    void input()
    {
        for (int i = 0; i < 5; i++)
        {
            // taking name input
            cout << "Enter " << i + 1 << " student name: ";
            cin >> s[i].name;

            // taking roll number input
            cout << "Enter " << i + 1 << " student roll number: ";
            cin >> s[i].roll;
            // checking if the roll number is repeated
            for(int j = i; j >=0; j--){
                while(s[i].roll == s[j-1].roll){
                    cout << "REPEATED roll number. Please enter a valid roll number: ";
                    cin >> s[i].roll;
                    j = i;
                }
            }

            // taking input for sgpa
            cout << "Enter " << i + 1 << " student SGPA: ";
            cin >> s[i].sgpa;
            while(s[i].sgpa > 10 && s[i].sgpa < 0 ){
                cout << "Enter " << i + 1 << " student SGPA: ";
                cin >> s[i].sgpa;
            }
        }
    }

    void display(){
        for (int i = 0; i < 5; i++){
            cout << s[i].name << "\t" << s[i].roll << "\t" << s[i].sgpa << endl;
        }
    }

    void linear_search(int key){
        for (int i = 0; i < 5; i++){
            if (s[i].sgpa == key){
                cout << "Records found" << endl;
                cout << s[i].name << "\t" << s[i].roll << "\t" << s[i].sgpa << endl;
            }
        }
    }

    void bubble_sort(){
        for(int i = 0; i < 5; i++){
            for ( int j = 0; j < 5-i-1 ;j++){
                if (s[j].roll > s[j+1].roll){
                    swap(s[j+1],s[j]);
                }
            }
        }
        display();
    }

    void insertion_sort(){
        string kname;
        int kroll;
        float ksgpa;
        for(int i = 0; i<5; i++){
            kname = s[i].name;
            kroll = s[i].roll;
            ksgpa = s[i].sgpa;
            int j = i-1;
            while(j >=0 && kname < s[j].name){
                s[j+1].name = s[j].name;
                s[j+1].roll = s[j].roll;
                s[j+1].sgpa = s[j].sgpa;
                j--;
            }
            s[j+1].name = kname;
            s[j+1].roll = kroll;
            s[j+1].sgpa = ksgpa;
        }
    }

    int partition(int low, int high){
        int i = low;
        int j = high;
        int pivot = s[low].sgpa;

        while (true){
            while (i <= j && s[i].sgpa < pivot){
                i++;
            }
            while( i <= j && s[j].sgpa >= pivot){
                j--;
            }
            if (i < j){
                swap(s[i],s[j]);
            }
            else{
                break;
            }
        }
        swap(s[low],s[j]);
        return j;
    }

    void quicksort(int low, int high){
        if (low < high){
            int pivotIndex = partition(low,high);
            quicksort(low,pivotIndex - 1);
            quicksort(pivotIndex + 1, high);
        }
    }

    void binary_search(string key, int low, int high){
        int mid;
        if(low > high){
            return;
        }
        else{
            mid = (low+high) / 2;
            if ( key == s[mid].name){
                cout << "STUDENT FOUND" << endl;
                cout << s[mid].name << "\t" << s[mid].roll << "\t" << s[mid].sgpa;
            }
            else if (key > s[mid].name){
                binary_search(key,mid+1,high);
            }
            else if( key < s[mid].name){
                binary_search(key,low,mid-1);
            }
            else{
                cout << "Name not found" << endl;
            }
        }
    }
};

int main()
{
    database d;
    int choice;

    do
    {
        cout << endl;
        cout << "1. Input" << endl;
        cout << "2. Display" << endl;
        cout << "3. Linear Search by SGPA" << endl;
        cout << "4. Bubble Sort by Roll number" << endl;
        cout << "5. Insertion Sort by name" << endl;
        cout << "6. Quick sort by SGPA" << endl;
        cout << "7. Binary Search by name" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            d.input();
            break;
        }
        case 2:
        {
            d.display();
            break;
        }
        case 3:
        {
            int key;
            cout << "Enter SGPA you want to search: ";
            cin >> key;
            d.linear_search(key);
            break;
        }
        case 4:
        {
            d.bubble_sort();
            break;
        }
        case 5:
        {
            d.insertion_sort();
            d.display();
            break;
        }
        case 6:
        {
            d.quicksort(0,4);
            d.display();
            break;
        }
        case 7:
        {
            string name;
            d.insertion_sort();
            cout << "Enter student name you want to find: ";
            cin >> name;
            d.binary_search(name,0,4);
        }
        case 0:
            break;

        default:
            cout << "INVALID INPUT" << endl;
        }
    } while (choice != 0);
}
