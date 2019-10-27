#include "Pixel.cuh"

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/*
	Pixel CLASS CASE
*/
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


__device__ Pixel::Pixel() :
	R(NULL),
	G(NULL),
	B(NULL),
	color_range(255)
{
	//Nothing here
}

__device__  Pixel::Pixel(const unsigned char R, const unsigned char G, const unsigned char B) :
	R(R),
	G(G),
	B(B),
	color_range(255)
{
	//Nothing here
}

__device__  Pixel::Pixel(const Pixel& Object) :
	R(Object.R),
	G(Object.G),
	B(Object.B),
	color_range(Object.color_range)
{
	//Nothing here
}

__device__ void Pixel::Show_Object() const
{
	//_STD cout << "Red: [" << static_cast<int>(this->R) << " ] " << "Green: [" << static_cast<int>(this->G) << " ] " << "Blue: [" << static_cast<int>(this->B) << " ] " << "Color range: " << this->color_range << NEW_LINE;
	printf("RED [%d] GREEN [%d] BLUE [%d]", static_cast<int>(this->R), static_cast<int>(this->G), static_cast<int>(this->B));
}

__device__ void Pixel::Set_R(const unsigned char R)
{
	this->R = R;
}

__device__ void Pixel::Set_G(const unsigned char G)
{
	this->G = G;
}

__device__ void Pixel::Set_B(const unsigned char B)
{
	this->B = B;
}

__device__  void Pixel::Set_Color_Range(const int Color_Range)
{
	this->color_range = Color_Range;
}

__device__ const unsigned char Pixel::Get_R() const
{
	return this->R;
}

__device__ const unsigned char Pixel::Get_G() const
{
	return this->G;
}

__device__ const unsigned char Pixel::Get_B() const
{
	return this->B;
}

__device__ const int Pixel::Get_Color_Range() const
{
	return this->color_range;
}

__device__ Pixel& Pixel::operator=(const Pixel& Object)
{
	//if (this != _STD addressof(Object))
	if (this != &Object)
	{
		this->R = Object.R;
		this->G = Object.G;
		this->B = Object.B;
		this->color_range = Object.color_range;
	}
	return *this;
}

__device__ Pixel::~Pixel()
{
	this->R = NULL;
	this->G = NULL;
	this->B = NULL;
	this->color_range = NULL;
}


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////