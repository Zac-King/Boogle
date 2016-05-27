// BoggleTest.cpp
//
// Programming Rules:
//  1. Any C++ compiler may be used.  Preferably VS2008, VS2010, or VS2012.
//     A. Please document which compiler (including version) was used.
//     B. Include make files or project files where appropriate.
//     C. Document target platform (Windows 32bit, Windows 64bit, Unix, etc.)
//     D. If you don't have a compiler, we recommend downloading Visual Studio
//        Express 2012 for Windows, or XCode for Mac (both are free)
//  2. Any core language feature in the latest C++ standard may be used
//  3. All of the standard library may be used, including latest standards or
//     or technical reports.
//  4. 3rd Party libraries (such as Boost) are not allowed
//  5. Submit all source files needed to build final executable
//
// Game Rules:
//  Boggle is a word game.  The goal is to make as many words as possible
//  out of the given set of letters laid out in a 4x4 grid.  Words are 
//  formed by starting with any letter and moving to an adjacent letter
//  (up, down, left, right, or diagonal) and so-forth on.  Once a letter
//  is used in a word, it can not be used again.  All words must be a 
//  minimum of 3 characters in length.  Finally, in this version, a "q"
//  will always represent "qu", since "u" nearly always follows "q" in
//  English.  If a word may be formed multiple ways on the same board, it
//  only counts once.
//
// Example:
//
// Board:
//    P W Y R
//    E N T H
//    G S I Q
//    O L S A
//
// A few possible words:
//   pen
//   peg
//   quit
//   hit
//   slit
//   slits
//
// Command line arguments:
//  BoggleTest.exe <dictionary_filename> <board_filename> <output_filename>
//
// Dictionary:
//  The dictionary file is an ASCII text file that lists acceptable words.  Each word is
//  new line separated.  Words are in alphabetical order and all lowercase, utilizing
//  only letters 'a' to 'z'.
//
// Board:
//  The board file is an ASCII text file that is 4 lines of 4 characters.  These
//  represent the game board, a 4x4 matrix of characters.  These may be mixed case.
//  Whitespace is optional and should be ignored.  Only letters 'a' to 'z' or 'A'
//  to 'Z' are used.
//
// Output:
//  The output should be an ASCII text file (in alphabetical order) of all legal words
//  possible to spell on the current board that are in the given dictionary.  These
//  should be all lowercase and newline separated (same format as the dictionary).
//
// Notes:
//  Your final solution should be PRODUCTION QUALITY, as if it is getting checked
//  in to live production code.

#include <iostream>

int main(const int argc, const char* const argv[])
{
	BoogleTest a = BoogleTest();
	a.ReadBoard();
	system("pause");

	if (argc != 4)
	{
		std::cerr << "Usage: BoggleTest <dictionary_filename> <board_filename> <output_filename>" << std::endl;
		return -1;
	}

	system("pause");
	return 0;
}

class BoogleTest
{	
	public std::string board_FilePath = "C:\Users\zac.king\Desktop\Programming Test 1\Programming Test 1\board_1.txt";		//
	public std::string dictionary_FilePath = "C:\Users\zac.king\Desktop\Programming Test 1\Programming Test 1";				//
	public std::string solution_FilePath = "C:\Users\zac.king\Desktop\Programming Test 1\Programming Test 1";				//

	BoogleTest();	// Defualt Constructor
	BoogleTest(std::string a_board, std::string a_dict, std::string a_solu)	// Custom Constructor
	{
		board_FilePath = a_board;
		dictionary_FilePath = a_dict;
		solution_FilePath = a_solu;
	}

	void ReadBoard()
	{
		std::ifstream in(board_FilePath);
		char element;
		while (getchar(in, element))
		{
			std::cout << element << std::endl;

		}
	}

	void ReadDictionary()
	{

	}

	void WriteSolution(std::string [] solu)
	{

	}
};