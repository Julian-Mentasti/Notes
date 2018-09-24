# CPSC 425 Assignment 1
Julian Mentasti
e0q1b

## Question 1: boxfilter

``` python
>>> boxfilter(3)
array([[0.11111111, 0.11111111, 0.11111111],
       [0.11111111, 0.11111111, 0.11111111],
       [0.11111111, 0.11111111, 0.11111111]])
>>> boxfilter(4)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "/home/julian/Notes/CPSC425/A1/assignment.py", line 13, in boxfilter
    assert ((n%2) != 0), "Dimension must be odd"
AssertionError: Dimension must be odd
>>> boxfilter(5)
array([[0.04, 0.04, 0.04, 0.04, 0.04],
       [0.04, 0.04, 0.04, 0.04, 0.04],
       [0.04, 0.04, 0.04, 0.04, 0.04],
       [0.04, 0.04, 0.04, 0.04, 0.04],
       [0.04, 0.04, 0.04, 0.04, 0.04]])
```

## Question 2: gauss1d

``` python
>>> gauss1d(0.3)
array([0.00383626, 0.99232748, 0.00383626])
>>> gauss1d(0.5)
array([0.10650698, 0.78698604, 0.10650698])
>>> gauss1d(1)
array([0.00443305, 0.05400558, 0.24203623, 0.39905028, 0.24203623,
       0.05400558, 0.00443305])
>>> gauss1d(2)
array([0.0022182 , 0.00877313, 0.02702316, 0.06482519, 0.12110939,
       0.17621312, 0.19967563, 0.17621312, 0.12110939, 0.06482519,
       0.02702316, 0.00877313, 0.0022182 ])
```

## Question 3: gauss2d

``` python
>>> gauss2d(0.5)
array([[0.01134374, 0.08381951, 0.01134374],
       [0.08381951, 0.61934703, 0.08381951],
       [0.01134374, 0.08381951, 0.01134374]])
>>> gauss2d(1)
array([[1.96519161e-05, 2.39409349e-04, 1.07295826e-03, 1.76900911e-03,
        1.07295826e-03, 2.39409349e-04, 1.96519161e-05],
       [2.39409349e-04, 2.91660295e-03, 1.30713076e-02, 2.15509428e-02,
        1.30713076e-02, 2.91660295e-03, 2.39409349e-04],
       [1.07295826e-03, 1.30713076e-02, 5.85815363e-02, 9.65846250e-02,
        5.85815363e-02, 1.30713076e-02, 1.07295826e-03],
       [1.76900911e-03, 2.15509428e-02, 9.65846250e-02, 1.59241126e-01,
        9.65846250e-02, 2.15509428e-02, 1.76900911e-03],
       [1.07295826e-03, 1.30713076e-02, 5.85815363e-02, 9.65846250e-02,
        5.85815363e-02, 1.30713076e-02, 1.07295826e-03],
       [2.39409349e-04, 2.91660295e-03, 1.30713076e-02, 2.15509428e-02,
        1.30713076e-02, 2.91660295e-03, 2.39409349e-04],
       [1.96519161e-05, 2.39409349e-04, 1.07295826e-03, 1.76900911e-03,
        1.07295826e-03, 2.39409349e-04, 1.96519161e-05]])
```

## Question 4: gaussconveolve2d

## Part 2:
## Question 1: lowPass

Using a sigma of 6.

![alt text](https://i.imgur.com/jg9jVHB.png)

## Question 2: HighPass

Using a sigma of 6.

![alt text](https://i.imgur.com/2cayBuy.jpg)

## Question 3: Hybrid

![alt text](https://i.imgur.com/E8v63UU.jpg)

## Other hybrids 

## Using a sigma of 3:
![alt text](https://imgur.com/CWTbhtA.jpg)
![alt text](https://imgur.com/xGPhRHe.jpg)
![alt text](https://imgur.com/Ej7e1nJ.jpg)

### Using sigma of 6:
![alt text](https://imgur.com/QDEjfdm.jpg)
![alt text](https://imgur.com/4vmSfd2.jpg)
![alt text](https://i.imgur.com/E8v63UU.jpg)

## Using a sigma of 13:
![alt text](https://imgur.com/CWTbhtA.jpg)
![alt text](https://imgur.com/KXyoXgO.jpg)
![alt text](https://imgur.com/jUC0ghA.jpg)

## Just for fun

## Battle Ship:
![alt text](https://imgur.com/NWkl2HX.jpg)
## Eiffel Tower:
![alt text](https://imgur.com/5BIK67n.jpg)

## BattleShip as lowPass and Eiffel Tower as HighPass
### Sigma of 3
![alt text](https://imgur.com/GGaRTfM.jpg)
### Sigma of 6
![alt text](https://imgur.com/ExYWc5I.jpg)
### Sigma of 13
![alt text](https://imgur.com/wsLqtH9.jpg)

## Eiffel Tower as lowPass and BattleShip as HighPass
### Sigma of 3
![alt text](https://imgur.com/FfCm3kN.jpg)
### Sigma of 6
![alt text](https://imgur.com/9vcAsro.jpg)
### Sigma of 13
![alt text](https://imgur.com/Wcgrhwb.jpg)
