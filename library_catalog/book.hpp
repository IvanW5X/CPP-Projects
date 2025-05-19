/*******************************************************
 * File Name: book.hpp
 * Date: 1/24/2025
 * Description: Header file for book structure and it
 *              specific functions
 * Author(s): Ivan Wong
 *******************************************************/

#pragma once

#include <iostream>
#include <string>

class Book
{
private:
    std::string __title;
    std::string __author;
    uint __year;
    uint __numBooks;

public:
    /* Constructors */
    Book();
    Book(std::string title, std::string author, uint year, uint num_books);
    Book(const Book& bookCopy);
    ~Book();

    /* Getters */
    const std::string getTitle();
    const std::string getAuthor();
    const uint getYear();
    const uint getNumBooks();

    /* Setters */


    

};
