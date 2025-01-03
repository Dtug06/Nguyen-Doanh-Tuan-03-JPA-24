#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
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

void displayBooks(Book books[], int bookCount) {
	system("cls"); 
    printf("\n-------------------------------------------------------------------------------------------- Display Books --------------------------------------------------------------------------------------------\n");
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
    printf("| %-4s | %-60s | %-60s | %-8s | %-40s |\n", "ID", "Name", "Author", "Price", "Category");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("| %-4d | %-60s | %-60s | %-8d | %-40s |\n",
               books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
    }
}


void addBook(Book books[], int *bookCount) {
	system("cls"); 
    if (*bookCount >= MAX_BOOKS) {
        printf("Book storage is full.\n");
        return;
    }

    Book newBook;
    int isValid = 0;

    while (!isValid) {
        newBook.id = *bookCount + 1;
        newBook.isDeleted = 0; 

        printf("\n-------------------------------------------------------------------------------------------- Add New Book --------------------------------------------------------------------------------------------\n");
        printf("| %-4s | %-60s | %-60s | %-8s | %-40s |\n", "ID", "Name", "Author", "Price", "Category");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("%d \n ", newBook.id);

        printf("Enter book name: ");
        fgets(newBook.name, sizeof(newBook.name), stdin);
        newBook.name[strcspn(newBook.name, "\n")] = '\0';
        printf("%s\n ", newBook.name);

        printf("Enter author name: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0';
        printf("%s \n ", newBook.author);

        printf("Enter book price: ");
        scanf("%d", &newBook.price);
        getchar(); 
        printf("%d\n ", newBook.price);

        printf("Enter book category: ");
        fgets(newBook.category, sizeof(newBook.category), stdin);
        newBook.category[strcspn(newBook.category, "\n")] = '\0';
        printf("%s \n", newBook.category);

        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        isValid = validateBook(books, *bookCount, &newBook);
        if (!isValid) {
            printf("Invalid data. Please enter the book information again.\n");
        }
    }

    books[(*bookCount)++] = newBook;
    printf("Book added successfully!\n");
}


void updateBook(Book books[], int bookCount) {
	system("cls");
    int id;
    printf("\n-------------------------------------------------------------------------------------------- Update Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter book ID to update: ");
    scanf("%d", &id);
    getchar();

    if (id <= 0 || id > bookCount) {
        printf("Invalid book ID.\n");
        return;
    }

    Book *book = &books[id - 1];

    printf("Enter new book name (current: %s): ", book->name);
    fgets(book->name, sizeof(book->name), stdin);
    book->name[strcspn(book->name, "\n")] = '\0';

    printf("Enter new author name (current: %s): ", book->author);
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter new book price (current: %d): ", book->price);
    scanf("%d", &book->price);
    getchar(); 

    printf("Enter new book category (current: %s): ", book->category);
    fgets(book->category, sizeof(book->category), stdin);
    book->category[strcspn(book->category, "\n")] = '\0';

    printf("Book updated successfully!\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void deleteBook(Book books[], int *bookCount) { 
    int id;
    printf("\n-------------------------------------------------------------------------------------------- Delete  Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    getchar();

    if (id <= 0 || id > *bookCount) {
        printf("Invalid book ID.\n");
        return;
    }

    for (int i = id; i < *bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    for (int i=0;i<*bookCount;i++){
    	books[i].id =i+1; 
    } 
    (*bookCount)--; 
    printf("Book deleted successfully!\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void searchBookByName(Book books[], int bookCount) {
	system("cls");
    char name[100];
    printf("\n-------------------------------------------------------------------------------------------- Sreach  Book --------------------------------------------------------------------------------------------\n");
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
            printf("Category: %s\n", books[i].category);
            printf("--------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the name \"%s\".\n", name);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void sortBooksByPrice(Book books[], int bookCount,int choice ) {
	system("cls");
    printf("1 Sap xep tang dan \n");
    printf("2 Sap xep giam dan \n");
    fflush(stdin); 
    scanf("%d",&choice );
    switch (choice){
    	case 1://Tang dan 
	    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].price > books[j + 1].price) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    } 
    break ; 
    case 2://giam dan 
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].price < books[j + 1].price) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    } 
    break ; 
    default ://truong hop khac 
    printf ("khong hop le \n "); 
    } 
    printf("Books sorted by price successfully!\n");
}

void saveData(Book books[], int bookCount, const char* filename) {
	system("cls"); 
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
        printf("Books loaded successfully from %s\n", filename);
    } else {
        printf("No data file found. Starting with an empty book list.\n");
    }
}
int validateBook(Book books[], int bookCount, Book *book) {
    int valid = 1;
    if (strlen(book->name) == 0 || strlen(book->name) > 200) {
        printf("Error: Book name is empty or too long.\n");
        valid = 0;
    }
    if (strlen(book->author) == 0 || strlen(book->author) > 200) {
        printf("Error: Author name is empty or too long.\n");
        valid = 0;
    }
    if (book->price <= 0) {
        printf("Error: Book price is invalid.\n");
        valid = 0;
    }
    if (strlen(book->category) == 0 || strlen(book->category) > 50) {
        printf("Error: Book category is empty or too long.\n");
        valid = 0;
    }
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isDeleted == 0 && strcmp(books[i].name, book->name) == 0) {
            printf("Error: Book name already exists.\n");
            valid = 0;
            break;
        }
    }

    return valid;
}



	





