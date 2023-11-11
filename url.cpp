#include "url.h"
#include <algorithm>
#include <cstring>
#include <stdlib.h>

bool isSchemeValid(const std::string& schemeName)
{
	for (auto c : schemeName) {
		if (!isalpha(c) && c != '+' && c != '-' && c != '.') {
            return false;
        }
	}
	return true;
}

bool ParseURL::getPort(int* outPort) const
{
	if (!isValid()) {
        return false;
    }
	const int port = atoi(port_.c_str());
	if (port <= 0 || port > 65535) {
        return false;
    }
	if (outPort) {
        *outPort = port;
    }
	return true;
}

ParseURL ParseURL::parseURL(const std::string& URL)
{
	ParseURL result;
	const char* currentString = URL.c_str();
	{
        // поиск двоеточия
		const char* localString = strchr(currentString, ':');
        // в случае если не найдено возвращает ошибку
		if (!localString) {
			return ParseURL(UrlParserError_NoUrlCharacter);
		}
        // присваевает протокол
		result.scheme_ = std::string(currentString, localString - currentString);
        // проверка протокола на правильность написания 
		if (!isSchemeValid(result.scheme_)) {
			return ParseURL(UrlParserError_InvalidSchemeName);
		}
        // преобразование заглавных букв в маленькие
		std::transform(result.scheme_.begin(), result.scheme_.end(), result.scheme_.begin(), ::tolower);
        // переход на символ после двоеточия
		currentString = localString + 1;
	}
    // проверка на два слеша
	if (*currentString++ != '/' || *currentString++ != '/') {
        return ParseURL(UrlParserError_NoDoubleSlash);
    }
    // есть ли имя пользователя в URL
	bool bHasUserName = false;
	const char* localString = currentString;
	while (*localString) {
		if (*localString == '@') {
			bHasUserName = true;
			break;
		}
		else if (*localString == '/') {
			break;
		}
		localString++;
	}
	localString = currentString;
    // в случае если имя пользователя есть присваевает классовой переменной userName
	if (bHasUserName) {
		while (*localString && *localString != ':' && *localString != '@') {
            localString++;
        }
		result.userName_ = std::string(currentString, localString - currentString);
		currentString = localString;
        // в случае если за именем еще есть двоиточие присваевается классовой переменной пароль
		if (*currentString == ':') {
			currentString++;
			localString = currentString;
			while (*localString && *localString != '@') {
                localString++;
            }
			result.password_ = std::string(currentString, localString - currentString);
			currentString = localString;
		}
        // если после пароля нет '@', то выдает ошибку
		if (*currentString != '@') {
			return ParseURL(UrlParserError_NoAtSign);
		}
		currentString++;
	}
	const bool bHasBracket = (*currentString == '[');
    // чтение хоста (URL и URI)
	localString = currentString;
	while (*localString) {
		if (bHasBracket && *localString == ']') {
			localString++;
			break;
		}
		else if (!bHasBracket && (*localString == ':' || *localString == '/')) {
			break;
		}
		localString++;
	}
    // запись хоста
	result.host_ = std::string(currentString, localString - currentString);
    // провека есть ли порт
	currentString = localString;
	if (*currentString == ':') {
		currentString++;
		localString = currentString;
		while (*localString && *localString != '/') {
            localString++;
        }
        // запись порта
		result.port_ = std::string(currentString, localString - currentString);
		currentString = localString;
	}
    // проверка конца строки
	if (!*currentString)
	{
		result.errorCode_ = UrlParserError_Ok;
		return result;
	}
    // при отсутствие слеша после хоста или порта вернуть ошибку
	if (*currentString != '/') {
		return ParseURL(UrlParserError_NoSlash);
	}
	currentString++;
    // парсинг пути URL
	localString = currentString;
	while (*localString && *localString != '#' && *localString != '?') {
        localString++;
    }
    // запись пути
	result.path_ = std::string(currentString, localString - currentString);
    // проверка запроса
	currentString = localString;
	if (*currentString == '?') {
		currentString++;
		localString = currentString;
		while (*localString&&* localString != '#') {
            localString++;
        }
        // запись запроса
		result.query_ = std::string(currentString, localString - currentString);
		currentString = localString;
	}
    // проверка наличия фрагмента
	if (*currentString == '#') {
		currentString++;
		localString = currentString;
		while (*localString) {
            localString++;
        }
        // запись фрагмента
		result.fragment_ = std::string(currentString, localString - currentString);
		currentString = localString;
	}
    // установка того что ошибок нет и возврат результата
	result.errorCode_ = UrlParserError_Ok;
	return result;
}

std::ostream& operator<<(std::ostream& os, const ParseURL& URL)
{
    if (URL.isValid()) {
        os << "Scheme    : " << URL.scheme_ << std::endl;
        os << "Host      : " << URL.host_ << std::endl;
        os << "Port      : " << URL.port_ << std::endl;
        os << "Path      : " << URL.path_ << std::endl;
        os << "Query     : " << URL.query_ << std::endl;
        os << "Fragment  : " << URL.fragment_ << std::endl;
        os << "User name : " << URL.userName_ << std::endl;
        os << "Password  : " << URL.password_;
    }
    else {
        os << "Parsing error: " << URL.errorCode_;
    }
    return os;
}