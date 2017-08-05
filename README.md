# Fast (Arduino Compatible)

Fast and simple IO for Arduino, easy to use for library making.

Tested in: ATmega328p, ATTiny85.

Results in ATmega328p @ 16 MHz

Benchmarking 100000 toggles 
Digital Write Manual Toggle took 472 ms - 211.0 kHz
Fast Manual Toggle took 254 ms - 393.0 kHz
Fast Auto Toggle took 329 ms - 303.0 kHz
Fast Pointer Manual Toggle took 249 ms - 401.0 kHz
Fast Pointer Auto Toggle took 348 ms - 287.0 kHz
Fast Cached Pointer Manual Toggle took 148 ms - 675.0 kHz
Fast Cached Pointer Auto Toggle took 155 ms - 645.0 kHz
DirectIO Manual Toggle took 273 ms - 366.0 kHz
DirectIO Auto Toggle took 355 ms - 281.0 kHz
DirectIO Pointer Manual Toggle took 267 ms - 374.0 kHz
DirectIO Pointer Auto Toggle took 355 ms - 281.0 kHz
Benchmark complete.