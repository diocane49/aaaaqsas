#include "includes.h"
#include "vector.h"

FVector FVec;
Color::Color()
{
	this->R = 0.0f;
	this->G = 0.0f;
	this->B = 0.0f;
	this->A = 0.0f;
}

Color::Color(int _R, int _G, int _B, int _A)
{
	this->R = (_R / 255.0f);
	this->G = (_G / 255.0f);
	this->B = (_B / 255.0f);
	this->A = (_A / 255.0f);
}

Color::Color(float _R, float _G, float _B)
{
	this->R = _R;
	this->G = _G;
	this->B = _B;
	this->A = 1.0f;
}

float Color::GetRed()
{
	return this->R;
}

float Color::GetGreen()
{
	return this->G;
}

float Color::GetBlue()
{
	return this->B;
}

float Color::GetAlpha()
{
	return this->A;
}

void Color::SetRed(float _R)
{
	this->R = _R;
}

void Color::SetGreen(float _G)
{
	this->G = _G;
}

void Color::SetBlue(float _B)
{
	this->B = _B;
}

void Color::SetAlpha(float _A)
{
	this->A = _A;
}

void Color::SetRed(int _R)
{
	this->R = (_R / 255.0f);
}

void Color::SetGreen(int _G)
{
	this->G = (_G / 255.0f);
}

void Color::SetBlue(int _B)
{
	this->B = (_B / 255.0f);
}

void Color::SetAlpha(int _A)
{
	this->A = (_A / 255.0f);
}
Color Color::FromHSB(float hue, float saturation, float brightness)
{
	float h = hue == 1.0f ? 0 : hue * 6.0f;
	float f = h - (int)h;
	float p = brightness * (1.0f - saturation);
	float q = brightness * (1.0f - saturation * f);
	float t = brightness * (1.0f - (saturation * (1.0f - f)));

	if (h < 1)
	{
		return Color(
			(unsigned char)(brightness * 255),
			(unsigned char)(t * 255),
			(unsigned char)(p * 255)
		);
	}
	else if (h < 2)
	{
		return Color(
			(unsigned char)(q * 255),
			(unsigned char)(brightness * 255),
			(unsigned char)(p * 255)
		);
	}
	else if (h < 3)
	{
		return Color(
			(unsigned char)(p * 255),
			(unsigned char)(brightness * 255),
			(unsigned char)(t * 255)
		);
	}
	else if (h < 4)
	{
		return Color(
			(unsigned char)(p * 255),
			(unsigned char)(q * 255),
			(unsigned char)(brightness * 255)
		);
	}
	else if (h < 5)
	{
		return Color(
			(unsigned char)(t * 255),
			(unsigned char)(p * 255),
			(unsigned char)(brightness * 255)
		);
	}
	else
	{
		return Color(
			(unsigned char)(brightness * 255),
			(unsigned char)(p * 255),
			(unsigned char)(q * 255)
		);
	}
}

FRotator::FRotator()
{
	this->Pitch = 0.0f;
	this->Yaw = 0.0f;
	this->Roll = 0.0f;
}

FRotator::FRotator(float _Pitch, float _Yaw, float _Roll)
{
	this->Pitch = _Pitch;
	this->Yaw = _Yaw;
	this->Roll = _Roll;
}

float FRotator::GetPitch()
{
	return this->Pitch;
}

float FRotator::GetYaw()
{
	return this->Yaw;
}

float FRotator::GetRoll()
{
	return this->Roll;
}
float FRotator::Size()
{
	return sqrt((this->Pitch * this->Pitch) + (this->Yaw * this->Yaw) + (this->Roll * this->Roll));
}
void FRotator::Normalize()
{
	while (this->Yaw > 180.0f)
		this->Yaw -= 360.0f;

	while (this->Yaw < -180.0f)
		this->Yaw += 360.0f;

	while (this->Pitch > 180.0f)
		this->Pitch -= 360.0f;

	while (this->Pitch < -180.0f)
		this->Pitch += 360.0f;
}

FRotator FRotator::operator+ (const FRotator& A)
{
	return FRotator(this->Pitch + A.Pitch, this->Yaw + A.Yaw, this->Roll + A.Roll);
}

