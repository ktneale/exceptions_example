#include <iostream>

typedef enum {
    ERR_BAD_PARAMETERS = 0,
    ERR_BAD_ALLOC,
    ERR_INTERNAL_ERROR,
    ERR_UNKNOWN
} exceptions_t;

const char *exception_to_string(exceptions_t e)
{
    switch (e) {
    case 0:
        return ("Error! Bad parameters");
    case 1:
        return ("Error! Could not allocate memory");
    case 2:
        return ("Error! Internal error");
    case 3:
        return ("Error! Unknown");
    default:
        return ("");
    }
}

int foo(int x)
{

    std::cout << "input: " << x << std::endl;
    if (x < 0)
        throw ERR_BAD_PARAMETERS;

    switch (x) {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void test_main()
{
    try {
        int x = -2;
        foo(x);
    }
    catch( ...) {
        throw;
    }

    return;
}

int main()
{
    try {
        test_main();
    }
    catch(exceptions_t e) {
        std::
            cout << "exception caught: " << exception_to_string(e) << std::
            endl;
    }
    catch( ...) {
        std::cout << "exception caught" << std::endl;
    }

    return 0;
}
