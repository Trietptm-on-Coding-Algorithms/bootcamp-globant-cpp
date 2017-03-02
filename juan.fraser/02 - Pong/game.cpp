#include "stdafx.h"
#include "game.h"

typedef enum STATE{
	PLAY_TIME, PREP_TIME
};

game::game(const int maxScore, sf::RenderWindow *rw) {
	this->maxScore = maxScore;
	this->rw = rw;
	int x = rw->getSize().x;
	int y = rw->getSize().y;
	player players[playersAmount] = { 
		player(0,y,sf::Keyboard::W, sf::Keyboard::S), 
		player(x,y,sf::Keyboard::Up, sf::Keyboard::Down) };
}
game::~game() {

}

int game::run() {
	sf::Clock clock;
	sf::Event event;
	bool lostFocus = false;
	STATE s = PREP_TIME;
	while (rw->isOpen()) {
		//Window Management
		while (rw->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				rw->close();
			else if (event.type == sf::Event::LostFocus) {
				rw->requestFocus();
				lostFocus = true;
			}
			else if (event.type == sf::Event::GainedFocus) {
				lostFocus = false;
				clock.restart();
			}

		}

		//Unfocus "Pause"
		if (lostFocus)
			continue;

		//Time Elapsed
		int dt = clock.restart().asMilliseconds();
		if (dt > 100)
			dt = 100;

		switch (s) {
		case PLAY_TIME:
			input();
			update(dt);
			render();
			break;
		case PREP_TIME:
			break;
		default:
			s = PLAY_TIME;
		}
		/*
		//Phisics Updates
		vx += ax*da*dt;
		vy += ay*da*dt;
		vx -= sd*vx*dt;
		vy -= sd*vy*dt;

		//Collisions
		if (rectangle.getGlobalBounds().top < 0)
			rectangle.setPosition(4, 0);
		if (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height > screenY)
			rectangle.setPosition(4, screenY - rectangle.getGlobalBounds().height);

		if (ball.getGlobalBounds().left < rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width
			&& ball.getGlobalBounds().top < rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height
			&& ball.getGlobalBounds().top + ball.getGlobalBounds().height > rectangle.getGlobalBounds().top)
			vx = -vx;

		if (ball.getGlobalBounds().left < 0 && vx < 0)
			vx = -vx;
		if (ball.getGlobalBounds().top < 0 && vy < 0)
			vy = -vy;
		if (ball.getGlobalBounds().left + ball.getGlobalBounds().width > screenX
			&& vx > 0)
			vx = -vx;
		if (ball.getGlobalBounds().top + ball.getGlobalBounds().height > screenY
			&& vy > 0)
			vy = -vy;

		//Object Update
		ball.move(vx*dv*dt, vy*dv*dt);

		//Renders

		*/
	}

	// state machine????

	int ret;
	if (rw->isOpen()) {
		int winner = 0;
		for (int i = 0; i < playersAmount; i++) {
			if (players[i].getScore() >= maxScore) {
				ret = i;
				break;
			}
		}
	} else
		ret = -1;
	return ret;
}

void game::input() {
	for (int i = 0; i < playersAmount; i++) {
		player p = players[i];
		p.movingUp = sf::Keyboard::isKeyPressed( p.getUp() );
		p.movingDown = sf::Keyboard::isKeyPressed(p.getDown());
	}
}

void game::update(int dt) {
	if (dt > 0) {
		for (int i = 0; i < playersAmount; i++)
			players[i].pUpdate(dt);
		// TODO: update ball.
	}
}

void game::render() {
	rw->clear();

	for (int i = 0; i < playersAmount; i++)
		rw->draw(* (players[i].getTab()) );
	// TODO: update ball.
	rw->display();
}