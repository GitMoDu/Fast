// Shifter.h

#ifndef _SHIFTER_h
#define _SHIFTER_h


#include <Arduino.h>

class Fast
{
private:
	bool LastValue = false;
	volatile u8 *Mode;
	volatile u8 *OutPin;
	u8 PinAddress;

public:
	bool virtual Setup(u8 pin, bool startValue);
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
	virtual bool Setup(u8 pin, bool startValue);
	void PulseLow();
	void PulseHigh();
};



#endif

