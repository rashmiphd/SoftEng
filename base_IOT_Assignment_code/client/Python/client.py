#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway
import urllib2
import matplotlib.pyplot as plt

X,Y=[],[]

response = urllib2.urlopen('http://localhost:8080/')
resp = response.read()
resp.rstrip()
a=resp.split(',')
print "Temp-Time data"
print a
count=0
  
for x in a:
  #print count
  if count % 2==1:
    X.append(x)
  else:
    Y.append(x)
  count+=1
	
print "All the elements in our list X-Temperature data"
print X 
print "All the elements in our list Y-Time data"
print Y
print "Last element in Y is just a newline so lets pop it out"
Y.pop()
print Y

print "The Graph!!" 
plt.xlabel('Time')
plt.ylabel('Temperature')
plt.plot(X,Y)
plt.show()


