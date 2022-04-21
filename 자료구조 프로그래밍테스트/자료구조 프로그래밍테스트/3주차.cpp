#include <iostream>


using namespace std;

// [문제] 배열 arr[10]에 들어있는 문자열을 거꾸로 출력하는 방법
//  -- *찍기 실습문제를 재귀함수로 이용하여 해결하면?
//  배열 S에서 search를 구현하는 방법은?

int reverse(int count, int arr[])
{
	if (count == 0)
		return -1;
	cout << arr[count - 1] << endl;
	reverse(count - 1, arr);
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse(10, arr);
	
}