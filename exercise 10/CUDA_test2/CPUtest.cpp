/*
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <vector>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <chrono>
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace chrono;

#define N 400000

int main()
{
	cout << "Testing CPU" << endl;
	cout << "Reserving RAM" << endl;

	vector <int> X(N);
	vector <int> Y(N);
	vector <int> Z(N);

	for (int i = 0; i < N; i++)
	{
		X[i] = i;
		Y[i] = i * i;
	}

	cout << "Reserving Completed" << endl;

	vector<int> d_X = X;
	vector<int> d_Y = Y;

	cout << "Current progress: " << endl;

	auto begin = std::chrono::steady_clock::now();

	int j = 1;
	for (int i = 0; i < 100; i++)
	{
		transform(d_X.begin(), d_X.end(), d_Y.begin(), Z.begin(), thrust::plus<int>());

		if (i / 5 == j)
		{
			auto end1 = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin);
			cout << elapsed_ms.count() << " - ms - " << i / 1 << " %" << endl;
			j = j + 1;
		}

	}
	auto end2 = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin);
	cout << "TOTAL time for: " << elapsed_ms.count() << " - ms.";

	return 0;
}
*/