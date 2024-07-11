#include"book.h"

Book::Book()
{
	strcpy(this->Bookname,"Not Given");
    strcpy(this->AuthorName,"Not Given"); 
    strcpy(this->Isbn,"Not Given"); 
    Price=0;
    rating=0;
}
//////////////////////////////////////////////////
Book::Book(char* bn,char* an,char* isb,double p,double r)
{
	strcpy(this->Bookname,bn);
    strcpy(this->AuthorName,an); 
    strcpy(this->Isbn,isb); 
    this->Price=p;
    this->rating=r;
}
//////////////////////////////////////////////////

void Book::setBookname( char* bn )
{
	strcpy(this->Bookname,bn);
}
//////////////////////////////////////////////////
void Book::setIsbn( char* isb)
{
	strcpy(this->Isbn,isb);
}
//////////////////////////////////////////////////
void Book::setAuthorname(char* an)
{
	strcpy(this->AuthorName,an); 
}
//////////////////////////////////////////////////
void Book::setPrice(double p)
{
	this->Price=p;
}
//////////////////////////////////////////////////
void Book::setrating(double r)
{
	this->rating=r;
}
//////////////////////////////////////////////////
char* Book::getBookname()
{
	return this->Bookname;
}
//////////////////////////////////////////////////
char* Book::getIsbn()
{
	return this->Isbn;
}
//////////////////////////////////////////////////
char* Book::getAuthorname()
{
	return this->Authorname;
}
//////////////////////////////////////////////////
double Book::getPrice()
{
	return this->Price;
}
//////////////////////////////////////////////////
double Book::getrating()
{
	return this->rating;
}
//////////////////////////////////////////////////
void Book::storeBook(Book* arr, int n)
{
	char nme[30], author[30], isbn[15];
    double price, rating;

    for(int i = 0; i < n; i++) {
        cout<<"Book Name: ";
        cin.ignore(); // Ignore newline character in buffer
        cin.getline(nme, 30);
        arr[i].setBookname(nme);

        cout<<"Author name: ";
        cin.getline(author, 30);
        arr[i].setAuthorname(author);

        cout<<"ISBN no: ";
        cin.getline(isbn, 15);
        arr[i].setIsbn(isbn);

        cout<<"Price: ";
        cin>>price;
        arr[i].setPrice(price);

        cout<<"Rating: ";
        cin>>rating;
        arr[i].setrating(rating);
    }
}
//////////////////////////////////////////////////
void Book::addBook(Book* arr, int& n, int t)
{
	char nme[30], author[30], isbn[15];
    double price, rating;

    for(int i = n; i < t; i++) {
        cout<<"Book Name: ";
        cin.ignore();
        cin.getline(nme, 30);
        arr[i].setBookname(nme);

        cout<<"Author name: ";
        cin.getline(author, 30);
        arr[i].setAuthorname(author);

        cout<<"ISBN no: ";
        cin.getline(isbn, 15);
        arr[i].setIsbn(isbn);

        cout<<"Price: ";
        cin>>price;
        arr[i].setPrice(price);

        cout<<"Rating: ";
        cin>>rating;
        arr[i].setrating(rating);
    }

    n = t; // Update the number of books in the array
}
//////////////////////////////////////////////////
void Book::removeBook(Book* arr, int* n)
{
	char isbn[15];
    cout<<"Enter the ISBN Number of the Book to remove: ";
    cin.ignore();
    cin.getline(isbn, 15);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(arr[i].getIsbn(), isbn) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            cout<<"Book with ISBN Number "<<isbn<<" removed.\n";
            break;
        }
    }

    if (found == 0) 
	{
        cout<<"Book with ISBN Number "<<isbn<<" not found.\n";
    }
}
//////////////////////////////////////////////////
void Book::searchBook(Book* arr, int n)
{
	int choice;
    cout<<"\nSearch Book By:\n1. Name\n2. ISBN No\nEnter Choice for Search: ";
    cin>>choice;

    switch (choice)
	 {
        case 1:
            searchbyBook(arr, n);
            break;
        case 2:
            searchbyIsbn(arr, n);
            break;
        default:
            cout<<"Invalid Choice! Please enter a valid choice.\n";
    }
}
//////////////////////////////////////////////////
void Book::searchbyBook(Book* arr, int n)
{
	char searchname[30];
    cout<<"\nEnter Book name you want to search: ";
    cin.ignore();
    cin.getline(searchname, 30);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if (strcmp(arr[i].getBookname(), searchname) == 0) {
            count++;
            arr[i].display();
        }
    }

    if(count == 0)
	 {
        cout<<"Book not found! Please enter a valid name.\n";
    }
}
//////////////////////////////////////////////////
void Book::searchbyIsbn(Book* arr, int n)
{
	char isbn[15];
    cout<<"\nEnter ISBN No you want to search: ";
    cin.ignore();
    cin.getline(isbn, 15);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if (strcmp(arr[i].getIsbn(), isbn) == 0) {
            count++;
            arr[i].display();
        }
    }

    if(count == 0)
    {
        cout<<"Book not found! Please enter a valid ISBN number.\n";
    }
}
//////////////////////////////////////////////////
void Book::updateBook(Book* arr, int n)
{
	char isbn[15];
    cout<<"\nEnter ISBN No you want to update: ";
    cin.ignore();
    cin.getline(isbn, 15);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].getIsbn(), isbn) == 0) {
            count++;
            int choice;
            cout<<"\nUpdate Book:\n1. Price\n2. Rating\nEnter choice: ";
            cin>>choice;

            switch (choice) {
                case 1:
                    double price;
                    cout<<"Update Price: ";
                    cin>>price;
                    arr[i].setPrice(price);
                    cout<<"Book with ISBN Number "<<isbn<<" 's price updated.\n";
                    break;
                case 2:
                    double rating;
                    cout<<"Update rating: ";
                    cin>>rating;
                    arr[i].setrating(rating);
                    cout<<"Book with ISBN Number "<<isbn<<" 's rating updated.\n";
                    break;
                default:
                    cout<<"Invalid choice! Please enter a valid choice.\n";
            }
        }
    }

    if (count == 0) 
	{
        cout<<"Book not found! Please enter a valid ISBN number.\n";
    }
}
//////////////////////////////////////////////////
void Book::top3(Book* arr, int n)
{
	int choice;
    cout<<"\nSearch Top 3 Stat By:\n1. Price\n2. Rating\nEnter Choice for Search: ";
    cin>>choice;

    switch (choice) 
	{
        case 1:
            maxPrice(arr, n);
            break;
        case 2:
            maxrating(arr, n);
            break;
        default:
            cout<<"Invalid Choice! Please enter a valid choice.\n";
    }
}
//////////////////////////////////////////////////
void maxPrice(Book* arr, int n)
{
	Book temp;

    for (int i = 0; i < n - 1; i++)
	 {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].getPrice() < arr[j + 1].getPrice()) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<<"Top 3 books with the highest Price:\n";
    for (int i = 0; i < 3 && i < n; i++) 
	{
        arr[i].display();
    }
}
//////////////////////////////////////////////////
void Book::maxrating(Book* arr, int n)
{
	Book temp;

    for (int i = 0; i < n - 1; i++)
	 {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].getrating() < arr[j + 1].getrating()) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<<"\nTop 3 books with the highest rating:\n";
    for (int i = 0; i < 3 && i < n; i++) 
	{
        arr[i].display();
    }
}
//////////////////////////////////////////////////
void Book::display()
{
	    cout<<"\nBOOK name: "<<this->Bookname;
        cout<<"\nAuthor name: "<<this->AuthorName;
        cout<<"\nISBN No: "<<this->Isbn;
        cout<<"\nPrice: "<<this->Price;
        cout<<"\nRating: "<<this->rating;
}
//////////////////////////////////////////////////