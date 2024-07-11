#include "book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
 {
    int n, choice;
    char c;
    cout<<"Enter No of Books you want to enter in Store: ";
    cin>>n;

    Book* arr = new Book[n];
    for
    arr[0].storeBook(arr, n);

    do {
        cout<<"\nMENU\n1. Add Book\n2. Remove Book\n3. Search Book\n4. Update Book\n5. Top 3\n6. Display Book\n7. Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                int a, t;
                cout<<"No of Books you want to add: ";
                cin>>a;
                t = n + a;
                arr = (Book*)realloc(arr, sizeof(Book) * t);
                addBook(arr, n, t);
                break;
            case 2:
                removeBook(arr, &n);
                break;
            case 3:
                searchBook(arr, n);
                break;
            case 4:
                updateBook(arr, n);
                break;
            case 5:
                top3(arr, n);
                break;
            case 6:
                for(int i = 0; i < n; i++) {
                    arr[i].display();
                }
                break;
            case 7:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please enter a valid choice.\n";
        }

        cout<<"\nDo You want to Continue (y/n): ";
        cin>>c;
    } while (c == 'y' || c == 'Y');
}
