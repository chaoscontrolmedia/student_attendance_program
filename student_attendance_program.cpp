//Write a C++ program that gets the students names inan array.
//Names can be called out at random
//need a function to mark attandance 
//Name randomness should be based on attendance 
//keep track of total number of students, as well as number of present students
//Add date to students.txt output

//Add Date, save to computer

#include <iostream>
#include <string>
#include <fstream> // For file operations
using namespace std;


const int MAX_STUDENTS = 100;

int gather_student_data(string students[], int& student_count){
    cout << "Student Roster\n";
    cout << "Enter '0' to finish input.\n";

        while (true) {
            cout << "\nEnter Student (0 to finish): ";
            cin >> students[student_count];

            if (students[student_count] == "0")
                break;  // Break out of the loop if "0" is entered

            student_count++;
            
        if (student_count >= MAX_STUDENTS) {
            cout << "Maximum number of students reached." << endl;
            break; // Break out of the loop if maximum number of students reached
        }
    }

    return student_count;
    
}

void display_student_data(string students[], int student_count) {
    cout << "\nTotal Students: " << student_count << endl;
    cout << "Student Names:\n";
    for (int i = 0; i < student_count; i++) {
        cout << students[i] << "\n";
    }
}

void save_student_data(const string& students_file, string students[], int student_count){
    ofstream outFile(students_file);

    if(outFile.is_open()){
        if(student_count == 0) {cout << "No students saved\n";} 
        
        if (student_count >0 ){
            outFile << "Student count:" << student_count << "\n";
            for(int i = 0; i< student_count; i++){
                outFile<< students[i] << "\n";
            }
            cout << "\nNumbers saved to file: "<< students_file << "\n";
        }

        
        outFile.close();
        } else {
            cerr << "\nUnable to open file ffor writing" << students_file << "\n";
    }

}

void total_attendance() {
    string students[MAX_STUDENTS];
    int student_count = 0;
    int choice;


while(true){
    cout << "Student Attendance."
    "\n1. Gather/Display/Save Student Data." 
    "\n2. Exit program";

    cin >> choice;

    switch(choice){
        case 1:
            gather_student_data(students, student_count);
            display_student_data(students, student_count);
            save_student_data("students.txt", students, student_count);
            break;
        case 2:
            return;

        default:
            cout << "Invalid";
            break;
        }
    }

        

    


    
}

int main(){
    total_attendance();
    return 0;
}



/*
void total_attendance(){

    const int MAX_STUDENTS = 100;
    string students[MAX_STUDENTS];
    int student_count = 0;


    cout << "Student Roster\n";
    cout << "Enter '0' to finish input.\n";
    while (true){
        cout << "\nEnter Student(0 to finish): ";
        cin >> students[student_count];
        if(students[student_count] == "0") break;
        else{student_count++;}

        if(student_count >= MAX_STUDENTS){
            cout << "Max students reached." << endl;
            break;
        }
    }


    cout << "\nTotal Students: " << student_count << " ";
    cout << "\nStudent Names:\n";
    for(int i = 0; i<student_count; i++){
        cout << students[i] << "\n"; 
    }

};
*/




