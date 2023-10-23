#include <iostream>
#include "student.hpp"
#include "international.hpp"

using namespace std;

#ifndef __TOEFL_HPP__
#define __TOEFL_HPP__

class ToeflScore
{
public:

	ToeflScore(int reading, int listening, int speaking, int writing, int total);
	ToeflScore(int Reading, int Listening, int Speaking, int Writing);
	ToeflScore();

	//get functions
	int get_reading() const;
	int get_listening() const;
	int get_speaking() const;
	int get_writing() const;
	int get_total() const;

	//set functions
  void set_total(ToeflScore &toefl, int total);
  void set_reading(ToeflScore &toefl, int reading);
  void set_writing(ToeflScore &toefl, int writing);
  void set_speaking(ToeflScore &toefl, int speaking);
  void set_listening(ToeflScore &toefl, int listening);
  void set_toefl(ToeflScore toefl, int listening, int reading, int writing, int speaking, int total);

  /*friend ostream& operator<<(ostream& os, ToeflScore& toefl);*/
	//void set_total();//sets it by adding up the other functions

private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total;
};

#endif