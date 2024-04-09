
#include "sis.h"
#include "test_int.h"


/*
 *  called when the program starts up
 */
int __attribute__((weak)) init_test()
{
    com_add_command("_test", com_test, /* changes_network */ 1);
}
