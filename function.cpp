#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "function.h"
#include "url.h"

void deleteBackSpace(std::string& URL)
{
    uint16_t size = URL.length();
    while (isspace(URL[size])) {
        URL[size] = '\0';
        --size;
    }
}

std::string enterURL()
{
    std::string URL;
    std::cout << "Enter URL : ";
    std::cin >> URL;
    deleteBackSpace(URL);
    return URL;
}

void startFunction()
{
    std::string stringURL = enterURL();
    const auto classURL = ParseURL::parseURL(stringURL);
    std::cout << classURL << std::endl;
}

#endif