#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  if(phrase.length() > 0){
    repetition++;
  }

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}
bool Password::has_mixed_case(string phrase){
 bool upper=false;
 bool lower=false;
  for(int i=0; i<phrase.length();i++){
      if(phrase.at(i) >='A' && phrase.at(i) <= 'Z'){
        upper = true;
      } 
      if(phrase.at(i) >='a' && phrase.at(i) <= 'z'){
        lower = true;
      }
     }
  if(upper == true && lower == true){
    return true;
  }
  else{
    return false;
  }
}


