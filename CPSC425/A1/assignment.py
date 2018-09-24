from PIL import Image
import numpy as np
import math
from scipy import signal

"""
Returns an nxn array whose values add up to 1, given that n is odd.
else returns an AssertionError.
"""
def boxfilter(n):
    assert ((n%2) != 0), "Dimension must be odd"
    return np.full((n,n),(1/(n*n)))

"""
Returns a 1d gaussian array with length (6*sigma) rounded up to the next odd integer
"""
def gauss1d(sigma):
    assert (sigma>=0), "Sigma cannot be smaller or equal to zero."
    length = math.ceil(6*sigma)

    if (length%2)== 0:
        length = length + 1

    edges = math.floor(length/2)
    arange = np.arange(-edges, edges+1)
    result = np.exp(-arange**2/(2*sigma**2))
    result /= np.sum(result)
    return result

"""
Returns a 2d gaussian filter for a given value of sigma. 
"""
def gauss2d(sigma):
    oneDim = gauss1d(sigma)
    twoDim = oneDim[np.newaxis]
    twoDimT = twoDim.transpose()
    result = signal.convolve2d(twoDim, twoDimT)
    result /= np.sum(result)
    return result

"""
Applies a gaussian convolution to a 2d array and returns the result
"""
def gaussconvolve2d(array,sigma):
    filter = gauss2d(sigma)
    result = signal.convolve2d(array,filter,'same')
    return result


"""
Returns a lowpass image array of the provided image using the provided sigma
"""
def lowPass(im, sigma):
    array = np.asarray(im)
    blue = array[:,:,0]
    green = array[:,:,1]
    red =array[:,:,2]

    green = gaussconvolve2d(green,sigma) # Green
    blue = gaussconvolve2d(blue,sigma) # Blue
    red = gaussconvolve2d(red,sigma) # Red
  
    width = array.shape[0]
    height = array.shape[1]

    rgbArray = np.zeros((width, height,3), 'uint8')
    rgbArray[...,0] = blue
    rgbArray[...,1] = green
    rgbArray[...,2] = red
    result = np.clip(rgbArray,0,255)
    
    return rgbArray

"""
Returns a highpass image array of the provided image
"""
def highPass(im, sigma):
    lowPassArray = lowPass(im, sigma)

    array = np.asarray(im)
    blue = array[:,:,0]
    green = array[:,:,1]
    red =array[:,:,2]
  
    width = array.shape[0]
    height = array.shape[1]

    lpBlue = lowPassArray[:,:,0]
    lpGreen = lowPassArray[:,:,1]
    lpRed = lowPassArray[:,:,2]

    rgbArray = np.zeros((width, height,3), 'uint8')
    rgbArray[...,0] = blue - lpBlue
    rgbArray[...,1] = green - lpGreen
    rgbArray[...,2] = red - lpRed

    rgbNarray = np.zeros((width, height, 3), 'uint8')
    rgbNarray[...,0] = blue
    rgbNarray[...,1] = green
    rgbNarray[...,2] = red

    result = rgbArray.astype('uint8')
    result = np.clip(result,0,255)
    return result

"""
Returns a hybrid image of the first image as a low pass and the second as highpass 
usign a sigma of 6
"""
def hybrid(im1, im2):

    im1_lp = lowPass(im1, 6)
    im2_hp = highPass(im2, 6)

    final = im1_lp + im2_hp 

    return final


"""
Returns a hybrid image of the first image as a low pass and the second as highpass
using a custom sigma
"""
def custom_hybrid(im1, im2, sigma):

    im1_lp = lowPass(im1, sigma)
    im2_hp = highPass(im2, sigma)

    final = im1_lp + im2_hp 

    return final

"""
Returns a hybrid image composed of im1 as a lowPass and im2 as a highPass using sigma
"""
def makeHybrid(im1, im2, sigma):
    im1_ar = np.asarray(im1)
    im2_ar = np.asarray(im2)
    res = custom_hybrid(im1_ar, im2_ar, sigma)
    image = Image.fromarray(res.astype('uint8'))
    return image

"""
Returns a hybrid image of a cat and dog
"""
def catDog():
    dog = Image.open("dog.jpg")
    cat = Image.open("cat.bmp")
    

    res = hybrid(dog, cat)
    res = res.clip(min=0)
    res = res.clip(max=255)
    result = ((res - res.min()) * (1/(res.max() - res.min()) * 255)).astype('uint8')
    image = Image.fromarray(res.astype('uint8'))
    return image

