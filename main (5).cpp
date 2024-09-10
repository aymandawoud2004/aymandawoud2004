#include "BookList.h"
#include <ctime>
#include <cstdlib>
int main() {
BookList B1, B2;
BookNode n1;
B1.addToTail(1,"A Tale of Two Cities","novel");
B1.addToTail(2,"The Lord of the Rings","fiction");
B1.addToTail(3,"Death on the Nile","Mystery");
cout << "**** My 1st List of Books ****" << endl;
B1.printAll();
cout << "Number of Books =" << B1.listLength()<< endl<< endl;
if (B1.isInList("A Tale of Two Cities"))
cout << "My favourite Book:A Tale of Two Cities is in the list :)" << endl<< endl;
else
cout << "My favourite Book:A Tale of Two Cities is not in the list :(" << endl<< endl;
n1 = B1.deleteNode("The Lord of the Rings");
B2.addToTail(n1.id, n1.name,n1.type);
cout << "The deleted Book from the list is: " << n1.name << " with ID = " << n1.id << endl<< endl;
if (B1.isInList("The Lord of the Rings"))
cout << "My favourite Book:The Lord of the Rings is in the list :)" << endl<< endl;
else
cout<< "My favourite Book:The Lord of the Rings is not in the list :(" << endl<< endl;
n1 = B1.deleteIndexNode(1);
B2.addToTail(n1.id, n1.name,n1.type);
cout << "The deleted Book from ths list is: " << n1.name << "\twith ID = " << n1.id<< endl<< endl;
cout << "**** My 1st List of Books ****" << endl<< endl;
B1.printAll();
cout << "Number of Books =" << B1.listLength()<< endl<< endl;
cout << "**** My 2nd List of Books ****" << endl<< endl;
B2.printAll();
cout << "Number of Books =" << B2.listLength()<< endl<< endl;





    BookList myBooks, Group1, Group2, Group3, Group4;
    int count = 0;
    string name;
    string type;
    int randomGroup;

    // 1. Get the user input for the names of 16 different books.
    for (int i = 1; i <= 16; i++) {
        cout << " please Enter a book " << i << " name: ";
        cin >> name;
        cout << " please Enter a book " << i << " type: ";
        cin >> type;
        myBooks.addToTail(i, name, type);
    }

    

    // 3. get books to the groups .
    srand(time(0));
    while (count < 16) {
        randomGroup = rand() % 4 + 1;
        switch (randomGroup) {
            case 1:
                if (Group1.listLength() < 4) {
                    BookNode temp = myBooks.deleteIndexNode(count);
                    Group1.addToTail(temp.id, temp.name, temp.type);
                }
                break;
            case 2:
                if (Group2.listLength() < 4) {
                    BookNode temp = myBooks.deleteIndexNode(count);
                    Group2.addToTail(temp.id, temp.name, temp.type);
                }
                break;
            case 3:
                if (Group3.listLength() < 4) {
                    BookNode temp = myBooks.deleteIndexNode(count);
                    Group3.addToTail(temp.id, temp.name, temp.type);
                }
                break;
            case 4:
                if (Group4.listLength() < 4) {
                    BookNode temp = myBooks.deleteIndexNode(count);
                    Group4.addToTail(temp.id, temp.name, temp.type);
                }
                break;
        }
        count++;
    }

    cout << "Group1:" << endl;
    Group1.printAll();
    cout << "Group2:" << endl;
    Group2.printAll();
    cout << "Group3:" << endl;
    Group3.printAll();
    cout << "Group4:" << endl;
    Group4.printAll();

    

return 0;
}
