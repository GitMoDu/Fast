/*
		Benchmark program to test speed of IO.
		Intended only for testing and optimization in real world scenarios, not for synthetic testing or comparison.

		Created for personal use, use it at your own risk and benefit.
		https://github.com/GitMoDu/Fast

modified 5 Aug 2017
by MoDu
*/

#include <Fast.h>
#include <DirectIO.h>

FastOut ledPin;
FastOut *ledPinPointer;
FastOutCached *ledPinCachedPointer;
OutputPin DirectPin(LED_BUILTIN);
OutputPin *DirectPinPointer;

#define BENCHMARK_SIZE 100000
#define BENCHMARK_STEP_DELAY 300

void setup() {
	Serial.begin(115200);

	Benchmark();
}

void Benchmark()
{
	Serial.print(F("Benchmarking "));
	Serial.print(BENCHMARK_SIZE);
	Serial.println(F(" toggles "));

	uint32_t Start, Duration;
	bool ManualToggle = false;

	pinMode(LED_BUILTIN, OUTPUT);
	ManualToggle = LOW;
	digitalWrite(LED_BUILTIN, ManualToggle);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		digitalWrite(LED_BUILTIN, ManualToggle);
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	digitalWrite(LED_BUILTIN, ManualToggle);
	PrintBenchmarkResults(Duration, "Digital Write Manual Toggle");


	ledPin.Setup(LED_BUILTIN, ManualToggle);

	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		//ledPin = ManualToggle;
		ledPin.Set(ManualToggle);
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPin = ManualToggle;
	PrintBenchmarkResults(Duration, "Fast Manual Toggle");

	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		ledPin.Toggle();
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPin = ManualToggle;
	PrintBenchmarkResults(Duration, "Fast Auto Toggle");


	ledPinPointer = new FastOut(LED_BUILTIN, ManualToggle);

	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		ledPinPointer->Set(ManualToggle);
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPinPointer->Set(ManualToggle);
	PrintBenchmarkResults(Duration, "Fast Pointer Manual Toggle");

	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		ledPinPointer->Toggle();
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPinPointer->Set(ManualToggle);
	PrintBenchmarkResults(Duration, "Fast Pointer Auto Toggle");

	ledPinCachedPointer = new FastOutCached(LED_BUILTIN, ManualToggle);
	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		ledPinCachedPointer->Set(ManualToggle);
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPinCachedPointer->Set(ManualToggle);
	PrintBenchmarkResults(Duration, "Fast Cached Pointer Manual Toggle");

	//ledPinCachedPointer = new FastOutCached(LED_BUILTIN, ManualToggle);
	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		ledPinCachedPointer->Toggle();
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	ledPinCachedPointer->Set(ManualToggle);
	PrintBenchmarkResults(Duration, "Fast Cached Pointer Auto Toggle");

	DirectPin = ManualToggle;
	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{

		DirectPin = ManualToggle;
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	DirectPin = ManualToggle;
	PrintBenchmarkResults(Duration, "DirectIO Manual Toggle");

	DirectPin = ManualToggle;
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		DirectPin.toggle();
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	DirectPin = ManualToggle;
	PrintBenchmarkResults(Duration, "DirectIO Auto Toggle");

	DirectPinPointer = new OutputPin(LED_BUILTIN);
	DirectPinPointer->write(ManualToggle);
	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{

		DirectPinPointer->write(ManualToggle);
		ManualToggle = !ManualToggle;
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	DirectPinPointer->write(ManualToggle);
	PrintBenchmarkResults(Duration, "DirectIO Pointer Manual Toggle");

	DirectPinPointer = new OutputPin(LED_BUILTIN);
	DirectPinPointer->write(ManualToggle);
	delay(BENCHMARK_STEP_DELAY);
	Start = millis();
	for (uint32_t counter = 0; counter < BENCHMARK_SIZE; counter++)
	{
		DirectPin.toggle();
	}
	Duration = millis() - Start;
	ManualToggle = LOW;
	DirectPinPointer->write(ManualToggle);
	PrintBenchmarkResults(Duration, "DirectIO Pointer Auto Toggle");


	digitalWrite(LED_BUILTIN, HIGH);
	Serial.println(F("Benchmark complete."));
	delay(BENCHMARK_STEP_DELAY * 3);
	digitalWrite(LED_BUILTIN, LOW);

}

void PrintBenchmarkResults(uint32_t duration, char* benchmarkType)
{
	Serial.print(benchmarkType);
	Serial.print(F(" took "));
	Serial.print(duration);
	Serial.print(F(" ms - "));

	uint32_t Frequency = (BENCHMARK_SIZE * 1000) / duration;
	float FrequencyKHz = Frequency / 1000;
	Serial.print(FrequencyKHz, 1);
	Serial.println(F(" kHz"));
}

void loop() {
}
