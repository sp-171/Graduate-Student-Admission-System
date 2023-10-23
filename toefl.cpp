#include <iostream>
using namespace std;
#include "toefl.hpp"

using namespace std;

ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing, int Total)
{
	this->reading = Reading;
	this->listening = Listening;
	this->speaking = Speaking;
	this->writing = Writing;
	this->total = Total;

}

ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing)
{
	this->reading = Reading;
	this->listening = Listening;
	this->speaking = Speaking;
	this->writing = Writing;
	this->total = Reading + Listening + Speaking + Writing;
}

ToeflScore::ToeflScore()
{
	this->reading = 0;
	this->listening = 0;
	this->speaking = 0;
	this->writing = 0;
	this->total = 0;
}

//Get Function**********************************************
int ToeflScore::get_reading() const
{
	return reading;
}

int ToeflScore::get_listening() const
{
	return listening;
}

int ToeflScore::get_speaking() const
{
	return speaking;
}

int ToeflScore::get_writing() const
{
	return writing;
}

int ToeflScore::get_total() const
{
	return total;
}

//Set functions**********************************************
void ToeflScore::set_total(ToeflScore &toefl, int total)
{
  toefl.total = total; 
}

void ToeflScore::set_reading(ToeflScore &toefl, int reading)
{
  toefl.reading = reading; 
}
void ToeflScore::set_writing(ToeflScore &toefl, int writing)
{
  toefl.writing = writing; 
}

void ToeflScore::set_speaking(ToeflScore &toefl, int speaking)
{
  toefl.speaking = speaking; 
}

void ToeflScore::set_listening(ToeflScore &toefl, int listening)
{
  toefl.listening = listening; 
}

void set_toefl(ToeflScore toefl, int listening, int reading, int writing, int speaking, int total)
{
  toefl.set_total(toefl, total);
  toefl.set_reading(toefl, reading);
  toefl.set_writing(toefl, writing); 
  toefl.set_speaking(toefl, speaking); 
  toefl.set_listening(toefl, listening);
}