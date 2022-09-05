#ifndef H_DEBUG
#define H_DEBUG
#define ASSERT(condition)                                                              \
    if (!(condition))                                                                  \
    {                                                                                  \
        printf ("Error:\n");                                                           \
        printf ("The condition %s is not met (invalid value).\n", #condition);         \
        printf ("Error location:\n");                                                  \
        printf ("\tFile:              %s \n", __FILE__);                               \
        printf ("\tLine:            %d \n", __LINE__);                                 \
        printf ("\tFunction:           %s \n", __PRETTY_FUNCTION__);                   \
    }
#endif
