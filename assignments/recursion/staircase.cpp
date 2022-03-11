#include <iostream>

int stepPerms(int n){
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else{
        return ((stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3)) %10000000007);
    }
}

int main()
{
	std::cout << stepPerms(4) << std::endl;
	return 0;
}

