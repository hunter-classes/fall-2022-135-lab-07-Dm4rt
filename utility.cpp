#include <iostream>
#include <fstream>
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

int countChar(std::string line, char c){
  int count=0;
  for(int x=0;x<line.length();x++){
    if(line[x]==c){
      count++;
    }
  }
  return count;
}

void unindent(std::string file){
  std::ifstream myfile;
  myfile.open(file);
  std::ofstream goodfile;
  goodfile.open("good-code.cpp");
  std::string line;
  while(std::getline(myfile, line)){
    std::string newLine = removeLeadingSpaces(line);
    goodfile<<newLine<<std::endl;
  }
  myfile.close();
  goodfile.close();
}

void indent(std::string file){
  std::ifstream myfile;
  myfile.open(file);
  std::ofstream betterfile;
  betterfile.open("better-code.cpp");
  std::string line;
  int count=0;
  while(std::getline(myfile, line)){
    count-=countChar(line,'}');
    std::string betterLine;
    for(int x=0;x<count;x++){
      betterLine+="\t";
    }
    betterLine+=line;
    betterfile<<betterLine<<std::endl;
    count+=countChar(line,'{');
  }
  myfile.close();
  betterfile.close();
}
