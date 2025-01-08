#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void printMenu() {
    printf("\n---- Book Management Menu ----\n");
    printf("1. Display Books\n");
    printf("2. Add Book\n");
    printf("3. Update Book\n");
    printf("4. Delete Book\n");
    printf("5. Search Book by Name\n");
    printf("6. Sort Books by Price\n");
    printf("7. Save and Exit\n");    
    printf("Enter your choice: ");
}

void printCustomerMenu() {
    printf("\n---- Customer Management Menu ----\n");
    printf("1. Display Customers\n");
    printf("2. Add Customer\n");
    printf("3. Update Customer\n");
    printf("4. Toggle Customer Status\n");
    printf("5. Search Customer by Name\n");
    printf("6. Borrow Books\n");
    printf("7. Return Books\n");
    printf("8. Delete customers\n");
    printf("Enter your choice: ");
}

void displayBooks(Book books[], int bookCount) {
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------- Display Books --------------------------------------------------------------------------------------------\n");
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
    printf("| %-4s | %-60s | %-60s | %-8s | %-8s |\n", "ID", "Name", "Author", "Price", "Quantity");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("| %-4d | %-60s | %-60s | %-8d | %-8d |\n",
               books[i].id, books[i].name, books[i].author, books[i].price, books[i].quantity);
    }
}

void displayCustomers(Customer customers[], int customerCount) {
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------- Display Customers --------------------------------------------------------------------------------------------\n");
    if (customerCount == 0) {
        printf("No customers available.\n");
        return;
    }
    printf("| %-4s | %-30s | %-20s | %-50s | %-6s |\n", "ID", "Name", "Phone Number", "Address", "Status");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < customerCount; i++) {
        printf("| %-4d | %-30s | %-20s | %-50s | %-6s |\n",
               customers[i].id, customers[i].name, customers[i].phoneNumber, customers[i].address, customers[i].status == 0 ? "Active" : "Locked");
    }
}

