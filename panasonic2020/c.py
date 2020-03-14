import numpy
ary = input().split(" ");
a = float(ary[0])
b = float(ary[1])
c = float(ary[2])
if numpy.sqrt(a) + numpy.sqrt(b) < numpy.sqrt(c):
    print("Yes")
else:
    print("No")
