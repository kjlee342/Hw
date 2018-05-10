#과제 HW 3-1
#문자들과 숫자를 구별하여 추출

def sortNumAndLetter(string):
    numbers = ['1','2','3','4','5','6','7','8','9','0']
    num = ''
    letter = ''
    for x in string:
        if(x in numbers):
            num += x
        else:
            letter += x
    return num, letter

flag = 0
yes = ['yes', 'Yes', 'y', 'Y', 'YES']
no = ['no', 'No', 'n', 'N', 'NO']
print("한 줄에 입력된 숫자와 문자를 구분해 드립니다.")
while(flag == 0):
    raw = input("구별해야하는 숫자와 문자를 입력해 주세요. : ")
    num, letter = sortNumAndLetter(raw)
    print('구별된 숫자: ' + num + '\n' + '구별된 문자: ' + letter)
    while(True):
        again = input("계속 하시겠습니까? [yes, no] : ")
        if (again in no):
            flag = 1
            break
        elif (again in yes):
            break
