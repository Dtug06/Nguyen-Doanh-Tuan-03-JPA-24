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
    printf("7. xoa du lieu file\n") ;
    printf("8. Save and Exit\n");
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

int validateBook(Book books[], int bookCount, char* name, char* author, char* category, int price, int currentIndex) {
    if (strlen(name) > 50) {
        printf("Error: Book name cannot exceed 50 characters.\n");
        return 0;
    }

    if (strlen(author) > 50) {
        printf("Error: Author name cannot exceed 50 characters.\n");
        return 0;
    }

    if (strlen(category) > 50) {
        printf("Error: Book category cannot exceed 50 characters.\n");
        return 0;
    }

    if (price < 0) {
        printf("Error: Book price cannot be negative.\n");
        return 0;
    }

    for (int i = 0; i < bookCount; i++) {
        if (i != currentIndex && strcmp(books[i].name, name) == 0) {
            printf("Error: Book name already exists.\n");
            return 0;
        }
    }

    return 1;
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
        printf("Book ID %d not found.\n", id);
    }
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

    char newName[100], newAuthor[100], newCategory[100];
    int newPrice;

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
            if (i != id - 1 && strcmp(books[i].name, newName) == 0) {
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
        printf("Enter new book category (current: %s): ", book->category);
        fgets(newCategory, sizeof(newCategory), stdin);
        newCategory[strcspn(newCategory, "\n")] = '\0';

        if (strlen(newCategory) > 50) {
            printf("Error: Book category cannot exceed 50 characters. Please re-enter.\n");
            continue;
        }

        break;
    } while (1);
    strcpy(book->category, newCategory);

    printf("Book updated successfully!\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void addBook(Book books[], int *bookCount) {
    system("cls");
    printf("\n-------------------------------------------------------------------------------------------- Add  Book --------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    if (*bookCount >= MAX_BOOKS) {
        printf("Book storage is full.\n");
        return;
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
        printf("Enter book category: ");
        fgets(newBook.category, sizeof(newBook.category), stdin);
        newBook.category[strcspn(newBook.category, "\n")] = '\0';

        if (strlen(newBook.category) > 50) {
            printf("Error: Book category cannot exceed 50 characters. Please re-enter.\n");
            continue;
        }

        break;
    } while (1);

    books[(*bookCount)++] = newBook;
    printf("Book added successfully!\n");
}
void clearFileData(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
        printf("Data in file %s has been cleared successfully.\n", filename);
    } else {
        printf("Error clearing data in file %s.\n", filename);
    }
}




