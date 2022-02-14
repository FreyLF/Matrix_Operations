#include "MathL.h"
#include <math.h>

#define PI 3.14159f

using namespace MathL;

// ------------ Vectors ------------ 

#pragma region Vector3

// ------------ Constructors ------------ 

MathL::Vec3::Vec3()
{
	x = 1; y = 1; z = 1;
}

MathL::Vec3::Vec3(float _value)
{
	x = _value; y = _value; z = _value;
}

MathL::Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

MathL::Vec3::Vec3(const Vec3& _copy)
{
	x = _copy.x; y = _copy.y; z = _copy.z;
}

// ------------ Operators ------------ 

Vec3 MathL::Vec3::operator+(const Vec3& vector)
{
	Vec3 temp;
	temp.x = x + vector.x;
	temp.y = y + vector.y;
	temp.z = z + vector.z;
	return temp;
}

Vec3 MathL::Vec3::operator-(const Vec3& vector)
{
	Vec3 temp;
	temp.x = x - vector.x;
	temp.y = y - vector.y;
	temp.z = z - vector.z;
	return temp;
}

Vec3 MathL::Vec3::operator=(const Vec3& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

//------------  Methods ------------ 

float MathL::Vec3::DotProduct(const Vec3& vector)
{
	return (x * vector.x) + (y * vector.y) + (z * vector.z);
}

float MathL::Vec3::Length()
{
	// This is the norm...
	return static_cast<float>(sqrt((static_cast<double>(x) * x) + (static_cast<double>(y) * y) + (static_cast<double>(z) * z)));
}

Vec3 MathL::Vec3::CrossProduct(const Vec3& vector)
{
	float i = y * vector.z - vector.y * z;
	float j = (-1) * (x * vector.z - vector.x * z);
	float k = x * vector.y - vector.x * y;
	return Vec3(i, j, k);
}

Vec3 MathL::Vec3::Scale(float scalar)
{
	return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 MathL::Vec3::Reflection(Vec3 v_surface)
{
	// reflection = direction − 2 (direction ⋅ normalized) normalized
	Vec3 reflect;
	Vec3 normalized = v_surface.Normalize();
	Vec3 direction = *this;
	float dot = 2 * direction.DotProduct(normalized);
	reflect = direction - normalized.Scale(dot);

	return reflect;
}

Vec3 MathL::Vec3::Normalize()
{
	return Vec3(x / Vec3::Length(), y / Vec3::Length(), z / Vec3::Length());
}

Vec4 MathL::Vec3::ConvertToVec4()
{
	return Vec4(x, y, x, 1);
}

#pragma endregion

#pragma region Vector4

// ------------ Constructors ------------ 

MathL::Vec4::Vec4()
{
	x = 1; y = 1; z = 1; w = 1;
}

MathL::Vec4::Vec4(float _value)
{
	x = _value; y = _value; z = _value; w = _value;
}

MathL::Vec4::Vec4(float _x, float _y, float _z, float _w)
{
	x = _x; y = _y; z = _z; w = _w;
}

MathL::Vec4::Vec4(const Vec4& _copy)
{
	x = _copy.x; y = _copy.y; z = _copy.z; w = _copy.w;
}

// ------------ Operators ------------ 

Vec4 MathL::Vec4::operator+(const Vec4& vector)
{
	Vec4 temp;
	temp.x = x + vector.x;
	temp.y = y + vector.y;
	temp.z = z + vector.z;
	temp.w = w + vector.w;
	return temp;
}

Vec4 MathL::Vec4::operator-(const Vec4& vector)
{
	Vec4 temp;
	temp.x = x - vector.x;
	temp.y = y - vector.y;
	temp.z = z - vector.z;
	temp.w = w - vector.w;
	return temp;
}

Vec4 MathL::Vec4::operator=(const Vec4& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
	return *this;
}

Vec4 MathL::Vec4::operator*(const Mat4& mat)
{
	Vec4 vec;
	vec.x = x * mat.v00 + y * mat.v10 + z * mat.v20 + w * mat.v30;
	vec.y = x * mat.v01 + y * mat.v11 + z * mat.v21 + w * mat.v31;
	vec.z = x * mat.v02 + y * mat.v12 + z * mat.v22 + w * mat.v32;
	vec.w = x * mat.v03 + y * mat.v13 + z * mat.v23 + w * mat.v33;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;

	return *this;
}

// ------------ Methods ------------ 

float MathL::Vec4::DotProduct(const Vec4& vector)
{
	return (x * vector.x) + (y * vector.y) + (z * vector.z) + (w * vector.w);
}

float MathL::Vec4::Length()
{
	// This is the norm...
	return static_cast<float>(sqrt((static_cast<double>(x) * x) + (static_cast<double>(y) * y) + (static_cast<double>(z) * z) + (static_cast<double>(w) * w)));
}

Vec4 MathL::Vec4::ScaleMultiplication(float scalar)
{
	return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vec4 MathL::Vec4::Normalize()
{
	return Vec4(x / Vec4::Length(), y / Vec4::Length(), z / Vec4::Length(), w / Vec4::Length());
}

Vec3 MathL::Vec4::ConvertToVec3()
{
	return Vec3(x, y, z);
}

#pragma endregion

// ------------ Matrices ------------ 

#pragma region Matrix3
// ------------ Constructors ------------ 
void MathL::Mat3::Fill(float _value)
{
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] = _value;
		}
	}
}

