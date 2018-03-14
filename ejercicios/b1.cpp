#include "pila.h"

Book getBook() {
    Book book; // Crear libro

    // Pedir información libro
    std::cout << "Titulo: " << '\n';
    std::cin >> book.title;
    std::cout << "Autor: " << '\n';
    std::cin >> book.author;
    std::cout << "Año: " << '\n';
    std::cin >> book.year;

    return book; // devolver libro
}

std::string chooseTitle() {
    std::string title;
    std::cout << "Título? " << '\n';
    std::cin >> title;
    return title;
}

void createBooks(Stack& books) {
    Book book;

    book.title = "a";
    book.author = "aa";
    book.year = 1111;
    books.push(book);

    book.title = "b";
    book.author = "bb";
    book.year = 2222;
    books.push(book);

    book.title = "c";
    book.author = "cc";
    book.year = 3333;
    books.push(book);
}

void takeBackBooks(Stack& discarded, Stack& books) {
    Book book;
    do {
        book = discarded.pop();
        if (book.title != "") {
            books.push(book);
        }
    } while(book.title != "");
}

bool findBook(std::string title, Stack& books) {
    Stack discarded;
    discarded.init();
    Book book;
    bool found = false;

    do {
        book = books.pop(); // Sacar libro
        if (title == book.title) { // Mirar título
            found = true;
            break;
        } else if (book.title != "") {
            discarded.push(book);
        }
    } while((book.title != "") && (title != book.title));
    // Mientras hay libros en la pila y no hemos encontrado el libro
    discarded.print();
    // Devolver libros a la pila orginal vaciando la temporal
    takeBackBooks(discarded, books);
    return found;
}

int main() {
    Stack books;
    books.init();
    createBooks(books);
    books.print();

    std::string title = chooseTitle();
    bool found = findBook(title, books);
    books.print();
    if (found) {
        std::cout << "Toma tu libro" << '\n';
    } else {
        std::cout << "No he encontrado tu asqueroso libro" << '\n';
    }
}
