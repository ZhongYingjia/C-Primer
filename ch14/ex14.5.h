#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book{
    friend std::istream &operator>>(std::istream&, Book&);
    friend std::ostream &operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
public:
    Book() = default;
    Book(unsigned No, std::string name, std::string author, std::string pubdate)
        :No_(No), name_(name), author_(author), pubdate_(pubdate){ }
    Book(std::istream& is){ is >> *this; }

private:
    unsigned No_;
    std::string name_;
    std::string author_;
    std::string pubdate_;

};
std::istream &operator>>(std::istream&, Book&);
std::ostream &operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);



#endif