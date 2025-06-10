#include "utils.hpp"
/*******************************************************
 * File Name: util.cpp
 * Date: 5/18/2025
 * Description: Utilities function definitions for
 *              project
 * Author(s): Ivan Wong
 *******************************************************/

#include "utils.hpp"

Book* processBook(std::string line)
{
    std::string title;
    std::string author;
    std::string yearString;
    std::string numBooksString;

    std::istringstream tokenizer(line);
    std::getline(tokenizer, title, ',');
    std::getline(tokenizer, author, ',');
    std::getline(tokenizer, yearString, ',');
    std::getline(tokenizer, numBooksString);

    if (!tokenizer)
    {
        std::cerr << "Too few colons at proccessBook() from utils.cpp\n";
        return nullptr;
    }
    Book *newBook = new Book(title, author, (uint) stoi(yearString), (uint) stoi(numBooksString));

    if (newBook = nullptr)
    {
        std::cerr << "Memory allocation failed at processBook() from utile.cpp\n";
        return nullptr;
    }
    return newBook;
}