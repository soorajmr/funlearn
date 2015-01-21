# funlearn
Functional programming by example

A simple example to give a novice a quick glimpse of functional programming style. This consists of a tiny car race simulation written in C and Standard ML, so that the reader can compare the styles. Expertise in C/C++ is expected from the reader.

Here are the details of the car race simulation:
Three cars are competing in our “Speed Circuit” race. One Jaguar, one Porsche and one Audi. The whole thing is very deterministic: cars start running with a uniform acceleration until they reach their max speed. Then on, they just travel at constant speed till the end of the track. Here are the acceleration and max speed values of the cars:
 
| Car	|  Acceleration (m/s2)	|  Max speed (m/s)|
|------|-----------------------|-----------------|
| Jaguar	| 8	| 120 |
| Porsche | 9 | 99 |
| Audi	| 6 | 126 |
 

See c directory for the C language implementation. This is written in a modular, "object oriented" style. The functional version written in Standard ML is in the sml directory. The purpose of these examples is to show the differences in basic constructs and introduce map & reduce, function composition, closures, etc. to the reader, rather than showing the best way to design functional programs.


This was inspired by https://codewords.hackerschool.com/issues/one/an-introduction-to-functional-programming 






