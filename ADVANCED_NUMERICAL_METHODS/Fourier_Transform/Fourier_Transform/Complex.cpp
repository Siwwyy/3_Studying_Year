#include "Complex.hpp"

Complex::Complex::Complex():
	Im(0.0f),
	Re(0.0f)
{

}

Complex::Complex::Complex(const float Im, const float Re):
	Im(Im),
	Re(Re)
{

}

Complex::Complex::Complex(const Complex& Object):
	Im(Object.Im),
	Re(Object.Re)
{

}

void Complex::Complex::Print() const
{
	_STD cout << "Im: " << this->Im << " Re: " << this->Re << '\n';
}

void Complex::Complex::Set_Im(const float Im)
{
	this->Im = Im;
}

void Complex::Complex::Set_Re(const float Re)
{
	this->Re = Re;
}

Complex::Complex& Complex::Complex::operator=(const Complex& Object)
{
	if (this != &Object)
	{
		this->Im = Object.Im;
		this->Re = Object.Re;
	}
	return *this;
}

float Complex::Complex::Get_Im() const
{
	return this->Im;
}

float Complex::Complex::Get_Re() const
{
	return this->Re;
}

Complex::Complex::~Complex()
{
	this->Im = 0.0f;
	this->Re = 0.0f;
}
