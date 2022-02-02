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
	for (int s=0; s<=30; s++){
		std::cout << "Input passed to stepPerms(int n): " << s << ",\t " << "Output: " << stepPerms(s) << std::endl;
	}
	return 0;
}