FRotator FRotator::operator- (const FRotator& A)
{
	return FRotator(this->Pitch - A.Pitch, this->Yaw - A.Yaw, this->Roll - A.Roll);
}

float FRotator::Length()
{
	return (float)sqrt(pow(this->Pitch, 2) + pow(this->Yaw, 2) + pow(this->Roll, 2));
}

FVector FRotator::ToVector()
{
	float angle, sr, sp, sy, cr, cp, cy;

	angle = this->Yaw * (M_PI * 2 / 360);
	sy = sin(angle);
	cy = cos(angle);

	angle = this->Pitch * (M_PI * 2 / 360);
	sp = sin(angle);
	cp = cos(angle);

	angle = this->Roll * (M_PI * 2 / 360);
	sr = sin(angle);
	cr = cos(angle);

	return FVector(cp * cy, cp * sy, -sp);
}

void FRotator::GetVectors(FVector* Forward, FVector* Right, FVector* Up)
{
	static float sr, sp, sy, cr, cp, cy;
	float angle;

	angle = (float)this->Pitch * ((float)M_PI * 2 / 360);
	sp = sin(angle);
	cp = cos(angle);


	angle = (float)this->Yaw * ((float)M_PI * 2 / 360);
	sy = sin(angle);
	cy = cos(angle);

	angle = (float)this->Roll * ((float)M_PI * 2 / 360);
	sr = sin(angle);
	cr = cos(angle);

	if (Forward)
		*Forward = FVector(cp * cy, cp * sy, sp);

	if (Right)
		*Right = FVector(-1 * sr * sp * cy + -1 * cr * -sy, -1 * sr * sp * sy + -1 * cr * cy, -1 * sr * cp);

	if (Up)
		*Up = FVector(cr * sp * cy + -sr * -sy, cr * sp * sy + -sr * cy, cr * cp);
};

FVector::FVector()
{
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;
}

FVector::FVector(float _X, float _Y, float _Z)
{
	this->X = _X;
	this->Y = _Y;
	this->Z = _Z;
}

FVector FVector::operator+ (const FVector& A)
{
	return FVector(this->X + A.X, this->Y + A.Y, this->Z + A.Z);
}

FVector FVector::operator+ (const float A)
{
	return FVector(this->X + A, this->Y + A, this->Z + A);
}

FVector FVector::operator+= (const FVector& A)
{
	this->X += A.X;
	this->Y += A.Y;
	this->Z += A.Z;
	return *this;
}

FVector FVector::operator+= (const float A)
{
	this->X += A;
	this->Y += A;
	this->Z += A;
	return *this;
}

FVector FVector::operator- (const FVector& A)
{
	return FVector(this->X - A.X, this->Y - A.Y, this->Z - A.Z);
}

FVector FVector::operator- (const float A)
{
	return FVector(this->X - A, this->Y - A, this->Z - A);
}

FVector FVector::operator-= (const FVector& A)
{
	this->X -= A.X;
	this->Y -= A.Y;
	this->Z -= A.Z;
	return *this;
}

FVector FVector::operator-= (const float A)
{
	this->X -= A;
	this->Y -= A;
	this->Z -= A;
	return *this;
}

FVector FVector::operator* (const FVector& A)
{
	return FVector(this->X * A.X, this->Y * A.Y, this->Z * A.Z);
}

FVector FVector::operator* (const float A)
{
	return FVector(this->X * A, this->Y * A, this->Z * A);
}

FVector FVector::operator*= (const FVector& A)
{
	this->X *= A.X;
	this->Y *= A.Y;
	this->Z *= A.Z;
	return *this;
}

FVector FVector::operator*= (const float A)
{
	this->X *= A;
	this->Y *= A;
	this->Z *= A;
	return *this;
}

FVector FVector::operator/ (const FVector& A)
{
	return FVector(this->X / A.X, this->Y / A.Y, this->Z / A.Z);
}

FVector FVector::operator/ (const float A)
{
	return FVector(this->X / A, this->Y / A, this->Z / A);
}

FVector FVector::operator/= (const FVector& A)
{
	this->X /= A.X;
	this->Y /= A.Y;
	this->Z /= A.Z;
	return *this;
}

