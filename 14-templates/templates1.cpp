#include <iostream>

using namespace std;

template <typename T>
const T& max_p(const T& x, const T& y)
{
    return (x > y) ? x : y;
}

int main()
{
    int i = max_p(3, 7);
    cout << i << endl;

    double d = max_p(6.32, 18.528);
    cout << d << endl;

    char ch = max_p('a', '6');
    cout << ch << endl;

    return 0;
}