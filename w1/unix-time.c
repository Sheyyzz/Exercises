#include <stdio.h>
#include <time.h>


int main(void) {
  

    time_t now = time(NULL);
    printf("%ld secondes se sont ecoulees depuis le 1.1.1970 a minuit.", now);

    struct tm *lt = localtime(&now);
    printf("nous sommes donc le %02d/%02d/%d à %02d:%02d:%02d\n",
           lt->tm_mday,        /* jour du mois */
           lt->tm_mon + 1,     /* mois: 0..11 -> +1 */
           lt->tm_year + 1900, /* année depuis 1900 */
           lt->tm_hour,
           lt->tm_min,
           lt->tm_sec);
    
}
