from PIL import Image, ImageDraw
import numpy as np
import math
from scipy import signal
import ncc

fShrinking_factor = 0.75

"""
Returns a list of the original image, followed by its reductions untill they reach the min size
:Param image: PIL image
:minsize int: size int
"""
def MakePyramid(image, minsize):
    lPyramid = [image]
    iSize = image.size[0]

    while (minsize <= iSize):
        # Grab the smallest image so far
        imgTail = lPyramid[-1]

        # Get the height and width of the image
        (iHeight, iWidth) = imgTail.size

        # Resize the image by shrinking the image by fShrinking_factor
        imgSmallest = imgTail.resize((int(iHeight*fShrinking_factor),int(iWidth*fShrinking_factor)), Image.BICUBIC)
        
        # Append the shrunk image to the list
        lPyramid.append(imgSmallest)

        # Get the new smallest size
        iSize = int(imgSmallest.size[0])
    
    return lPyramid

"""
Returns a compilation of all the images in lPyramid
:param lPyramid: List of im images
"""
def showPyramid(lPyramid): 

    # get the total height
    iTotHeight = lPyramid[0].size[1]

    # get the total width
    iTotWidth  = sum([im.size[0] for im in lPyramid])
    
    # create blank canvas
    imgCanvas = Image.new("L", (iTotWidth, iTotHeight))

    iOffset_x = 0
    for image in lPyramid:
        # Paste the image with the correct offset
        imgCanvas.paste(image,(iOffset_x,(iTotHeight - image.size[1])))

        # Counter for the x offset
        iOffset_x = iOffset_x + image.size[0]
            
    imgCanvas.show()
    
"""
Returns the correlation between the Pyramid images and the template
:param lPyramid: list of images
:param template: image template
:param threshold: int value
"""
def findTemplate(lPyramid, template, threshold):

    # Hold the found values
    found = []

    # NCC set at 15
    iTemplate_width = 15

    # get the ammount that the image should be scaled down
    iShrink = template.size[0]/iTemplate_width

    #resize the template
    template = template.resize((int(iTemplate_width),int(template.size[1]/iShrink)), Image.BICUBIC)

    # original image width
    imgOriginal = lPyramid[0]
    iOriginalWdith = imgOriginal.size[0]
    for image in lPyramid:

        # apply the template
        iRes = ncc.normxcorr2D(image, template)
        
        # get the scale of the image
        imageWidth = image.size[0]
        imgScale = imageWidth/iOriginalWdith

        # for every row
        for y_cord in range(len(iRes)):
            # for every column
            for x_cord in range(len(iRes[0])):
                
                # if the pixel value is above our threshold
                if iRes[y_cord][x_cord] >= threshold:
                    
                    #Scale to resize the image
                    if (imgScale == 0):
                        continue
                    iScale = 1/imgScale

                    # Get the updated template size
                    (imgWidth, imgHeight) = template.size
                    
                    # calculate the area of the outline for each face
                    face = (x_cord*iScale, y_cord*iScale, imgWidth*iScale, imgHeight*iScale)

                    #facebook
                    found.append(face)


    # Image converted to RGB
    image_c = lPyramid[0].convert("RGB")

    # get the dimensions of the template 
    (width, height) = template.size

    for face in found: 
        drawOutline(image_c, *face)

    image_c.show()

"""
Draws a red outline on an image
:parm image: image object
:param x: bottom right x cord
:param y: bottom right y cord
:param width: width of the box
:param height: height of the box
"""
def drawOutline(image, x, y ,width, height):
    #Upper left corner
    x = x - width/2
    y = y - height/2

    #draw the line
    draw = ImageDraw.Draw(image)
    
    # draw the four lines
    # left vertical line+
    draw.line((x,y,x, y+height), fill="red", width=2)
    # right vertical line
    draw.line((x+width,y,x+width, y+height), fill="red", width=2)
    # top horizontal line
    draw.line((x,y,x+width,y), fill="red", width=2)
    # bottom horizontal line
    draw.line((x,y+height, x+width, y+height), fill="red", width=2)

    del draw

def main():
    im = Image.open("faces/students.jpg")
    minsize = 20
    lPyramid = MakePyramid(im, minsize)
    showPyramid(lPyramid)

    template = Image.open("faces/template.jpg")
    findTemplate(lPyramid, template,0.7)

#Will test out the 6 images
def questionFive(threshold):
    im1 = Image.open("faces/students.jpg")
    im2 = Image.open("faces/judybats.jpg")
    im3 = Image.open("faces/tree.jpg")
    im4 = Image.open("faces/family.jpg")
    im5 = Image.open("faces/fans.jpg")
    im6 = Image.open("faces/sports.jpg")

    template = Image.open("faces/template.jpg")
    minsize = 20
    #load the pyramids
    pyramid1 = MakePyramid(im1, minsize)
    pyramid2 = MakePyramid(im2, minsize)
    pyramid3 = MakePyramid(im3, minsize)
    pyramid4 = MakePyramid(im4, minsize)
    pyramid5 = MakePyramid(im5, minsize)
    pyramid6 = MakePyramid(im6, minsize)

    findTemplate(pyramid1, template,threshold)
    findTemplate(pyramid2, template,threshold)
    findTemplate(pyramid3, template,threshold)
    findTemplate(pyramid4, template,threshold)
    findTemplate(pyramid5, template,threshold)
    findTemplate(pyramid6, template,threshold)
