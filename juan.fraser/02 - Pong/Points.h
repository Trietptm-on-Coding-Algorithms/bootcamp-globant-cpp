#pragma once
class Points
{
private:
	int p;
	static int maxPoints;
	void setPoints(int newPoints);
public:
	int getPoints();
	static void setMaxPoints(int newMaxPoints);
	bool incrementPoints();
	bool hasWon();
	void resetPoints();

	Points();
	~Points();
};

