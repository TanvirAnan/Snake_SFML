#include "snake.h"


int main()
{
	srand(time(0));
	printf("\n\n\n  !!!Welcome to the Snake Game!!!!\n\n\n");
	//getchar();
	Snake snake;
	while (snake.running())
	{
		snake.update();
		snake.render();
	}
//	printf("You have gained %d points\n", snake.points);

}