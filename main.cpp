#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
The do-while loop is used to repeat the menu 
options until the user chooses to exit.
The while loop is used to generate the Fibonacci sequence.
The for loop is used to calculate the sum of the Fibonacci sequence.
The for-each loop is used to output the Fibonacci sequence.
*/

int main() {
    
    /* GPT: C++ PROGRAM THAT HAS 4 OPTIONS (A,B,C,X) */
    char option;
    
    //DO WHILE LOOP
    do {
        
        cout << "Please choose an option:" << endl;
        
        cout << "A: Fibonacci sequence" << endl;
        cout << "B: Sum of n Fibonacci numbers" << endl;
        cout << "C: Create palindrome" << endl;
        cout << "X: Exit" << endl;
        
        cin >> option;
        
        option = toupper(option);
        
        switch(option) {
            
            /* GPT: A MUST OUTPUT THE FIBONACCI SEQUENCE 
            (NUMBER OF TERMS IS GIVEN BY USER) */
            case 'A': {
                
                int n;
                
                cout << "Enter the number of terms in the sequence: ";
                
                /* VALIDATES USER INPUT (IF N DOEST READ 
                FROM THE SYSTEM OR IF N IS LESS THAN 1) */
                if (!(cin >> n) || n < 1) {
                    
                    cout << "Invalid input. Please enter a positive integer." 
                    << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    break;
                }
                
                vector<int> fibonacci = {0, 1};
                
                //WHILE LOOP
                while (fibonacci.size() < n) {
                    
                    int next = fibonacci[fibonacci.size() - 1] 
                             + fibonacci[fibonacci.size() - 2];
                    fibonacci.push_back(next);
                    
                }
                
                cout << "Fibonacci sequence: ";
                
                //FOR EACH LOOP
                for (int num : fibonacci) {
                    cout << num << " ";
                }
                
                cout << endl;
                
                break;
                
            }
            
            /* GPT: B MUST OUTPUT THE SUM OF THE FIBONACCI 
            SEQUENCE (NUMBER OF TERMS IS GIVEN BY USER) */
            case 'B': {
                
                int n;
                
                cout << "Enter the number of Fibonacci numbers to sum: ";
                
                /* VALIDATES USER INPUT (IF N DOEST READ 
                FROM THE SYSTEM OR IF N IS LESS THAN 1) */
                if (!(cin >> n) || n < 1) {
                    
                    cout << "Invalid input. Please enter a positive integer." 
                    << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    break;
                    
                }
                
                int a = 0, b = 1, c, sum = 1;
                
                //FOR LOOP
                //fOR i <= n (starting from 3) IN INCRAMENTS OF 1
                for (int i = 3; i <= n; i++) {
                    
                    //CALCULATES SUM
                    c = a + b;
                    a = b;
                    b = c;
                    sum += c;
                    
                }
                
                cout << "The sum of the first " << n 
                << " Fibonacci numbers is " << sum << endl;
                
                break;
                
            }
            
            /* GPT: C MUST ACCEPT A STRING FROM THE USER 
            AND USE IT TO OUTPUT A PALINDROME */
            case 'C': {
                
                cout << "Enter a string: ";
                string str;
                cin >> str;
                
                string palindrome = str;
                
                //.length STARTS FROM 1, index STARTS FROM 0 (before)
                int i = str.length()-1;
                int j = str.length();
                
                //WHILE LOOP
                while (i >= 1) {
                    
                    /*INSERT A LETTER STARTING FROM THE SECOND LAST
                    LETTER (str{i-1}), AFTER THE LAST LETTER (J) ,ONCE (1) */
                    palindrome.insert(j, 1, str[i-1]);
                    i=i-1;
                    j=j+1;
                }
                
                cout << "The palindrome is: " << palindrome << endl;
                
                break;
                
            }
            
            case 'X': {
                
                //EXIT THE PROGRAM
                cout << "Exiting program..." << endl;
                break;
                
            }
            
            default: {
                
                //VALIDATE USER INPUT FOR CHOICE
                cout << "Invalid option. Please choose again." << endl;
                break;
                
            }
            
        }
        
    } while (option != 'X');
    
    return 0;
    
}

