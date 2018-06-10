# Dr. Estery or: How I Learned to Stop Worrying and Love big O. 

# Table of contents
1. [Introduction](#introduction)
2. [Big O Notation Rundown](#paragraph1)
    1. [Growth Rates](#subparagraph1)
3. [In Place and Stable Algorithms](#paragraph2)
4. [Sorting Algorithms](#paragraph3)
    1. [Selection Sort](#subparagraph4)
    2. [Insertion Sort](#subparagraph5)
    3. [Merge Sort](#subparagraph6)
    4. [Quick Sort](#subparagraph7)
5. [Trees](#paragraph4)
    1. [Tree Types](#subparagraph6)
    2. [Tree Traversals](#subparagraph7)
    3. [Tree Rotations](#subparagraph8)
6. [Lists](#paragraph5)
    1. [Singly - the lonely](#subparagraph9)
    2. [Doubly - the unorignal names](#subparagraph8)
7. [Stacks](#paragraph6)
8. [Queues](#paragraph7)


## Introduction <a name="introduction"></a>
These are my notes to help me revise for the upcoming midterm for 221. I hope you find these usefull. Also I am known for having awful spelling.

## Big O Notation Rundown <a name="paragraph1"></a>
Its a mathematical notation that decribes how a function can be limited when it tends towards infinity. More specifically, in computer science it is used to describe how the running time or space requirements of an algorithm increase with the growth of their input size. Big 'O' provides the upperbound of the growth rate of a function - 'Wost Case'. It can be expressed as f(n)=O(g(n)) where n is the size of the input. If there exists some constant c such that for all large enough n, f(n)≤ c*g(n), if the same holds for all c>0, then f(n)=O(g(n)).

While 'Ω' - Big Omega - describes the asymptotical lower bounds of the growth of a function since it bounds the growth of the running time form below for large enough imput sizes. A good example is the imprecise statement. If you have ten marbles then you can say that you 'Have atleast ten marbles'. While correct, it is not very precise. 

big-Θ - Big Theta - is used to decribe a function that has a 'tight' upper and lower bound. In a rather simplistic example its when O(n) = Ω(n). Let f(n) and g(n) be functions that map positive integers into psoitive real numbers. 

Figure 1.0: Taken from sacert. 
<p align="center">
  <img src="https://i.imgur.com/4kZ9Fe8.png">
</p>


### Growth Rates - screw large gradients <a name="subparagraph1"></a>
Figure 2.0: Taken from 'Big O cheatsheet' 
<p align="center">
  <img src="https://i.imgur.com/ZFG8gfG.png">
</p>

## Another paragraph <a name="paragraph2"></a>
The second paragraph text
