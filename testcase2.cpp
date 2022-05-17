#include "notes.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <fstream>


bool is_file_exist(std::string fileName)
{
    std::ifstream infile(fileName);
    return infile.is_open();
}

void Test_Save(){
	std::string file="Test1";
	std::string file2="Test2";
	std::vector<Entry*> notepad;
	save_notepad(file, notepad);
	if(is_file_exist(file)){
		std::cout << "\nFile " << file << " exists\n";
	}else{
		std::cout << "\nError File " << file << " does not exist exists\n";
	}
	if(is_file_exist(file2)){
		std::cout << "\nFile " << file << " exists\n";
	}else{
		std::cout << "\nError File " << file << " does not exist exists\n";
	}
}

void Test_Changelog_Writer(){
	std::string test_string_1 = "Test1";
	std::string test_string_2 = "Test2";
	changelog_writer(test_string_1,test_string_2);
	std::fstream file_opener;//how the file will be accessed
    file_opener.open("Changelog.txt");//accesses the changelog
    std::string file_line;//string to hold the lines
	std::string prevline=file_line;
	while(std::getline(file_opener,file_line))//while the string has a line from the text file
	{
		if(file_line!="\n"){
			prevline=file_line;
		}
	}
	if(test_string_1+": "+test_string_2==prevline){
		std::cout << "Changelog works\n";
	}else{
		std::cout << "Changelog Errors\n";
	}
	
}
int main()
{
  Test_Save();
  Test_Changelog_Writer();
}