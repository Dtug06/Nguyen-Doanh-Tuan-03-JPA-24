#ifndef DATATYPES_H
#define DATATYPES_H

#define MAX_BOOKS 100
#define MAX_CUSTOMERS 100

typedef struct {
    int id;
    char name[100];
    char author[50];
    int price;
    int quantity; // Thay ð?i t? category sang quantity
} Book;

typedef struct {
    int id;
    char name[100];
    char phoneNumber[20];
    char address[200];
    int status; // 0: active, 1: locked
} Customer;

#endif

