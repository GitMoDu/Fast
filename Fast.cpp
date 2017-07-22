/// 
///  Created for personal use, use it at your own risk and benefit.
/// 

#include "Fast.h"

bool FastShifter::Setup(u8 pin, bool startValue)
{
	Fast::Setup(pin, startValue);
}

void FastShifter::PulseHigh()
{
	Set(HIGH);
	Set(LOW);
}

void FastShifter::PulseLow()
{
	Set(LOW);
	Set(HIGH);
}

bool Fast::Setup(u8 pin, bool startValue)
{
	PinAddress = digitalPinToBitMask(pin);
	Mode = portModeRegister(digitalPinToPort(pin));
	OutPin = portOutputRegister(digitalPinToPort(pin));

	// set pin port as ouput
	*Mode |= PinAddress;

	Set(startValue);
}

void Fast::Set(bool value)
{
	LastValue = value;

	if(LastValue)
	{
		*OutPin |= PinAddress;
	}
	else 
	{
		*OutPin &= ~PinAddress;
	}
}

bool Fast::GetLast()
{
	return LastValue;
}

void Fast::Toggle()
{
	Set(!LastValue);
}

