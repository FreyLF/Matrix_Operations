#pragma once
#include <vector>

namespace MathL
{
	class Vec4;
	class Mat4;
	class Vec3
	{
	public:
		float x, y, z;

		// Construct
		Vec3();
		Vec3(float _value);
		Vec3(float _x, float _y, float _z);
		Vec3(const Vec3& _copy);

		// Operators
		Vec3 operator +(const Vec3& vector);
		Vec3 operator -(const Vec3& vector);
		Vec3 operator =(const Vec3& vector);

		// Methods
		float DotProduct(const Vec3& vector);
		float Length();
		Vec3 CrossProduct(const Vec3& vector);
		Vec3 Scale(float scalar);
		Vec3 Reflection(Vec3 v_surface);
		Vec3 Normalize();
		Vec4 ConvertToVec4();
	};

	class Vec4
	{
	public:
		float x, y, z, w;
		// Construct
		Vec4();
		Vec4(float _value);
		Vec4(float _x, float _y, float _z, float _w);
		Vec4(const Vec4& _copy);

		// Operators
		Vec4 operator +(const Vec4& vector);
		Vec4 operator -(const Vec4& vector);
		Vec4 operator =(const Vec4& vector);
		Vec4 operator *(const Mat4& mat);

		// Methods
		float DotProduct(const Vec4& vector);
		float Length();
		Vec4 ScaleMultiplication(float scalar);
		Vec4 Normalize();
		Vec3 ConvertToVec3();
	};

	class Mat3
	{	
		void Fill(float _value);

	public:
		float values[3][3];

		// Construct
		Mat3();
		Mat3(const Mat3& _mat);
		Mat3(std::vector<float>&);

		// Operators
		Mat3 operator +(const Mat3& _mat);
		Mat3 operator -(const Mat3& _mat);
		Mat3 operator *(float scale);
		Vec3 operator *(const Vec3& _vec);
		Mat3 operator *(const Mat3& _mat);

		// Methods
		Mat3 Identity();
		Mat3 Zero();
		Mat3 Transpose();
		float Determinant();
	};

	class Mat4
	{
		void Fill(float _value);
	public:
		union
		{
			float values[4][4];
			// Single elements in row major format
			struct
			{
				float v00, v01, v02, v03;
				float v10, v11, v12, v13;
				float v20, v21, v22, v23;
				float v30, v31, v32, v33;
			};
		};

		// Construct
		Mat4();
		Mat4(const Mat4& _mat);
		Mat4(std::vector<float>&);

		// Operators
		Mat4 operator +(const Mat4& _mat);
		Mat4 operator -(const Mat4& _mat);
		Mat4 operator *(float scale);
		Vec4 operator *(const Vec3& _vec);
		Vec4 operator *(const Vec4& _vec);
		Mat4 operator *(const Mat4& _mat);

		// Methods
		Mat4 ScaleByVec3(const Vec3& _vec);
		Mat4 ScaleByVec4(const Vec4& _vec);
		Mat4 CreateTransformMat(Vec4& _vec);
		Mat4 RotateX(float _degree);
		Mat4 RotateY(float _degree);
		Mat4 RotateZ(float _degree);
		Mat4 Identity();
		Mat4 Zero();
		Mat4 Transpose();
		Mat4 Minor();
		Mat4 Cofactors();
		Mat4 Inverse();
		float Determinant();
		float Determinant(float v00, float v01, float v02,
						float v10, float v11, float v12, 
						float v20, float v21, float v22);
	};
}