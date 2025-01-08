#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "datatypes.h"

void printMenu();
void printCustomerMenu();
void displayBooks(Book books[], int bookCount);
void addBook(Book books[], int *bookCount);
void updateBook(Book books[], int bookCount);
void deleteBook(Book books[], int *bookCount);
void searchBookByName(Book books[], int bookCount);
void sortBooksByPrice(Book books[], int bookCount, int choice);
void saveData(Book books[], int bookCount, const char* filename);
void loadData(Book books[], int *bookCount, const char* filename);
void displayCustomers(Customer customers[], int customerCount);
void addCustomer(Customer customers[], int *customerCount);
void updateCustomer(Customer customers[], int customerCount);
void toggleCustomerStatus(Customer customers[], int customerCount);
void searchCustomerByName(Customer customers[], int customerCount);
void borrowBooks(Customer customers[], int customerCount, Book books[], int bookCount);
void returnBooks(Customer customers[], int customerCount, Book books[], int bookCount);
void saveCustomers(Customer customers[], int customerCount, const char* filename);
void loadCustomers(Customer customers[], int *customerCount, const char* filename);
void deleteCustomer(Customer customers[], int *customerCount);

#endif

