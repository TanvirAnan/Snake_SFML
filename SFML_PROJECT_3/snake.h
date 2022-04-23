#pragma once

#include<vector>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<conio.h>
#include<iostream>
#include<Windows.h>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctime>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<dos.h>
#include<iomanip>
#include<windows.h>
#include<dos.h>
#include<time.h>


using namespace std;
using namespace sf;


class Snake
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;
	sf::Event key1;
	int control;

	sf::CircleShape ball;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::RectangleShape line;
	sf::RectangleShape head;

	bool endgame;
	int points;
	int ballmax;
	int balls;
	float movementspeed;
	bool firstkey;
	bool ev1;
	int option = 0;
	bool gameover;
	int prevx, prevy;
	float x, y;
	int xdir = 10;


	vector<RectangleShape>lines;

	void initvariable();
	void initwindow();
	void initball();
	void initline();
	void inittexture();
	void initsprite();
	void initext();



public:
	Snake();
	~Snake();

	bool running();
	void getheadpos();
	void pollEvents();

	void updateball();
	void updateline();
	void input();
	void collision();


	void update();

	void renderball(sf::RenderTarget& target);
	void renderline(sf::RenderTarget& target);
	void render();


};

