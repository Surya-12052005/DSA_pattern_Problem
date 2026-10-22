/*
========================================================
        BIT MANIPULATION - SHORT NOTES
========================================================

1. BITWISE OPERATORS
--------------------
&   -> AND
|   -> OR
^   -> XOR
<<  -> Left Shift
>>  -> Right Shift
~   -> NOT (Bitwise Complement)


2. AND (&)
-----------
Rule:
1 & 1 = 1
All other combinations = 0

Shortcut:
Both bits must be 1 to get 1.


3. OR (|)
---------
Rule:
0 | 0 = 0
All other combinations = 1

Shortcut:
At least one bit must be 1 to get 1.


4. XOR (^)
-----------
Rule:
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1

Shortcut:
Same bits -> 0
Different bits -> 1

Important:
n ^ n = 0
n ^ 0 = n

For integers:
a ^ b = 1 at a bit position if the
corresponding bits of a and b differ.


5. LEFT SHIFT (<<)
-------------------
Formula:
n << k = n * 2^k

Example:
13 = 1101 (binary)

13 << 1 = 11010 = 26
13 << 2 = 110100 = 52

Shortcut:
Shift bits left by k positions.
For non-negative integers, multiplication
by 2^k applies when no overflow occurs.


6. RIGHT SHIFT (>>)
--------------------
For non-negative integers:
n >> k = floor(n / 2^k)

Example:
13 = 1101 (binary)

13 >> 1 = 0110 = 6
13 >> 2 = 0011 = 3
13 >> 3 = 0001 = 1
13 >> 4 = 0000 = 0

Shortcut:
Shift bits right by k positions.
For non-negative integers, divide by 2^k
and discard the fractional part.


7. QUICK REVISION
------------------
AND (&)  -> Both bits 1
OR (|)   -> At least one bit 1
XOR (^)  -> Different bits give 1
LEFT (<<)-> Multiply by 2^k (when safe)
RIGHT(>>)-> Divide by 2^k for non-negative n
NOT (~)  -> Flip every bit in the integer type

========================================================
*/

//what is the largest integer that a integer datatype can store : 2^{31}-1 




/*
========================================================
     BIT MANIPULATION - NOTES (PART 2)
========================================================

1. SIGN BIT
------------
In a typical 32-bit signed integer:
- MSB (bit 31) = 0 -> Non-negative
- MSB (bit 31) = 1 -> Negative

MSB = Most Significant Bit (leftmost bit).


2. BITWISE NOT (~)
-------------------
NOT flips every bit:
0 -> 1
1 -> 0

Example (8-bit representation):
  5  = 00000101
 ~5  = 11111010

In C++, for a signed integer:
~n = -n - 1

Therefore:
~5  = -6
~-6 = 5

Remember:
~n is NOT the same as -n.


3. 1'S COMPLEMENT
------------------
1's complement = Flip every bit.

Example:
  5 = 00000101
Flip bits:
    = 11111010

This is the bitwise NOT operation.
In signed representations, 1's complement
is not the representation normally used by
modern C++ systems for signed integers.


4. 2'S COMPLEMENT
------------------
2's complement = 1's complement + 1

To represent a negative number:
Step 1: Write the positive number in binary.
Step 2: Flip all bits.
Step 3: Add 1.

Example: Represent -5 using 8 bits.

  +5 = 00000101
Flip = 11111010
 +1  = 11111011

Therefore:
  -5 = 11111011 (8-bit 2's complement)


5. FINDING A NEGATIVE NUMBER
-----------------------------
For a positive integer n:
-n = ~n + 1

Example:
n = 5
-5 = ~5 + 1

In C++:
int n = 5;
int negative = -n;


6. INTEGER RANGE (32-BIT SIGNED INT)
-------------------------------------
Total bits = 32
Sign bit   = 1
Value bits = 31

Maximum:
2^31 - 1
= 2,147,483,647

Minimum:
-2^31
= -2,147,483,648

Formula:
INT_MAX =  2^31 - 1
INT_MIN = -2^31

Note:
The range is asymmetric:
INT_MIN has a magnitude one greater than INT_MAX.


7. LEFT SHIFT (<<)
-------------------
Formula:
n << k = n * 2^k

Example:
13 << 1 = 26

Caution:
Signed left shifts can have restrictions.
Avoid shifts that overflow or use invalid counts.


8. RIGHT SHIFT (>>)
--------------------
For non-negative integers:
n >> k = floor(n / 2^k)

Examples:
13 >> 1 = 6
13 >> 2 = 3
13 >> 3 = 1
13 >> 4 = 0

For negative signed integers, right shift
rounding/behavior differs from simple unsigned
division; modern C++ specifies arithmetic
right shift for negative signed values.


========================================================
QUICK REVISION
========================================================

~n      -> Flip all bits
~n      -> -n - 1 (for C++ int)
-n      -> ~n + 1 (conceptual 2's complement)
INT_MAX ->  2^31 - 1 (typical 32-bit int)
INT_MIN -> -2^31     (typical 32-bit int)

========================================================
*/