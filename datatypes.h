#ifndef DATATYPES_H
#define DATATYPES_H

#define MAX_BOOKS 100

typedef struct {
    int id;
    char name[100];
    char author[50];
    int price;
    char category[50]; 
} Book;

#endif

