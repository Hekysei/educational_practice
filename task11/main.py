import cv2

image = cv2.imread("input.jpg")
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

green_mask = cv2.inRange(hsv_image, (36, 25, 25), (70, 255, 255))

contours, _ = cv2.findContours(green_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for contour in contours:
    for dot in contour:
        print(dot)
        cv2.circle(image, dot[0], 7, (0, 0, 255), -1)

cv2.imshow("res", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
