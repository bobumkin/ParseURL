#include "unitTest.h"
#include "url.h"

void unitTest()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}

void test1()
{
    const auto URL = ParseURL::parseURL("https://John:Dow@github.com:80/corporateshark/LUrlParser/?&query=ssl#q=frag");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "github.com");
    bool bPort = (URL.port_ == "80");
    bool bPath = (URL.path_ == "corporateshark/LUrlParser/");
    bool bQuery = (URL.query_ == "&query=ssl");
    bool bFragment = (URL.fragment_ == "q=frag");
    bool bUserName = (URL.userName_ == "John");
    bool bPassword = (URL.password_ == "Dow");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test1 ok\n";
    }
    else {
        std::cout << "Test1 error\n";
    }
}

void test2()
{
    const auto URL = ParseURL::parseURL("HTTPS://ESPN.com/BOLD/PATH?a=A&B=b");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "ESPN.com");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "BOLD/PATH");
    bool bQuery = (URL.query_ == "a=A&B=b");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test2 ok\n";
    }
    else {
        std::cout << "Test2 error\n";
    }
}

void test3()
{
    const auto URL = ParseURL::parseURL("https://[fe80::9a01:a7ff:feb1:7dc9]:80/corporateshark/LUrlParser");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "[fe80::9a01:a7ff:feb1:7dc9]");
    bool bPort = (URL.port_ == "80");
    bool bPath = (URL.path_ == "corporateshark/LUrlParser");
    bool bQuery = (URL.query_ == "");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test3 ok\n";
    }
    else {
        std::cout << "Test3 error\n";
    }
}

void test4()
{
    const auto URL = ParseURL::parseURL("https://www.youtube.com/watch?v=dQw4w9WgXcQ");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "www.youtube.com");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "watch");
    bool bQuery = (URL.query_ == "v=dQw4w9WgXcQ");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test4 ok\n";
    }
    else {
        std::cout << "Test4 error\n";
    }
}

void test5()
{
    const auto URL = ParseURL::parseURL("https://rt-solar.ru/about_company");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "rt-solar.ru");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "about_company");
    bool bQuery = (URL.query_ == "");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test5 ok\n";
    }
    else {
        std::cout << "Test5 error\n";
    }
}

void test6()
{
    const auto URL = ParseURL::parseURL("https://career.habr.com/vacancies/1000133783");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "career.habr.com");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "vacancies/1000133783");
    bool bQuery = (URL.query_ == "");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test6 ok\n";
    }
    else {
        std::cout << "Test6 error\n";
    }
}

void test7()
{
    const auto URL = ParseURL::parseURL("https://www.freeformatter.com/url-parser-query-string-splitter.html");

    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "www.freeformatter.com");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "url-parser-query-string-splitter.html");
    bool bQuery = (URL.query_ == "");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test7 ok\n";
    }
    else {
        std::cout << "Test7 error\n";
    }
}

void test8()
{
    const auto URL = ParseURL::parseURL("https://duckduckgo.com/?q=mark+twain&atb=v23_c&ia=web");
    
    bool bScheme = (URL.scheme_ == "https");
    bool bHost = (URL.host_ == "duckduckgo.com");
    bool bPort = (URL.port_ == "");
    bool bPath = (URL.path_ == "");
    bool bQuery = (URL.query_ == "q=mark+twain&atb=v23_c&ia=web");
    bool bFragment = (URL.fragment_ == "");
    bool bUserName = (URL.userName_ == "");
    bool bPassword = (URL.password_ == "");
    bool reqs = (bScheme && bHost && bPort && bPath
        && bQuery && bFragment && bUserName && bPassword);

    if (reqs) {
        std::cout << "Test8 ok\n";
    }
    else {
        std::cout << "Test8 error\n";
    }
}