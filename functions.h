

#include "datatypes.h"

void printMenu();
void displayBooks(Book books[], int bookCount);
void addBook(Book books[], int *bookCount);
void updateBook(Book books[], int bookCount);
void deleteBook(Book books[], int *bookCount);
void searchBookByName(Book books[], int bookCount);
void sortBooksByPrice(Book books[], int bookCount,int choice );
void saveData(Book books[], int bookCount, const char* filename);
void loadData(Book books[], int *bookCount, const char* filename);
int validateBook(Book books[], int bookCount, Book *book);
 