void addBook(Book books[], int *bookCount) {
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------- Add  Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); 
    if (*bookCount >= MAX_BOOKS) {
        printf("Book storage is full.\n");
        return;
    }
    int numBooksToAdd;
    printf("Enter the number of books you want to add: ");
    scanf("%d", &numBooksToAdd);
    getchar();
    for (int n = 0; n < numBooksToAdd; n++) {
        if (*bookCount >= MAX_BOOKS) {
            printf("Book storage is full.\n");
            break;
        }
        Book newBook;
        do {
            printf("Enter book ID: ");
            scanf("%d", &newBook.id);
            getchar();

            int idExists = 0;
            for (int i = 0; i < *bookCount; i++) {
                if (books[i].id == newBook.id) {
                    printf("Error: Book ID already exists. Please re-enter.\n");
                    idExists = 1;
                    break;
                }
            }
            if (!idExists) {
                break;
            }
        } while (1);
        do {
            printf("Enter book name: ");
            fgets(newBook.name, sizeof(newBook.name), stdin);
            newBook.name[strcspn(newBook.name, "\n")] = '\0';
            if (strlen(newBook.name) > 50) {
                printf("Error: Book name cannot exceed 50 characters. Please re-enter.\n");
                continue;
            }
            int nameExists = 0;
            for (int i = 0; i < *bookCount; i++) {
                if (strcmp(books[i].name, newBook.name) == 0) {
                    printf("Error: Book name already exists. Please re-enter.\n");
                    nameExists = 1;
                    break;
                }
            }
            if (!nameExists) {
                break;
            }
        } while (1);
        do {
            printf("Enter author name: ");
            fgets(newBook.author, sizeof(newBook.author), stdin);
            newBook.author[strcspn(newBook.author, "\n")] = '\0';
            if (strlen(newBook.author) > 50) {
                printf("Error: Author name cannot exceed 50 characters. Please re-enter.\n");
                continue;
            }
            break;
        } while (1);
        do {
            printf("Enter book price: ");
            scanf("%d", &newBook.price);
            getchar();
            if (newBook.price < 0) {
                printf("Error: Book price cannot be negative. Please re-enter.\n");
                continue;
            }
            break;
        } while (1);
        do {
            printf("Enter book quantity: ");
            scanf("%d", &newBook.quantity);
            getchar();

            if (newBook.quantity < 0) {
                printf("Error: Book quantity cannot be negative. Please re-enter.\n");
                continue;
            }
            break;
        } while (1);
        books[(*bookCount)++] = newBook;
        printf("Book added successfully!\n");
    }
}
void addCustomer(Customer customers[], int *customerCount) {
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------- Add Customer --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); 
    if (*customerCount >= MAX_CUSTOMERS) {
        printf("Customer storage is full.\n");
        return;
    }
    int numCustomersToAdd;
    printf("Enter the number of customers you want to add: ");
    scanf("%d", &numCustomersToAdd);
    getchar();
    for (int n = 0; n < numCustomersToAdd; n++) {
        if (*customerCount >= MAX_CUSTOMERS) {
            printf("Customer storage is full.\n");
            break;
        }
        Customer newCustomer;
       while (1) {
            printf("Enter customer ID: ");
            scanf("%d", &newCustomer.id);
            getchar();
            int idExists = 0;
            for (int i = 0; i < *customerCount; i++) {
                if (customers[i].id == newCustomer.id) {
                    printf("Error: Customer ID already exists. Please re-enter.\n");
                    idExists = 1;
                    break;
                }
            }
            if (!idExists) break;
        }
        while (1) {
            printf("Enter customer name: ");
            fgets(newCustomer.name, sizeof(newCustomer.name), stdin);
            newCustomer.name[strcspn(newCustomer.name, "\n")] = '\0';
            if (strlen(newCustomer.name) >= 50) {
                printf("Error: Customer name cannot exceed 50 characters. Please re-enter.\n");
                continue;
            }
            break;
        }
        while (1) {
            printf("Enter phone number: ");
            fgets(newCustomer.phoneNumber, sizeof(newCustomer.phoneNumber), stdin);
            newCustomer.phoneNumber[strcspn(newCustomer.phoneNumber, "\n")] = '\0';
            int validPhone = 1;
            if (strlen(newCustomer.phoneNumber) != 10 || newCustomer.phoneNumber[0] != '0') {
                validPhone = 0;
            } else {
                for (int i = 0; i < 10; i++) {
                    if (newCustomer.phoneNumber[i] < '0' || newCustomer.phoneNumber[i] > '9') {
                        validPhone = 0;
                        break;
                    }
                }
            }
            if (!validPhone) {
                printf("Error: Phone number must start with 0 and be 10 digits long. Please re-enter.\n");
                continue;
            }

            int phoneExists = 0;
            for (int i = 0; i < *customerCount; i++) {
                if (strcmp(customers[i].phoneNumber, newCustomer.phoneNumber) == 0) {
                    printf("Error: Phone number already exists. Please re-enter.\n");
                    phoneExists = 1;
                    break;
                }
            }
            if (!phoneExists) break;
        }

        while (1) {
            printf("Enter address: ");
            fgets(newCustomer.address, sizeof(newCustomer.address), stdin);
            newCustomer.address[strcspn(newCustomer.address, "\n")] = '\0';
            if (strlen(newCustomer.address) >= 200) {
                printf("Error: Address cannot exceed 200 characters. Please re-enter.\n");
                continue;
            }
            break;
        }

        newCustomer.status = 0; 

        customers[(*customerCount)++] = newCustomer;
        printf("Customer added successfully!\n");
    }
}



