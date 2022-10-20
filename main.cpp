#include <iostream>
#include <fstream>
#include "utility.h"

int main(){
  std::ifstream myfile;
  myfile.open("bad-code.cpp");
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
