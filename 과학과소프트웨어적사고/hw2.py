#컴퓨터와 가위 바위 보 하나빼기
import random
head = "=" * 15 + "\t\t"
tail = "\t\t" + "=" * 15

def check(player, computer):
    flag = 0
    print(head, end= "")
    if (player == computer):
        print("비겼음!", tail)
        flag = 0
    elif (player == "바위"):
        if (computer == "보"):
            print("컴퓨터가 이겼음!", end= tail)
            flag = -1
        else:
            print("사용자가 이겼음!", end= tail)
            flag = 1
    elif (player == "보"):
        if (computer == "비위"):
            print("사용자가 이겼음!", end= tail)
            flag = 1
        else:
            print("컴퓨터가 이겼음!", end= tail)
            flag = -1
    elif (player == "가위"):
        if (computer == "바위"):
            print("컴퓨터가 이겼음!", end= tail)
            flag = -1
        else:
            print("사용자가 이겼음!", end= tail)
            flag = 1
    print('\n')
    return flag

win = 0
lose = 0
draw = 0
RPS = ["가위", "바위", "보"]

print("두 판을 먼저 이기는 측이 승리하게 됩니다.")
print("가위, 바위, 보가 아닌 입력을 하게 되면 반칙패 하게 됩니다.(공백 포함)")
print("하나를 뺄 때 정확히 입력하지 않으면 반칙패 하게 됩니다.\n")

while (win < 2 and lose < 2):
    print(head,"가위 바위 보!", tail)
    computer = RPS[:]
    temp = computer[random.randint(0, 2)]
    computer.remove(temp)
    player = [(input("가위, 바위, 보 중 하나를 입력하세요. : ")),
              (input("가위, 바위, 보 중 하나를 더 입력해 주세요. : "))]
    if ((RPS.count(player[0]) + RPS.count(player[1])) < 2):
        lose += 1
        print(head, "반칙패!", tail, "\n")
        continue
    print(head, "하나 빼기!", tail)
    print("컴퓨터: ", computer)
    computer.remove(computer[random.randint(0, 1)])
    temp = input("뺄 것을 입력하세요. {0}: " .format(player))
    if (player.count(temp) != 1):
        lose += 1
        print(head, "반칙패!", tail, "\n")
        continue
    player.remove(temp)
    print("사용자:", player)
    print("컴퓨터: ", computer)
    temp = check(player[0], computer[0])
    if(temp == 1) :
        win += 1
    elif(temp == 0):
        draw += 1
    else :
        lose += 1

print(head, win, "승", draw, "무", lose, "패", tail)
print(head, end="")
if(win == 2):
    print("사용자 승리!", tail)
else :
    print("컴퓨터 승리!", tail)





