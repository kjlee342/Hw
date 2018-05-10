import os.path
import pickle
from tkinter import *

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
        if (self.__balance - amount < 0):
            raise KeyError
        self.__balance -= amount
        return self.__balance

    def deposit(self, amount):
        self.__balance += amount
        return self.__balance

    def transfer(self, other, amount):
        if (self.__balance - amount < 0):
            raise KeyError
        self.__balance -= amount
        other.__balance += amount
        return self.__balance

    def login(self, pwd):
        if (self.__pwd == pwd):
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

def startStage():
    global startFrame
    startFrame = Frame(window)
    startFrame.pack(side=LEFT,padx = 50)
    Label(startFrame, text='환영합니다.', font="Helvetica 15").pack()
    Button(startFrame, text="로그인", font="Helvetica 20", command=uiLogin, width=10).pack(pady = 10)
    Button(startFrame, text="계좌 생성", font="Helvetica 20", width=10, command=uiNewAccount).pack(pady=10)
    Button(startFrame, text="종료", font="Helvetica 20", width=10, command=window.destroy).pack(pady=10)

def loginStage():
    startFrame.destroy()
    loginFrame = Frame(window)
    loginFrame.pack(side=LEFT, padx=50)
    Label(loginFrame, text=BankAccount.accountList[index].getId() + '님 환영합니다.', font="Helvetica 15").pack()
    Button(loginFrame, text="계좌 확인", font="Helvetica 20", width=10, command=checkAccount).pack(pady=10)
    Button(loginFrame, text="입금", font="Helvetica 20", width=10, command=uiDeposit).pack(pady=10)
    Button(loginFrame, text="출금", font="Helvetica 20", width=10, command=uiWithdraw).pack(pady=10)
    Button(loginFrame, text="송금", font="Helvetica 20", width=10, command=uiTransfer).pack(pady=10)
    Button(loginFrame, text="로그아웃", font="Helvetica 20", width=10, command=lambda f=loginFrame:logout(f)).pack(pady=10)

def createSubFrame():
    global subFrame
    subFrame.destroy()
    subFrame = Frame(window)
    subFrame.pack(fill=BOTH, expand=True)
    subFrame.place(x=400, y=200)

def uiDeposit():
    createSubFrame()
    Label(subFrame, text='입금액').pack()
    e = Entry(subFrame)
    e.pack()
    Button(subFrame, text="확인", font="Helvetica 10", width=10, command=lambda e=e:deposit(e)).pack(pady=10)

