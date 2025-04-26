F-23 code
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    int rollNo;
    char name[20], div, address[30];

    void accept() {
        cout << "\tEnter Roll Number : "; cin >> rollNo;
        cout << "\tEnter Name : "; cin >> name;
        cout << "\tEnter Division : "; cin >> div;
        cout << "\tEnter Address : "; cin >> address;
    }

    void modifyRoll() {
        cout << "\tEnter new Roll Number : "; cin >> rollNo;
    }

    void modifyName() {
        cout << "\tEnter new Name : "; cin >> name;
    }

    void show() const {
        cout << "\n\t" << rollNo << "\t" << name << "\t" << div << "\t" << address;
    }

    int getRollNo() const { return rollNo; }
};

void insertRecords() {
    Student s;
    fstream f("StuRecord.txt", ios::out);
    char choice;
    do {
        s.accept();
        f.write((char*)&s, sizeof(s));
        cout << "Add more? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    f.close();
}

void displayRecords() {
    Student s;
    fstream f("StuRecord.txt", ios::in);
    while (f.read((char*)&s, sizeof(s))) {
        s.show();
    }
    f.close();
}

void editRecordByRoll() {
    int roll;
    cout << "Enter roll number to modify: "; cin >> roll;
    Student s;
    fstream f("StuRecord.txt",ios::in| ios::out);
    while (f.read((char*)&s,sizeof(s))){
        if(s.getRollNo()==roll)
        {
            cout<<"Record found\n";
            f.seekp(-sizeof(s),ios::cur);
            s.accept();
            f.write((char*)&s,sizeof(s));
            f.close();
            return;
        }
    }
        
    cout << "Record not found.\n";
    f.close();
}

void editRecordByName() {
    char name[20];
    cout << "Enter name to modify: "; cin >> name;
    Student s;
    fstream f("StuRecord.txt", ios::in | ios::out);
    while (f.read((char*)&s, sizeof(s))) {
        if (strcmp(name, s.name) == 0) {
            cout << "Record found.\n";
            f.seekp(-sizeof(s), ios::cur);
            s.accept();
            f.write((char*)&s, sizeof(s));
            f.close();
            return;
        }
    }
    cout << "Record not found.\n";
    f.close();
}

void modifyOnlyRoll() {
    int roll;
    cout << "Enter roll number to change: "; cin >> roll;
    Student s;
    fstream f("StuRecord.txt", ios::in | ios::out);
    while (f.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == roll) {
            cout << "Record found.\n";
            f.seekp(-sizeof(s), ios::cur);
            s.modifyRoll();
            f.write((char*)&s, sizeof(s));
            f.close();
            return;
        }
    }
    cout << "Record not found.\n";
    f.close();
}

void modifyOnlyName() {
    char name[20];
    cout << "Enter name to change: "; cin >> name;
    Student s;
    fstream f("StuRecord.txt", ios::in | ios::out);
    while (f.read((char*)&s, sizeof(s))) {
        if (strcmp(name, s.name) == 0) {
            cout << "Record found.\n";
            f.seekp(-sizeof(s), ios::cur);
            s.modifyName();
            f.write((char*)&s, sizeof(s));
            f.close();
            return;
        }
    }
    cout << "Record not found.\n";
    f.close();
}

void deleteRecord() {
    int roll;
    cout << "Enter roll number to delete: "; cin >> roll;
    Student s;
    fstream f("StuRecord.txt", ios::in);
    fstream temp("Temp.txt", ios::out);

    bool found = false;
    while (f.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() != roll)
            temp.write((char*)&s, sizeof(s));
        else
            found = true;
    }

    f.close();
    temp.close();
    remove("StuRecord.txt");
    rename("Temp.txt", "StuRecord.txt");

    if (found) cout << "Record deleted successfully.\n";
    else cout << "Record not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n\n********** MENU **********\n";
        cout << "1. Insert/Overwrite Records\n2. Display Records\n3. Edit by Roll No.\n4. Edit by Name\n5. Modify only Roll No.\n6. Modify only Name\n7. Delete a Record\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: insertRecords(); break;
            case 2: displayRecords(); break;
            case 3: editRecordByRoll(); break;
            case 4: editRecordByName(); break;
            case 5: modifyOnlyRoll(); break;
            case 6: modifyOnlyName(); break;
            case 7: deleteRecord(); break;
            case 8: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
