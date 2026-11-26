#include <iostream>
#include <fstream>

struct Highscore {
	char name[4];
	uint32_t score;
};

int main() {

	{
		//write to file
		std::ofstream highscores("highscores.txt");

		if (!highscores) {
			std::cerr << "ERROR: creating file." << std::endl;
			return 1;
		}

		highscores << "LOL" << 1234 << std::endl;
		highscores << "LIL" << 4321 << std::endl;
		highscores << "LEL" << 5678 << std::endl;
		highscores << "LAL" << 8765 << std::endl;

		if (highscores.bad()) {
			std::cerr << "ERROR: cannot write to file." << std::endl;
			return 1;
		}

		highscores.close();
	}

	{
		//add to file
		std::ofstream highscores("highscores.txt", std::ofstream::app);

		if (!highscores) {
			std::cerr << "ERROR: cannot edit file." << std::endl;
			return 1;
		}

		highscores << "GET" << 5555 << std::endl;

		if (highscores.bad()) {
			std::cerr << "ERROR: cannot write to file." << std::endl;
			return 1;
		}

		highscores.close();
	}

	{
		//read from file
		std::ifstream highscores("highscores.txt");

		if (!highscores) {
			std::cerr << "ERROR: cannot read file." << std::endl;
			return 1;
		}

		char names[4];
		int score;

		while (highscores >> names >> score) {
			std::cout << names << " " << score << std::endl;
		}

		highscores.close();
	}

	{
		//write to file binary
		std::ofstream highscores("highscores.bin", std::ios::binary);
		
		if (!highscores) {
			std::cerr << "ERROR: cannot open file." << std::endl;
			return 1;
		}

		Highscore scores[] = {
			{ "NOM", 1234 },
			{ "NAM", 2345 },
			{ "NIM", 3456 },
			{ "NUM", 4567 }
		};

		auto numScores = std::size(scores);
		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores));
		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(Highscore));

		if (highscores.bad()) {
			std::cerr << "ERROR: cannot write to binary file." << std::endl;
			return 1;
		}

		highscores.close();
	}

	{
		//read binary file
		std::ifstream highscore("highscores.bin", std::ios::binary);

		if (!highscore) {
			std::cerr << "ERROR: cannot open file." << std::endl;
		}

		size_t numEntries;
		highscore.read(reinterpret_cast<char*>(&numEntries), sizeof(numEntries));

		Highscore* scores = new Highscore[numEntries];

		highscore.read(reinterpret_cast<char*>(scores), numEntries * sizeof(Highscore));

		if (highscore.bad()) {
			std::cerr << "ERROR: failed to read file." << std::endl;
			return 1;
		}

		for (int i = 0; i < numEntries; ++i) {
			std::cout << scores[i].name << " " << scores[i].score << std::endl;
		}

		delete[] scores;

		highscore.close();

	}

	return 0;
}