FVector FVector::operator/= (const float A)
{
	this->X /= A;
	this->Y /= A;
	this->Z /= A;
	return *this;
}

bool FVector::operator== (const FVector& A)
{
	if (this->X == A.X
		&& this->Y == A.Y
		&& this->Z == A.Z)
		return true;

	return false;
}

bool FVector::operator!= (const FVector& A)
{
	if (this->X != A.X
		|| this->Y != A.Y
		|| this->Z != A.Z)
		return true;

	return false;
}

float FVector::GetX()
{
	return this->X;
}

float FVector::GetY()
{
	return this->Y;
}

float FVector::GetZ()
{
	return this->Z;
}

float FVector::Size()
{
	return sqrt((this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z));
}

FRotator FRotator::operator/ (float a)
{
	return FRotator(this->Pitch / a, this->Yaw / a, this->Roll / a);
}

FRotator FRotator::operator/= (float a)
{
	this->Pitch /= a;
	this->Yaw /= a;
	this->Roll /= a;
	return *this;
}

FRotator FRotator::operator* (float a)
{
	return FRotator(this->Pitch * a, this->Yaw * a, this->Roll * a);
}

FVector FVector::GetDirectionUnitVector(FVector To)
{
	return (To - *this).GetSafeNormal();
}

float InvSqrt(float a)
{
	return 1.0f / sqrt(a);
}

FVector FVector::GetSafeNormal()
{
	const float SquareSum = pow(X, 2) + pow(Y, 2) + pow(Z, 2);

	if (SquareSum == 1.f)
		return *this;

	const float Scale = InvSqrt(SquareSum);

	return FVector(X * Scale, Y * Scale, Z * Scale);
}

FRotator FVector::ToRotator()
{
	float Yaw;
	float Pitch;
	float Forward;

	if (this->X == 0.0f
		&& this->Y == 0.0f)
	{
		Yaw = 0.0f;

		if (this->Z > 0.0f)
			Pitch = 90.0f;

		else
			Pitch = 270.0f;
	}
	else
	{
		if (this->X)
			Yaw = (atan2(this->Y, this->X) * (180.0f / M_PI));

		else if (this->Y > 0)
			Yaw = 90.0f;

		else
			Yaw = 270.0f;

		if (Yaw < 0.0f)
			Yaw += 360.0f;

		Forward = sqrt((this->X * this->X) + (this->Y * this->Y));
		Pitch = (atan2(this->Z, Forward) * (180.0f / M_PI));

		if (Pitch < 0.0f)
			Pitch += 360.0f;
	}

	return FRotator(-Pitch, Yaw, 0);
}

bool FVector::IsValid()
{
	return *this != FVector(0, 0, 0);
}

FVector2D::FVector2D()
{
	this->X = 0.0f;
	this->Y = 0.0f;
}

FVector2D::FVector2D(float _X, float _Y)
{
	this->X = _X;
	this->Y = _Y;
}
FVector2D FVector2D::operator+ (const FVector2D& A)
{
	return FVector2D(this->X + A.X, this->Y + A.Y);
}

FVector2D FVector2D::operator+ (const float A)
{
	return FVector2D(this->X + A, this->Y + A);
}

FVector2D FVector2D::operator+= (const FVector2D& A)
{
	this->X += A.X;
	this->Y += A.Y;
	return *this;
}

FVector2D FVector2D::operator+= (const float A)
{
	this->X += A;
	this->Y += A;
	return *this;
}

FVector2D FVector2D::operator- (const FVector2D& A)
{
	return FVector2D(this->X - A.X, this->Y - A.Y);
}

FVector2D FVector2D::operator- (const float A)
{
	return FVector2D(this->X - A, this->Y - A);
}

FVector2D FVector2D::operator-= (const FVector2D& A)
{
	this->X -= A.X;
	this->Y -= A.Y;
	return *this;
}

FVector2D FVector2D::operator-= (const float A)
{
	this->X -= A;
	this->Y -= A;
	return *this;
}

FVector2D FVector2D::operator* (const FVector2D& A)
{
	return FVector2D(this->X * A.X, this->Y * A.Y);
}

