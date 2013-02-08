#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
//This function will find the first blank from input
//string and then return the char pointer
//if can not find blank from input string return NULL
char *findBlank(char *pStr)
{
  char *pc=pStr;
  int len=strlen(pStr);
  int i;

  if(*pc == NULL)
    return NULL;
  if(len == 0)
    return NULL;
#if DEBUG
  printf("[Debug]: findBblank(%s), len=%d\n", pc, len);
#endif

  for(i=0;i<len;i++)
  {
    if(*pc==' ') return pc;
    pc++;
  }

  return NULL;
}

//This function will find first character from input
//string and then return the char pointer
//if can not find character from input string return NULL
char *findChar(char *pStr)
{
  char *pc=pStr;
  int len=strlen(pStr);
  int i;

  if(pc == NULL)
    return NULL;
  if(len == 0)
    return NULL;
#if DEBUG
  printf("[Debug:] findChar(%s), len=%d\n",pStr,len);
#endif

  for(i=0;i<len;i++)
  {
    if(*pc > 32 && *pc < 127) return pc;
    pc++;
  }
  return NULL;
}

//This function will return year value by int format
//Users have to input the parameter by ctime() function 
int getYear(char *stringOfctime)
{

  return 0;
}

//This function will returne month value by int format
//Users have to imput the parameter by ctime() funtion
int getMonth(char *stringOfctime)
{
  char *cp=stringOfctime;

  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug]: getMonth() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }
  
  cp=findBlank(cp);
  if(cp)
  {
    char Mon[4] = 0;
    cp++;
    if(strlen(cp)>=3)
    {
      strncat(Mon,cp,3);
      if(strcmp(Mon,"Feb") == 0)
        return 2;
    }
  }
  return 0;
}

//This function will return day value by int format
//User have to input the parameter by ctime() function
int getDay(char *stringOfctime)
{

  return 0;
}

//This function will return day in week by int format
//User have to input the parameter by ctime() function
int getWeek(char *stringOfctime)
{

  return 0;
}

//This function will return hour value by int format
//Users have to input the parameter by ctime() function
int getHour(char *stringOfctime)
{

  return 0;
}

//This function will return minute value by iut format
//Users have to input the parameter by ctime() function
int getMinute(char *stringOfctime)
{

  return 0;
}

//This function will return second value by int format
//Users have to input the parameter by ctime() function
int getSecond(char *stringOfctime)
{
  
  return 0;
}



main()
{
  time_t tp;
  char *str;
  int year, month, day, week, hour, minute, second;

  time(&tp);
  str=ctime(&tp);
  printf("ctime function return sting is : %s\n",str); // test ctime function

  year = getYear(str);
  month = getMonth(str);
  day = getDay(str);
  week = getWeek(str);
  hour = getHour(str);
  minute = getMinute(str);
  second = getSecond(str);
  printf("year=%d,month=%d,day=%d,week=%d,hour=%d,minute=%d,second=%d\n",
          year,month,day,week,hour,minute,second);

}
