#파일을 통한 연락처 관리 프로그램.

import os.path

def sortNumAndLetter(string):
    numbers = ['1','2','3','4','5','6','7','8','9','0']
    num = ''
    for x in string:
        if(x in numbers):
            num += x
    return num

def printFriend():
    print("{0:<8}\t{1:<15}\t{2:15}".format("번호","이름","연락처"))
    for x in range(len(friends)):
        print("{0:<8}\t{1:<15}\t{2:15}".format(x+1, friends[x][0], friends[x][1]))

menu = 0
friends = []

if os.path.isfile("address.txt"):
    infile = open("address.txt", "r")
    for line in infile:
        wordList = line.split()
        temp = [wordList[0],wordList[1]]
        friends.append(temp)
    infile.close()

while True:
    print("--------------------")
    print("1. 연락처 보기")
    print("2. 연락처 추가")
    print("3. 연락처 삭제")
    print("4. 이름 변경")
    print("5. 연락처 변경")
    print("9. 종료")
    try:
        menu = int(input("메뉴를 선택하시오: "))
        if menu == 1:
            printFriend()
        elif menu == 2:
            temp = []
            name = input("이름을 입력하시오: ")
            temp.append(name)
            phoneNum = input("연락처를 입력하시오: ")
            temp.append(sortNumAndLetter(phoneNum))
            friends.append(temp)
        elif menu == 3:
            printFriend()
            index = int(input("삭제하고 싶은 번호를 입력하시오: "))
            if (index <= len(friends) and index > 0):
                friends.pop(index-1)
            else:
                print("번호가 잘 못 되었습니다.")
        elif menu == 4:
            printFriend()
            index = int(input("변경하고 싶은 이름의 번호를 입력하시오: "))
            if (index <= len(friends) and index > 0):
                newName = input("새로운 이름을 입력해 주세요: ")
                friends[index - 1][0] = newName
            else:
                print("번호가 잘 못 되었습니다.")
        elif menu == 5:
            printFriend()
            index = int(input("변경하고 싶은 연락처의 번호를 입력하시오: "))
            if (index <= len(friends) and index > 0):
                newPhone = input("새로운 번호를 입력해 주세요: ")
                friends[index - 1][1] = newPhone
            else:
                print("올바른 번호를 입력해주세요")
        elif menu == 9:
            outfile = open("address.txt", "w")
            for x in range(len(friends)):
               outfile.write(friends[x][0] + " " + friends[x][1] + '\n')
            outfile.close()
            break
    except ValueError:
        print("올바른 숫자를 입력해 주세요.")

