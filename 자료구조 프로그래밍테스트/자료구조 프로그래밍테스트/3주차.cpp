#include <iostream>


using namespace std;

// [����] �迭 arr[10]�� ����ִ� ���ڿ��� �Ųٷ� ����ϴ� ���
//  -- *��� �ǽ������� ����Լ��� �̿��Ͽ� �ذ��ϸ�?
//  �迭 S���� search�� �����ϴ� �����?

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