MathL::Mat3::Mat3()
{
	Fill(1);
}

MathL::Mat3::Mat3(const Mat3& _mat)
{
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] = _mat.values[row][col];
		}
	}
}

MathL::Mat3::Mat3(std::vector<float>& _vec)
{
	unsigned int count = 0;
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] = _vec[count];
			++count;
		}
	}
}

// ------------ Operators ------------ 
Mat3 MathL::Mat3::operator+(const Mat3& _mat)
{
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] += _mat.values[row][col];
		}
	}
	return *this;
}

Mat3 MathL::Mat3::operator-(const Mat3& _mat)
{
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] -= _mat.values[row][col];
		}
	}
	return *this;
}

Vec3 MathL::Mat3::operator*(const Vec3& _vec)
{
	Vec3 temp;
	temp.x = _vec.x * this->values[0][0] + _vec.y * this->values[1][0] + _vec.z * this->values[2][0];
	temp.y = _vec.x * this->values[0][1] + _vec.y * this->values[1][1] + _vec.z * this->values[2][1];
	temp.z = _vec.x * this->values[0][2] + _vec.y * this->values[1][2] + _vec.z * this->values[2][2];
	return temp;
}

Mat3 MathL::Mat3::operator*(const Mat3& _mat)
{
	Mat3 temp;
	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int j = 0; j < 3; ++j)
		{
			float value = 0;
			for (unsigned int k = 0; k < 3; ++k)
			{
				value += this->values[i][k] * _mat.values[k][j];
			}
			temp.values[i][j] = value;
		}
	}
	return temp;
}

Mat3 MathL::Mat3::operator*(float scale)
{
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			values[row][col] *= scale;
		}
	}
	return *this;
}

// ------------ Methods ------------ 
Mat3 MathL::Mat3::Identity()
{
	Mat3 temp;
	temp.Zero();
	temp.values[0][0] = 1;
	temp.values[1][1] = 1;
	temp.values[2][2] = 1;
	return temp;
}

Mat3 MathL::Mat3::Zero()
{
	this->Fill(0);
	return *this;
}

Mat3 MathL::Mat3::Transpose()
{
	Mat3 transpose;
	for (unsigned int row = 0; row < 3; ++row)
	{
		for (unsigned int col = 0; col < 3; ++col)
		{
			transpose.values[row][col] *= this->values[col][row];
		}
	}
	return transpose;
}

