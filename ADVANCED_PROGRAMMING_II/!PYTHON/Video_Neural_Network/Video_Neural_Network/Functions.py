import cv2 as photo
import numpy as np
from matplotlib import pyplot as plt

def Write_Circle(image):
    image = photo.circle(image, (300, 400), 40, (255,255,0), 100)

#def Find_Pixels(Pixel_Array):

def Fourier_Transform():
    img = photo.imread('download.jpg',0)
    dft = photo.dft(np.float32(img),flags = photo.DFT_COMPLEX_OUTPUT)
    dft_shift = np.fft.fftshift(dft)
    magnitude_spectrum = 20*np.log(photo.magnitude(dft_shift[:,:,0],dft_shift[:,:,1]))
    plt.subplot(121),plt.imshow(img, cmap = 'gray')
    plt.title('Input Image'), plt.xticks([]), plt.yticks([])
    plt.subplot(122),plt.imshow(magnitude_spectrum, cmap = 'gray')
    plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
    plt.show()


def Make_Edge():
    img = photo.imread('download.png',0)
    edges = photo.Canny(img,300,300)
    plt.subplot(121),plt.imshow(img, cmap = None)
    plt.title('Eskalibur'), plt.xticks([]), plt.yticks([])
    plt.subplot(122),plt.imshow(edges,cmap = None)
    plt.title('Edged Eskalibur'), plt.xticks([]), plt.yticks([])
    plt.show()