#include <iostream> 
#include "Phonebook.h"
#include "Contact.h"

/*
 * Phonebook Class implementation written by: Derek Avery
 *
 * Written for CS 300: Assignment 1 - Bellevue College
 *
 * Due 2018/10/08
 *
 */


// Constructor //

/*
 * This is the primary constructor for the phonebook class; it allocates memory for an array of
 * the specified capacity and stores this capacity in the 'size' field. When instantiated, the Phonebook
 * is empty, and therefore the 'contactnum' field is initialized to a value of 0.
 */
Phonebook::Phonebook(int _size) {
    size = _size;                               //set 'size' field  equal to size argument
	contacts = new Contact*[size];               //dynamically allocate memory for array to hold Contact* pointers
    contactnum = 0;                             //set number of contacts equal to 0
}

// Methods //

/*
 * Basic 'getter' method returning the size of the Phonebook's
 * Contact array (size)
 */
int Phonebook::getcontactnum() {
    return size;
}

/*
 * Basic 'getter' method returning the number of contacts stored
 * in the Phonebook (contactnum)
 */
int Phonebook::getsize() {
    return contactnum;
}

/*
 *  Upsizes the 'contacts' array by factor of two
 *  and copies over all existing elements
 */
void Phonebook::upsize() {
	//create enlarged array (double size)
	Contact** copy = new Contact*[size*2];
	
	//copy over all Contacts to new array element-by-element
    for(int i = 0; i < size; i++) {
        copy[i] = contacts[i];
    }
    
    //double the size field to reflect new array size
    size *= 2;
		
    //release memory from old array
	delete[] contacts;
    
    //reassign contacts pointer to the new array
	contacts = copy;
}

/* 
 * Returns value of the index where a contact name (non-case sensitive) exists
 * in 'contacts' or -1 if it does not exist in the Phonebook
 */
int Phonebook::indexof(std::string _name) const {
    //convert the contact name argument string to upper-case
    std::transform(_name.begin(), _name.end(), _name.begin(), ::toupper);
    
	// iterate through each contact pointed in array and check
    // if its 'name' field is equal to 'checkname'
	for(int i = 0; i < contactnum; i++) {
        //store current contact name as upper-case string
        std::string curname = contacts[i] -> getName();
        
        //convert curname string to upper case
        for(int i = 0; i < curname.size(); i++)
            std::transform(curname.begin(), curname.end(), curname.begin(), ::toupper);

        //return 1 (true) if the current contact is equal to 'checkname'
        if(curname.compare(_name) == 0) {
			return i;
        }
	}
    //if name is not found in the contacts array, return -1
	return -1;
}

/*
 * This method will add a Contact to the Phonebook 'contacts' array at the next available entry,
 * and increment the contactnum to correspond to the new number of contacts stored in the Phonebook
 */
void Phonebook::add(Contact* c) {
    //check if contacts array can hold another contact; if not, upsize it
    if(size <= contactnum + 1) {
        upsize();
    }
    //add new Contact to the contacts array and increment contactnum
    contacts[contactnum] = c;
    contactnum++;
}

/*
 * This method will remove a contact from the phonebook (searched by name) IFF the contact
 * exists, and will shift all remaining contacts at indices above the index of the removed
 * Contact down by one to make sure contacts fill the array from the 'bottom up'
 */
void Phonebook::remove(std::string _name) {
    //find the index of the contact (if such a contact exists)
    int contact_index = indexof(_name);
    
    //check to make sure the contact exists; if so, 'delete' it
    if(contact_index != -1) {
        //shift elements in 'contacts' at indices > contact_index down by 1
        for(int i = contact_index; i < contactnum; i++)
            contacts[i] = contacts[i+1];
        //decrement the number of contacts by one due to deletion
        contactnum--;
    }
}

/*
 * This method will return a string containing the contact number corresponding
 * to the passed 'name' parameter, assuming that the name exists in a contact element
 * in the Phonebook. If the name does not exist, the string returned will contain output
 * indicating to the user that the contact does not exist, with the string 'name not found'
 */

std::string Phonebook::search(std::string _name) const {
    int index = indexof(_name);
    if(index != -1) {               //check that the name exists in the phonebook
        return contacts[index] -> getNumber();
    } else {
        return "NAME NOT FOUND";
    }
}

/*
 * This method will print all of the contacts' name/numbers
 * stored in the Phonebook to standard out, in the order in
 * which they are stored
 */
void Phonebook::listall() {
    for(int i = 0; i < contactnum; i++)
        std::cout << (*contacts[i]);
}
