# PHONEBOOK-DIRECTORY-USING-DOUBLY-LINKED-LIST

This project is a Phonebook Directory implemented in C, using a doubly linked list data structure. The application allows users to create, view, update, search, and delete contacts. Each contact consists of a name, phone number, and email.

## Features

- **Add Contact**: Allows users to create and add a new contact to the directory.
- **Display Contacts**: Displays all contacts in the directory in a sorted manner.
- **Update Contact**: Provides the functionality to update existing contact details.
- **Search Contacts**: Supports searching by name, phone number, or email.
- **Delete Contact**: Allows users to delete a contact from the directory.
- **Sort Contacts**: Sorts contacts for easy viewing.

## Getting Started

### Prerequisites

- C compiler (such as GCC)

### Installation

1. Clone this repository or download the code file.
2. Compile the code using a C compiler.
3. Run the compiled program.

## Usage

Upon running the program, follow the on-screen prompts to interact with the phonebook. Menu options include adding, updating, searching, and deleting contacts.

## Functions

- **`menu()`**: Main menu to navigate between different functionalities.
- **`create()`**: Adds a new contact.
- **`display()`**: Displays all contacts in sorted order.
- **`update()`**: Updates an existing contact's details.
- **`search()`**: Searches for a contact by name, phone number, or email.
- **`deletecontact()`**: Deletes a specific contact from the directory.

## Data Structure

The phonebook utilizes a doubly linked list where each node stores:
- `name`: Name of the contact
- `number`: Contact's phone number
- `mail`: Contact's email address
- `next` and `prev`: Pointers to the next and previous nodes, respectively

## Example

1. Enter your name when prompted to personalize the experience.
2. Use the menu options to add and manage contacts.