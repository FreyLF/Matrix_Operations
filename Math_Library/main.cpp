#include <iostream>
#include "MathL.h"
using namespace MathL;

void TestVec3();
void TestVec4();
void TestMat4Minor();
void TestInverse();
void TestSeb();

int main(int argc, const char argv[])
{
	
	//TestMat4Minor();
	TestInverse();

	return 0;
}

void TestVec3()
{
	Vec3 v1 = Vec3(1, 1, 1);
	Vec3 v2 = Vec3(2, 2, 2);
	Vec3 vTest = v1 + v2;
	std::cout << "Sum: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	vTest = v1 - v2;
	std::cout << "Subtraction: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	vTest = v1;
	std::cout << "Equal: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	float dot = v1.DotProduct(v2);
	std::cout << "Dot: " << dot << '\n';

	float norm = v1.Length();
	std::cout << "Norm/Length: " << norm << '\n';
	norm = v2.Length();
	std::cout << "Norm/Length: " << norm << '\n';

	vTest = v1.CrossProduct(v2);
	std::cout << "Cross: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	vTest = v1.Scale(3);
	std::cout << "Scale x3: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	vTest = v1.Normalize();
	std::cout << "Normalized (1,1,1): ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	vTest = v2.Normalize();
	std::cout << "Normalized (2,2,2): ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';

	Vec3 reflection1 = Vec3(-3, 3, 0);
	Vec3 reflection2 = Vec3(3, 0, 0);
	vTest = reflection1.Reflection(reflection2);
	std::cout << "Reflection: ";
	std::cout << vTest.x << ", " << vTest.y << ", " << vTest.z << '\n';
}

void TestVec4()
{
	Vec4 vector10(1, 1, 1, 1);
	Vec4 vector11(2, 2, 2, 2);


	Vec4 vector12 = vector10 + vector11;
	std::cout << "Vector 4 Tests\n";
	std::cout << "===============================================================================================================\n";
	std::cout << "Test for + override \n";
	std::cout << "Expected: 3333 \n";
	std::cout << "Actual: " << vector12.x << vector12.y << vector12.z << vector12.w;

	vector12 = vector10 - vector11;
	std::cout << "\n=================================================\n";
	std::cout << "Test for - override \n";
	std::cout << "Expected: -1-1-1-1 \n";
	std::cout << "Actual: " << vector12.x << vector12.y << vector12.z << vector12.w;

	vector10 = vector11;
	std::cout << "\n=================================================\n";
	std::cout << "Test for = override \n";
	std::cout << "Expected: 2222 \n";
	std::cout << "Actual: " << vector10.x << vector10.y << vector10.z << vector10.w;

	std::cout << "\n=================================================\n";
	std::cout << "Test for Dot Product\n";
	std::cout << "Expected: 16 \n";
	std::cout << "Actual: " << vector10.DotProduct(vector11);;

	std::cout << "\n=================================================\n";
	std::cout << "Test for Length\n";
	std::cout << "Expected: 4 \n";
	std::cout << "Actual: " << vector10.Length();

	Vec4 vector13 = vector10.Normalize();
	std::cout << "\n=================================================\n";
	std::cout << "Test for Normalize\n";
	std::cout << "Expected: 1 \n";
	std::cout << "Actual: " << vector13.Length();
	vector13 = vector13.Normalize();
	std::cout << "\n=================================================\n";
	std::cout << "Test for Normalize if length is 1 \n";
	std::cout << "Expected: 1 \n";
	std::cout << "Actual: " << vector13.Length();


	Vec4 vector14(1, 1, 1, 1);
	vector14 = vector14.ScaleMultiplication(4);
	std::cout << "\n=================================================\n";
	std::cout << "Test for Scale \n";
	std::cout << "Expected: 4444 \n";
	std::cout << "Actual: " << vector14.x << vector14.y << vector14.z << vector14.w;
	std::cout << "\n===============================================================================================================\n";
}

void TestMat4Minor()
{
	Mat4 m;
	m.v00 = 1; m.v01 = 0;		m.v02 = 0;		m.v03 = 0;
	m.v10 = 0; m.v11 = 0.309;	m.v12 = 0.951;	m.v13 = 0;
	m.v20 = 0; m.v21 = -0.951;	m.v22 = 0.309;	m.v23 = 0;
	m.v30 = 7; m.v31 = -2.282;	m.v32 = 9.153;	m.v33 = 1;

	std::cout << "\n---- Matrix ----\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m.values[i][j] << "   ";
		}
		std::cout << '\n';
	}

	Mat4 minor = m.Minor();
	std::cout << "\n---- Minor Matrix ----\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << minor.values[i][j] << "   ";
		}
		std::cout << '\n';
	}

	Mat4 cofactor = minor.Cofactors();
	std::cout << "\n---- Cofactor Matrix ----\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << cofactor.values[i][j] << "   ";
		}
		std::cout << '\n';
	}

	Mat4 transpose = minor.Transpose();
	std::cout << "\n---- Transpose Matrix ----\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << cofactor.values[j][i] << "   ";
		}
		std::cout << '\n';
	}

	float determinant = m.Determinant();
	std::cout << "\nOriginal Determinant: " << determinant << "\n";

	Mat4 multiplyDet = transpose * (1 / determinant);
	std::cout << "\n---- Divide by Determinant ----\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << multiplyDet.values[i][j] << "   ";
		}
		std::cout << '\n';
	}

	std::cout << "\n---- Inverse Result ----\n";
	std::cout << "1	0	0	0\n0	0.309	-0.951	0\n0	0.951	0.309	0\n-7	-8	-5	1";

}

