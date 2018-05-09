#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;
class myRational
{	
public:
	myRational(long num = 0, long den = 1);
	myRational(const myRational &rat);

	long getNumerator() const;
	long getDenominator() const;

	myRational reciprocal() const;

	myRational operator +(myRational &rat);
	myRational operator -(myRational &rat);
	myRational operator *(myRational &rat);
	myRational operator /(myRational &rat);

	myRational& operator +=(myRational &rat);
	myRational& operator -=(myRational &rat);
	myRational& operator *=(myRational &rat);
	myRational& operator /=(myRational &rat);

	myRational operator+(long value);
	myRational operator-(long value);
	myRational operator*(long value);
	myRational operator/(long value);

	myRational& operator+=(long value);
	myRational& operator-=(long value);
	myRational& operator*=(long value);
	myRational& operator/=(long value);

	friend myRational operator+(long value, myRational &rat);
	friend myRational operator-(long value, myRational &rat);
	friend myRational operator*(long value, myRational &rat);
	friend myRational operator/(long value, myRational &rat);

	myRational& operator++();
	myRational& operator--();
	myRational& operator++(int);
	myRational& operator--(int);

	myRational operator-();

	bool operator<(myRational &rat);
	bool operator>(myRational &rat);
	bool operator<=(myRational &rat);
	bool operator>=(myRational &rat);
	bool operator==(myRational &rat);
	bool operator!=(myRational &rat);

	bool operator<(long value);
	bool operator>(long value);
	bool operator<=(long value);
	bool operator>=(long value);
	bool operator==(long value);
	bool operator!=(long value);

	friend ostream &operator <<(ostream &outStream, const myRational& r);
	friend istream &operator >>(istream &inStream, myRational& r);
private:
	// 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
	long _num; // numerator
	long _den; // denominator
	long gcd(long m, long n); // 최대공약수
	void reduce();
};


myRational::myRational(long num, long den) 
	:_num(num), _den(den)
{
	reduce();
}
myRational::myRational(const myRational &rat) {
	_den = rat._den;
	_num = rat._num;
	reduce();
}

long myRational::getNumerator() const {
	return _num;
}
long myRational::getDenominator() const {
	return _den;
}

myRational myRational::reciprocal() const {
	return myRational(_den, _num);
}

myRational myRational::operator +(myRational &rat) {
	myRational temp;
	temp._num = _num * rat._den + _den * rat._num;
	temp._den = _den * rat._den;
	temp.reduce();
	return temp;
}
myRational myRational::operator -(myRational &rat) {
	myRational temp;
	temp._num = _num * rat._den - _den * rat._num;
	temp._den = _den * rat._den;
	temp.reduce();
	return temp;
}
myRational myRational::operator *(myRational &rat) {
	myRational temp;
	temp._num = _num * rat._num;
	temp._den = _den * rat._den;
	temp.reduce();
	return temp;
}
myRational myRational::operator /(myRational &rat) {
	myRational temp;
	if (rat._num == 0) {
		temp._num = 0;
		temp._den = 1;
		return temp;
	}
	temp._num = _num * rat._den;
	temp._den = _den * rat._num;
	temp.reduce();
	return temp;
}

myRational& myRational::operator +=(myRational &rat) {
	_num = _num * rat._den + _den * rat._num;
	_den = _den * rat._den;
	reduce();
	return *this;
}
myRational& myRational::operator -=(myRational &rat) {
	_num = _num * rat._den - _den * rat._num;
	_den = _den * rat._den;
	reduce();
	return *this;
}
myRational& myRational::operator *=(myRational &rat) {
	_num = _num * rat._num;
	_den = _den * rat._den;
	reduce();
	return *this;
}
myRational& myRational::operator /=(myRational &rat) {
	if (rat._num == 0) {
		_num = 0;
		_den = 1;
		return *this;
	}
	_num = _num * rat._den;
	_den = _den * rat._num;
	reduce();
	return *this;
}

myRational myRational::operator+(long value) {
	myRational temp;
	temp._num = _num + _den * value;
	temp._den = _den;
	temp.reduce();
	return temp;
}
myRational myRational::operator-(long value) {
	myRational temp;
	temp._num = _num - _den * value;
	temp._den = _den;
	temp.reduce();
	return temp;
}
myRational myRational::operator*(long value) {
	myRational temp(_num * value, _den);
	temp.reduce();
	return temp;
}
myRational myRational::operator/(long value) {
	if (value == 0) {
		myRational temp(0, 1);
		return temp;
	}
	myRational temp(_num, _den * value);
	temp.reduce();
	return temp;
}

myRational& myRational::operator+=(long value) {
	_num = _num + _den * value;
	reduce();
	return *this;
}
myRational& myRational::operator-=(long value) {
	_num = _num - _den * value;
	reduce();
	return *this;
}
myRational& myRational::operator*=(long value) {
	_num = _num * value;
	reduce();
	return *this;
}
myRational& myRational::operator/=(long value) {
	if (value == 0) {
		_num = 0;
		_den = 1;
		return *this;
	}
	_den = _den * value;
	reduce();
	return *this;
}

myRational operator+(long value, myRational &rat) {
	myRational temp(value * rat._den + rat._num, rat._den);
	temp.reduce();
	return temp;
}
myRational operator-(long value, myRational &rat) {
	myRational temp(value * rat._den - rat._num, rat._den);
	temp.reduce();
	return temp;
}
myRational operator*(long value, myRational &rat) {
	myRational temp(value * rat._num, rat._den);
	temp.reduce();
	return temp;
}
myRational operator/(long value, myRational &rat) {
	
	if (value == 0) {
		myRational temp(0,1);
		return temp;
	}
	myRational temp(rat._den * value, rat._num);
	temp.reduce();
	return temp;
}

