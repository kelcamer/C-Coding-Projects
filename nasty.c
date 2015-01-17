#include <stdio.h>
struct foo{  int num;
             char* word;
             struct foo *ptr;};

char w1[5]; int r[20],h[20];
void func1(struct foo);
void func2(struct foo*);
int main() {
        w1[0]='a'; w1[1]='b'; w1[2]='c'; w1[3]='\0';
        struct foo a,b,c;
        a.num= 5; a.ptr= &b;
        b.num=80; b.ptr= &c;
        c.num=50; c.ptr= &a;
        a.word= &r;
        b.word= &h;
        c.word= &r;
        strcpy(a.word,"whichwordgoods");
        strcpy(b.word, w1);
         printf("89 is %d %s %s\n", a.num, w1, c.word);
      a.word= &w1[0];
        strcpy(a.word,w1);
         printf("80 is %d %s %s\n", a.num, w1, b.word);
        func1(c);
        func1(a);
        printf("8 is %d %s\n", a.num, a.word);

        a.num = 100;
        a.word = "secondword";
        func2(&a);
        printf("11 %d %s\n", a.num, a.word);
        system("pause");
}                                          //    ONLY THIS OUTPUT WILL BE GRADED
void func1(struct foo a)                  //          |----------------------
{      while(*(a.word) != '\0')           //          |
           {                              //    Line 1|______________________
                putchar(*(a.word));       //          |
                a.word++;                 //    Line 2|______________________
                a.word++;                 //          |
                                          //    Line 3|______________________
           }                              //          |
        putchar('\n');                    //    Line 4|______________________
        a.word--; a.word--; a.word--;     //          |
        printf("2 is %s\n", a.word );     //    Line 5|______________________
                                          //          |
        strcpy(a.word, "whatever");       //    Line 6|______________________
        if(a.num % 10 != 0)               //          |
           { a.num *= 2; }                //    Line 7|______________________
        a.word--;
      //  printf("WORDDDD %s\n", a.word);                //          |
        strcpy(a.word, "whatever");       //    Line 8|______________________
        a.word[5]='P';
        a.word[6]='\n';                   //          |
        printf("3 is %d\n", a.num);       //    Line 9|______________________
        if( (a).num ==  a.ptr->num)        //         |
          { (a).num = (* (a.ptr)).num +1; } // Line 10|______________________
        else                                //        |
          { a.num = 200; }                  // Line 11|______________________
        a.ptr->ptr = &a;
        printf("4 is %d %s\n", (a).num, (*((*(a.ptr)).ptr)).word);
        printf("5 is %s\n",  a.word);
        strcpy(a.word,"wordseven");
        printf("6 is %d %s\n", (a).num, a.word);
        printf("7 is %s\n", (*((*((*(a.ptr)).ptr))).ptr).word);
        strcpy(a.ptr->ptr->ptr->word,"wordsix");
}
void func2(struct foo *a)
{       while(*(a->word) != '\0')     //TRY DOING THIS IN EXPANDED NOTATION
           {    putchar(*(a->word));
                a->word++;
           }
        putchar('\n');
        if(a->num % 10 != 0)
           { a->num *= 2; }
        a->word--;
        printf("10 is %d\n", (*a).num);
}
