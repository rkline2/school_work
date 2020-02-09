#include <iostream>
#include <string>
using namespace std;

void grade_entry()
{
    float grade = 0.0; 
    int total_attempts = 0;
    bool valid = true;    

    cout << "Enter a grade: " << endl;
    cin >> grade;

    total_attempts += 1;
    
    if(grade < 0 || grade > 100)
        valid = false;

    while(cin.fail() || valid == false)
    {
        cout << "Invalid input. Enter a number: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> grade;

        if(grade < 0 || grade > 100)
                valid = false;
        else
        {
                total_attempts += 1;
                valid = true;
        }
    }
    
    cout << "Your grade is valid!" << endl;
    cout << "The total attempt times are: " << total_attempts << endl;
}

int main()
{

   string name;
   int sum = 0;
   int record_number = 0;
   /* 
   cout << "Enter your first and last name: " << endl;
   getline(cin, name);
   */   

   grade_entry();

   //record_number += 1; 
   //cout << "Your name is: " << name << endl;
    
   //cout << "The valid records number is: " << record_number << endl;
   return 0;
}