def deposit(e):
    try:
        money = int(e.get())
        balance = BankAccount.accountList[index].deposit(money)
    except ValueError:
        window2 = Tk()
        Label(window2, text="임금액을 확인해주세요.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        createSubFrame()
        Label(subFrame, text="입금이 완료되었습니다.").pack(pady=10)
        Label(subFrame, text="계좌 잔액: " + str(balance)).pack(pady=10)
        Button(subFrame, text="확인", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)

def uiWithdraw():
    createSubFrame()
    Label(subFrame, text='출금액').pack()
    e = Entry(subFrame)
    e.pack()
    Button(subFrame, text="확인", font="Helvetica 10", width=10, command=lambda e=e: withdraw(e)).pack(pady=10)

def withdraw(e):
    try:
        money = int(e.get())
        balance = BankAccount.accountList[index].withdraw(money)
    except ValueError:
        window2 = Tk()
        Label(window2, text="출금액을 확인해주세요.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    except KeyError:
        window2 = Tk()
        Label(window2, text="잔액이 부족합니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        createSubFrame()
        Label(subFrame, text="출금이 완료되었습니다.").pack(pady=10)
        Label(subFrame, text="계좌 잔액: " + str(balance)).pack(pady=10)
        Button(subFrame, text="확인", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)

def uiTransfer():
    global transferAccount
    transferAccount = -1
    createSubFrame()
    Label(subFrame, text='송금 계좌').pack()
    address = Entry(subFrame)
    address.pack()
    b1 = Button(subFrame, text="계좌 확인", font="Helvetica 10", width=10)
    b1.configure(command=lambda a=address, b=b1: checkAddress(a, b))
    b1.pack(pady=10)
    Label(subFrame, text='송금액').pack()
    money = Entry(subFrame)
    money.pack()
    Button(subFrame, text="송금", font="Helvetica 10", width=10, command=lambda e=money:transfer(e)).pack(pady=10)
    Button(subFrame, text="취소", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)

def checkAddress(address, b):
    global transferAccount
    a = address.get()
    try:
        for x in range(BankAccount.accountNum):
            if (a == BankAccount.accountList[x].getAccount()):
                transferAccount = x
        if (transferAccount == -1):
            raise NameError
    except NameError:
        window2 = Tk()
        Label(window2, text="동일한 계좌번호가 존재하지 않습니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        b.configure(text="확인되었습니다.", width=15)

def transfer(e):
    try:
        money = int(e.get())
        if(transferAccount == -1):
            raise NameError
    except NameError:
        window2 = Tk()
        Label(window2, text="계좌 번호를 확인해주세요.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    except ValueError:
        window2 = Tk()
        Label(window2, text="송금액을 써주세요.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        createSubFrame()
        Label(subFrame,text=BankAccount.accountList[transferAccount].getId() + "에게 " + str(money) + "원").pack()
        Button(subFrame, text="확인", font="Helvetica 10", width=10, command=lambda m=money:checkTransfer(m)).pack(pady=10)
        Button(subFrame, text="취소", font="Helvetica 10", width=10,command=uiTransfer).pack(pady=10)

def checkTransfer(money):
    try:
        BankAccount.accountList[index].transfer(BankAccount.accountList[transferAccount], money)
        createSubFrame()
        Label(subFrame, text="송금이 완료되었습니다.").pack()
        Button(subFrame, text="확인", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)
    except KeyError:
        window2 = Tk()
        Label(window2, text="잔액이 부족합니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()


def logout(frame):
    global subFrame
    subFrame.destroy()
    frame.destroy()
    startStage()

def checkAccount():
    createSubFrame()
    Label(subFrame, text='계좌 번호: ' + BankAccount.accountList[index].getAccount()).pack(pady=10)
    Label(subFrame, text='계좌 잔액: ' + str(BankAccount.accountList[index].getBalance())).pack(pady=10)
    Button(subFrame, text="확인", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)
    subFrame.update()

def uiLogin():
    createSubFrame()
    Label(subFrame, text='id').pack()
    i = Entry(subFrame)
    i.pack()
    Label(subFrame, text='password').pack()
    p = Entry(subFrame)
    p.pack()
    Button(subFrame, text="확인", font="Helvetica 10", width=10, command=lambda i=i, p=p: login(i, p)).pack(pady=10)
    Button(subFrame, text="취소", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)

def login(i, p,):
    global index
    id = i.get()
    pwd = p.get()
    try:
        index = -1
        for x in range(BankAccount.accountNum):
            if (BankAccount.accountList[x].getId() == id):
                index = x
        if (index == -1):
            raise NameError
        if (not BankAccount.accountList[index].login(pwd)):
            raise KeyError
    except NameError:
        window2 = Tk()
        Label(window2, text="id가 존재하지 않습니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    except KeyError:
        window2 = Tk()
        Label(window2, text="password가 틀렸습니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        subFrame.destroy()
        loginStage()

def uiNewAccount():
    createSubFrame()
    Label(subFrame, text='id').pack()
    i = Entry(subFrame)
    i.pack()
    Label(subFrame, text='password').pack()
    p = Entry(subFrame)
    p.pack()
    Button(subFrame, text="생성", font="Helvetica 10", width=10,command = lambda i=i, p=p: newAccount(i, p)).pack(pady=10)
    Button(subFrame, text="취소", font="Helvetica 10", width=10,command = subFrame.destroy).pack(pady=10)

def newAccount(i, p):
    try:
        id = i.get()
        pwd = p.get()
        if(id == "" or pwd == ""):
            raise KeyError
        for x in range(BankAccount.accountNum):
            if (BankAccount.accountList[x].getId() == id):
                raise NameError
    except NameError:
        window2 = Tk()
        Label(window2, text="id가 중복 됐습니다.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    except KeyError:
        window2 = Tk()
        Label(window2, text="id와 password를 써주세요.").pack()
        Button(window2, text="확인", command=window2.destroy).pack()
    else:
        temp = BankAccount(id, pwd)
        createSubFrame()
        Label(subFrame, text="id가 생성되었습니다.").pack()
        Label(subFrame, text='id: ' + str(temp.getId())).pack(pady=10)
        Label(subFrame, text='계좌 번호: '+str(temp.getAccountNum())).pack(pady=10)
        Button(subFrame, text="확인", font="Helvetica 10", width=10, command=subFrame.destroy).pack(pady=10)

if os.path.isfile("account"):
    infile = open("account", "rb")
    BankAccount.accountList = pickle.load(infile)
    temp = 0
    for x in BankAccount.accountList:
        temp += 1
    BankAccount.accountNum = temp
    infile.close()

index = -1
transferAccount = -1

window = Tk()
window.title('ATM')
window.geometry("800x600")
startFrame = Frame()
subFrame = Frame()
startStage()
window.mainloop()

outfile = open("account", "wb")
pickle.dump(BankAccount.accountList, outfile)
outfile.close()


