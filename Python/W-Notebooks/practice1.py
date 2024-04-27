def add(chinese, maths, english):
    "将成绩相加"
    m = chinese + maths + english
    return(m)

chinese = input("chinese: ")
c = float(chinese)
maths = input("maths: ")
m = float(maths)
english = input("english: ")
e = float(english)

adding = add(c, m, e)
z = adding/3
print("总分为:", adding, "\n")
print("三门平均分为: ", z)