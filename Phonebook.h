#ifndef PHONEBOOK_H
#define PHONEBOOK_H

/*
 * Phonebook application header file written by: Derek Avery
 *
 * Written for CS 300: Assignment 1 - Bellevue College
 *
 * Due 2018/10/08
 *
 */

#include <iostream>
#include "Contact.h"
#include "Phonebook.h"


/* This class includes functionality similar to a traditional phone book; it can read a given .txt file with contact
 * name/number in line-separated format and add them to a dynamic array of 'Contact' objects. It can also add/delete
 * contacts, search existing contacts, or list existing contacts all via a command line interface. For the purposes of
 * this application, names will NOT be case-sensitive. Additionally, duplicates (that is, identical name and number)
 * will NOT be accepted. However, duplicate phone numbers will be accepted, so users will need to ensure accurate information
 * is provided, as this application does not provide complete error-checking capability. The contact array will be automatically
 * upsized as necessary as contacts are added. However, if contacts are deleted the structure's capacity will not be reduced.
 */
 
class Phonebook {
    
	private:
    
        // Fields //
    
	int size;						                        //size of existing Contact array
        int contactnum;                                     //number of contacts stored in the Phonebook
        Contact** contacts;                                  //pointer to array of pointers to Contacts in the Phonebook
    
        // Functions //
    
    
    
	public:
    
        // Constructor //
    
        Phonebook(int size = 10);                       //instantiate Phonebook with 'Contact' array of default size 10
    
        // Functions //
    
        void upsize();                                      //double the capacity of the Contact array and copy over existing elements
        std::string search(std::string name) const;         //returns contact number string it exists in the Phonebook, or 'name not found' otherwise
        void add(Contact* c);                               //add pointer to user-provided contact to the 'contacts' array
        void remove(std::string name);                      //delete a given contact (specified by name) from the 'Phonebook'
        int indexof(std::string name) const;                //returns index of a contact name if it exists in the Phonebook, or -1 otherwise
        void listall();                                     //iterates through all Contacts stored in the phonebook and writes them to standard out
        int getsize();                                      //returns the size of the Contact array
        int getcontactnum();                                //returns the number of contacts stored in the Phonebook
    
};

#endif
