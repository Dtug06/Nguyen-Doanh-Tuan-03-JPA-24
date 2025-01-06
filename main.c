#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    int choice,sapXep; 
    Book books[MAX_BOOKS];
    int bookCount = 0;
  
    loadData(books, &bookCount, "books.dat"); 
    char  leaveOrExit;
  
    while (1) {
    	   printf("nhan a de mo menu , nhan bat ky  de thoat ") ;
    	   fflush (stdin );
		  scanf(" %c",&leaveOrExit);
		  if (leaveOrExit=='a'){
		  	printf("Open menu "); 
		  } else 
		  return 0; 
		   
        printMenu();
        printf("Select choice: ");
        scanf("%d", &choice);
        getchar(); 
        

        switch (choice) {
            case 1: //in danh sach sach ra man hinh  
                displayBooks(books, bookCount);          
                break;
            case 2://them sach vao mang  
                addBook(books, &bookCount);
                saveData(books, bookCount, "books.dat");
                
                break;
            case 3://cap nh?t lai thong tin sach  
                updateBook(books, bookCount);
                saveData(books, bookCount, "books.dat"); 
                
                break;
            case 4://xoa sach vi tri cu the  
            	displayBooks(books, bookCount);
                deleteBook(books, &bookCount);
                saveData(books, bookCount, "books.dat");
			  
                break;
            case 5://tim kiem sach  
                searchBookByName(books, bookCount);
               
                break;
            case 6:// sap xep sach theo gia tien (giam/tang dan ) 
                sortBooksByPrice(books, bookCount,sapXep);	
                displayBooks(books, bookCount);
			 	  
                break; 
            case 7 ://thoat  
                saveData(books, bookCount, "books.dat");
                printf("Data saved. Exiting program.\n");              
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                
        }
    }

    return 0;
}

