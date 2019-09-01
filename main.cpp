#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
 * 
 * This program takes input from the user, and does some basic analysis on it.
 * C @ TCC
 * Arick Mounts
 * 
 */

int GetNumOfNonWSCharacters(const string& userString){
   int num =0;
   for(int i =0; i < userString.length(); i++){
      if (!isspace(userString.at(i))){
         num++;
      }   
   }   
   return num;
}

int FindText(const string& userString, const string findWord){
   int x = 0;
   int num =0;
   while ((x =userString.find(findWord, x)) != string::npos)
     {
       num++;
       x += findWord.length();
     }  
   return num;
}

void ReplaceExclamation(string& userString){
   for(int i =0; i < userString.length(); i++){
      if (userString.at(i) == '!'){
         userString.at(i) = '.';
      }   
   } 
} 
void ShortenSpace(string& userString){
   for(int i =0; i < userString.length(); i++){
      if (userString.at(i) == ' '&& userString.at(i + 1) == ' '){
         userString.erase(i, 1);
         i = 0;
      }   
   } 
} 

int GetNumOfWords(const string& userString){
   int num =0;
   for(int i =0; i < userString.length(); i++ ){
      if (isalpha(userString.at(i)) && (isspace(userString.at(i+1)) || userString.at(i+1) == '.' || userString.at(i+1) == ',' || userString.at(i+1) == '!' || userString.at(i+1) == ';')){
         num++;
      }   
      
   }   
   return num;
}

void  PrintMenu(string& userString){
   string findWord;
   char menuIn;
    do{
      cout << "MENU" << endl << "c - Number of non-whitespace characters" << endl << "w - Number of words" << endl << "f - Find text" << endl << "r - Replace all !'s" << endl << "s - Shorten spaces" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
      cin >> menuIn;
      switch (menuIn){
         case ('c'):
            cout<< "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userString) << endl << endl;
            break;
         case ('w'):
            cout<< "Number of words: " << GetNumOfWords(userString)<< endl<< endl;
            
            break;
         case('f'):
            cout<< "Enter a word or phrase to be found:"<< endl;
            cin.ignore();
            getline (cin, findWord);
            cout << '\"'<< findWord <<"\" instances: "<< FindText(userString, findWord) << endl<< endl;
            break;
         case('r'):
            ReplaceExclamation(userString);
            cout << "Edited text: " << userString << endl<< endl;
            break;
         case('s'):
            ShortenSpace(userString);
            
            cout << "Edited text: " << userString << endl<< endl;
            break;
        case('q'):
              break;
         default:
             cout << "Please enter a valid option" << endl<< endl;
            break;
         }
      }while(menuIn != 'q');
}

int main() {
   string userString;
   cout << "Enter a sample text:" << endl << endl;
   cin.ignore();
   getline (cin, userString);
   
   cout << "You entered: " << userString << endl << endl;
  
      
   PrintMenu(userString);
      
      
   return 0;
}