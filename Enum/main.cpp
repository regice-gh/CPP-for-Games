#include <iostream>
#include <cstdint>
#include <type_traits>

using std::cin;
using std::cout;
using std::endl;

enum Day {
	Monday,
	Tuesday,
	Wednesday,
	Thurday,
	Friday,
	Saterday,
	Sunday,
};

enum class Color : uint32_t {
	Black = 0x000000,
	Red = 0xFF0000,
	Green = 0x00FF00,
	Blue = 0x0000FF,
	White = Red | Green | Blue,
	LightGray,
};

Color red = Color::Red;

//uint32_t green = Color::Green;
//Color blue = 3;
auto green = static_cast<std::underlying_type_t<Color>>(Color::Green);

enum class GameStates {
	MainMenuState,
	GameState,
	GameOverState,
	LeaderboardState,
};

void MainMenu();
void Game();
void Gameover();
void Leaderboard();

void checkForInput();
bool readCharacter(char c);
void checkSwitch(GameStates);
void changeState(char character);

GameStates gameState = GameStates::MainMenuState;


int main() {


	checkSwitch(gameState);
	
	return 0;
}

void MainMenu()
{
	std::cout << "viewing main menu" << std::endl;
	checkForInput();
}

void Game()
{
	std::cout << "game is running..." << std::endl;
	checkForInput();
}

void Gameover()
{
	std::cout << "game over!" << std::endl;
	checkForInput();
}

void Leaderboard()
{
	std::cout << "viewing leaderboard!" << std::endl;
	checkForInput();
}

void checkForInput() {
	char character;
	cout << "Q: Main Menu" << endl;
	cout << "S: Start game" << endl;
	cout << "D: Game Over" << endl;
	cout << "L: Show Leaderboard" << endl;
	cin >> character;
	while (!readCharacter(character)) {
		cout << "ERROR: invalid input, only accepts the characters(Q, S, D, L)!" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Try again...." << endl;
		cin >> character;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	changeState(character);
}

bool readCharacter(char c)
{
	c = static_cast<unsigned char>(tolower(c));
	return c == 'q' || c == 's' || c == 'd' || c == 'l';
}

void changeState(char character) {
	character = static_cast<unsigned char>(std::tolower(character));
	switch (character) {
	case 'q': gameState = GameStates::MainMenuState; break;
	case 's' : gameState = GameStates::GameState; break;
	case 'd': gameState = GameStates::GameOverState; break;
	case 'l': gameState = GameStates::LeaderboardState; break;
	}
	checkSwitch(gameState);
}

void checkSwitch(GameStates gameState)
{
	switch (gameState)
	{
	case GameStates::MainMenuState:
		MainMenu();
		break;
	case GameStates::GameState:
		Game();
		break;
	case GameStates::GameOverState:
		Gameover();
		break;
	case GameStates::LeaderboardState:
		Leaderboard();
		break;
	default:
		break;
	}
}
