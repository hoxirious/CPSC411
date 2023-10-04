#include "scanner.hpp"
#include <regex>
using namespace std;

unordered_map<string, string> operators_map = {
    {"<", "LESS_THAN"},
    {">", "GREATER_THAN"},
    {"<=", "LESSER_OR_EQUAL"},
    {">=", "GREATER_OR_EQUAL"},
    {"*", "ASTERICK"},
    {"+", "PLUS"},
    {"-", "MINUS"},
    {"/", "DIVIDE"},
    {"=", "EQUALS"},
    {"|=", "NOT_EQUALS"},
    {"==", "COMPARISION_EQUAL"},
};

unordered_map<string, string> seperators_map = {
    {"{", "O_CURL"},  {"}", "C_CURL"},  {"(", "O_PAREN"},
    {")", "C_PAREN"}, {";", "SEM_COL"}, {",", "COMMA"},
};

unordered_map<string, string> comments_map = {{"/*", "O_COMM"},
                                              {"*/", "C_COMM"}};

const regex id("[a-zA-Z][a-zA-Z]*");
const regex num("[0-9][0-9]*");
const regex keywords("int|return|while|else|if|void");
const regex operators("\\|=|==|<|>|<=|>=|\\*|\\+|-|\\/|=");
const regex separators("\\{|\\}|,|\\(|\\)|;");
bool commentStarted = false;
int line = 1;


bool isComment(const string &str) { return str == "/*" || str == "*/"; }
bool isOperator(const string &str) { return regex_match(str, operators); }
bool isWhiteSpace(const string &str) { return str == " "; }
bool isDigit(const string &str) { return regex_match(str, num); }
bool isKeyword(const string &str) { return regex_match(str, keywords); }
bool isId(const string &str) { return regex_match(str, id); }
bool isSeparator(const string &str) { return regex_match(str, separators); }
bool isEOL(const char &c) { return c == '\n' || c == '\r'; }

void printToken(const string &token) {
  cout << line << ": ";
  if (isOperator(token))
    cout << operators_map[token];
  else if (isSeparator(token))
    cout << seperators_map[token];
  else if (isKeyword(token))
    cout << token;
  else if (isDigit(token))
    cout << "NUM " << token;
  else if (isId(token)) {
    if (commentStarted)
      cout << "COMM_CONTENT " << token;
    else
      cout << "ID " << token;
  } else if (isComment(token))
    cout << comments_map[token];
  else
    cout << "Invalid token: " << token;
  cout << endl;
}

void scanFile(const string &fileName) {
  char c;
  string buffer;

  fstream inputFile(fileName, std::fstream::in);

  if (!inputFile.is_open()) {
    cout << "Can't open file " << fileName << endl;
    exit(0);
  }

  while (inputFile >> noskipws >> c) {

      // Increment line
      if (isEOL(c)) {
          if (!buffer.empty()) {
              printToken(buffer);
              buffer = "";
          }
          line++;
          continue;
      }

    // Catch content & close comment
    if (commentStarted && c == '*') {
      string comm(1, c);
      inputFile >> c;
      if (c == '/') {
        comm += c;
        commentStarted = false;
        printToken(comm);
      }
      continue;
    }

    // Catch open comment
    if (c == '/') {
      string comm(1, c);
      inputFile >> c;
      if (c == '*') {
        commentStarted = true;
        comm += c;
      }
      if (commentStarted) {
        printToken(comm);
        continue;
      }
    }

    string _c = string(1, c);
    if (isOperator(_c) && !isOperator(buffer)) {
        if (!buffer.empty()) {
            printToken(buffer);
            buffer = "";
        }
    }

    if (isWhiteSpace(_c)) {
      if (!buffer.empty()) {
        printToken(buffer);
        buffer = "";
      }
      continue;
    }
    if (isSeparator(_c)) {
      if (!buffer.empty()) {
        printToken(buffer);
        buffer = "";
      }
      if (isSeparator(_c)) {
        printToken(_c);
        continue;
      }
    }
    buffer += c;
  }

  inputFile.close();
}