void updateBook(Book books[], int bookCount) {
    system("cls");
    int id;
    printf("\n-------------------------------------------------------------------------------------------- Update Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter book ID to update: ");
    scanf("%d", &id);
    getchar();
    int found = 0;
    Book *book = NULL;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            book = &books[i];
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid book ID.\n");
        return;
    }

    char newName[100], newAuthor[100];
    int newPrice, newQuantity;

    do {
        printf("Enter new book name (current: %s): ", book->name);
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = '\0';

        if (strlen(newName) > 50) {
            printf("Error: Book name cannot exceed 50 characters. Please re-enter.\n");
            continue;
        }

        int nameExists = 0;
        for (int i = 0; i < bookCount; i++) {
            if (&books[i] != book && strcmp(books[i].name, newName) == 0) {
                printf("Error: Book name already exists. Please re-enter.\n");
                nameExists = 1;
                break;
            }
        }

        if (!nameExists) {
            break;
        }
    } while (1);
    strcpy(book->name, newName);

    do {
        printf("Enter new author name (current: %s): ", book->author);
        fgets(newAuthor, sizeof(newAuthor), stdin);
        newAuthor[strcspn(newAuthor, "\n")] = '\0';

        if (strlen(newAuthor) > 50) {
            printf("Error: Author name cannot exceed 50 characters. Please re-enter.\n");
            continue;
        }

        break;
    } while (1);
    strcpy(book->author, newAuthor);

    do {
        printf("Enter new book price (current: %d): ", book->price);
        scanf("%d", &newPrice);
        getchar();

        if (newPrice < 0) {
            printf("Error: Book price cannot be negative. Please re-enter.\n");
            continue;
        }

        break;
    } while (1);
    book->price = newPrice;

    do {
        printf("Enter new book quantity (current: %d): ", book->quantity);
        scanf("%d", &newQuantity);
        getchar();

                if (newQuantity < 0) {
            printf("Error: Book quantity cannot be negative. Please re-enter.\n");
            continue;
        }

        break;
    } while (1);
    book->quantity = newQuantity;

    printf("Book updated successfully!\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void deleteBook(Book books[], int *bookCount) {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    getchar();
    int found = 0;
    for (int i = 0; i < *bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            (*bookCount)--;
            printf("Book with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Book ID %d not found.\n");
    }
}
void deleteCustomer(Customer customers[], int *customerCount) {
    system("cls");
    int id;
    printf("Enter customer ID to delete: ");
    scanf("%d", &id);
    getchar();

    int found = 0;
    for (int i = 0; i < *customerCount; i++) {
        if (customers[i].id == id) {
            found = 1;
            for (int j = i; j < *customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            (*customerCount)--;
            printf("Customer with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Customer ID %d not found.\n", id);
    }
}


void searchBookByName(Book books[], int bookCount) {
    system("cls");
    char name[100];
    printf("\n-------------------------------------------------------------------------------------------- Search  Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter book name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].name, name) != NULL) {
            printf("ID: %d\n", books[i].id);
            printf("Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Price: %d\n", books[i].price);
            printf("Quantity: %d\n", books[i].quantity);
            printf("--------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the name \"%s\".\n", name);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void sortBooksByPrice(Book books[], int bookCount, int choice) {
    system("cls");
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("3. Sap xep theo bang chu cai\n");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice) {
        case 1: // Tang dan
            for (int i = 0; i < bookCount - 1; i++) {
                for (int j = 0; j < bookCount - i - 1; j++) {
                    if (books[j].price > books[j + 1].price) {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                }
            }
            break;
        case 2: // Giam dan
            for (int i = 0; i < bookCount - 1; i++) {
                for (int j = 0; j < bookCount - i - 1; j++) {
                    if (books[j].price < books[j + 1].price) {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                }
            }
            break;
        case 3: // Theo bang chu cai
            for (int i = 0; i < bookCount - 1; i++) {
                for (int j = 0; j < bookCount - i - 1; j++) {
                    if (strcmp(books[j].name, books[j + 1].name) > 0) {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    printf("Books sorted successfully!\n");
}

void saveData(Book books[], int bookCount, const char* filename) {
    
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&bookCount, sizeof(int), 1, file);
        fwrite(books, sizeof(Book), bookCount, file);
        fclose(file);
        printf("Books saved successfully to %s\n", filename);
    } else {
        printf("Error saving books to %s\n", filename);
    }
}

void loadData(Book books[], int *bookCount, const char* filename) {
    system("cls");
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        fread(bookCount, sizeof(int), 1, file);
        fread(books, sizeof(Book), *bookCount, file);
        fclose(file);
    }
}

void updateCustomer(Customer customers[], int customerCount) {
    system("cls");
    int id;
    printf("Enter customer ID to update: ");
    scanf("%d", &id);
    getchar();

    Customer *customer = NULL;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            customer = &customers[i];
            break;
        }
    }

    if (customer == NULL) {
        printf("Customer ID not found.\n");
        return;
    }

    while (1) {
        printf("Enter new customer name (current: %s): ", customer->name);
        fgets(customer->name, sizeof(customer->name), stdin);
        customer->name[strcspn(customer->name, "\n")] = '\0';
        if (strlen(customer->name) >= 50) {
            printf("Error: Customer name cannot exceed 50 characters. Please re-enter.\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Enter new phone number (current: %s): ", customer->phoneNumber);
        fgets(customer->phoneNumber, sizeof(customer->phoneNumber), stdin);
        customer->phoneNumber[strcspn(customer->phoneNumber, "\n")] = '\0';
        int validPhone = 1;
        if (strlen(customer->phoneNumber) != 10 || customer->phoneNumber[0] != '0') {
            validPhone = 0;
        } else {
            for (int i = 0; i < 10; i++) {
                if (customer->phoneNumber[i] < '0' || customer->phoneNumber[i] > '9') {
                    validPhone = 0;
                    break;
                }
            }
        }
        if (!validPhone) {
            printf("Error: Phone number must start with 0 and be 10 digits long. Please re-enter.\n");
            continue;
        }

        int phoneExists = 0;
        for (int i = 0; i < customerCount; i++) {
            if (strcmp(customers[i].phoneNumber, customer->phoneNumber) == 0 && &customers[i] != customer) {
                printf("Error: Phone number already exists. Please re-enter.\n");
                phoneExists = 1;
                break;
            }
        }
        if (!phoneExists) break;
    }

    while (1) {
        printf("Enter new address (current: %s): ", customer->address);
        fgets(customer->address, sizeof(customer->address), stdin);
        customer->address[strcspn(customer->address, "\n")] = '\0';
        if (strlen(customer->address) >= 200) {
            printf("Error: Address cannot exceed 200 characters. Please re-enter.\n");
            continue;
        }
        break;
    }

    printf("Customer updated successfully!\n");
}


void toggleCustomerStatus(Customer customers[], int customerCount) {
    
    int id;
    printf("Enter customer ID to toggle status: ");
    scanf("%d", &id);
    getchar();

    Customer *customer = NULL;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            customer = &customers[i];
            break;
        }
    }

    if (customer == NULL) {
        printf("Customer ID not found.\n");
        return;
    }

    customer->status = !customer->status;
    printf("Customer status toggled successfully!\n");
}

void searchCustomerByName(Customer customers[], int customerCount) {
   
    char name[100];
    printf("Enter customer name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        if (strstr(customers[i].name, name) != NULL) {
            printf("ID: %d\n", customers[i].id);
            printf("Name: %s\n", customers[i].name);
            printf("Phone Number: %s\n", customers[i].phoneNumber);
            printf("Address: %s\n", customers[i].address);
            printf("Status: %s\n", customers[i].status == 0 ? "Active" : "Locked");
            printf("--------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No customers found with the name \"%s\".\n", name);
    }
}

void borrowBooks(Customer customers[], int customerCount, Book books[], int bookCount) {
    
    int customerId;
    printf("Enter customer ID to borrow books: ");
    scanf("%d", &customerId);
    getchar();

    Customer *customer = NULL;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == customerId) {
            customer = &customers[i];
            break;
        }
    }

    if (customer == NULL) {
        printf("Customer ID not found.\n");
        return;
    }

    if (customer->status == 1) { // Khóa
        printf("Customer is currently locked.\n");
        return;
    }

    int bookId, quantity;
    printf("Enter book ID to borrow: ");
    scanf("%d", &bookId);
    getchar();

    Book *book = NULL;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }

    if (book == NULL) {
        printf("Book ID not found.\n");
        return;
    }

    printf("Enter quantity to borrow: ");
    scanf("%d", &quantity);
    getchar();

    if (quantity > book->quantity) {
        printf("Not enough books available.\n");
        return;
    }

    
    book->quantity -= quantity;

    printf("Books borrowed successfully!\n");
}



