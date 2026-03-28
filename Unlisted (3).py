class Contact:
    def __init__(self, name, phone, email):
        self.name = name
        self.phone = phone
        self.email = email

    def __str__(self):
        return f"Name: {self.name}, Phone: {self.phone}, Email: {self.email}"


class ContactBook:
    def __init__(self):
        # Dictionary: name -> Contact object
        self.contacts = {}

    # Add Contact
    def add_contact(self, name, phone, email):
        if name in self.contacts:
            print("Contact already exists.")
        else:
            self.contacts[name] = Contact(name, phone, email)
            print("Contact added successfully.")

    # Remove Contact
    def remove_contact(self, name):
        if name in self.contacts:
            del self.contacts[name]
            print("Contact removed successfully.")
        else:
            print("Contact not found.")

    # Search Contact
    def search_contact(self, name):
        if name in self.contacts:
            print(self.contacts[name])
        else:
            print("Contact not found.")

    # Update Contact
    def update_contact(self, name, phone=None, email=None):
        if name in self.contacts:
            if phone:
                self.contacts[name].phone = phone
            if email:
                self.contacts[name].email = email
            print("Contact updated successfully.")
        else:
            print("Contact not found.")

    # List All Contacts
    def list_contacts(self):
        if not self.contacts:
            print("No contacts available.")
        else:
            for contact in self.contacts.values():
                print(contact)


# ----------------------------
# Example Usage
# ----------------------------
if __name__ == "__main__":
    cb = ContactBook()

    cb.add_contact("Alice", "1234567890", "alice@email.com")
    cb.add_contact("Bob", "9876543210", "bob@email.com")

    print("\nAll Contacts:")
    cb.list_contacts()

    print("\nSearch Alice:")
    cb.search_contact("Alice")

    print("\nUpdate Alice:")
    cb.update_contact("Alice", phone="1112223333")

    print("\nAfter Update:")
    cb.search_contact("Alice")

    print("\nRemove Bob:")
    cb.remove_contact("Bob")

    print("\nFinal Contact List:")
    cb.list_contacts()