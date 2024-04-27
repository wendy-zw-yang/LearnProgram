""" python设计第一个小游戏 """

temp = input("guess a number: ")
guess = int(temp)

if guess == 8:
    print("correct!!")
    print("but there's no bonus!")
else:
    print("wrong, I want 8")

print("game over")