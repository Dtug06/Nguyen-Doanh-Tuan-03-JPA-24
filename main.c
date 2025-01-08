#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    int choice, sapXep;
    Book books[MAX_BOOKS];
    int bookCount = 0;
    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;

    loadData(books, &bookCount, "books.dat");
    loadCustomers(customers, &customerCount, "customers.dat");

    while (1) {
        printf("Nhap 1 de quan ly sach , nhap 2 de quan ly khach hang, bay ky de thoat  ");
        int mainChoice;
        scanf("%d", &mainChoice);
        getchar();

        if (mainChoice == 1) {
            printMenu();
            printf("Select choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice) {
                case 1:
                    displayBooks(books, bookCount);
                    break;
                case 2:
                    addBook(books, &bookCount);
                    saveData(books, bookCount, "books.dat");
                    break;
                case 3:
                    updateBook(books, bookCount);
                    saveData(books, bookCount, "books.dat");
                    break;
                case 4:
                    displayBooks(books, bookCount);
                    deleteBook(books, &bookCount);
                    saveData(books, bookCount, "books.dat");
                    break;
                case 5:
                    searchBookByName(books, bookCount);
                    break;
                case 6:
                    printf("Chon cach sap xep: 1. Tang dan 2. Giam dan  3. Theo bang chu cai: ");
                    scanf("%d", &sapXep);
                    getchar();
                    sortBooksByPrice(books, bookCount, sapXep);
                    displayBooks(books, bookCount);
                    break;
                case 7:
                    saveData(books, bookCount, "books.dat");
                    printf("Data saved. Exiting program.\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else if (mainChoice == 2) {
            printCustomerMenu();
            printf("Select choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice) {
                case 1:
                    displayCustomers(customers, customerCount);
                    break;
                case 2:
                    addCustomer(customers, &customerCount);
                    saveCustomers(customers, customerCount, "customers.dat");
                    break;
                case 3:
                    updateCustomer(customers, customerCount);
                    saveCustomers(customers, customerCount, "customers.dat");
                    break;
                case 4:
                    toggleCustomerStatus(customers, customerCount);
                    saveCustomers(customers, customerCount, "customers.dat");
                    break;
                case 5:
                    searchCustomerByName(customers, customerCount);
                    break;
                case 6:
                    borrowBooks(customers, customerCount, books, bookCount);
                    saveData(books, bookCount, "books.dat");
                    break;
                case 7:
                    returnBooks(customers, customerCount, books, bookCount);
                    saveData(books, bookCount, "books.dat");
                    break;
                case 8:
			  deleteCustomer(customers,  &customerCount);
                    break; 
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else {
            printf("Exiting program.\n");
            break; 
        }
    }

    return 0;
}

