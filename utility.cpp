#include <iostream>
#include <cctype>
#include "utility.h"

std::string removeLeadingSpaces(std::string line){
  std::string newLine;
  for(int x=0;x<line.length();x++){
    char letter=line[x];
    if(isspace(letter)==false){
      newLine=line.substr(x,line.length()-x);
      break;
    }
  }
  return newLine;
}
