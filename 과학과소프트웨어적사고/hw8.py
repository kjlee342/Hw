import os.path
import pickle

class BankAccount:
    accountNum = 0
    accountList = []
    def __init__(self, id, pwd):
        self.__id = id
        self.__pwd = pwd
        self.__balance = 0
        BankAccount.accountNum += 1
        self.__accountAddress = str(20123394) + str(BankAccount.accountNum)
        BankAccount.accountList.append(self)

    def withdraw(self, amount):
        try:
            if(self.__balance - amount < 0):
                raise ValueError
            self.__balance -= amount
            print()
            print("계좌에서 ", amount, "원이 출금 되었음.\n")

            return self.__balance
        except ValueError:
            print()
            print("잔고가 부족합니다.\n")
    
    def deposit(self, amount):
        self.__balance += amount
        print()
        print("계좌에 ", amount, "원이 입금 되었음.\n")
        return self.__balance

    def transfer(self, other, amount):
        try:
            if(self.__balance - amount < 0):
                raise ValueError
            self.__balance -= amount
            other.__balance += amount
            print()
            print(other.__id," 계좌에 ", amount, "원이 송금 되었음.\n")
            return self.__balance
        except ValueError:
            print()
            print("잔고가 부족합니다.\n")

    def login(self, pwd):
        if(self.__pwd == pwd):
            return True
        else:
            return False

    def getAccountNum(self):
        return self.__accountAddress

    def getId(self):
        return self.__id

    def getAccount(self):
        return self.__accountAddress

    def getBalance(self):
        return self.__balance

if os.path.isfile("account"):
    infile = open("account", "rb")
    BankAccount.accountList = pickle.load(infile)
    temp = 0
    for x in BankAccount.accountList:
        temp += 1
    BankAccount.accountNum = temp
    infile.close()

menu = 0
while True:
    print("--------------------")
    print("1. 로그인")
    print("2. 계좌 생성")
    print("9. 종료")
    try:
        menu = int(input("메뉴를 선택하시오. : "))
        if menu == 1:
            id = input("id를 입력하시오. : ")
            try:
                index = -1
                for  x in range(BankAccount.accountNum):
                    if (BankAccount.accountList[x].getId() == id) :
                        index = x
                if(index == -1):
                    raise NameError

                pwd = input("패스워드를 입력하시오. : ")
                if(not BankAccount.accountList[index].login(pwd)):
                    raise KeyError
                menu2 = 0
                while menu2 != 9:
                    print("--------------------")
                    print("1. 계좌 확인")
                    print("2. 입금")
                    print("3. 출금")
                    print("4. 송금")
                    print("9. 로그아웃")
                    try:
                        menu2 = int(input("메뉴를 선택하시오. : "))
                        if menu2 == 1:
                            print()
                            print('계좌 번호: ', BankAccount.accountList[index].getAccount(), '\n')
                            print("계좌 잔액: ",BankAccount.accountList[index].getBalance(), '\n')
                        elif menu2 == 2:
                            money = int(input("입금하려는 돈을 입력하시오. : "))
                            BankAccount.accountList[index].deposit(money)
                        elif menu2 == 3:
                            money = int(input("출금하려는 돈을 입력하시오. : "))
                            BankAccount.accountList[index].withdraw(money)
                        elif menu2 == 4:
                            account = input("송금하려는 계좌를 입력하시오. : ")

                            tempAccount = ""
                            for x in range(BankAccount.accountNum):
                                if(account == BankAccount.accountList[x].getAccount()):
                                    tempAccount = x
                            if(tempAccount == ""):
                                raise NameError

                            money = int(input('송금하려는 돈을 입력하시오. : '))
                            print()
                            print(BankAccount.accountList[tempAccount].getId(), "에게 ", money, "원\n\n1. 확인\t\t2. 취소\n")

                            while True:
                                try:
                                    if (int(input('번호를 입력하시오. : ')) == 2):
                                        raise KeyError
                                    break
                                except ValueError:
                                    print()
                                    print('올바른 숫자를 입력해 주세요.\n')
                                    
                            BankAccount.accountList[index].transfer(BankAccount.accountList[tempAccount], money)
                            
                    except ValueError:
                        print()
                        print("올바른 숫자를 입력해 주세요.\n")
                    except NameError:
                        print()
                        print('올바른 계좌를 입력해 주세요.\n')
                    except KeyError:
                        print()
                        print("취소 되었습니다.\n")

            except NameError:
                print()
                print('id가 존재하지 않습니다.\n')
            except KeyError:
                print()
                print('패스워드가 틀렸습니다.\n')

        elif menu == 2:
            id = input("id를 입력하시오. : ")
            try:
                for x in range(BankAccount.accountNum):
                    if (BankAccount.accountList[x].getId() == id):
                        raise NameError

                pwd = input("비밀번호를 입력하시오. : ")
                temp = BankAccount(id, pwd)
                print()
                print('계좌가 생성되었습니다.\n')
                print('계좌 번호: ', str(temp.getAccountNum()),'\n')
            except NameError:
                print()
                print("같은 id가 등록 되어 있습니다.\n")

        elif menu == 9:
            outfile = open("account", "wb")
            pickle.dump(BankAccount.accountList, outfile)
            outfile.close()
            break

    except ValueError:
        print()
        print("올바른 숫자를 입력해 주세요.\n")
