#include "stdafx.h"
#include "Game.h"


int Game::getScreenX() { return this->w->getSize().x; }
int Game::getScreenY() { return this->w->getSize().y; }

int Game::run()
{
	sf::Clock clock;
	sf::Event event;
	static const int maxMS = 100;

	static const int waitTime = 3000;
	int waiting;

	bool lostFocus = false;
	State s = START;
	while (w->isOpen())
	{
		//Window Management
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			w->close();
		}
		while (w->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				w->close();
			}
			else if (event.type == sf::Event::LostFocus) {
				w->requestFocus();
				lostFocus = true;
			}
			else if (event.type == sf::Event::GainedFocus) {
				lostFocus = false;
				clock.restart();
			}
		}
		//Unfocus "Pause"
		if (lostFocus) {
			continue;
		}
		//Time Elapsed
		int ms = clock.restart().asMilliseconds();
		if (ms > maxMS) {
			ms = maxMS;
		}

		switch (s) {
		case START: {
			message = "Press SPACEBAR to begin, or Esc to exit.\n";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				waiting = waitTime;
				s = PREP_TIME;
			}
			break;
		}
		case PREP_TIME: {
			message = "Starting in ";
			waiting -= ms;
			float show = waiting / 1000.f;
			message.append(to_string(show));
			message.append(".\n");
			if (waiting <= 0) {
				s = PLAY_TIME;
			}
			break;
		}
		case PLAY_TIME: {
			message = "";
			message.append(to_string(players.front()->getPoints()));
			message.append(" : ");
			message.append(to_string(players.back()->getPoints()));
			message.append("\n");
			input();
			bool ret = update(ms);
			if (ret) {
				s = END;
			}		
			break;
		}
		case END: {
			for (auto p : players) {
				if (p->hasWon())
					message = p->name;
			}
			message.append(" has WON.\n");
			message.append("Press SPACEBAR to begin again, or Esc to exit.\n");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				for (auto p : players) {
					p->reset();
				}
				for (auto b : balls) {
					b->reset();
				}
				waiting = waitTime;
				s = PREP_TIME;
			}
			break;
		}
		default: {
			s = START;
		}
		}
		render();
	}
	return 0;
}

void Game::input()
{
	for (auto p : players) {
		p->updateInput();
	}
}
bool Game::update(int ms)
{
	bool ret = false;
	for (auto p : players) {
		p->updatePos(ms);
		p->collision(0.f, static_cast<float>(getScreenY()) );
	}
	for (auto b : balls) {
		b->updatePos(ms);
		b->wallCollision(0.f, static_cast<float>(getScreenY()) );
		int retValue = b->edgeCollision(0.f, static_cast<float>(getScreenX()));
		if (retValue != 0) {
			bool gameOver = false;
			if (retValue < 0) {
				gameOver = players.back()->incrementPoints();
			}
			else if (retValue > 0) {
				gameOver = players.front()->incrementPoints();
			}
			if (gameOver) {
				ret = true;
			}
			else {
				b->reset();
			}
		}
		for (auto p : players) {
			b-> objectCollision(p->getShape());
		}
	}
	
	// TODO? //
	// Collisions between balls

	return ret;
}
void Game::render()
{
	w->clear();
	for (auto p : players) {
		w->draw(*p->getShape());
	}
	for (auto b : balls) {
		w->draw(*b->getShape());
	}
	renderMessage();
	w->display();
}

void Game::renderMessage()
{
	printf( (this->message).c_str() );
	// TODO? //
	// Proper Graphic Text
}

Game::Game(sf::RenderWindow* w)
{
	this->w = w;
	this->players = vector<Player*>();
	this->balls = vector<Ball*>();
	this->message = "";
	
	static const float height = 64;
	static const float width = 16;
	static const sf::Vector2f size(width, height);
	players.push_back(new Player("Player 1", size, sf::Vector2f(0, (getScreenY() - height) / 2), sf::Keyboard::W, sf::Keyboard::S));
	players.push_back(new Player("Player 2", size, sf::Vector2f(getScreenX() - width, (getScreenY() - height) / 2), sf::Keyboard::Up, sf::Keyboard::Down));

	static const float radius = 16.0f;
	static const sf::Vector2f initVel(0.3f, 0.3f);
	static const sf::Vector2f initPos( (getScreenX()-2*radius) / 2.f, (getScreenY()-2*radius) / 2.f);
	balls.push_back( new Ball(radius, initVel, initPos) );
}


Game::~Game()
{
}