float MathL::Mat3::Determinant()
{
	// i|ad - cb| - j|...| + k|...|
	return (values[0][0] * (values[1][1] * values[2][2] - values[2][1] * values[1][2])
			- values[0][1] * (values[1][0] * values[2][2] - values[2][0] * values[1][2])
			+ values[0][2] * (values[1][0] * values[2][1] - values[2][0] * values[1][1]));
}

#pragma endregion

#pragma region Matrix4
void MathL::Mat4::Fill(float _value)
{
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] = _value;
		}
	}
}

// ------------ Constructors ------------ 
MathL::Mat4::Mat4()
{
	this->Fill(1);
}

MathL::Mat4::Mat4(const Mat4& _mat)
{
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] = _mat.values[row][col];
		}
	}
}

MathL::Mat4::Mat4(std::vector<float>& _vec)
{
	unsigned int count = 0;
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] = _vec[count];
			++count;
		}
	}
}

// ------------ Operators ------------ 
Mat4 MathL::Mat4::operator+(const Mat4& _mat)
{
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] += _mat.values[row][col];
		}
	}
	return *this;
}

Mat4 MathL::Mat4::operator-(const Mat4& _mat)
{
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] -= _mat.values[row][col];
		}
	}
	return *this;
}

Mat4 MathL::Mat4::operator*(float _scale)
{
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			values[row][col] *= _scale;
		}
	}
	return *this;
}

Vec4 MathL::Mat4::operator*(const Vec3& _vec)
{
	Vec4 temp;
	temp.x = _vec.x * this->values[0][0] + _vec.y * this->values[1][0] + _vec.z * this->values[2][0];
	temp.y = _vec.x * this->values[0][1] + _vec.y * this->values[1][1] + _vec.z * this->values[2][1];
	temp.z = _vec.x * this->values[0][2] + _vec.y * this->values[1][2] + _vec.z * this->values[2][2];
	temp.w = 1;
	return temp;
}

Vec4 MathL::Mat4::operator*(const Vec4& _vec)
{
	Vec4 temp;
	temp.x = _vec.x * this->values[0][0] + _vec.y * this->values[1][0] + _vec.z * this->values[2][0] + _vec.w * this->values[3][0];
	temp.y = _vec.x * this->values[0][1] + _vec.y * this->values[1][1] + _vec.z * this->values[2][1] + _vec.w * this->values[3][1];
	temp.z = _vec.x * this->values[0][2] + _vec.y * this->values[1][2] + _vec.z * this->values[2][2] + _vec.w * this->values[3][2];
	temp.w = _vec.x * this->values[0][3] + _vec.y * this->values[1][3] + _vec.z * this->values[2][3] + _vec.w * this->values[3][3];
	return temp;
}

Mat4 MathL::Mat4::operator*(const Mat4& _mat)
{
	Mat4 temp;
	temp.Fill(0);
	for (unsigned int i = 0; i < 4; ++i)
	{
		for (unsigned int j = 0; j < 4; ++j)
		{
			float value = 0;
			for (unsigned int k = 0; k < 4; ++k)
			{
				value += this->values[i][k] * _mat.values[k][j];
			}
			temp.values[i][j] = value;
		}
	}
	return temp;
}

// ------------ Methods ------------ 

Mat4 MathL::Mat4::Translate(Vec4 vec)
{
	Mat4 temp = temp.Identity();
	temp.v30 = vec.x; temp.v31 = vec.y; temp.v32 = vec.z;
	return temp;
}

Mat4 MathL::Mat4::ScaleByVec3(const Vec3& _vec)
{
	values[0][0] *= _vec.x; values[0][1] *= _vec.y; values[0][2] *= _vec.z;
	values[1][0] *= _vec.x; values[1][1] *= _vec.y; values[1][2] *= _vec.z;
	values[2][0] *= _vec.x; values[2][1] *= _vec.y; values[2][2] *= _vec.z;
	return *this;
}

