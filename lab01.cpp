#include <iostream>
#include <string>
using namespace std;

float get_grade(float grade)
{
        int total_attempts = 0;
        bool valid = true;   

        cout << "Enter a grade between 0 - 100: ";
        cin >> grade;

        total_attempts += 1;

        if(grade < 0 || grade > 100)
            valid = false;

        while(cin.fail() || valid == false)
        {
            cout << "Invalid input. Enter a grade between 0 - 100: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> grade;

            total_attempts += 1;

            if(grade < 0 || grade > 100)
                    valid = false;
            else
                    valid = true;
        }

        cout << "Your grade is valid!" << endl;
        cout << "The total attempt times are: " << total_attempts << endl;

        return grade;
}

int main()
{
       string name;
       int sum = 0;
       int record_number = 0;

       float first_grade = 0.0;
       float second_grade = 0.0;
       float third_grade = 0.0;

       float average = 0.0;

       cout << "Enter your first and last name: ";
       getline(cin, name);

       first_grade = get_grade(first_grade);
       record_number += 1; 
       cout << "The valid records number is: " << record_number << endl;
       cout << " " << endl;   

       second_grade = get_grade(second_grade);
       record_number += 1; 
       cout << "The valid records number is: " << record_number << endl;
       cout << " " << endl;  

       third_grade = get_grade(third_grade);
       record_number += 1; 
       cout << "The valid records number is: " << record_number << endl;
       cout << " " << endl;  

       average = (first_grade + second_grade + third_grade)/record_number;

       cout << name << " your average is: " << average << endl;

       return 0;
}
