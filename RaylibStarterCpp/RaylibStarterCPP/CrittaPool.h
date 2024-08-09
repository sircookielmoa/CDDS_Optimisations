#pragma once
class CrittaPool
{
public:
	void init(double x, double y, double xVel, double yVel, int lifetime);
	void animate();
	bool isAlive() const;

private:
	int framesleft_;
	double x_, y_;
	double xVel_, yVel_;
};

