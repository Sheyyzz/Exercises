#include <stdio.h>


const int ORIGINYEAR = 1980;
int IsLeapYear(int year);
int DaysForMonth(int year, int month);

int main(void) {
    int days = 0;// 31 décembre 2008; comes from the hardware in real
    int year = ORIGINYEAR; // 1980, Microsoft epoch
    
    printf("enter the number of days: ");
    scanf("%d", &days);
    
   
    while (days > 366) {
        if (IsLeapYear(year)) { // 2008 is a leap year
            if (days > 366) {
                days -= 366;
                year += 1;
            } 
        }
        else {
            if (days > 365)
            {
                days -= 365;
                year += 1;
            }
        }
    }

    int month = 1;
    while (DaysForMonth(year, month) < days)
    {
        
        days  -= DaysForMonth(year,month);
        month += 1;
        
    }

    printf("%02d/%02d/%d",days,month,year);
    
}

int IsLeapYear(int year) {
    if ((ORIGINYEAR - year) % 4 == 0)
    {
        return 1;
    } 
    
    else return 0;
}

int DaysForMonth(int year, int month) {

    switch (month)
    {
    case 1: return 31;
    case 2: if (IsLeapYear(year))
    {
        return 29;
    }
    else return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    
    default:
        break;
    }
    
}