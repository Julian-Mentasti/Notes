## Address alignment

An aligned address are those whose numeric value is a multiple of the object size

 - they are better because you can fit two shorts in an int..
 - CPUs don't support misaligned addresses
 - misaligned access is slower

 Ex:

 - address 6 is aligned for a short (2 byte)
 - address 6 is not aligned for a 4 byte

## Extending a byte


This would extend - add more figures
```
byte b = -6;
int i = b;
```

if we want to remove figures we can do the following:
```
int i = 35;
short s = i;
```

int i   -> 0000 0000 0000 0000 0000 0010 0011
short s ->                     0000 0010 0011

Ex1:

Suppose `int i = 65550;`

equals: 0000 ... 0001 0000 0000 0000 1110

after: `short s = i;`

equals: 0000 0000 1110 (14)


Ex2:

Suppose `int i = 65530`

equals: 0000 ... 0000 1111 1111 1111 1010

after: `short s = i;`

equals: 1111 1111 1111 1010 (6)

## Bit operations:

 - a << b Shift all bit in a to the left b times, fill the remaining with zeros
 - a >> b Shit all bits in a to the right b times, fill the remaining with zeros
 - a & b AND applied
 - a | b OR applied
 - a ^ b XOR applied

`byte b = 10;` ->    0000 1010
`b << 3`       -> ~~000~~ 0101 0000 (b *  2^3)
`b << 3`       ->    000 0000 1010 ~~1010~~ (b / 2^3)
`~a`           -> 1111 0101

# Revise:

 - two's compliment
