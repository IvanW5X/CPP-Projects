#include "book.hpp"
/*******************************************************
 * File Name:
 * Date: 1/24/2025
 * Description:
 * Author(s): Ivan Wong
 *******************************************************/

#include "book.hpp"

Book::Book()
{
    return;
}

Book::Book(std::string title, std::string author, uint year, uint numBooks) : 
    __title(title),
    __author(author),
    __year(year),
    __numBooks(numBooks)
{}

Book::Book(const Book &bookCopy)
{
    return;
}

Book::~Book()
{
}

const std::string Book::getTitle() { return this->__title; }
const std::string Book::getAuthor() { return this->__author; }
const uint Book::getYear() { return this->__year; }
const uint Book::getNumBooks() { return this->__numBooks; }

void Book::setTitle(const std::string &title) { this->__title = title; }
void Book::setAuthor(const std::string &author) {this->__author = author; }
void Book::setYear(const uint year) { this->__year = year; }
void Book::setNumBooks(const uint numBooks) {this->__numBooks - numBooks; }
