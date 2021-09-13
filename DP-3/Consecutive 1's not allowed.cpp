#include<iostream>

using namespace std ;

int main()
{
	int no ;

	cin >> no ;

	int oldOnes = 1 ;
	int oldZeros = 1 ;

	for( int i = 2 ; i <= n ; i++ )
	{
		int newOnes = oldZeros+oldOnes ;
		int newzeros = oldOnes ;

		oldOnes = newOnes ;
		oldZeros = newzeros ;
	}

	cout<< oldZeros+oldOnes ;


	return 0 ;
}
