#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_hello.h"

static zend_function_entry hello_functions[] =
{
    PHP_FE(hello_world, NULL)
    PHP_FE(hello_long, NULL)
    PHP_FE(hello_double, NULL)
    PHP_FE(hello_bool, NULL)
    PHP_FE(hello_null, NULL)
    PHP_FE(hello_true, NULL)
    PHP_FE(hello_false, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_HELLO_WORLD_EXTNAME,
    hello_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HELLO_WORLD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif

PHP_FUNCTION(hello_world)
{
    RETURN_STRING("Hello World", 1);
}

// Equivalent to the code above but assigns the string
// and returns a  pointer of the assigned string (0) in the second argument
// of RETURN_STRING
// PHP_FUNCTION(hello_world)
// {
//     char *str;
//     str = estrdup("Hello World");
//     RETURN_STRING(str, 0);
// }

PHP_FUNCTION(hello_long)
{
    RETURN_LONG(42);
}

PHP_FUNCTION(hello_double)
{
    RETURN_DOUBLE(3.1415926535);
}

PHP_FUNCTION(hello_bool)
{
    RETURN_BOOL(1);
}

PHP_FUNCTION(hello_null)
{
    RETURN_NULL();
}

PHP_FUNCTION(hello_true)
{
    RETURN_TRUE;
}

PHP_FUNCTION(hello_false)
{
    RETURN_FALSE;
}
