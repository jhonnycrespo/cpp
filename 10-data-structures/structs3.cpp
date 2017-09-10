/**
 * The typedef keyword
 *
 * There is an easier way to define structs or you could "alias" types you create. 
 */

typedef struct {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;


int main() {
    // Now, you can use Books directly to define variables of Books type without using struct keyword.
    Books Book1, Book2;
}