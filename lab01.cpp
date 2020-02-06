#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    float first_grade; 
    float second_grade;
    float third_grade;
    
    int total_attempts = 0;
    int record_number = 0;
    
    cout << "Enter your first and last name: " << endl;
    getline(cin, name);
    
    cout << "Please enter your first grade: " << endl;
    cin >> first_grade;
    
    total_attempts = total_attempts + 1;
    record_number = record_number + 1;
    
    while(cin.fail())
    {
        cout << "Invalid input. Enter a number: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> first_grade;
        total_attempts = total_attempts + 1;
    }
    
    cout << "Your first grade is valid!" << endl;
    cout << "The total attempt times are: " << total_attempts << endl;
    cout << "The valid records number is: " << record_number << endl;
    
    cout << "Your name is: " << name << endl;

    return 0;
}
