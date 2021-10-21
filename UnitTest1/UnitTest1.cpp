#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.2/lab5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:

		TEST_METHOD(TestMethod1) {
			int		n = 1;
			double	t = Sum(0, n, 0.0001);
			Assert::AreEqual(0., t);
		}
	};
}