Mat4 MathL::Mat4::ScaleByVec4(const Vec4& _vec)
{
	values[0][0] *= _vec.x; values[0][1] *= _vec.y; values[0][2] *= _vec.z; values[0][3] *= _vec.w;
	values[1][0] *= _vec.x; values[1][1] *= _vec.y; values[1][2] *= _vec.z; values[1][3] *= _vec.w;
	values[2][0] *= _vec.x; values[2][1] *= _vec.y; values[2][2] *= _vec.z; values[2][3] *= _vec.w;
	values[3][0] *= _vec.x; values[3][1] *= _vec.y; values[3][2] *= _vec.z; values[3][3] *= _vec.w;
	return *this;
}

Mat4 MathL::Mat4::RotateX(float _degree)
{
	_degree = _degree * (PI / 180);
	Mat4 rotation;
	rotation.Fill(0);
	rotation.values[0][0] = 1; rotation.values[3][3] = 1;
	rotation.values[1][1] = cosf(_degree); rotation.values[1][2] = -sinf(_degree);
	rotation.values[2][1] = sinf(_degree); rotation.values[2][2] = cosf(_degree);

	return rotation;;
}

Mat4 MathL::Mat4::RotateY(float _degree)
{
	_degree = _degree * (PI / 180);
	Mat4 rotation;
	rotation.Fill(0);
	rotation.values[1][1] = 1; rotation.values[3][3] = 1;
	rotation.values[0][0] = cosf(_degree); rotation.values[0][2] = sinf(_degree);
	rotation.values[2][0] = -sinf(_degree); rotation.values[2][2] = cosf(_degree);

	return rotation;
}

Mat4 MathL::Mat4::RotateZ(float _degree)
{
	_degree = _degree * (PI / 180);
	Mat4 rotation;
	rotation.Fill(0);
	rotation.values[2][2] = 1; rotation.values[3][3] = 1;
	rotation.values[0][0] = cosf(_degree); rotation.values[0][1] = -sinf(_degree);
	rotation.values[1][0] = sinf(_degree); rotation.values[1][1] = cosf(_degree);

	return rotation;
}

Mat4 MathL::Mat4::CreateTransformMat(Vec4& _vec)
{
	Mat4 temp;
	temp.Fill(0);
	temp.values[0][0] = 1;
	temp.values[1][1] = 1;
	temp.values[2][2] = 1;
	temp.values[0][3] = _vec.x;
	temp.values[1][3] = _vec.y;
	temp.values[2][3] = _vec.z;
	temp.values[3][3] = _vec.w;
	return temp;
}

Mat4 MathL::Mat4::Identity()
{
	Mat4 temp;
	temp.Fill(0);
	temp.values[0][0] = 1;
	temp.values[1][1] = 1;
	temp.values[2][2] = 1;
	temp.values[3][3] = 1;
	return temp;
}

Mat4 MathL::Mat4::Zero()
{
	Fill(0);
	return *this;
}

Mat4 MathL::Mat4::Transpose()
{
	Mat4 transpose = transpose.Zero();
	for (unsigned int row = 0; row < 4; ++row)
	{
		for (unsigned int col = 0; col < 4; ++col)
		{
			transpose.values[row][col] = this->values[col][row];
		}
	}
	return transpose;
}

Mat4 MathL::Mat4::Inverse()
{
	float determinant = this->Determinant();
	Mat4 temp = temp.Zero();
	temp = this->Minor();
	temp = temp.Cofactors();
	temp = temp.Transpose();
	temp = temp * (1 / determinant);
	return temp;
}

