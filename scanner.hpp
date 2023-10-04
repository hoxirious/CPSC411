#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

bool isId(const std::string &str);
bool isComment(const std::string &str);
bool isOperator(const std::string &str);
bool isDigit(const std::string &str);
bool isKeyword(const std::string &str);
bool isSeparator(const std::string &str);
bool isWhiteSpace(const std::string &str);
void printToken(const vector<std::string>& tokens);
void scanFile(const std::string &nameOfFile);
