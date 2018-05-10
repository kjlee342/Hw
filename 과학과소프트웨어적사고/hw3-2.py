#1과 100사이의 모든 배수와 총 개수를 출력

def findMultiple(n):
    count = 0
    for i in range(1,100+1):
        if(i % n == 0) :
            print(n ,"x", i // n, "=",i)
            count += 1
    return count

flag = 0
yes = ['yes', 'Yes', 'y', 'Y', 'YES']
no = ['no', 'No', 'n', 'N', 'NO']
print("입력하시는 수의 1부터 100사이의 배수와 총 개수를 알려드립니다.")
while(flag == 0):
    while (True):
        num = int(input("양의 정수를 입력하세요. : "))
        if (num > 0):
            break
    print("배수의 총 개수:", findMultiple(num))
    while(True):
        again = input("계속 하시겠습니까? [yes, no] : ")
        if (again in no):
            flag = 1
            break
        elif(again in yes):
            break
