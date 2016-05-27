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
#include <fstream>
#include <list>
#include <string>

struct pos
{
	int x, y;
};

class BoogleTest
{
private:
	std::string board_FilePath = "C:\\Users\\zac.king\\Desktop\\Programming Test 1\\Programming Test 1\\board_1.txt";	//
	std::string dictionary_FilePath = "C:\\Users\\zac.king\\Desktop\\Programming Test 1\\Programming Test 1\\dictionary.txt";			//
	std::string solution_FilePath = "C:\\Users\\zac.king\\Desktop\\Programming Test 1\\Programming Test 1";				//
	char boardElements[4][4];	// 4x4 || 16 elements in a one dimentional arrary
	std::list<std::string> validAnswers;
public:
	BoogleTest() {}	// Defualt Constructor
	BoogleTest(std::string a_board, std::string a_dict, std::string a_solu)	// Custom Constructor
	{
		board_FilePath = a_board;
		dictionary_FilePath = a_dict;
		solution_FilePath = a_solu;
	}

	void ReadBoard()
	{
		std::ifstream board(board_FilePath);
		int x, y = 0;
		for (int i = 0; i < 16; i++)
		{
			x = i / 4;
			y = i % 4;

			char c;
			board >> c;
			if ((int)c >= 65 && (int)c <= 90)	// if the element is A-Z
			{
				boardElements[x][y] = (char)(c + 32);	// toLowercase and store it
			}
		}

		//for (int i = 0; i < 4; i++)
		//{
		//	std::cout << "|";
		//	for each (char v in boardElements[i])
		//	{
		//		std::cout << v << ", ";
		//	}
		//	std::cout << "|\n";
		//}

		board.close();
	}

	bool TraverseBoard(pos a, std::string s, int index, std::list<pos> t)
	{
		pos tRight = pos{ a.x + 1, a.y - 1 };
		pos tLeft = pos{ a.x - 1, a.y - 1 };
		pos top = pos{ a.x , a.y - 1 };
		pos bRight = pos{ a.x + 1, a.y + 1 };
		pos bLeft = pos{ a.x + 1, a.y + 1 };
		pos below = pos{ a.x, a.y + 1 };
		pos right = pos{ a.x + 1, a.y };
		pos left = pos{ a.x - 1, a.y };


		bool found = false;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		// Above check
		if (a.y - 1 > 0)
		{
			found = (std::find(t.begin(), t.end(), top) != t.end());
			if (boardElements[top.x][top.y] == s[index] && !found)
			{
				std::list<pos> trav = t;
				trav.push_front(top);
				return TraverseBoard(top, s, index++, t);
			}
				
			//////////////////////////////////////////////////
			// Above and to the right check
			if (a.x + 1 < 4)
			{
				found = (std::find(t.begin(), t.end(), tRight) != t.end());
				if (boardElements[a.x + 1][a.y - 1] == s[index] && !found)
				{
					std::list<pos> trav = t;
					trav.push_front(tRight);
					return TraverseBoard(tRight, s, index++, t);
				}
			}
			//////////////////////////////////////////////////
			// Above and to the left check
			if (a.x - 1 >= 0)
			{
				found = (std::find(t.begin(), t.end(), tLeft) != t.end());
				if (boardElements[a.x - 1][a.y - 1] == s[index] && !found)
				{
					std::list<pos> trav = t;
					trav.push_front(tLeft);
					return TraverseBoard(tLeft, s, index++, t);
				}
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		// Below check
		if (a.y + 1 < 4)
		{
			found = (std::find(t.begin(), t.end(), below) != t.end());
			if (boardElements[a.x][a.y + 1] == s[index] && !found)
			{
				std::list<pos> trav = t;
				trav.push_front(below);
				return TraverseBoard(below, s, index++, t);
			}
			//////////////////////////////////////////////////
			// Below and to the right check
			if (a.x + 1 < 4)
			{
				found = (std::find(t.begin(), t.end(), bRight) != t.end());
				if (boardElements[a.x + 1][a.y + 1] == s[index] && !found)
				{
					std::list<pos> trav = t;
					trav.push_front(bRight);
					return TraverseBoard(bRight, s, index++, t);
				}
			}
			//////////////////////////////////////////////////
			// Below and to the left check
			if (a.x - 1 >= 0)
			{
				found = (std::find(t.begin(), t.end(), bLeft) != t.end());
				if (boardElements[a.x - 1][a.y + 1] == s[index] && !found)
				{
					std::list<pos> trav = t;
					trav.push_front(bLeft);
					return TraverseBoard(bLeft, s, index++, t);
				}
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		// Right check
		if (a.x + 1 < 4)
		{
			found = (std::find(t.begin(), t.end(), right) != t.end());
			if (boardElements[a.x + 1][a.y] == s[index] && !found)
			{
				std::list<pos> trav = t;
				trav.push_front(right);
				return TraverseBoard(right, s, index++, t);
			}
		}

		// Left
		if (a.x - 1 >= 0)
		{
			found = (std::find(t.begin(), t.end(), right) != t.end());
			if (boardElements[a.x + 1][a.y] == s[index] && !found)
			{
				std::list<pos> trav = t;
				trav.push_front(right);
				return TraverseBoard(right, s, index++, t);
			}
		}

	}

	void ReadDictionary()
	{
		std::ifstream dictionary(dictionary_FilePath);
		std::string word;
		while (std::getline(dictionary, word))	// for each word in the dictionary we will try 
		{
			std::list<pos> searched;

			for(int i = 0; i < 16; i++)
			{
				int x = i / 4;
				int y = i % 4;
				if (boardElements[x][y] == word[0])	// only if the first letter can be found on the board do we continue
				{
					std::list<pos> traveresed;
					traveresed.push_front(pos{ x,y });
					if (TraverseBoard(pos{ x,y }, word, 1, traveresed))
					{
						validAnswers.push_front(word);
					}
				}
			}
		}
		dictionary.close();
	}

	//void WriteSolution(std::string[] solu)
	//{
	//
	//}
};

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
