#include <string>
using namespace std;

class BookNode {
public:
int id;
string name;
string type;
BookNode *next;

BookNode(int bookId, string bookName, string bookType, BookNode *ptr = 0) {
id = bookId; name = bookName; type = bookType; next = ptr;
}
BookNode() {
id = 0; name = ""; type = ""; next = 0;
}
};
