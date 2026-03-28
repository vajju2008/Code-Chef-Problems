class contact:
    def __init__(self, name, email, mobile):
        self.name = name
        self.email = email
        self.mobile = phone

    def show(self):
        print("Name:", self.name)
        print("Email:", self.email)
        print("phone:", self.mobile)

    def update(self, name, phone=None, email=None):
        if phone:
            self.phone = phone
        if email:
            self.email = email


def add(contact_obj):
    if contact_obj.name in Contacts:
        print(f"Name is {contact_obj[name].name} already exists")
    else:q
        contact_obj[name] = contact_obj
        print(f"Name is {contact_obj[name].name} added")


def remove_contact(name):
    if name in Contacts:
        del Contacts[name]
        print(f"Name is {name} removed")
    else:
        print(f"Name is {name} not found")


def search_contact(name):
    if name in Contacts:
        name.show()
    else:
        print(f"Name is {name} not found")


def update_contact(name, phone, email):
    if name in Contacts:
        Contacts[name].update(phone, email)
        print(f"Name is {name} updated")
    else:
        print(f"Name is {name} not found")


def list_contacts():
    for c in Contacts.values():
        c.show()


Contacts = {}
while True:
    print("\n1.Add\n2.Remove\n3.Search\n4.update\n5.List\n6.Exit\n")
    choice = int(input("enter Choice"))
    if choice == 1:
        name = input("enter name:")
        email = input("enter Email:")
        phone = eval(input("enter phone:"))
        add(contact(name, email, phone))

    elif choice == 2:
        remove_contact(input("enter Name to remove:"))
    elif choice == 3:
        name = input("enter Name to search:")
        search_contact(name)
    elif choice == 4:
        name = input("Enter Name to Update:")
        phone = eval(input("Enter phone to Update:"))
        email = input("Enter Email to Update:")
        update_contact(name, phone, email)
    elif choice == 5:
        list_contacts()

if choice == 6:
        exit()


