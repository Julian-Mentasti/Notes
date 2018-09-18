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
Returns an 
"""
def gauss1d(sigma):
    length = 6*sigma
    if (length%2)== 0:
        array_length = length + 1
    array = np.linspace(-(length/2),(length/2),array_length) *sigma

                        #      (- x^2 / (2*sigma**2))
    gauss_eq = lambda t: t**(-(t^2)/(2*sigma^2))
    #scale = lambda x: x * 3
    result = gauss_eq(array)
    return result
