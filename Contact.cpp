#include "Contact.h"

/*
 * Contact class file written by:
 * 
 * Derek Avery
 * 
 * for CS 300 - Assignment 1 --- Bellevue College
 * 
 * Due 2018/10/08
 * 
 */

/*
 * Default constructor; instantiates a contact object with "null" name
 * and "null" number. These values will never be displayed to the user, as
 * the Phonebook class in which they are used will track which Contacts
 * have been added by the user via a Contact counter
 */
Contact::Contact() {
    Contact("NULL", "NULL");
}

/*
 * Main constructor, which initializes name/contact to the
 * _name and _number arguments passed to it.
 */
Contact::Contact(std::string _name, std::string _number) {
	name = _name;
	number = _number;
}

/*
 * Basic 'getter' method returning the 'name' field
 * of this class instance
 */
std::string Contact::getName() const {
	return name;
}

/*
 * Basic 'getter' method returning the 'number' field
 * of this class instance
 */
std::string Contact::getNumber() const {
	return number;
}

/*
 * Basic 'setter' method changing the 'name' field
 * of this class instance
 */
void Contact::changeName(std::string new_name) {
	name = new_name;
}

/*
 * Basic 'setter' method changing the 'number' field
 * of this class instance
 */
void Contact::changeNumber(std::string new_number) {
	number = new_number;
}

/*
 * Overloaded ostream::<< operator allows use of the << operator
 * to write a representative string to an output stream in the
 * format "name number", where 'name' and 'number' represent the
 * instance fields "name" and "number", respectively
 */
std::ostream &operator<<(std::ostream &os, Contact &c) {
    os << c.name << " " << c.number << std::endl;
    return os;
}