void TestInverse()
{
	Mat4 m;
	m.v00 = 1; m.v01 = 0;		m.v02 = 0;		m.v03 = 0;
	m.v10 = 0; m.v11 = 0.309;	m.v12 = 0.951;	m.v13 = 0;
	m.v20 = 0; m.v21 = -0.951;	m.v22 = 0.309;	m.v23 = 0;
	m.v30 = 7; m.v31 = -2.282;	m.v32 = 9.153;	m.v33 = 1;

	Mat4 n = m.Inverse();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << n.values[i][j] << "   ";
		}
		std::cout << '\n';
	}

	std::cout << "\n---- Inverse Result ----\n";
	std::cout << "1	0	0	0\n0	0.309	-0.951	0\n0	0.951	0.309	0\n-7	-8	-5	1";
}

void TestSeb()
{
	Vec3 v(1, 2, 3);

	Mat3 m;
	m.values[0][0] = 1; m.values[0][1] = 2; m.values[0][2] = 3;
	m.values[1][0] = 4; m.values[1][1] = 5; m.values[1][2] = 6;
	m.values[2][0] = 7; m.values[2][1] = 8; m.values[2][2] = 9;

	Vec3 v2 = m * v;
	std::cout << v2.x << "   ";
	std::cout << v2.y << "   ";
	std::cout << v2.z << "   ";
	std::cout << '\n';
	std::cout << '\n';


	Mat4 m2;
	m2.values[0][0] = 1; m2.values[0][1] = 2; m2.values[0][2] = 3; m2.values[0][3] = 4;
	m2.values[1][0] = 5; m2.values[1][1] = 6; m2.values[1][2] = 7; m2.values[1][3] = 8;
	m2.values[2][0] = 9; m2.values[2][1] = 10; m2.values[2][2] = 11; m2.values[2][3] = 12;
	m2.values[3][0] = 13; m2.values[3][1] = 14; m2.values[3][2] = 15; m2.values[3][3] = 16;

	Vec4 v3(1, 2, 3, 4);
	Vec4 v4 = m2 * v3;
	std::cout << v4.x << "   ";
	std::cout << v4.y << "   ";
	std::cout << v4.z << "   ";
	std::cout << v4.w << "   ";
	std::cout << '\n';
	std::cout << '\n';
	
	Mat3 m3;
	m3.values[0][0] = 1; m3.values[0][1] = 2; m3.values[0][2] = 3;
	m3.values[1][0] = 4; m3.values[1][1] = 5; m3.values[1][2] = 6;
	m3.values[2][0] = 7; m3.values[2][1] = 8; m3.values[2][2] = 9;

	Mat3 m4;
	m4.values[0][0] = 1; m4.values[0][1] = 2; m4.values[0][2] = 3;
	m4.values[1][0] = 4; m4.values[1][1] = 5; m4.values[1][2] = 6;
	m4.values[2][0] = 7; m4.values[2][1] = 8; m4.values[2][2] = 9;

	Mat3 m5 = m3 * m4;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << m5.values[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';


	Mat4 m6;
	m6.values[0][0] = 1; m6.values[0][1] = 2; m6.values[0][2] = 3; m6.values[0][3] = 4;
	m6.values[1][0] = 5; m6.values[1][1] = 6; m6.values[1][2] = 7; m6.values[1][3] = 8;
	m6.values[2][0] = 9; m6.values[2][1] = 10; m6.values[2][2] = 11; m6.values[2][3] = 12;
	m6.values[3][0] = 13; m6.values[3][1] = 14; m6.values[3][2] = 15; m6.values[3][3] = 16;

	Mat4 m7;
	m7.values[0][0] = 17; m7.values[0][1] = 18; m7.values[0][2] = 19; m7.values[0][3] = 20;
	m7.values[1][0] = 21; m7.values[1][1] = 22; m7.values[1][2] = 23; m7.values[1][3] = 24;
	m7.values[2][0] = 25; m7.values[2][1] = 26; m7.values[2][2] = 27; m7.values[2][3] = 28;
	m7.values[3][0] = 29; m7.values[3][1] = 30; m7.values[3][2] = 31; m7.values[3][3] = 32;

	Mat4 m8 = m6 * m7;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m8.values[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';



	Mat4 m9;
	m9.values[0][0] = 1; m9.values[0][1] = 0; m9.values[0][2] = 0; m9.values[0][3] = 0;
	m9.values[1][0] = 0; m9.values[1][1] = .309f; m9.values[1][2] = .951f; m9.values[1][3] = 0;
	m9.values[2][0] = 0; m9.values[2][1] = -.951f; m9.values[2][2] = .309f; m9.values[2][3] = 0;
	m9.values[3][0] = 7; m9.values[3][1] = -2.282f; m9.values[3][2] = 9.153f; m9.values[3][3] = 1;


	Mat4 m10 = m9.Inverse();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m10.values[i][j] << "   ";
		}
		std::cout << '\n';
	}
}