# Dogs-Vets-Examine-Join-Algorithm-
C++ program that reads 3 data files and groups dogs by age who were examined by vets. 


Consider the following schema:
Veterinarians (vid: integer, eLevel);
Examine (vid: integer, did: integer, fee: integer);
Dogs (did: integer, age: integer);


The eLevel is meant to be an experience rating level; it is in the range: [1, 10].
Fee is in the approximate range: [75, 200], age is in the range: [9, 12]
Heap files corresponding to instances of the above relations are VFile (for Veterinarians), EFile (for
Examine) and DFile (for Dogs); on each line of the heap file, the attributes are listed in the above
corresponding schema order. 


You are to write a C/C++ program to find the answer to the following query:
SELECT D.age, COUNT(*), AVG(X.fee), AVG(V.eLevel)
FROM Dogs D, Exmaine X, Veterinarians V
WHERE D.did=X.did AND X.vid=V.vid
GROUP BY D.age


You are expected to implement an efficient join algorithm as part of your solution to this problem.
However, you must assume that main memory is limited, and it is not possible to read all of the
relations into main memory at once; furthermore, your solution must be capable of processing files
of unbounded (unknown) size. Your program is to use VFile, DFile and EFile as input to the
program. Your score on this problem may be based in part on the performance of your
implementation. You must implement your own join algorithm. It is NOT acceptable to use
library routines / system calls / commands / etc. which provide a join capability.
