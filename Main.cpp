#include "Contact.h"
#include "Phonebook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Phonebook* pb = new Phonebook();    //Phonebook object to hold and process contacts

/*
 * This code takes as arguments two strings, and tokenizes
 * the string using the 'delim' argument as a delimiter, then
 * returns a vector containing all tokens in the string.
 *
 * This code was obtained from a submission on StackOverflow by
 * user 'Sviatoslav' at the following URL on the date Oct. 05, 2018:
 *
 * https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
 */
std::vector<std::string> split(const std::string& str, const std::string& delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while
        (pos < str.length() && prev < str.length());
    return tokens;
}


/*
 * Reads a file containing line-separated contact strings in the format
 * "name number", and uses them to instantiate a Contact object; these Contact
 * objects are each stored in the global Phonebook variable "pb". Code for this
 * method was developed in part by referencing code from: 
 *
 * The "CS300Fall18_Assignment1.pdf" assignment file,
 * provided by Professor Fatma Cemile Cerce, Chair @ Bellevue College
 */
void readfile(std::string filename) {
    //open the file using an ifstream object
    std::ifstream file;
    file.open(filename);
    
    std::string curline;                //variable to hold the current line of the text file being processed
    std::string cur_token;              //variable to hold each token extracted from the current line
    std::vector<std::string> tokens;    //vector to hold tokens from each line of the text file
    std::string name, number;           //variables to hold the name and number from each field
    int num_tokens;                     //number of tokens stored in the vector 'tokens'

    //create & store Contacts to 'pb' by extracting the name and number from each line of input
    while(std::getline(file, curline)) {
        //split up space-separated tokens into vector 'tokens' using the split() method
        tokens = split(curline, " ");
        num_tokens = tokens.size();     //size of the vector 'tokens'
        
        //reset name/number to empty strings
        name = "";
        number = "";
        
        //add the last token to the 'number' string and 'pop' it; decrement num_tokens
        number += tokens.back();
        tokens.pop_back();
        num_tokens--;

        //add tokens representing name to the vector
        for(int i = 0; i < num_tokens-1; i++) {
            name = " " + tokens.back() + name;  //add name tokens (include spaces) to 'name'
            tokens.pop_back();                  //remove each token from the vector once added to 'name'
        }
        name = tokens.back() + name;            //add last token (no space) to the 'name' string
        
        Contact* c = new Contact(name, number);
        pb -> add(c);
    }
}

/*
 * The main method provides a simple text-based user interface that prompts
 * users for command arguments that allow manipulation of a Phonebook object.
 * Users may add, remove, list or search existing contacts. This method will
 * also accept a command-line argument representing the name of a text file
 * with contact information; if this argument is provided, the file will be read
 * and new Contacts from the fill will be generated and added to the Phonebook
 */

int main(int argc, char* argv[]) {
    std::string const MENU = "A(Add) | S (Search) | D (Delete) | L (List) | Q (Quit): "; //string showing user input options
    
    std::string input;      //user input string
    if(argc > 1)            //check to see if command-line argument (text file name) has been entered
        readfile(argv[1]);  //read the file provided in the command-line argument
    
    //Introduction message: displayed once, when the application is started
    std::cout << "*** MY PHONEBOOK APPLICATION ***\nPlease choose an operation:\n";
    
    //prompt for user input and execute the corresponding operations until the 'Quit' option is selected
    while(true) {
        std::cout << MENU;
        std::getline(std::cin, input);
        
        if(input == "A" || input == "a") {  //execute "Add" operation if user enters "A" or "a"
            
            std::string name, number;     //variables to store name/number input by user
            
            //prompt for and store user input for name/number
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter number: ";
            std::getline(std::cin, number);
            
            //create new Contact from name/number and store it in the Phonebook
            Contact* c = new Contact(name, number);
            pb -> add(c);
            delete c;
            
            std::cout << "\n"; 
            
        } else if(input == "S" || input == "s") {//execute "Search" operation if user enters "S" or "s"
            
            std::string name, number;       //variables to store name (user input) and number (function output)
            
            //prompt for and store user-input name
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            
            //output result of Phonebook search for 'name'
            std::cout << "Phone Number: " << (pb -> search(name)) << "\n\n";
            
        } else if (input == "D" || input == "d") { //execute "Delete" operation if user enters "D" or "d"
            
            std::string name, number;     //variable to store name input by user
            
            //prompt for and store user input for name/number
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            
            pb -> remove(name);
            std::cout << "\n";
            
        } else if(input == "L" || input == "l") { //execute "List" operation if user enters "L" or "l"
            pb -> listall();
            
        } else if(input == "Q" || input == "q"){ //stop execution if user enters "Q" or "q"
            break;
            
        } else {//if the user input is not valid, display a warning message
            
            std::cout << "INVALID INPUT: PLEASE REVIEW THE AVAILABLE OPERATIONS AND TRY AGAIN\n";
            std::cout << "\n";
            
        }
    }
}

