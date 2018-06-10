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


### Growth Rates - be afraid of large gradients <a name="subparagraph1"></a>
Figure 2.0: Taken from 'Big O cheatsheet' 
<p align="center">
  <img src="https://i.imgur.com/ZFG8gfG.png">
</p>

## In place and Stable algorithms - when you just need to be extra picky. <a name="paragraph2"></a>
In place algorthms are algorithms (Duh) which maps an input using so auxiliary data sructures. This does not mean that you cannot use auxiliary variables. In other words the input is overwritten by the algorithm as it executes. It does not use extra space for manipulating the input. When an algorithm has to create new data structures is it called out of place. 

Stable algorithms, or more specifically stable sorts are those that maintain the relative order of records with equal values. So if you have a list of {1, 3(a), 7, 3(b), 9} when it is sorted by its numeric value it will output {1 ,3(a) ,3(b) ,7 ,9}. An unstable sort algorithm is when the order of identical elements is not guaranteed to stay in the same order they appeared in the input. i.e  {1 ,3(b) ,3(a) ,7 ,9}.

## Sorting algorithms - get your affairs in order. <a name="paragraph3"></a>
Sorting algorithms are those that puts elements of a list in order. 

### Selection Sort - simple <a name="subparagraph2"></a>
Selection sort is a very simple and somewhat inefficient sorting algorithm. It works by swapping the first unsorted item with the smallest item and adding it to its approrate sorted list. 

In terms of its time complexity its worst case senario is O(n^2) and its best case senario is Ω(n^2) thus its Θ(n^2). Its in place because it does not need to create any other data structures and it can be stable depending on how it is programmed. 

Figure 3.1: Taken from HackerEarth.
<p align="center">
  <img src="https://he-s3.s3.amazonaws.com/media/uploads/2888f5b.png">
</p>

### Insertion Sort - The first item is always sorted! <a name="subparagraph3"></a>
Insertion sort is a simple algorithm that is relatively efficient for small lists. It assumes the first item in the list is sorted then you add the next value and places it in its appropriate spot in the sorted selection by shifting values. 

Its an inplace algorithm and it may be stable depending on the implementation. Its worst case senario is O(n^2) but its best case senario is Ω(n).

Figure 3.2: Taken from Supriyo Ghosh
<p align="center">
  <img src="https://media.licdn.com/media/gcrc/dms/image/C5112AQHNYaMUMohXxA/article-cover_image-shrink_600_2000/0?e=2128291200&v=beta&t=jHdAZ7HJCPgmXkuRJ1EkDW37myYH2IWQOljVmiCTdNo">
</p>

### Merge Sort - Because a list with one item is always sorted. <a name="subparagraph4"></a>
Merge sort is an algorithm that divides the unsorted list into n sublists, each containing 1 element. Then repeatedly merge the sublists to produce new sorted sublists until there is only one list remaining; this will be sorted. 

Merge Sort is defenetly not an in place algorithm but it is stable. Its best case senario is Ω(n log(n)) and its worst case senario is O(n^2). 

Figure 3.3: Taken from ROSALIND.
<p align="center">
  <img src="https://i.imgur.com/9IC043f.png">
</p>

### QuickSort - if quick attack was a sorting algorithm. <a name="subparagraph5"></a>
Quicksort is a fast sorting algorithm that picks an element called a pivot usually from the begining or end of an array. Then it makes two new lists one for less or qual to the value of the pivot and the other for those values greater than the pivor. Once all the sublists have one item you join the items to make a sorted lists.

Quicksort is considered to be inplace, but it really depends on the implementation. The same applies to whether it is a stable sorting algorithm. Its best case senario is Ω(n log(n)) and its worst case senario is O(n^2).

Figure 3.4: Taken from NCZOnline.
<p align="center">
  <img src="https://www.nczonline.net/images/wp-content/uploads/2012/11/quicksort_partition1.png">
</p>
