import cv2 

carCascade = cv2.CascadeClassifier('cars.xml')
count=0

img = cv2.imread('m1.png')
height,width=img.shape[0:2]
gray = cv2.cvtColor(img , cv2.COLOR_BGR2GRAY)
box = carCascade.detectMultiScale(gray,8,1)
for (x ,y ,w ,h) in box:
  cv2.rectangle(img, (x,y),(x+w,y+h),(100,200,0), 4 )
  
  cv2.line(img,(0,height-775),(width,height-775),(0,225,225),2)
  cordcar=int(y+h/2)
  cordline=height-775
  if(cordcar>cordline):
      count=count+1
cv2.putText(img,'VEHICLES:'+ str(count),(50,70),1,2,(100,200,0),4)
time = int(int(count)*1.2+5)
cv2.putText(img,'TIME :'+str(time),(370,70),1,2,(100,200,0),4)
cv2.imshow('TRAFFIC SIGNAL',img)
cv2.waitKey(0)

