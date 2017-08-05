
/// 
///  Fast and simple IO library for Arduino compatible boards.
///  Not the fastest, but simplest to use (for me at least).
///  Created for personal use, use it at your own risk and benefit.
///	 https://github.com/GitMoDu/Fast
/// 

#ifndef _SHIFTER_h
#define _SHIFTER_h


#include <Arduino.h>

class Fast
{
private:
	bool LastValue = false;
	volatile uint8_t *Mode;
	volatile uint8_t *OutPin;
	uint8_t PinAddress;

public:
	bool virtual Setup(uint8_t pin, bool startValue = false);
	void Set(bool value);
	bool GetLast();
	void Toggle();
};

class FastOut : public Fast
{
};

class FastShifter : public Fast
{
public:
	virtual bool Setup(uint8_t pin, bool startValue = false);
	void PulseLow();
	void PulseHigh();
	void PulseLow(const uint16_t pulseIntervalMicros);
	void PulseHigh(const int16_t pulseIntervalMicros);
};



#endif

