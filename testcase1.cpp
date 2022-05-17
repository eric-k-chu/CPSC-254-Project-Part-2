#include "notes.cpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>


bool is_file_exists(const std::string& filename) 
{
	std::ifstream file(filename);
	return file.is_open();
}

void test_case_01(const std::string& filename)
{
	std::vector<Entry*> notepad;
	
	import_notepad(notepad);
	
	if (is_file_exists(filename))
		std::cout << "\nPassed";
	else 
		std::cout << "\nFailed";
}


int main() 
{	
	//test_case_01("test1");
	test_case_01("test2");
	return 0;
}