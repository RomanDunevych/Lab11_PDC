#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int INF = std::numeric_limits<int>::max();

// ��������� ������� floydWarshall � ��������� ����
void floydWarshall(int n, std::vector<std::vector<int>>& dist) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// �������� ���� 3 ������� � 3 �����
			int n = 3;
			std::vector<std::vector<int>> dist = {
				{ 0, 3, INF },
				{ INF, 0, 1 },
				{ INF, INF, 0 }
			};

			// ���������� ��������� ���� ��������� ���������
			std::vector<std::vector<int>> expected = {
				{ 0, 3, 4 },
				{ INF, 0, 1 },
				{ INF, INF, 0 }
			};

			// �������� �������� ������-��������
			floydWarshall(n, dist);

			// ����������, �� ��������� ��������� ������� � ����������
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					Assert::AreEqual(expected[i][j], dist[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2)
		{
			// �������� ���� � ������������ ��������� (���� ����� �� ������� ���������)
			int n = 4;
			std::vector<std::vector<int>> dist = {
				{ 0, INF, INF, 10 },
				{ INF, 0, 3, INF },
				{ INF, INF, 0, 1 },
				{ INF, INF, INF, 0 }
			};

			// ���������� ��������� ���� ��������� ���������
			std::vector<std::vector<int>> expected = {
				{ 0, INF, INF, 10 },
				{ INF, 0, 3, 4 },
				{ INF, INF, 0, 1 },
				{ INF, INF, INF, 0 }
			};

			// �������� �������� ������-��������
			floydWarshall(n, dist);

			// ����������, �� ��������� ��������� ������� � ����������
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					Assert::AreEqual(expected[i][j], dist[i][j]);
				}
			}
		}
	};
}
