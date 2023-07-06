import cv2
import numpy as np

img = cv2.imread("D:\\srtp\\ForSRTP\\3.png")
# cv2.namedWindow('img_window')
cv2.namedWindow("Demo3", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Demo3", 400, 300)
cv2.imshow("Demo3", img)

# cv2.imshow('img_window', img)
print(img.shape)

height = img.shape[0]
print('height is:', height)

print(img[200:250, 200:250])

cv2.waitKey(0)