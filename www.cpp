#include <iostream>
#include <fstream>
#include <string>

std::string readFromFile(std::string filename)
{
	std::fstream src;
	std::string result = "", inStr;
	src.open(filename);
	if (src.is_open())
	{
		while (!src.eof())
		{
			src >> inStr;
			result += inStr + ' ';
		}
	}
	else
		std::cout << "File not exist\n";
	src.close();
	result = result.substr(0, result.length() - 1);
	return result;
}

int main()
{
	bool field[] = { true, true, true, true, true, true, true, true, true, true, true, true, true };
	std::string answer, pQues, pAnsw;
	int curPos = 0, delta, markTV = 0, markExpert = 0;
	while (markExpert < 6 && markTV < 6)
	{
		std::cout << "Enter number sectors: ";
		std::cin >> delta;
		if (delta > 0)
		{
			curPos = (curPos + (delta % 13)) % 13;
			if (!field[curPos])
			{
				while (!field[curPos])
					curPos = (curPos + 1) % 13;
			}
			pQues = "Question" + std::to_string(curPos) + ".txt";
			pAnsw = "Answer" + std::to_string(curPos) + ".txt";
			field[curPos] = false;
			std::cout << readFromFile(pQues) << ' ';
			std::cin >> answer;
			if (answer == readFromFile(pAnsw))
			{
				markExpert++;
				std::cout << "Expert +1 mark. Common result " << markExpert << ':' << markTV << '\n';
			}
			else
			{
				markTV++;
				std::cout << "TV team +1 mark. Common result " << markExpert << ':' << markTV << '\n';
			}
		}
		else
			std::cout << "You entered an incorrect value\n";
	}
	if (markExpert == 6)
		std::cout << "Expert win!\n";
	else
		std::cout << "TV team win!\n";
}