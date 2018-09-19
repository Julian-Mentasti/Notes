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
Returns a 1d gaussian array 
"""
def gauss1d(sigma):
    length = 6*sigma
    if (length%2)== 0:
        array_length = length + 1
    else:
        array_length = length
    array = np.linspace(-(length/2),(length/2),array_length) *sigma

    #gauss = lambda t: t**(-(t^2)/(2*signal^2))
    #scale = lambda x: (-(x**2)/(2*sigma**2))
    scale = np.exp( array^2 / (2*sigma^2))

    return scale

"""
def gauss2d(sigma):
    1d = gauss1d(sigma)
    two_dim = one_dim[np.newaxis]
    2d_trans = two_dim.transpose()
    result = signal.convolve2d(two_dim, 2d_trans)
    return result
    """

def gauss2d(sigma):
    oneDim = gauss1d(sigma)
    twoDim = oneDim[np.newaxis]
    twoDimT = twoDim.transpose()
    result = signal.convolve2d(twoDim, twoDimT)
    return result

def gauss(sigma=1):
    n = sigma * 6
    r = range(-int(n/2),int(n/2)+1)
    return [1 / (sigma * sqrt(2*pi)) * exp(-float(x)**2/(2*sigma**2)) for x in r]
