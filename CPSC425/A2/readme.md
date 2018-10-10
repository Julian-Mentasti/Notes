# Assignment 2
## Julian Mentasti
## 90772385 e0q1b

# Question 2:
```python
>>> from a2 import *
>>> im = Image.open("faces/students.jpg")
>>> minsize = 20
>>> pyramid = MakePyramid(im, minsize)
>>> pyramid
[<PIL.Image.Image image mode=L size=426x443 at 0x7F042AFCF9D0>, 
<PIL.Image.Image image mode=L size=319x332 at 0x7F042AFCFA10>, 
<PIL.Image.Image image mode=L size=239x249 at 0x7F042AFCFA50>, 
<PIL.Image.Image image mode=L size=179x186 at 0x7F042AFCFA90>, 
<PIL.Image.Image image mode=L size=134x140 at 0x7F042AFCFAD0>, 
<PIL.Image.Image image mode=L size=101x105 at 0x7F042AFCFB10>, 
<PIL.Image.Image image mode=L size=75x78 at 0x7F042AFCFB50>, 
<PIL.Image.Image image mode=L size=56x59 at 0x7F042AFCFB90>, 
<PIL.Image.Image image mode=L size=42x44 at 0x7F042AFCFBD0>, 
<PIL.Image.Image image mode=L size=31x33 at 0x7F042AFCFC10>, 
<PIL.Image.Image image mode=L size=23x24 at 0x7F042AFCFC50>]
```
# Question 3:
```python
>>> from a2 import *
>>> im = Image.open("faces/students.jpg")
>>> minsize = 20
>>> ShowPyramid(pyramid)
```
![students pyramid](https://i.imgur.com/HvAbNmj.jpg)

# Question 4:
```python
>>> im = Image.open("faces/students.jpg")
>>> minsize = 20
>>> lPyramid = MakePyramid(im, minsize)
>>> template = Image.open("faces/template.jpg")
>>> findTemplate(lPyramid, template,0.72)
```
![students face detection](https://i.imgur.com/ZW4dJec.jpg)
```python
>>>im1 = Image.open("faces/students.jpg")
>>>im2 = Image.open("faces/judybats.jpg")
>>>im3 = Image.open("faces/tree.jpg")
>>>im4 = Image.open("faces/family.jpg")
>>>im5 = Image.open("faces/fans.jpg")
>>>im6 = Image.open("faces/sports.jpg")
>>>template = Image.open("faces/template.jpg")
>>>minsize = 15
>>>#load the pyramids
>>>pyramid1 = MakePyramid(im1, minsize)
>>>pyramid2 = MakePyramid(im2, minsize)
>>>pyramid3 = MakePyramid(im3, minsize)
>>>pyramid4 = MakePyramid(im4, minsize)
>>>pyramid5 = MakePyramid(im5, minsize)
>>>pyramid6 = MakePyramid(im6, minsize)
>>>threshold = 0.585
>>>findTemplate(pyramid1, template,threshold)
>>># Student faces not seen as faces: 4
>>># Student faces seen as faces: 22
>>># Non Faces seen as Faces: 3
>>>findTemplate(pyramid2, template,threshold)
>>># Judybats faces not seen as faces: 1
>>># Judybats faces seen as faces: 4
>>># Non faces as seen as face: 0
>>>findTemplate(pyramid3, template,threshold)
>>># Faces not seen as faces: 0
>>># Faces seen as faces: 0
>>># Non faces seen as faces:2
>>>findTemplate(pyramid4, template,threshold)
>>># faces not seen as faces: 1
>>># faces seen as faces: 2
>>># non faces seen as faces: 0
>>>findTemplate(pyramid5, template,threshold)
>>># faces not seen as faces: 2
>>># faces seen as faces: 0
>>># non faces seen as faces: 0
>>>findTemplate(pyramid6, template,threshold)
>>># faces not seen as faces: 3
>>># faces seen as faces: 0
>>># non faces seen as faces: 4
```
Using a threshold of: 0.585

### Images:
![family](https://i.imgur.com/IuNQtyH.jpg)
![fans](https://i.imgur.com/goZI9HJ.jpg)
![judybats](https://i.imgur.com/90UgT12.jpg)
![sports](https://i.imgur.com/u6aRzcB.jpg)
![students](https://i.imgur.com/vhRbHvc.jpg)
![tree](https://i.imgur.com/WSWvq6P.jpg)

# Question 6:

NCC is a measure of similarity between two images, it computes a value depending
on how relatively similar the images are. So if we have a template of face A then
it will only really look for face A instead of looking for a face. Thus, it will
have a lower recall rate on some images since some of the faces differ from face A.

Recall = (# Relevant found)/(# Relevant)

Recall rate for family: 2/3

Recall rate for fans: 0/3

Recall rate for Judybats: 4/5

Recall rate for sports: 0/2

Recall rate for students: 23/27

Recall rate for tree: 0/0
