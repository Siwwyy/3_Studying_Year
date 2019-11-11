
import Functions

img = Functions.photo.imread("Lena.ppm")
#photo.imshow("download.png",img);
#photo.waitKey(0);
#lower =(0, 0, 0) # lower bound for each channel
#upper = (80, 80,80) # upper bound for each channel

## create the mask and use it to change the colors
#mask = photo.inRange(img, lower, upper)
#img[mask != 0] = [255,0,255]



cap = Functions.photo.VideoCapture('ball.mov')
 
# Check if camera opened successfully
if (cap.isOpened()== False): 
  print("Error opening video stream or file")
 
# Read until video is completed
while(cap.isOpened()):
  # Capture frame-by-frame
  ret, frame = cap.read()
  if ret == True:
 
    # Display the resulting frame
    Functions.photo.imshow('Frame',frame)
 
    # Press Q on keyboard to  exit
    if Functions.photo.waitKey(25) & 0xFF == ord('q'):
      break
 
  # Break the loop
  else: 
    break
 
# When everything done, release the video capture object
cap.release()
 
# Closes all the frames
Functions.photo.destroyAllWindows()
#Functions.Write_Circle(img)

## display it
#Functions.photo.imshow("My Fucking Photo", img)
#Functions.photo.waitKey(0)

#Functions.Fourier_Transform()
#Functions.Make_Edge()
