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
Creates a hybrid image of sImg1 and SImg2, using the provided sigma for the filter, and saves it in file_name
"""
"""
def createHybrid(sImg1, sImg2, file_name, sigma):
    im1 = Image.open(sImg1)
    im2 = Image.open(sImg2)
  """

"""
Returns a blured image array of the provided image using the provided sigma
"""
def blurImage(im, sigma):
    #red, green, blue = im.split()
    red, green, blue = np.split(im, 3, axis=2)
    red = gaussconvolve2d(red,sigma) # Red
    green = gaussconvolve2d(green,sigma) # Green
    blue = gaussconvolve2d(blue,sigma) # Blue

    #nim = Image.merge("RGB", [red, green, blue])
    nim = np.concatenate((red, green, blue), axis=2)

    return nim
    
