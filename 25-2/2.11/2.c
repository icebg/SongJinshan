#include "assignment2.h" 
int main(int argc, char *argv[])  
{  
    FILE *in, *out;  
    char *in_name = "1.ini";  
    char *out_name = "1.xml";  
    char buf[M], name[100]={0},*p;  
    int i, n, flag;  
  
    if((in = fopen(in_name, "r")) == NULL)  
    {  
        printf("Can not open %s/n", in_name);  
        exit(0);  
    }  
  
    if((out = fopen(out_name, "w+")) == NULL)  
    {  
        printf("Can not open %s/n", out_name);  
        exit(0);  
    }  
  
    while(!feof(in))  
    {  
        flag = 0;
        do 
        { 
            fgets(buf, M, in); 
            if(flag == 0 && *buf == '/n') 
            { 
                fprintf(out, "</%s>/n/n", name); 
                flag = 1; 
            } 
            else if(*buf == '/n') 
            { 
                fprintf(out, "/n"); 
            } 
 
        }while(*buf == '/n'); 
 
        p = strchr(buf, '/n'); 
        if(p != NULL)  
            *p = '/0';
  
        i = match(buf, &n);  
          
        if(match_char[i] != '=' && n != 0)  
        {  
            printf("ERROR:It's not ini file!/n");  
                  
            exit(0);  
        }  
  
        switch(i)  
        {  
            case 0:  
                semicolon(buf, out);//鍒嗗彿  
                break;  
            case 1:  
    //          if(*name != '/0')  
    //              fprintf(out, "</%s>/n", name);  
                strncpy(name, brackets(buf, out), N);//鏂规嫭鍙?                
                break;  
            case 2:  
    //          fseek(out, (long)(-(len + 2)), SEEK_END);//鍏夋爣鍥炲埌</string>鍓?                equal(buf, out, n);  
    //          fseek(out, 0, SEEK_END);//鍏夋爣鍥炲埌鏈熬  
                break;  
            default:  
                printf("ERROR:No such symbol!/n");  
                exit(0);  
        }  
    }  
  
    fprintf(out, "</%s>/n", name);  
    fclose(in);  
    fclose(out);  
  
    printf("Sucess!/n");  
  
    return 0;  
}  
