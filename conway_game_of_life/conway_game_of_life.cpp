#include <ctime>
#include <windows.h>
#include <iostream>

class Life {
private:
	bool curentMap[20][20];
	bool nextMap[20][20];
public:

	Life() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				curentMap[j][i] = false;
			}
		}
	}


	void Setup() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (rand() % 4 == 2) {
					curentMap[j][i] = true;
				}
			}
		}
	}

	void Update() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int neighbors = CountNeighbors(j, i);
				if (curentMap[j][i]) {
				if (neighbors < 2 || neighbors > 3) {
					nextMap[j][i] = false;
				}
				else {
					if (neighbors == 3) {
						nextMap[j][i] = true;
					}
				}
			}
				else {
					if (neighbors == 3) {
						nextMap[j][i] = true;
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				curentMap[j][i] = nextMap[i][j];
			}
		}
	}

	int CountNeighbors(int x, int y) {
		int count = 0;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;
				int neighborX = x + j;
				int neighborY = y + i;
				if (neighborX >= 0 && neighborX < 20 && neighborY >= 0 && neighborY < 20){
					if (curentMap[neighborY][neighborX]) {
						count++;
					}
				}
			}
		}
		return count;
	}

	void Draw() {
		system("cls");
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (curentMap[j][i] == true) std::cout << "#";
				else std::cout << ".";
			}
			std::cout << std::endl;
		}
	}

};


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(0));

	Life game;
	game.Setup();

	while (true) {
		game.Draw();
		game.Update();
		Sleep(100);
	}
	return 0;
}
