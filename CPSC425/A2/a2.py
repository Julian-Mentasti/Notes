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
def makePyramid(image, minsize):
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
    template = template.resize((iTemplate_width, template.size[1]/iShrink), Image.BICUBIC)

    for image in lPyramid:

        # apply the template
        iRes = ncc.normxcorr2D(image, template)

        # append the values within the treshold
        found.append(np.where(iRes >= threshold, 1, 0))

    # start to draw the template

    # Image converted to RGB
    image_c = lPyramid[0].convert("RGB")

    # get the dimensions of the template 
    (width, height) = template.size

    draw = ImageDraw.Draw(image_c)
    curr_im = 0
    for image in found:

        points = np.nonzero(image)

        width /= fShrinking_factor ** curr_im
        height /= fShrinking_factor ** curr_im

        for cord in range(len(found[0])):

            x = points[1][cord] / (0.75) ** curr_im
            y = points[0][cord] / (0.75) ** curr_im

            draw.rectangle([(x-width/2, y-height/2), (x+width/2, y+height/2)], outline="red")

        curr_im += 1

    del draw
    image_c.show()

def main():
    im = Image.open("faces/students.jpg")
    minsize = 20
    lPyramid = makePyramid(im, minsize)
    showPyramid(lPyramid)

    template = Image.open("faces/template.jpg")
    res = findTemplate(lPyramid, template,0.5)
    print(res)