myRational& myRational::operator++() {
	_num = _num + _den * 1;
    this->reduce();
    return *this;
}
myRational& myRational::operator--() {
	_num = _num - _den * 1;
    this->reduce();
    return *this;
}
myRational& myRational::operator++(int) {
	static myRational temp = *this;
    _num = _num + _den * 1;
    long g = gcd(_num, _den);
    _num = _num / g;
    _den = _den / g;
    return temp;
}
myRational& myRational::operator--(int) {
	static myRational temp = *this;
    _num = _num - _den * 1;
    long g = gcd(_num, _den);
    _num = _num / g;
    _den = _den / g;
    return temp;
}

bool myRational::operator<(myRational &rat) {
	long num1 = _num * rat._den;
	long num2 = rat._num * _den;
	if (num1 < num2) {
		return true;
	}
	return false;
}
bool myRational::operator>(myRational &rat) {
	long num1 = _num * rat._den;
	long num2 = rat._num * _den;
	if (num1 > num2) {
		return true;
	}
	return false;
}
bool myRational::operator<=(myRational &rat) {
	long num1 = _num * rat._den;
	long num2 = rat._num * _den;
	if (num1 <= num2) {
		return true;
	}
	return false;
}
bool myRational::operator>=(myRational &rat) {
	long num1 = _num * rat._den;
	long num2 = rat._num * _den;
	if (num1 >= num2) {
		return true;
	}
	return false;
}
bool myRational::operator==(myRational &rat) {
	if (_num != rat._num) {
		return false;
	}
	if (_den != rat._den) {
		return false;
	}

	return true;
}
bool myRational::operator!=(myRational &rat) {
	return !(rat == *(this));
}

bool myRational::operator<(long value) {
	long num = value * _den;
	if (_num < num) {
		return true;
	}
	return false;
}
bool myRational::operator>(long value) {
	long num = value * _den;
	if (_num > num) {
		return true;
	}
	return false;
}
bool myRational::operator<=(long value) {
	long num = value * _den;
	if (_num <= num) {
		return true;
	}
	return false;
}
bool myRational::operator>=(long value) {
	long num = value * _den;
	if (_num >= num) {
		return true;
	}
	return false;
}
bool myRational::operator==(long value) {
	if (_num != (value * _den)) {
		return false;
	}
	return true;
}
bool myRational::operator!=(long value) {
	return !(*(this) == value);
}



myRational myRational::operator-() {
	return myRational(-_num, _den);
}

ostream &operator <<(ostream &outStream, const myRational& r)
{
	if (r._num == 0)
		outStream << 0;
	else if (r._den == 1)
		outStream << r._num;
	else
		outStream << r._num << "/" << r._den;
	return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
	inStream >> r._num >> r._den;
	if (r._den == 0)
	{
		r._num = 0;

		r._den = 1;
	}
	r.reduce();
	return inStream;
}
long myRational::gcd(long m, long n)
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}
void myRational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;
	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn * _num, _den);
	_num /= g;
	_den /= g;
}

static void testSimpleCase();
static void testDataFromFile();
int main()
{
	testSimpleCase();
	testDataFromFile();

	return 0;
}
void testSimpleCase()
{
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
	cout << frac1 << " " << frac2 << " " << frac3 << " "
		<< frac4 << " " << frac5 << endl;
	cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
	// Check arithmetic operators
	cout << frac1 * frac2 << " "
		<< frac1 + frac3 << " "
		<< frac2 - frac1 << " "
		<< frac3 / frac2 << endl;
	// Check comparison operators
	cout << ((frac1 < frac2) ? 1 : 0) << " "
		<< ((frac1 <= frac2) ? 1 : 0) << " "
		<< ((frac1 > frac2) ? 1 : 0) << " "
		<< ((frac1 >= frac2) ? 1 : 0) << " "
		<< ((frac1 == frac2) ? 1 : 0) << " "
		<< ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2 < frac3) ? 1 : 0) << " "
		<< ((frac2 <= frac3) ? 1 : 0) << " "
		<< ((frac2 > frac3) ? 1 : 0) << " "
		<< ((frac2 >= frac3) ? 1 : 0) << " "
		<< ((frac2 == frac3) ? 1 : 0) << " "
		<< ((frac2 != frac3) ? 1 : 0) << endl;
	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;
	cout << -frac6 << endl;
	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	cout << 2 * frac3 << " " << frac3 * 2 << " "
		<< 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if (inStream.fail()) {
		cerr << "Input Error.\n";
		exit(1);
	}

	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++) {
		int valueNum;
		inStream >> valueNum;
		myRational *r = new myRational[valueNum]();
		for (int j = 0; j < valueNum; j++) {
			inStream >> *(r+j);
		}

		myRational temp;
		for (int j = 0; j < valueNum; j++) {
			for (int k = 0; k < valueNum; k++) {
				if (r[j] < r[k]) {
					temp = r[j];
					r[j] = r[k];
					r[k] = temp;
				}
			}
		}
		for (int j = 0; j < valueNum; j++) {
			cout << *(r+j) << " ";
		}
		cout << endl;
		delete r;
	}
	inStream.close();
}