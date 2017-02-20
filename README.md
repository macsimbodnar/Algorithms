# Algorithms


The purpose of this project is try to implement in C some famous and important algorithms.

Also to show the difference in execution time, on same input, between algorithms that solve same problem but have different implementation.

The project is organized this way:

* main.c
* util.c
* runner.c
* algorithms.c
* .h files

### main

Contains the main loop and cli interface. You can ignore it.


### util

Contains some util function like populate an array with random integer or print separator line. You can ignore it.


### runner 

In this file i put the call to our "algorithms". 

Mainly i make this file to separate the "algorithms" from all that is redundant.
Things like execution time mensuration, status log, input set up etc... 


### algorithms

Finally, the most important file :)

Is there that happen **NASTY** and **FUNNY** things.
I try to make this file most clean possible. Here have place only the "algorithms" implementation.


### .h files

Just C headers files. They contain function prototypes, constants and data structures.



#### License

MIT License


#### References

Most of algorithms and complexity analysis are taken from [Introduction to Algorithms][1] by [Thomas H. Cormen][2], [Charles E. Leiserson][3], [Ronald L. Rivest][4], and [Clifford Stein][5].



[1]: https://mitpress.mit.edu/books/introduction-algorithms
[2]: http://www.cs.dartmouth.edu/~thc/
[3]: https://people.csail.mit.edu/cel/
[4]: https://people.csail.mit.edu/rivest/
[5]: http://www.columbia.edu/~cs2035/