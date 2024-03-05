/* For full ANSI compliance of global variable */

#include <projects.h>

C_NAMESPACE_VAR int pj_errno = 0;

/************************************************************************/
/*                          pj_get_errno_ref()                          */
/************************************************************************/

int *pj_get_errno_ref(void)

{
    return &pj_errno;
}

/* end */
