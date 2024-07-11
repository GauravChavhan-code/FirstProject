#include<iostream>
using namespace std;
class Book
{
	char Bookname[30];
    char AuthorName[30]; // Changed from char to char array for AuthorName
    char Isbn[15]; // Changed from char to char array for Isbn
    double Price;
    double rating;
    
    public:
    	Book();
    	Book(char*,char*,char*,double,double);
    	void setBookname(char* );
    	void setIsbn(char* );
    	void setAuthorname(char*);
    	void setPrice(double); 
    	void setrating(double);
        char* getBookname();
    	char* getIsbn();
    	char* getAuthorname();
    	double getPrice();
    	double getrating();
    	void storeBook(Book* , int );
        void addBook(Book* , int& , int );
        void removeBook(Book* , int* );
        void searchBook(Book*, int );
        void searchbyBook(Book* , int);
        void searchbyIsbn(Book* , int );
        void updateBook(Book* , int );
        void top3(Book* , int );
        void maxPrice(Book* , int );
        void maxrating(Book* , int );
        void display();
};