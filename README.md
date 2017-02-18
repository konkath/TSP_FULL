Made with Microsoft Visual Studio 2015 and C++11

Map is saved in form of two dimensional vector (adjacency matrix).
Program supports maps with both int and double type of costs. 
Map class supports loading XML files from TSPLib and saving generated map into XML file with same structure as used in TSPLib. 
For xml read/write rapidXML library is used. 
There is posibility to generate own maps of given size and type: Symetric and Asymetric.

Random number generation is implemented with using thread safe Mersenne Twister algorithm in form of singleton.

Generated solution holds information of path, cost and time it took to get it.

Timer class supports multithreading algorithms as it bases on system time instead of core frequency. Precision is in ms. 
Link with "Winmm.lib"

Currently supported algorithms:
- random solution (single thread)
- bruteforce (multi thread)
- greedy (single thread)


Planned algorithms:
- dynamic
- genetic
- 2-approximation
- 3/2-approximation
