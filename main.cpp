#include "scanner.hpp"
#include <ios>
#include <sstream>
int main(void) {
  scanFile("program.txt");
  return 0;
}

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

void printToken(const string &token) {
  cout << line << ": ";
  if (isComment(token))
    cout << comments_map[token];
  else if (commentStarted)
    cout << "COMM_CONTENT " << token;
  else if (isOperator(token))
    cout << operators_map[token];
  else if (isSeparator(token))
    cout << seperators_map[token];
  else if (isKeyword(token))
    cout << token;
  else if (isDigit(token))
    cout << "NUM " << token;
  else if (isId(token)) {
    cout << "ID " << token;
  } else
    cout << "Invalid token: " << token;
  cout << endl;
}

void popBuffer(string &buffer) {
  if (buffer != "") {
    printToken(buffer);
    buffer.clear();
  }
}

void scanFile(const string &fileName) {
  char c;
  string l;
  string buffer;
  ifstream inFile(fileName);

  if (!inFile.is_open()) {
    cout << "Can't open file " << fileName << endl;
    exit(0);
  }

  while (getline(inFile, l)) {
    istringstream iss(l);
    char backup_c = '\0';
    while (iss >> noskipws >> c) {

      string _c = string(1, c);
      // Catch content & close comment
      if (commentStarted && c == '*') {
        iss >> c;
        if (c == '/') {
          _c += c;
          commentStarted = false;
          printToken(_c);
        } else {
          backup_c = c;
        }
        // else move cursor to prev

      }

      // Catch open comment
      else if (c == '/') {
        iss >> c;
        if (c == '*') {
          commentStarted = true;
          _c += c;
        } else {
          backup_c = c;
        }
        if (commentStarted) {
          printToken(_c);
        }
      }

      if (isOperator(_c) && !isOperator(buffer)) {
        popBuffer(buffer);
        buffer += c;
      }

      else if (isWhiteSpace(_c)) {
        popBuffer(buffer);
      }

      else if (isSeparator(_c)) {
        popBuffer(buffer);
        printToken(_c);
      } else
        buffer += c;

      if (backup_c != '\0') {
        string _backup_c = string(1, backup_c);
        if (isOperator(_backup_c) && !isOperator(buffer)) {
          popBuffer(buffer);
          buffer += backup_c;
        }

        else if (isWhiteSpace(_backup_c)) {
          popBuffer(buffer);
        }

        else if (isSeparator(_backup_c)) {
          popBuffer(buffer);
          printToken(_backup_c);
        } else
          buffer += backup_c;

        backup_c = '\0';
      }
    }
    line++;
  }

  inFile.close();
}
