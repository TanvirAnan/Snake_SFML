#include "snake.h"


void Snake::initvariable()
{
	window = nullptr;
	endgame = false;
	points = 0;
	ballmax = 1;
	balls = ballmax;
	movementspeed = 5.f;
	firstkey = false;
	control = 0;
	bool ev1 = false;
	gameover = false;
}

void Snake::initwindow()
{
	videomode.height = 500;
	videomode.width = 700;
	window = new sf::RenderWindow(this->videomode, "Snake Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(50);

}

void Snake::initball()
{
	ball.setRadius(5.f);
	ball.setFillColor(sf::Color::Red);
	ball.setOutlineThickness(2.f);
	ball.setOutlineColor((sf::Color::Green));
	ball.setPosition(sf::Vector2f(rand() % window->getSize().x - ball.getGlobalBounds().width, rand() % window->getSize().y - ball.getGlobalBounds().height));
}

void Snake::initline()
{
	line.setSize(sf::Vector2f(10.f, 10.f));
	line.setFillColor(sf::Color::Blue);
	line.setPosition(sf::Vector2f(100.f, 100.f));
	//	lines.push_back(line);
	head = line;

}

void Snake::inittexture()
{
	texture.loadFromFile("Textures/jungle.png");

}

void Snake::initsprite()
{
	sprite.setTexture(texture);
	sprite.setScale(1.5, 1.5);
}

void Snake::initext()
{

}

Snake::Snake()
{
	initvariable();
	initwindow();
	initball();
	initline();
	initext();
	inittexture();
	initsprite();
}

Snake::~Snake()
{
	delete window;
}

bool Snake::running()
{
	return window->isOpen();
}

void Snake::getheadpos()
{
	if (points == 0)
	{
		prevx = head.getPosition().x;
		prevy = head.getPosition().y;
	}
	else if (points > 0)
	{
		prevx = lines[points - 1].getPosition().x;
		prevy = lines[points - 1].getPosition().y;
	}
}


void Snake::pollEvents()
{
	x = head.getPosition().x;
	y = head.getPosition().y;
	option = 0;
	while (this->window->pollEvent(this->ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			this->window->close();
		}
		else if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
		}
		if (firstkey == false)
		{

			if (ev.key.code == sf::Keyboard::A)
			{
				head.setPosition(head.getPosition().x - xdir, head.getPosition().y);
				//	head.move(-movementspeed, 0);
				control = 1;
			}
			else if (ev.key.code == sf::Keyboard::D)
			{
				head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
				//	head.move(movementspeed, 0);
				control = 2;
			}
			else if (ev.key.code == sf::Keyboard::W)
			{
				//head.setOrigin(head.getPosition().x, head.getPosition().y);
				//head.setOrigin(head.getGlobalBounds().left, head.getGlobalBounds().top);
				//head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
				//head.move(movementspeed, 0);
				//head.rotate(270.f);
				//head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
				head.setPosition(head.getPosition().x, head.getPosition().y - xdir);
				control = 3;
			}
			else if (ev.key.code == sf::Keyboard::S)
			{
				// head.setPosition(head.getPosition().x + xdir , head.getPosition().y);
				 //head.move(movementspeed, 0);
				 //head.setOrigin(20, 10);
				 //head.setOrigin(head.getPosition().x + head.getGlobalBounds().width, head.getPosition().y + head.getGlobalBounds().height);
				 //head.rotate(90.f);
				head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
				control = 4;
			}
			firstkey = true;
		}
		else if (firstkey == true)
		{
			ev1 = true;
			option = 1;
			if (ev.key.code == sf::Keyboard::A)
			{
				if (control == 3)
				{
					control = 1;
					//head.setOrigin(20, 10);
					//head.move(0, movementspeed);
				 //	head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
					//head.rotate(90.f);
					head.setPosition(head.getPosition().x - xdir, head.getPosition().y);
				}
				else if (control == 4)
				{
					control = 1;
					//head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
					//head.rotate(90.f);
					head.setPosition(head.getPosition().x - xdir, head.getPosition().y);

				}
				else
				{
					head.setPosition(head.getPosition().x - xdir, head.getPosition().y);
					//printf("SSS\n");
					//head.move(-movementspeed, 0);
				}
			}
			else if (ev.key.code == sf::Keyboard::D)
			{
				if (control == 3)
				{
					control = 2;
					head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
					//	head.setPosition(head.getPosition().x, head.getPosition().y + xdir );
					//	head.move(0, movementspeed);
					//	head.setOrigin(20, 10);
						//head.rotate(270.f);
				}
				else if (control == 4)
				{
					control = 2;
					//head.setPosition(head.getPosition().x, head.getPosition().y + xdir );
					//head.rotate(270.f);
					head.setPosition(head.getPosition().x + xdir, head.getPosition().y);

				}
				else
				{
					head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
					//	printf("AAA\n");
					//	head.move(movementspeed, 0);
				}
			}
			else if (ev.key.code == sf::Keyboard::W)
			{
				if (control == 1)
				{
					//	head.setOrigin(head.getPosition().x, head.getPosition().y);
					head.setPosition(head.getPosition().x, head.getPosition().y - xdir);
					//head.setOrigin(head.getGlobalBounds().left, head.getGlobalBounds().top);
				   // head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
					//head.move(movementspeed, 0);
					//head.setOrigin(20, 10);
					//head.setOrigin(head.getPosition().x + head.getGlobalBounds().width, head.getPosition().y + head.getGlobalBounds().height);
					//head.rotate(270.f);
					control = 3;

				}
				else if (control == 2)
				{
					//	head.setOrigin(head.getPosition().x, head.getPosition().y);
						//head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
						//head.rotate(270.f);
					control = 3;
					head.setPosition(head.getPosition().x, head.getPosition().y - xdir);
				}
				else
				{
					head.setPosition(head.getPosition().x, head.getPosition().y - xdir);
					//head.move(0, -movementspeed);
				}
			}
			else if (ev.key.code == sf::Keyboard::S)
			{
				if (control == 1)
				{
					//head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
					//head.move(movementspeed, 0);
					//head.setOrigin(20, 10);
					control = 4;
					head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
					//	head.setOrigin(head.getPosition().x + head.getGlobalBounds().width, head.getPosition().y + head.getGlobalBounds().height);
						//head.rotate(90.f);
				}
				else if (control == 2)
				{
					//	head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
					//	head.rotate(90.f);
					head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
					control = 4;

				}
				else
				{
					head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
					//	head.move(0, movementspeed);
				}
			}
		}
	}
	if (option == 0)
	{
		ev1 = false;
	}

}



