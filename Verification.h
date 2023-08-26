#ifndef VERIFICATION_H_INCLUDED
#define VERIFICATION_H_INCLUDED

void Ameliorer_Nom(char *ch)
{
    char *p ;
    if(*ch==' ')
        strcpy(ch,ch+1) ;
    if(*(ch+strlen(ch)-1)==' ')
        *(ch+strlen(ch)-1)='\0' ;
    *ch=toupper(*ch) ;
    for(p=ch+1;*p;p++)
        *p=tolower(*p) ;
    for(p=ch;strchr(p,' ');)
    {
        *(strchr(p,' ')+1)=toupper(*(strchr(p,' ')+1)) ;
        p=strchr(p,' ')+1 ;
    }
}
void Ameliorer_Date(char *ch1)
{
    char ch2[11]="0",ch3[11]="";
    if(isdigit(ch1[1])==0)
    {
        strcat(ch2,ch1) ;
        strcpy(ch1,ch2) ;
    }
    if(isdigit(*(ch1+4))==0)
    {
        strncpy(ch3,ch1,3) ;
        strcat(ch3,"0") ;
        strcat(ch3,ch1+3) ;
        strcpy(ch1,ch3) ;
    }
}
int Verif_Num(char *ch)
{
    char *p ;
    for(p=ch;*p;p++)
        if(!(isdigit(*p)))
            return 0 ;
    return 1 ;
}
int Num_Tel_Valide(char *ch)
{
    if(strlen(ch)!=8||Verif_Num(ch)==0||ch[0]=='1'||ch[0]=='0')
        return 0 ;
    return 1 ;
}
int Verif_Nom(char *ch)
{
    char *p ;
    if(strstr(ch,"  "))
        return 0 ;
    for(p=ch;*p;p++)
        if(!(isalpha(*p)||*p==' '))
            return 0 ;
    return 1 ;
}
int Date_Valide(char *ch)
{
    int jmax,jj,mm,aa,i ;
    Ameliorer_Date(ch) ;
    if(ch[2]!='/'||ch[5]!='/')
        return 0 ;
    for(i=0;ch[i];i++)
        if(i!=2&&i!=5&&isdigit(ch[i])==0)
            return 0 ;
    jj=atoi(ch);
    mm=atoi(ch+3);
    aa=atoi(ch+6);
    if(mm>12||mm<1||jj>31||jj<1||aa<1900||aa>2015)
        return 0;
    switch(mm)
    {
        case 2  : if(aa%4)
                    jmax=28 ;
                  else
                    jmax=29 ;
                  break;
        case 4  :
        case 6  :
        case 9  :
        case 11 : jmax=30;
                  break ;
        default : jmax=31;
    }
    if(jj>jmax)
        return 0 ;
    return 1 ;
}
int Rue_Valide(char *ch)
{
    char *p ;
    if(strlen(ch)==0)
        return 0 ;
    if(strstr(ch,"  "))
        return 0 ;
    for(p=ch;*p;p++)
        if(isalnum(*p)==0&&*p!=' ')
            return 0 ;
    return 1 ;
}
int E_Mail_Valide(char *ch)
{
    char *p,*pl,cp ;
    if(islower(*ch)==0)
        return 0 ;
    p=strchr(ch,'@') ;
    if(p==NULL||p!=strrchr(ch,'@'))
        return 0 ;
    for(pl=ch,cp=0;pl!=p;pl++)
    {
        if(*pl=='.')
            cp++ ;
        if(cp>1||(*pl!='.'&&islower(*pl)==0&&isdigit(*pl)==0))
                return 0 ;
    }
    if(cp&&isalnum(*(strchr(ch,'.')+1))==0)
        return 0 ;
    for(pl=p+1,cp=0;*pl;pl++)
    {
        if(*pl=='.')
            cp++ ;
        if(cp>1||(*pl!='.'&&islower(*pl)==0))
                return 0 ;
    }
    if(cp==0||islower(*(strchr(p,'.')+1))==0||*(strchr(p,'.')-1)=='@')
        return 0 ;
    return 1 ;
}

#endif // VERIFICATION_H_INCLUDED
