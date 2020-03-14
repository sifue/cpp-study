ary = input().split(" ");
a = int(ary[0])
b = int(ary[1])
c = int(ary[2])
left = (a * b * 4)
right = (c - b - a) * (c - b - a)
if left < right:
    print("Yes")
else:
    print("No")
