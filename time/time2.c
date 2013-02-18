#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

//This function will find the first blank from input
//string and then return the char pointer
//if can not find blank from input string return NULL
char *findBlank(char *pStr)
{
  char *pc=pStr;
  int len=strlen(pStr);
  int i;

  if(pc == NULL)
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

//This function will find the first ':' from string
//User have to input the parameter by ctime() function
//I can not remember the english character of ':', so can not 
//name the function 
char *findx(char *pStr)
{
  char *pc=pStr;
  int len=strlen(pStr);
  int i;

  if(pc == NULL)
    return NULL;
  if(len == 0)
    return NULL;
#if DEBUG
  printf("[Debug:] findx(%s), len=%d\n",pStr,len);
#endif

  for(i=0;i<len;i++)
  {
    if(*pc == ':') return pc;
    pc++;
  }
  return NULL;  
}

//This function will return year value by int format
//Users have to input the parameter by ctime() function 
int getYear(char *stringOfctime)
{
  char *cp=stringOfctime;
  int i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getYear() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }

  cp=findBlank(cp); 
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  
  if(cp)
  {
    char Year[5]="1900";
  
    if(strlen(cp)>=4)
    {
      int y=0;
      for(i=0;i<4;i++) Year[i]=cp[i];
      Year[i]='\0';
      y=atoi(cp);
      return y;
    }
  }
  return 0;
}

//This function will returne month value by int format
//Users have to imput the parameter by ctime() funtion
int getMonth(char *stringOfctime)
{
  char *cp=stringOfctime;
  int i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getMonth() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }
  
  cp=findBlank(cp);

  if(cp)
  {
    char Mon[4] = "000";
    cp++;
    if(strlen(cp)>=3)
    {
      //strncat(Mon,cp,3);
      for(i=0;i<3;i++) Mon[i]=cp[i];
      Mon[i]='\0';
      
#if DEBUG
      printf("[Debug:] Mon=%s\n",Mon);
#endif
      if(strcmp(Mon,"Jan") == 0)
        return 1;
      if(strcmp(Mon,"Feb") == 0)
        return 2;
      if(strcmp(Mon,"Mar") == 0)
        return 3;
      if(strcmp(Mon,"Apr") == 0)
        return 4;
      if(strcmp(Mon,"May") == 0)
        return 5;
      if(strcmp(Mon,"Jun") == 0)
        return 6;
      if(strcmp(Mon,"Jul") == 0)
        return 7;
      if(strcmp(Mon,"Aug") == 0)
        return 8;
      if(strcmp(Mon,"Sep") == 0)
        return 9;
      if(strcmp(Mon,"Oct") == 0)
        return 10;
      if(strcmp(Mon,"Nov") == 0)
        return 11;
      if(strcmp(Mon,"Dec") == 0)
        return 12;
    }
  }
  return 0;
}

//This function will return day value by int format
//User have to input the parameter by ctime() function
int getDay(char *stringOfctime)
{
  char *cp=stringOfctime;
  char *cp2;
  int len=0,i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getDay() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }

  cp=findBlank(cp); 
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp2=cp;
  
  if(cp)
  {
    char Day[3]="00";
  
    cp2=findBlank(cp2);
    
    if(cp2>cp)
    {
      len = cp2-cp;
      if(len<=2)
      {
        int d;
        for(i=0;i<len;i++) Day[i]=cp[i];
        Day[i]='\0';
        d=atoi(Day);
        return d;
      }
    }
  }
  return 0;
}

//This function will return day in week by int format
//User have to input the parameter by ctime() function
int getWeek(char *stringOfctime)
{
  char *cp=stringOfctime;
  int i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getMonth() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }
  
  cp=findChar(cp);
  
  if(cp)
  {
    char Day[4] = "000";
  
    if(strlen(cp)>=3)
    {
      //strncat(Mon,cp,3);
      for(i=0;i<3;i++) Day[i]=cp[i];
      Day[i]='\0';
      
#if DEBUG
      printf("[Debug:] Day=%s\n",Day);
#endif
      if(strcmp(Day,"Mon") == 0)
        return 1;
      if(strcmp(Day,"Tue") == 0)
        return 2;
      if(strcmp(Day,"Wed") == 0)
        return 3;
      if(strcmp(Day,"Thu") == 0)
        return 4;
      if(strcmp(Day,"Fri") == 0)
        return 5;
      if(strcmp(Day,"Sat") == 0)
        return 6;
      if(strcmp(Day,"Sun") == 0)
        return 7;
    }
  }

  return 0;
}

//This function will return hour value by int format
//Users have to input the parameter by ctime() function
int getHour(char *stringOfctime)
{
  char *cp=stringOfctime;
  char *cp2;
  int len=0,i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getDay() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }

  cp=findBlank(cp); 
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  
  cp2=findx(cp);
  
  if(cp2)
  {
    char hour[3]="00";
    
    if(cp2>cp)
    {
      len = cp2-cp;
      if(len<=2)
      {
        int h;
        for(i=0;i<len;i++) hour[i]=cp[i];
        hour[i]='\0';
        h=atoi(hour);
        return h;
      }
    }
  }

  return 0;
}

//This function will return minute value by iut format
//Users have to input the parameter by ctime() function
int getMinute(char *stringOfctime)
{
  char *cp=stringOfctime;
  char *cp2;
  int len=0,i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getDay() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }

  cp=findBlank(cp); 
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  
  cp=findx(cp);cp++;
  cp2=findx(cp);
  
  if(cp2)
  {
    char Min[3]="00";
    
    if(cp2>cp)
    {
      len = cp2-cp;
      if(len<=2)
      {
        int m;
        for(i=0;i<len;i++) Min[i]=cp[i];
        Min[i]='\0';
        m=atoi(Min);
        return m;
      }
    }
  }

  return 0;
}

//This function will return second value by int format
//Users have to input the parameter by ctime() function
int getSecond(char *stringOfctime)
{
  char *cp=stringOfctime;
  char *cp2;
  int len=0,i;
  
  if(cp==NULL)
  {
#if DEBUG
    printf("[Debug:] getDay() function inpurt parameter is NULL~!\n");
#endif
    return 0;
  }

  cp=findBlank(cp); 
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  cp=findBlank(cp);
  if(cp) cp++;
  
  cp=findx(cp);cp++;
  cp=findx(cp);cp++;
  cp2=findBlank(cp);
  
  if(cp2)
  {
    char Sec[3]="00";
    
    if(cp2>cp)
    {
      len = cp2-cp;
      if(len<=2)
      {
        int s;
        for(i=0;i<len;i++) Sec[i]=cp[i];
        Sec[i]='\0';
        s=atoi(Sec);
        return s;
      }
    }
  }
  
  return 0;
}


//This is main function
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
