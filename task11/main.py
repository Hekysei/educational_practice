import cv2

image = cv2.imread("input.jpg")
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

green_mask = cv2.inRange(hsv_image, (36, 25, 25), (70, 255, 255))

cv2.imshow("mask", green_mask)
cv2.waitKey(0)
cv2.destroyAllWindows()