Mat4 MathL::Mat4::Minor()
{
	Mat4 minors = minors.Zero();

	minors.values[0][0] = Determinant(values[1][1], values[1][2], values[1][3],
									values[2][1], values[2][2], values[2][3],
									values[3][1], values[3][2], values[3][3]);

	minors.values[0][1] = Determinant(values[1][0], values[1][2], values[1][3],
									values[2][0], values[2][2], values[2][3],
									values[3][0], values[3][2], values[3][3]);

	minors.values[0][2] = Determinant(values[1][0], values[1][1], values[1][3],
									values[2][0], values[2][1], values[2][3],
									values[3][0], values[3][1], values[3][3]);

	minors.values[0][3] = Determinant(values[1][0], values[1][1], values[1][2],
									values[2][0], values[2][1], values[2][2],
									values[3][0], values[3][1], values[3][2]);

	minors.values[1][0] = Determinant(values[0][1], values[0][2], values[0][3],
									values[2][1], values[2][2], values[2][3],
									values[3][1], values[3][2], values[3][3]);

	minors.values[1][1] = Determinant(values[0][0], values[0][2], values[0][3],
									values[2][0], values[2][2], values[2][3],
									values[3][0], values[3][2], values[3][3]);

	minors.values[1][2] = Determinant(values[0][0], values[0][1], values[0][3],
									values[2][0], values[2][1], values[2][3],
									values[3][0], values[3][1], values[3][3]);

	minors.values[1][3] = Determinant(values[0][0], values[0][1], values[0][2],
									values[2][0], values[2][1], values[2][2],
									values[3][0], values[3][1], values[3][2]);

	minors.values[2][0] = Determinant(values[0][1], values[0][2], values[0][3],
									values[1][1], values[1][2], values[1][3],
									values[3][1], values[3][2], values[3][3]);

	minors.values[2][1] = Determinant(values[0][0], values[0][2], values[0][3],
									values[1][0], values[1][2], values[1][3],
									values[3][0], values[3][2], values[3][3]);

	minors.values[2][2] = Determinant(values[0][0], values[0][1], values[0][3],
									values[1][0], values[1][1], values[1][3],
									values[3][0], values[3][1], values[3][3]);

	minors.values[2][3] = Determinant(values[0][0], values[0][1], values[0][2],
									values[1][0], values[1][1], values[1][2],
									values[3][0], values[3][1], values[3][2]);

	minors.values[3][0] = Determinant(values[0][1], values[0][2], values[0][3],
									values[1][1], values[1][2], values[1][3],
									values[2][1], values[2][2], values[2][3]);

	minors.values[3][1] = Determinant(values[0][0], values[0][2], values[0][3],
									values[1][0], values[1][2], values[1][3],
									values[2][0], values[2][2], values[2][3]);

	minors.values[3][2] = Determinant(values[0][0], values[0][1], values[0][3],
									values[1][0], values[1][1], values[1][3],
									values[2][0], values[2][1], values[2][3]);

	minors.values[3][3] = Determinant(values[0][0], values[0][1], values[0][2],
									values[1][0], values[1][1], values[1][2],
									values[2][0], values[2][1], values[2][2]);

	return minors;
}

Mat4 MathL::Mat4::Cofactors()
{	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i + j) % 2 != 0)
				this->values[i][j] *= -1;
		}
	}
	return *this;
}

float MathL::Mat4::Determinant(float v00, float v01, float v02,
								float v10, float v11, float v12,
								float v20, float v21, float v22)
{
	return (v00 * (v11 * v22 - v21 * v12)
			- v01 * (v10 * v22 - v20 * v12)
			+ v02 * (v10 * v21 - v20 * v11));
}

float MathL::Mat4::Determinant()
{
	float Ma = values[0][0] * Determinant(values[1][1], values[1][2], values[1][3],
										values[2][1], values[2][2], values[2][3],
										values[3][1], values[3][2],values[3][3]);

	float Mb = values[0][1] * Determinant(values[1][0], values[1][2], values[1][3],
										values[2][0], values[2][2], values[2][3],
										values[3][0], values[3][2], values[3][3]);

	float Mc = values[0][2] * Determinant(values[1][0], values[1][1], values[1][3],
										values[2][0], values[2][1], values[2][3],
										values[3][0], values[3][1], values[3][3]);

	float Md = values[0][3] * Determinant(values[1][0], values[1][1], values[1][2],
										values[2][0], values[2][1], values[2][2],
										values[3][0], values[3][1], values[3][2]);

	return (Ma - Mb + Mc - Md);
}
#pragma endregion
