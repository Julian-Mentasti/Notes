from PIL import Image
import numpy as np
import math
from scipy import signal

"""
Returns an nxn array whose values add up to 1, given that n is odd.
else returns an AssertionError.
:param n: integer
:return: numpy array, or AssertionError
"""
def boxfilter(n):
    assert ((n%2) != 0), "Dimension must be odd"
    return np.full((n,n),(1/(n*n)))



"""
Returns a 1d gaussian array with length (6*sigma) rounded up to the next odd integer
"""
def gauss1d(sigma):
    assert (sigma>=0), "Sigma cannot be smaller or equal to zero."
    sigma = float(sigma)
    length = 6*sigma
    if (length%2)== 0:
        length = length + 1

    edges = int(length)/2
    arange = np.arange(-edges, edges+1)
    result = np.exp(-arange**2/(2*sigma**2))
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
    #red, green, blue = im.split()
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
    
    #image = Image.fromarray(rgbArray)
    return rgbArray

"""
Returns a highpass image array of the provided image
"""
def highPass(im):
    sigma = 6
    lowPassArray = lowPass(im, sigma)
    orignal = np.asarray(im)
    
    width = orignal.shape[0]
    height = orignal.shape[1]

    hf_array = (orignal - lowPassArray) # + np.full((width, height, 3), 128)
    hf_array[hf_array < 0] = 0
    result = hf_array.astype('uint8')
    return result

"""
Returns a highpass image array of the provided image
"""
def highPass_filter(im):
    sigma = 6
    lowPassArray = lowPass(im, sigma)
    orignal = np.asarray(im)
    
    width = orignal.shape[0]
    height = orignal.shape[1]

    hf_array = (orignal - lowPassArray)
    return hf_array

"""
Returns a hybrid image of the first image as a low pass and the second as highpass 
"""
def hybrid(im1, im2):

    im1_lp = lowPass(im1, 6)
    im2_hp = highPass(im2)

    final = im1_lp + im2_hp 

    return final

def doEverything():
    dog = Image.open("dog.jpg")
    cat = Image.open("cat.bmp")
    

    res = hybrid(dog, cat)
    res = res.clip(min=0)
    res = res.clip(max=255)
    result = ((res - res.min()) * (1/(res.max() - res.min()) * 255)).astype('uint8')
    image = Image.fromarray(res.astype('uint8'))
    return image