FVector2D FVector2D::operator* (const float A)
{
	return FVector2D(this->X * A, this->Y * A);
}

FVector2D FVector2D::operator*= (const FVector2D& A)
{
	this->X *= A.X;
	this->Y *= A.Y;
	return *this;
}

FVector2D FVector2D::operator*= (const float A)
{
	this->X *= A;
	this->Y *= A;
	return *this;
}

FVector2D FVector2D::operator/ (const FVector2D& A)
{
	return FVector2D(this->X / A.X, this->Y / A.Y);
}

FVector2D FVector2D::operator/ (const float A)
{
	return FVector2D(this->X / A, this->Y / A);
}

FVector2D FVector2D::operator/= (const FVector2D& A)
{
	this->X /= A.X;
	this->Y /= A.Y;
	return *this;
}

FVector2D FVector2D::operator/= (const float A)
{
	this->X /= A;
	this->Y /= A;
	return *this;
}

bool FVector2D::operator== (const FVector2D& A)
{
	if (this->X == A.X
		&& this->Y == A.Y)
		return true;

	return false;
}

bool FVector2D::operator!= (const FVector2D& A)
{
	if (this->X != A.X
		|| this->Y != A.Y)
		return true;

	return false;
}
float FVector2D::Distance(FVector2D v)
{
	return float(sqrtf(powf(v.X - X, 2.0) + powf(v.Y - Y, 2.0)));
}
float FVector2D::GetX()
{
	return this->X;
}

float FVector2D::GetY()
{
	return this->Y;
}

float FVector2D::Size()
{
	return sqrt((this->X * this->X) + (this->Y * this->Y));
}
bool FVector2D::IsValid()
{
	return *this != FVector2D(0, 0);
}

//float CMath::GetDistance( centity_t *pEntity, FVector Location )
//{
//	return ( ( pEntity->lerpOrigin - Location ).Size( ) / 36 );
//}

/*
-=-=-=-=-=-=-=-=
3D to 2D Convert
-=-=-=-=-=-=-=-=
*/
float FVector::Dot(FVector pStart, FVector pEnd)
{
	return (pStart.X * pEnd.X) + (pStart.Y * pEnd.Y) + (pStart.Z * pEnd.Z);
}
float FVector::Distance(FVector v)
{
	return float(sqrtf(powf(v.X - X, 2.0) + powf(v.Y - Y, 2.0) + powf(v.Z - Z, 2.0)));
}
bool FVector::InAngle(FVector pStart, FVector pEnd, FVector pRotation, int nAngle)
{
	return (Dot((pStart - pEnd) / (pStart - pEnd).Size(), pRotation) > cos(nAngle * M_PI / 360));
}

int FVector::round(float fValue)
{
	return int(fValue + 0.5f);
}

/*
-=-=-=-=-=-=-=-=
Vector to Origin
-=-=-=-=-=-=-=-=
*/
FVector2D FVector::GetAngleToOrigin(FRotator ViewAngles, FVector vec_Start, FVector vec_End)
{
	FRotator rot_Angle = (vec_End - vec_Start).ToRotator();

	if (rot_Angle.Yaw > 180.0f) { rot_Angle.Yaw -= 360.0f; }
	else if (rot_Angle.Yaw < -180.0f) { rot_Angle.Yaw += 360.0f; }

	if (rot_Angle.Pitch > 180.0f) { rot_Angle.Pitch -= 360.0f; }
	else if (rot_Angle.Pitch < -180.0f) { rot_Angle.Pitch += 360.0f; }

	rot_Angle.Yaw -= ViewAngles.Yaw;
	rot_Angle.Pitch -= ViewAngles.Pitch;

	if (rot_Angle.Yaw > 180.0f) { rot_Angle.Yaw -= 360.0f; }
	else if (rot_Angle.Yaw < -180.0f) { rot_Angle.Yaw += 360.0f; }

	if (rot_Angle.Pitch > 180.0f) { rot_Angle.Pitch -= 360.0f; }
	else if (rot_Angle.Pitch < -180.0f) { rot_Angle.Pitch += 360.0f; }

	return FVector2D(rot_Angle.Yaw, rot_Angle.Pitch);
}

