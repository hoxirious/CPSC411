#include "scanner.hpp"
#include <ios>
#include <ostream>
#include <sstream>
#include <string>
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

const regex id("\\s*[a-zA-Z][a-zA-Z]*");
const regex num("\\s*[0-9][0-9]*");
const regex keywords("int|return|while|else|if|void");
const regex operators("\\|=|==|<|>|<=|>=|\\*|\\+|-|\\/|=|\\|");
const regex separators("\\{|\\}|,|\\(|\\)|;");
bool commentStarted = false;
string commentBuffer;
int line = 1;
int main(int argc, char *argv[]) {
  for (int i = 0; i < 5; i++) {
    string filelocation = "test/";
    string filename = "test" + to_string(i) + ".txt";
    cout << "Scanning result of " << filename << endl;
    cout << "==============================" << endl;
    scanFile(filelocation + filename);
    cout << "==============================" << endl;
    line = 1;
    commentStarted =false;
  }
  return 0;
}


bool isComment(const string &str) { return str == "/*" || str == "*/"; }
bool isOperator(const string &str) { return regex_match(str, operators); }
bool isWhiteSpace(const string &str) { return str == " "; }
bool isDigit(const string &str) { return regex_match(str, num); }
bool isKeyword(const string &str) { return regex_match(str, keywords); }
bool isId(const string &str) { return regex_match(str, id); }
bool isSeparator(const string &str) { return regex_match(str, separators); }

void printToken(const string &token) {
  if (!isComment(token) && !commentStarted)
    cout << line << ": ";
  if (isComment(token)) {
    if (!commentStarted) {
      commentBuffer.replace(2, 1, to_string(line));
      commentBuffer.replace(6, 1, "");
      commentBuffer += "\"";
      cout << endl << commentBuffer << endl;
      commentBuffer.clear();
    } else {
      commentBuffer += to_string(line);
      commentBuffer += "-";
      commentBuffer += to_string(line);
      commentBuffer += ": \"";
    }
    cout << line << ": " << comments_map[token];
  } else if (commentStarted) {
    commentBuffer += token;
  } else if (isOperator(token))
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
    cout << "Invalid token:" << token;

  if (!commentStarted)
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
  bool commentCanEnd = false;
  bool commentCanStart = false;
  while (getline(inFile, l)) {
    istringstream iss(l);
    while (iss >> noskipws >> c) {

      string _c = string(1, c);
      // Catch content & close comment
      if (commentStarted) {
        if (c == '*') {
          commentCanEnd = true;
          continue;
        }
        if (commentCanEnd) {
          if (c == '/') {

            commentStarted = false;
            commentCanEnd = false;
            printToken("*/");
            continue;
          } else {
            popBuffer(buffer);
            printToken("*");
            commentCanEnd = false;
          }
        }
      } else {
        // Catch open comment
        if (c == '/') {
          buffer += c;
          commentCanStart = true;
          continue;
        }
        if (commentCanStart) {
          if (c == '*') {
            commentStarted = true;
            commentCanStart = false;
            printToken("/*");
            continue;
          } else {
            string b = buffer.substr(0, buffer.size() - 1);
            popBuffer(b);
            printToken("/");
            buffer.clear();
            commentCanStart = false;
          }
        }
      }

      if (isOperator(_c) && !isOperator(buffer)) {
        popBuffer(buffer);
        buffer += c;
      }

      else if (!isOperator(_c) && isOperator(buffer)) {
        printToken(buffer);
        buffer = "";
      }

      else if (isWhiteSpace(_c) ) {
        popBuffer(buffer);
        if (commentStarted) {
          printToken(_c);
        }
      }

      else if (isSeparator(_c)) {
        popBuffer(buffer);
        printToken(_c);
      } else
        buffer += c;
    }
    popBuffer(buffer);
    line++;
  }

  inFile.close();
}
