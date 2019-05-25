#include "Vechile.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;


Vechile::Vechile(){
	Length=0;
	Width=0;
	MaxSpeed=5; //for now, later to be taken from configuration file
	Acceleration=1; //for now, later to be taken from configuration file
	LaneFreq=0; //for now, later to be taken from configuration file
	Speed=1;
        Speedy=0;
        Disx=2;
}


Vechile::~Vechile(){

}
//get any parameter
string Vechile::getType() const{
	return Type;
}
string Vechile::getColor() const{
	return Color;
}
int Vechile::getLength() const{
	return Length;
}
int Vechile::getWidth() const{
	return Width;
}
int Vechile::getMaxSpeed() const{
	return MaxSpeed;
}
int Vechile::getAcceleration() const{
	return Acceleration;
}
int Vechile::getLaneFreq() const{
	return LaneFreq;
}
int Vechile::getPosx() const{
	return Posx;
}
int Vechile::getPosy() const{
	return Posy;
}
int Vechile::getSpeed() const{
	return Speed;
}
int Vechile::getSpeedy() const{
	return Speedy;
}
int Vechile::getDisx() const{
	return Disx;
}
int Vechile::getDisy() const{
	return Disy;
}
//set any parameter manually
void Vechile::setType(string s) {
	Type=s;
}
void Vechile::setColor(string s) {
	Color=s;
}
void Vechile::setLength(int f) {
	Length=f;
}
void Vechile::setWidth(int f) {
	Width=f;
}
void Vechile::setMaxSpeed(int f) {
	MaxSpeed=f;
}
void Vechile::setAcceleration(int f) {
	Acceleration=f;
}
void Vechile::setLaneFreq(int f) {
	LaneFreq=f;
}
void Vechile::setPosx(int f) {
	Posx=f;
}
void Vechile::setPosy(int f) {
	Posy=f;
}
void Vechile::setSpeed(int f) {
	Speed=f;
}
void Vechile::setSpeedy(int f) {
	Speedy=f;
}
void Vechile::setDisx(int f){
	Disx=f;;
}
void Vechile::setDisy(int f){
	Disy=f;
}

void Vechile::movex(){
	setPosx((getPosx()) + (getSpeed()));
}
void Vechile::movey(){
        setPosy((getPosy())+(getSpeedy()));
}

