# Pandigital divisibility

A number is said to be pandigital in base 10 if it contains each of the digits from 0 to 9 (the leading digit must be nonzero). For example, 1406357289 is such a number. It has the additional property that each of its consecutive subnumbers of length 3, starting from the second digit, is divisible by the corresponding next prime below 20:

$\quad d_2d_3d_4=406$ is divisible by 2  
$\quad d_3d_4d_5=063$ is divisible by 3  
$\quad d_4d_5d_6=635$ is divisible by 5  
$\quad d_5d_6d_7=357$ is divisible by 7  
$\quad d_6d_7d_8=572$ is divisible by 11  
$\quad d_7d_8d_9=728$ is divisible by 13  
$\quad d_8d_9d_{10}=289$ is divisible by 17  

where $d_n$ is the $n$-th digit of the number.

You are asked to find all the pandigital numbers in base 10 with this property.  

The output of your program should be the list of all these numbers, one per line, in ascending order. Note that you are not allowed to use a sorting function.