void Snake::updateball()
{
	lines.push_back(line);
	if (lines.size() == 1)
	{
		lines[points - 1].setPosition(prevx, prevy);
	}
	else
	{
		lines[points - 1].setPosition(prevx, prevy);
	}
}


void Snake::updateline()
{
	if (ev1 == false)
	{
		if (control == 1)
		{
			head.setPosition(head.getPosition().x - xdir, head.getPosition().y);
			//head.move(-movementspeed, 0);
		}
		else if (control == 2)
		{
			head.setPosition(head.getPosition().x + xdir, head.getPosition().y);
			//head.move(movementspeed, 0);
		}
		else if (control == 3)
		{
			head.setPosition(head.getPosition().x, head.getPosition().y - xdir);
			//head.move(0, -movementspeed);
		}
		else if (control == 4)
		{
			head.setPosition(head.getPosition().x, head.getPosition().y + xdir);
			//head.move(0, movementspeed);
		}
	}
}


void Snake::input()
{
	int i = lines.size() - 1;
	for (; i >= 0; i--)
	{
		if (i != 0)
		{
			float j = lines[i - 1].getPosition().x;
			float k = lines[i - 1].getPosition().y;
			lines[i].setPosition(j, k);
		}
		else if (i == 0)
		{
			lines[i].setPosition(x, y);
		}
	}
}

void Snake::collision()
{
	if (head.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		ball.setPosition(sf::Vector2f(rand() % window->getSize().x - ball.getGlobalBounds().width, rand() % window->getSize().y - ball.getGlobalBounds().height));
		points++;

		updateball();
	}

	if (head.getPosition().x + head.getGlobalBounds().width > window->getSize().x)
	{
		//	printf("h\n");
		gameover = true;
	}
	if (head.getPosition().x < 0)
	{

		printf("g\n");
		gameover = true;
	}
	if (head.getPosition().y + head.getGlobalBounds().height > window->getSize().y)
	{
		printf("j\n");
		gameover = true;
	}
	if (head.getPosition().y < 0)
	{
		printf("l\n");
		gameover = true;
	}

	for (int i = 0; i < lines.size(); i++)
	{
		if (head.getGlobalBounds().intersects(lines[i].getGlobalBounds()))
			gameover = true;
	}





}



void Snake::update()
{
	getheadpos();
	pollEvents();
	updateline();
	collision();
	input();
	if (gameover == true)
	{
		printf("aa\n");
		window->close();
	}


}

void Snake::renderball(sf::RenderTarget& target)
{
	target.draw(sprite);
	target.draw(ball);
}

void Snake::renderline(sf::RenderTarget& target)
{
	target.draw(head);
	for (int i = 0; i < lines.size(); i++)
	{
		target.draw(lines[i]);
	}
}

void Snake::render()
{
	this->window->clear(sf::Color::Black);

	//draw
	//window->draw(sprite);
	renderball(*window);
	renderline(*window);

	this->window->display();
}