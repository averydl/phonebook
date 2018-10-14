#ifndef CONTACT_H
#define CONTACT_H

/*
 * Contact class header file written by:
 *
 * Derek Avery
 *
 * for CS 300 - Assignment 1 --- Bellevue College
 *
 * Due 2018/10/08
 *
 */

#include <iostream>
#include <fstream>

/* 
 * The Contact class represents a person and their contact
 * information; namely, each constructed contact object will hold two 
 * fields "Name" and "Number" representing the contact's
 * full name and phone number, respectively. 
 */
class Contact {

	private:
    
		// Fields //
    
		std::string name;   //full name of Contact
		std::string number; //phone number of Contact	

	public:
		
        // Constructors //
    
        Contact();                                          //default constructor, used for preallocation of memory
		Contact(std::string name, std::string number);      //main constructor, taking 'name' and 'number' arguments
		
		// Functions //
    
        friend std::ostream& operator<<(std::ostream &os,
                                        Contact &c);    //return ostream with contact name/number in string
    
		std::string getName() const;                    //return contact 'name' field
		std::string getNumber() const;                  //return contact 'number' field
		void changeName(std::string);                   //change contact 'name' field
		void changeNumber(std::string);                 //change contact 'number' field
};

#endif
