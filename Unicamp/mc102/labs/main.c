#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define WALL_TILE   '#'
#define EMPTY_TILE  '-'
#define START_TILE  's'
#define END_TILE    'e'
#define WALKED_TILE 'x'

#define INITIAL_STACK_SIZE 50

typedef enum {
	Up,
	Right,
	Down,
	Left
} Direction;

typedef struct {
	int x;
	int y;
} Coords;

void nextTile(Coords *curTile, Coords *newTile, Direction dir);
void readInput(int *mazeHeight, int *mazeWidth, char ***mazeTiles);
void printMaze(int mazeHeight, int mazeWidth, char **mazeTiles);
bool findPath(int mazeHeight, int mazeWidth, char **mazeTiles);

int main() {
	int mazeHeight, mazeWidth;
	char **mazeTiles;

	readInput(&mazeHeight, &mazeWidth, &mazeTiles);

	if (findPath(mazeHeight, mazeWidth, mazeTiles)) {
		printMaze(mazeHeight, mazeWidth, mazeTiles);
	} else {
		printf("NE\n");
	}

	return 0;
}

void nextTile(Coords *curTile, Coords *newTile, Direction dir) {
	*newTile = *curTile;

	switch (dir) {
	case Up:
		newTile->y--;
		return;

	case Right:
		newTile->x++;
		return;

	case Down:
		newTile->y++;
		return;

	case Left:
		newTile->x--;
		return;
	}
}

void readInput(int *mazeHeight, int *mazeWidth, char ***mazeTiles) {
	// Read maze size
	scanf("%d %d", mazeHeight, mazeWidth);

	// Allocate maze
	*mazeTiles = malloc(*mazeHeight * sizeof(char *));
	for (int i = 0; i < *mazeHeight; i++) {
		(*mazeTiles)[i] = malloc(*mazeWidth * sizeof(char));
	}

	// Read maze
	for (int i = 0; i < *mazeHeight; i++) {
		for (int j = 0; j < *mazeWidth; j++) {
			scanf(" %c", &((*mazeTiles)[i][j]));
		}
	}
}

void printMaze(int mazeHeight, int mazeWidth, char **mazeTiles) {
	for (int i = 0; i < mazeHeight; i++) {
		for (int j = 0; j < mazeWidth; j++) {
			printf("%c", mazeTiles[i][j]);
		}
		printf("\n");
	}
}

bool findPath(int mazeHeight, int mazeWidth, char **mazeTiles) {
	Coords *curTile;
	Stack *nextTiles = stackCreate(INITIAL_STACK_SIZE);

	// Pushes starting tile into next tiles stack
	for (int i = 0; i < mazeHeight; i++) {
		for (int j = 0; j < mazeWidth; j++) {
			if (mazeTiles[i][j] == START_TILE) {
				Coords *startCoords = malloc(sizeof(Coords));

				startCoords->x = j;
				startCoords->y = i;

				stackPush(nextTiles, startCoords);
			}
		}
	}

	while ((curTile = stackPop(nextTiles)) != NULL) {
		// Stop looking if we found the ending tile
		if (mazeTiles[curTile->y][curTile->x] == END_TILE) {
			break;
		}

		switch (mazeTiles[curTile->y][curTile->x]) {
			// Only mark as walked if the current tile is not the starting one
			// and push it back so we know when to 'unwalk' it
		case EMPTY_TILE:
			stackPush(nextTiles, curTile);
			mazeTiles[curTile->y][curTile->x] = WALKED_TILE;
			/* fallthrough */


			// Add adjacent tiles to next tiles stack, but only if we haven't
			// walked on it yet
		case START_TILE:
			for (Direction d = Up; d <= Left; d++) {
				Coords *newTile = malloc(sizeof(Coords));

				nextTile(curTile, newTile, d);

				if (mazeTiles[newTile->y][newTile->x] != WALKED_TILE) {
					stackPush(nextTiles, newTile);
				} else {
					free(newTile);
				}
			}
			break;


			// 'Unwalk' a walked tile
		case WALKED_TILE:
			mazeTiles[curTile->y][curTile->x] = EMPTY_TILE;
			/* fallthrough */

		default:
			free(curTile);
			break;
		}
	}

	// If we tried all possible tiles and none was left, then no path was found
	bool pathFound = !stackIsEmpty(nextTiles);

	freeStackItems(nextTiles);

	return pathFound;
}