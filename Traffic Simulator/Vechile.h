#include <iostream>
#include <string>

using namespace std;

#ifndef Vechile_H
#define Vechile_H

class Vechile{
public:
	Vechile(); // Constructor
	
	~Vechile(); //Destructor
	string getType() const; // returns type of vechile
	string getColor() const; // returns color of vechile
	int getLength() const; // returns length of vechile
	int getWidth() const; // returns width of vechile
	int getMaxSpeed() const; // returns max speed of vechile
	int getAcceleration() const; // returns acceleration of vechile
	int getLaneFreq() const;
	int getPosx() const;
	int getPosy() const;
        int getSpeed() const;
	int getSpeedy() const;
	int getDisx() const;
	int getDisy() const;

	//used for setting parameters
	void setType(string);
	void setColor(string);
	void setLength(int);
	void setWidth(int);
	void setMaxSpeed(int);
	void setAcceleration(int);
	void setLaneFreq(int);
	void setPosx(int);
	void setPosy(int);
        void setSpeed(int);
	void setSpeedy(int);
	void setDisx(int);
	void setDisy(int);

	void movex();
	void movey();

private:
	//Member Variables
	string Type;
	string Color;
	int Length;
	int Width;
	int MaxSpeed;
	int Acceleration;
	int LaneFreq; //Lane Change Frequency
	int Posx;
	int Posy;
        int Speed;
	int Disx;
	int Disy;
	int Speedy;
};

#endif