void returnBooks(Customer customers[], int customerCount, Book books[], int bookCount) {
    
    int customerId;
    printf("Enter customer ID to return books: ");
    scanf("%d", &customerId);
    getchar();

    Customer *customer = NULL;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == customerId) {
            customer = &customers[i];
            break;
        }
    }

    if (customer == NULL) {
        printf("Customer ID not found.\n");
        return;
    }

    int bookId, quantity;
    printf("Enter book ID to return: ");
    scanf("%d", &bookId);
    getchar();

    Book *book = NULL;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }

    if (book == NULL) {
        printf("Book ID not found.\n");
        return;
    }

    printf("Enter quantity to return: ");
    scanf("%d", &quantity);
    getchar();

    
    book->quantity += quantity;

    printf("Books returned successfully!\n");
}


void saveCustomers(Customer customers[], int customerCount, const char* filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&customerCount, sizeof(int), 1, file);
        fwrite(customers, sizeof(Customer), customerCount, file);
        fclose(file);
        printf("Customers saved successfully to %s\n", filename);
    } else {
        printf("Error saving customers to %s\n", filename);
    }
}

void loadCustomers(Customer customers[], int *customerCount, const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        fread(customerCount, sizeof(int), 1, file);
        fread(customers, sizeof(Customer), *customerCount, file);
        fclose(file);
    } 
}


