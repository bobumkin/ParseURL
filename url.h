#ifndef URL_H_
#define URL_H_

#include <string>
#include <iostream>

enum UrlParserError
{
	UrlParserError_Ok = 0,
	UrlParserError_Uninitialized = 1,
	UrlParserError_NoUrlCharacter = 2,
	UrlParserError_InvalidSchemeName = 3,
	UrlParserError_NoDoubleSlash = 4,
	UrlParserError_NoAtSign = 5,
	UrlParserError_UnexpectedEndOfLine = 6,
	UrlParserError_NoSlash = 7,
};

class ParseURL
{
public:
	UrlParserError errorCode_ = UrlParserError_Uninitialized;
	std::string scheme_;
	std::string host_;
	std::string port_;
	std::string path_;
	std::string query_;
	std::string fragment_;
	std::string userName_;
    std::string password_;

	bool isValid() const { return errorCode_ == UrlParserError_Ok; }
	bool getPort(int* outPort) const;
	static ParseURL parseURL(const std::string& url);
    
    friend std::ostream& operator<<(std::ostream& os, const ParseURL& URL);
private:
	ParseURL() = default;
	explicit ParseURL(UrlParserError errorCode)
		: errorCode_(errorCode)
	{}
};

#endif