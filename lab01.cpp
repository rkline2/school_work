#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char check_grade(float grade)
{
    bool valid = true;
    
    if(grade > 0 && grade < 100)
        valid = true;
    else
        valid = false;

    return valid;
}

char invalid_input(float grade)
{
    bool invalid = true;
    
    while(invalid)
    {
        cout << "Invalid input. Enter a grade between 0 and 100: ";
        cin >> grade;
        invalid = check_grade(grade);
        invalid = !invalid;
    }
    
    return grade;
}

char check_entries(int entries)
{
    bool limit = false;
    
    if(entries > 2)
        limit = true;
    else
        limit = false;
        
    return limit;
}



int main()
{

    char first_name[15];
    char last_name[15];

    float grade = 0;
    float sum = 0;
    
    bool valid = true;
    bool limit = false;
    int entries = 0;

    cout << "Enter your first name: " << endl;
    cin.getline(first_name, 10);
    cout << "Enter your last name: " << endl;
    cin.getline(last_name, 10); 

    while(valid, limit==false)
    {
        cout << "Enter your grade: " << endl;
        cin >> grade;
        
        valid = check_grade(grade);
           
        if(valid)
        {
            limit = check_entries(entries);
            
            if(valid, limit==false)
            {    
                sum = sum + grade;
                entries = entries + 1;
            }
        }
        else
        {
            grade = invalid_input(grade);
            limit = check_entries(entries);
            
            if(limit==false)
            {
                sum = sum + grade;
                entries = entries + 1;
            }
        }
    }        
    
    cout << "Your full name is: " << first_name << " " << last_name << endl;
    cout << "Your grade average is: " << sum << endl;

    return 0;
}
