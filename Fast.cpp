/// 
///  Created for personal use, use it at your own risk and benefit.
/// 

#include "Fast.h"

bool FastShifter::Setup(uint8_t pin, bool startValue)
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

bool Fast::Setup(uint8_t pin, bool startValue)
{
	PinAddress = digitalPinToBitMask(pin);
	Mode = portModeRegister(digitalPinToPort(pin));
	OutPin = portOutputRegister(digitalPinToPort(pin));

	*Mode |= PinAddress;

	Set(startValue);
}

void Fast::Set(bool value)
{
	if (value == LastValue)
	{
		return;
	}

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

